//      State.cpp -- A game state.
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

using namespace Aftermath::Engine;

State::State(const std::string & id, App & app) : mApp(app), mId(id),
        mInit(false), mPaused(false), mCleanup(false),
        mElapsedTime(0.0f), mPausedTime(0.0f) {
    mApp.getLogger() << "Constructed state '" << mId << "'" << std::endl;
}

State::~State() {}

const std::string & State::getId() const {
    return mId;
}

void State::init() {
    mApp.getLogger() << "Initalizing state '" << mId << "'" << std::endl;
    if(!mInit) {
        mInit = true;
        mPaused = false;
        mElapsedTime = 0.0f;
        mElapsedClock.Reset();
        mPausedTime = 0.0f;
        mPausedClock.Reset();
    }
}

void State::markCleanup() {
    mApp.getLogger() << "Marking state '" << mId << "' for cleanup"
                     << std::endl;
    if(mInit) {
        mCleanup = true;
        mInit = false;
        mElapsedTime += mElapsedClock.GetElapsedTime();
        if(mPaused)
            mPausedTime += mPausedClock.GetElapsedTime();
    }
}

bool State::isInitialized() const {
    return mInit;
}

bool State::isPaused() const {
    return mPaused;
}

void State::pause() {
    mApp.getLogger() << "Pausing state '" << mId << "'" << std::endl;
    if(!mPaused) {
        mPaused = true;
        mPausedClock.Reset();
    }
}

void State::resume() {
    mApp.getLogger() << "Resuming state '" << mId << "'" << std::endl;
    if(mPaused) {
        mPaused = false;
        mPausedTime += mPausedClock.GetElapsedTime();
    }
}

void State::startCleanup() {
    if (true == mCleanup) cleanup();
}

float State::getElapsedTime() const {
    float result = mElapsedClock.GetElapsedTime();
    if(!mInit) result = mElapsedTime;
    return result;
}

App & State::getApp() {
    return mApp;
}

void State::cleanup() {
    mApp.getLogger() << "Cleaning up state '" << mId << "'" << std::endl;
}
