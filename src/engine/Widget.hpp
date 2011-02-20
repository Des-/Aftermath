//      Widget.hpp -- A widget to work with a WidgetState.
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

#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

#include <SFML/Graphics/RenderWindow.hpp>

namespace Aftermath { namespace Engine { class State; } }

/**
 * @file Widget.hpp
 *
 * A widget to work with a WidgetState.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath { namespace Engine {

    /**
     * A Widget is a graphical element of a WidgetState that handles it's own
     * events and drawing.
     */
    class Widget {
        public:
            /**
             * Constructs a new Widget at (0, 0) with dimensions 0x0.
             */
            Widget();

            /**
             * Virtual destructor for Widget.
             */
            virtual ~Widget();

            /**
             * @return The state that this widget belongs to, as specified by
             * setState().
             */
            State * getState();

            /**
             * Sets the state that this widget belongs to. This does not add
             * this widget to the given state; it is assumed that this widget
             * is already a part of the given state.
             *
             * @param state - The state of this widget.
             */
            void setState(State * state);

            /**
             * @return The x position of this Widget, relative to the left
             * edge of its RenderWindow.
             */
            float getX() const;

            /**
             * Sets the x position of this Widget.
             *
             * @param x - The new x position.
             */
            void setX(float x);

            /**
             * @return The y position of this Widget, relative to the left
             * edge of its RenderWindow.
             */
            float getY() const;

            /**
             * Sets the y position of this Widget.
             *
             * @param y - The new y position.
             */
            void setY(float y);

            /**
             * Sets the x and y position of this widget.
             *
             * @param x - The new x position.
             * @param y - The new y position.
             */
            void setPosition(float x, float y);

            /**
             * Moves this Widget by the given offset.
             *
             * @param dx - The amount in the x direction to move by. This can
             * be negative.
             * @param dy - The amount in the y direction to move by. This can
             * be negative.
             */
            void move(float dx, float dy);

            /**
             * @return The width of this Widget, as specified by setWidth().
             */
            float getWidth() const;

            /**
             * Sets the width of this widget.
             *
             * @param width - The new width.
             */
            void setWidth(float width);

            /**
             * @return The height of this Widget, as specified by setHeight().
             */
            float getHeight() const;

            /**
             * Sets the height of this widget.
             *
             * @param height - The new height.
             */
            void setHeight(float height);

            /**
             * Sets the width and height of this widget.
             *
             * @param width - The new width.
             * @param height - The new height.
             */
            void setSize(float width, float height);

            /**
             * Gets if this Widget contains the given point on its
             * RenderWindow.
             *
             * @param true if this widget contains the given point, false
             * otherwise.
             */
            virtual bool contains(float x, float y) const;

            /**
             * @return true if the mouse is hovering over this Widget; false
             * otherwise.
             */
            bool isMouseOver() const;

            /**
             * @return true if the mouse is currently pressing this Widget;
             * false otherwise.
             */
            bool isMousePressing() const;

            /**
             * @return true if this Widget was clicked last click; false
             * otherwise.
             */
            bool isMouseFocused() const;

            /**
             * Calls the appropriate virtual member function for this Widget
             * to handle the given event.
             *
             * @param event - The event to handle.
             */
            void handleEvent(sf::Event & event);

            /**
             * Called when the mouse is moved inside this Widget. Override to
             * provide functionality.
             *
             * @param x - The x position of the mouse, relative to the left
             * edge of this widget.
             * @param y - The y position of the mouse, relative to the top
             * edge of this widget.
             */
            virtual void mouseMoved(int x, int y) {}

            /**
             * Called when the mouse enters this Widget. Override to provide
             * functionality.
             *
             * @param x - The x position of the mouse, relative to the left
             * edge of this widget.
             * @param y - The y position of the mouse, relative to the top
             * edge of this widget.
             */
            virtual void mouseEntered(int x, int y) {}

            /**
             * Called when the mouse exits this Widget. Override to provide
             * functionality.
             *
             * @param x - The x position of the mouse, relative to the left
             * edge of this widget.
             * @param y - The y position of the mouse, relative to the top
             * edge of this widget.
             */
            virtual void mouseExited(int x, int y) {}

            /**
             * Called when the mouse wheel is moved inside this Widget.
             * Override to provide functionality.
             *
             * @param delta - The number of ticks the wheel has moved
             * (positive is up, negative is down).
             * @param x - The x position of the mouse, relative to the left
             * edge of this widget.
             * @param y - The y position of the mouse, relative to the top
             * edge of this widget.
             */
            virtual void mouseWheelMoved(int delta, int x, int y) {}

            /**
             * Called when a mouse button is pressed inside this Widget.
             * Override to provide functionality.
             *
             * @param button - The mouse button that was pressed.
             * @param x - The x position of the mouse, relative to the left
             * edge of this widget.
             * @param y - The y position of the mouse, relative to the top
             * edge of this widget.
             */
            virtual void mouseButtonPressed(sf::Mouse::Button button,
                    int x, int y) {}

            /**
             * Called when a mouse button is released inside this Widget.
             * Override to provide functionality.
             *
             * @param button - The mouse button that was released.
             * @param x - The x position of the mouse, relative to the left
             * edge of this widget.
             * @param y - The y position of the mouse, relative to the top
             * edge of this widget.
             */
            virtual void mouseButtonReleased(sf::Mouse::Button button,
                    int x, int y) {}

            /**
             * Called when a key is pressed. Override to provide
             * functionality.
             *
             * @param code - The code of the key that was pressed.
             * @param alt - Whether or not the alt key is pressed.
             * @param control - Whether or not the control key is pressed.
             * @param shift - Whether or not the shift key is pressed.
             */
            virtual void keyPressed(sf::Key::Code code, bool alt,
                    bool control, bool shift) {}

            /**
             * Called when a key is released. Override to provide
             * functionality.
             *
             * @param code - The code of the key that was released.
             * @param alt - Whether or not the alt key is pressed.
             * @param control - Whether or not the control key is pressed.
             * @param shift - Whether or not the shift key is pressed.
             */
            virtual void keyReleased(sf::Key::Code code, bool alt,
                    bool control, bool shift) {}

            /**
             * Called when text is entered. Override to provide functionality.
             *
             * @param unicode - The 32 bit unicode character that was entered.
             */
            virtual void textEntered(sf::Uint32 unicode) {}

            /**
             * Updates this Widget. Called every update loop. Override to
             * provide functionality.
             */
            virtual void update() {}

            /**
             * Draws this Widget. Override to provide functionality.
             *
             * @param window - The RenderWindow to draw to.
             */
            virtual void draw(sf::RenderWindow & window) {}

        private:
            float mX;
            float mY;
            float mWidth;
            float mHeight;
            bool mMouseOver;
            bool mMousePressing;
            bool mMouseFocused;
            State * mState;
    };

} }

#endif // WIDGET_HPP_INCLUDED
