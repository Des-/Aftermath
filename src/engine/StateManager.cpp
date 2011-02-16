//      StateManager.cpp -- A manager for multiple states.
//
//      Copyright 2011 Kevin Harrison <keharriso@gmail.com>
//
//      This file is part of Aftermath.
//
//      Aftermath is free software: you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation, either version 3 of the License, or
//      (at your option) any later version.
//
//      Aftermath is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//
//      You should have received a copy of the GNU General Public License
//      along with Aftermath.  If not, see <http://www.gnu.org/licenses/>

#include "App.hpp"
#include "State.hpp"
#include "StateManager.hpp"

using namespace Aftermath::Engine;

StateManager::StateManager(App & app) : mApp(app) {
    mApp.getLogger() << "Constructing StateManager" << std::endl;
}

StateManager::~StateManager() {
    mApp.getLogger() << "Destructing StateManager" << std::endl;
    while (!mStack.empty()) {
        State * state = mStack.back();
        mStack.pop_back();

        state->pause();
        state->markCleanup();
        state->startCleanup();
        delete state;
    }
    while(!mDropped.empty()) {
        State* state = mDropped.back();
        mDropped.pop_back();

        state->pause();
        state->markCleanup();
        state->startCleanup();
        delete state;
    }
}

bool StateManager::isEmpty() const {
    return mStack.empty();
}

void StateManager::addState(State * state, bool active) {
    if (state != NULL) {
        if (active) {
            mApp.getLogger() << "Adding active state '" << state->getId()
                             << "'" << std::endl;
            if(!mStack.empty()) {
              // Pause the currently running state since we are changing the
              // currently active state to the one provided
              mStack.back()->pause();
            }

            mStack.push_back(state);
            mStack.back()->init();
        } else {
            mStack.insert(mStack.begin(), state);
        }
    } else mApp.getLogger() << "Attempting to add null state" << std::endl;
}

State * StateManager::getActiveState() {
    return mStack.back();
}

void StateManager::dropActiveState() {
    if(!mStack.empty()) {
        State * state = mStack.back();

        mApp.getLogger() << "Dropping state '" << state->getId() << "'"
                         << std::endl;

        state->pause();
        state->markCleanup();

        mStack.pop_back();
        mStack.insert(mStack.begin(), state);
    } else mApp.getLogger() << "Trying to drop state from empty stack"
                            << std::endl;

    if(!mStack.empty()) {
        if(mStack.back()->isInitialized()) {
            // Resume the new active state
            mStack.back()->resume();
        } else {
            // Initialize the new active state
            mStack.back()->init();
        }
    } else {
        // There are no states on the stack, exit the program
        mApp.stopRunning(0);
    }
}

void StateManager::removeActiveState() {
    if(!mStack.empty()) {
        State * state = mStack.back();

        mApp.getLogger() << "Removing state '" << state->getId() << "'"
                         << std::endl;

        state->pause();
        state->markCleanup();

        mStack.pop_back();

        // Move this state to our dropped stack
        mDropped.push_back(state);
    } else mApp.getLogger() << "Trying to remove state from empty stack"
                            << std::endl;

    if(!mStack.empty()) {
        if(mStack.back()->isInitialized()) {
            // Resume the new active state
            mStack.back()->resume();
        } else {
            // Initialize the new active state
            mStack.back()->init();
        }
    } else {
        // There are no states on the stack, exit the program
        mApp.stopRunning(0);
    }
}

void StateManager::setActiveState(const std::string & id) {
    std::vector<State*>::iterator it;

    // Find the state with the given id
    for(it = mStack.begin(); it != mStack.end(); it++) {
        if((*it)->getId() == id) {
            // Get a pointer to soon to be active state
            State * state = *it;

            mApp.getLogger() << "Activating state '" << state->getId()
                             << std::endl;

            // Erase it from the list of previously active states
            mStack.erase(it);

            if(!mStack.empty()) {
                // Pause the currently running state since we are changing the
                // currently active state to the one specified
                mStack.back()->pause();
            }

            // Add the new active state
            mStack.push_back(state);

            if(mStack.back()->isInitialized()) {
                // Resume the new active state
                mStack.back()->resume();
            } else {
                // Initialize the new active state
                mStack.back()->init();
            }
            break;
        }
    }
}

void StateManager::cleanup() {
    // Remove one of our Dropped states for every state added
    if(!mDropped.empty()) {
        State * state = mDropped.back();
        mDropped.pop_back();

        if(state->isInitialized()) state->markCleanup();
        state->startCleanup();
        delete state;
    }
}
