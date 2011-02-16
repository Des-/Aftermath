//      StateManager.hpp -- A manager for multiple states.
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

#ifndef STATEMANAGER_HPP_INCLUDED
#define STATEMANAGER_HPP_INCLUDED

namespace Aftermath { namespace Engine { class App;
                                         class State; } }

/**
 * @file StateManager.hpp
 *
 * A manager for multiple states.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath { namespace Engine {

    /**
     * A StateManager keeps track of multiple states by making sure they are
     * properly initialized and cleaned up.
     */
    class StateManager {
        public:
            /**
             * Constructs a new StateManager to manage the given App.
             *
             * @param app - The app for this manager to manage.
             */
            StateManager(App & app);

            /**
             * Virtual deconstructor for StateManager.
             */
            virtual ~StateManager();

            /**
             * @return true if state stack is empty; false otherwise.
             */
            bool isEmpty() const;

            /**
             * Adds the given state to this manager.
             *
             * @param state - The state to add.
             * @param active - If this is true, then the given state is added
             * to the top of the stack and becomes the active state. If this
             * is false, the state is added at the bottom of the stack.
             */
            void addState(State * state, bool active = true);

            /**
             * @return A pointer to the current active state. The active state
             * is the state that is on top of the stack.
             */
            State * getActiveState();

            /**
             * Causes the current active state to become an inactive state and
             * returns to the previous state on the stack.
             */
            void dropActiveState();

            /**
             * Causes the current active state to be removed and returns to
             * the previous state on the stack.  Once a state has been
             * removed, it must be re-added.  To just inactivate the current
             * active state, use dropActiveState instead.
             */
            void removeActiveState();

            /**
             * Finds the state specified by the given ID and makes it the
             * current active state. This makes the previously active state
             * the next state.
             *
             * @param id - The ID of the State to make active
             */
            void setActiveState(const std::string & id);

            /**
             * Deals with the cleanup of recently dropped states.
             */
            void cleanup();

        private:
            App              &   mApp;
            std::vector<State*>  mStack;
            std::vector<State*>  mDropped;
    };

} }

#endif // STATEMANAGER_HPP_INCLUDED
