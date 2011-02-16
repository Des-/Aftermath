//      MenuState.hpp -- The main menu screen.
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

#ifndef MENUSTATE_HPP_INCLUDED
#define MENUSTATE_HPP_INCLUDED

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "State.hpp"

namespace Aftermath { namespace Engine { class App; } }

/**
 * @file MenuState.hpp
 *
 * The main menu screen.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath { namespace Engine {

    /**
     * The menu state shows the main menu screen.
     */
    class MenuState : public State {
        public:
            /**
             * Constructs a new MenuState with the given App.
             *
             * @param app - The App of the new state.
             */
            MenuState(App & app);

            /**
             * MenuState deconstructor
             */
            ~MenuState();

            /**
             * Initializes this State
             */
            void init();

            /**
             * Handles the given event.
             *
             * @param event - The SFML event to handle.
             */
            void handleEvent(sf::Event event);

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
            sf::Sprite * mMenuSprite;
            sf::Text   * mMenuText1;
            sf::Text   * mMenuText2;
    };

} }

#endif // MENUSTATE_HPP_INCLUDED
