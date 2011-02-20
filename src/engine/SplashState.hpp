//      SplashState.hpp -- A splash screen.
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

#ifndef SPLASHSTATE_HPP_INCLUDED
#define SPLASHSTATE_HPP_INCLUDED

#include <SFML/Graphics/Sprite.hpp>

#include "State.hpp"

namespace Aftermath { namespace Engine { class App; } }

/**
 * @file SplashState.hpp
 *
 * The initial splash screen.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath { namespace Engine {

    /**
     * The SplashState shows a splash screen.
     */
    class SplashState : public State {
        public:
            /**
             * Constructs a new SplashState with the given App.
             *
             * @param id - The id of the new state.
             * @param time - The duration of the splash screen, in seconds.
             * @param image - The path of the image to show.
             * @param app - The App of the new state.
             */
            SplashState(const std::string & id, float time, const std::string
                & image, App & app);

            /**
             * MenuState deconstructor
             */
            ~SplashState();

            /**
             * Initializes this State
             */
            void init();

            /**
             * Handles the given event.
             *
             * @param event - The SFML event to handle.
             */
            void handleEvent(sf::Event & event);

            /**
             * Updates this State when it is active.
             */
            void update();

            /**
             * Draws this State when it is active.
             */
            void draw();

        protected:
            /**
             * Cleans up this State before it is removed.
             */
            void cleanup();

        private:
            float mTime;
            std::string mImage;
            sf::Sprite * mSplashSprite;
    };

} }

#endif // SPLASHSTATE_HPP_INCLUDED
