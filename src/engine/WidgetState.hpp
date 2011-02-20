//      WidgetState.hpp -- A game state with widgets.
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

#ifndef WIDGETSTATE_HPP_INCLUDED
#define WIDGETSTATE_HPP_INCLUDED

#include <vector>

#include "../Collection.hpp"
#include "State.hpp"
#include "Widget.hpp"

/**
 * @file WidgetState.hpp
 *
 * A game state with widgets.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath { namespace Engine {

    /**
     * A WidgetState is a State which handles its own Widgets.
     */
    class WidgetState : public State, public Collection<Widget *> {
        public:
            /**
             * Constructs a new WidgetState with the given App and no widgets.
             *
             * @param id - The id of the new state.
             * @param app - The App of the new state.
             */
            WidgetState(const std::string & id, App & app);

            /**
             * Virtual WidgetState deconstructor.
             */
            virtual ~WidgetState();

            /**
             * Initializes this State.
             */
            virtual void init();

            /**
             * Handles the given event.
             *
             * @param event - The SFML event to handle.
             */
            virtual void handleEvent(sf::Event & event);

            /**
             * Updates this State when it is active.
             */
            virtual void update();

            /**
             * Draws this State when it is active.
             */
            virtual void draw();

            /**
             * Adds the given widget to this state.
             *
             * @param widget - The widget to add.
             */
            void add(Widget * widget);

        protected:
            /**
             * Cleans up this State before it is removed.
             */
            virtual void cleanup();
    };

} }

#endif // WIDGETSTATE_HPP_INCLUDED
