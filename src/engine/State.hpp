//      State.hpp -- A game state.
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

#ifndef STATE_HPP_INCLUDED
#define STATE_HPP_INCLUDED

#include <string>

#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

namespace Aftermath { namespace Engine { class App; } }

/**
 * @file State.hpp
 *
 * A game state.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath { namespace Engine {

    /**
     * A State is a state of the game. These states are handled by a
     * StateManager and used by an App.
     */
    class State {
        public:
            /**
             * Constructs a new State with the given ID and App.
             * @param id - The ID to use for this State object
             * @param app - A reference to the App
             */
            State(const std::string & id, App & app);

            /**
             * Virtual State deconstructor.
             */
            virtual ~State();

            /**
             * @return The ID for this State object
             */
            const std::string & getId() const;

            /**
             * Initializes this State
             */
            virtual void init();

            /**
             * Marks this state for cleanup.
             */
            void markCleanup();

            /**
             * @return true if init() has been called without a call to
             * cleanup(); false otherwise.
             */
            bool isInitialized() const;

            /**
             * @return true if state is not the active state, false otherwise.
             */
            bool isPaused() const;

            /**
             * Pauses this State when the Application loses focus or another
             * State becomes activate.
             */
            virtual void pause();

            /**
             * Resumes this State when the Application gains focus or the
             * previous State is removed.
             */
            virtual void resume();

            /**
             * Handles the given event.
             *
             * @param event - The SFML event to handle.
             */
            virtual void handleEvent(sf::Event & event) = 0;

            /**
             * Updates this State when it is active.
             */
            virtual void update() = 0;

            /**
             * Draws this State when it is active.
             */
            virtual void draw() = 0;

            /**
             * Calls cleanup() if this class has been marked for cleanup.
             */
            void startCleanup();

            /**
             * getElapsedTime() will return one of the following:
             * 1) (If not paused) the total time since init was called
             * 2) (If paused) the total time since Pause was called
             * 3) (If uninitialized) the total time from init to markCleanup
             * @return total elapsed time as described above.
             */
            float getElapsedTime() const;

            /**
             * @return The app that this state belongs to.
             */
            App & getApp();

        protected:
            /** Reference to this state's App */
            App & mApp;

            /**
             * Cleans up this State before it is removed.
             */
            virtual void cleanup();

        private:
            std::string           mId;
            bool                  mInit;
            bool                  mPaused;
            bool                  mCleanup;
            sf::Clock             mElapsedClock;
            float                 mElapsedTime;
            sf::Clock             mPausedClock;
            float                 mPausedTime;
    };

} }

#endif // STATE_HPP_INCLUDED
