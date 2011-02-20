//      Button.hpp -- A button widget.
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

#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Widget.hpp"

namespace Aftermath { namespace Engine {

    /**
     * A button with or without text that handles press events with a
     * callback function.
     */
    class Button : public Widget {
        public:
            /**
             * Constructs a new button with the given images.
             *
             * @param upImage - The sprite displayed when the button is up.
             * @param overImage - The sprite displayed when the mouse is over
             * the button.
             * @param downImage - The sprite displayed when the button is
             * pressed down.
             * @param text - The text for this button to display. Leave NULL
             * for no text.
             * @param x - The initial x position of this button.
             * @param y - The initial y position of this button.
             * @param callback - The callback function to call on press.
             * @param width - The initial width of this buton. If negative,
             * the width will be set to the width of upImage.
             * @param height - The initial height of this button. If negative,
             * the height will be set to the height of upImage.
             * @param fitText - Whether or not to fit the given text to this
             * button.
             * @param fitToText - Whether or not to fit this button to its
             * text.
             */
            Button(sf::Sprite * upImage,
                    sf::Sprite * overImage,
                    sf::Sprite * downImage,
                    sf::Text * text = NULL,
                    int x = 0, int y = 0,
                    int width = -1, int height = -1,
                    void (*callback)(Widget *) = NULL,
                    bool fitText = true, bool fitToText = false);

            /**
             * Virtual destructor for Button. Frees text and images.
             */
            virtual ~Button();

            /**
             * Fits this button to the text it is displaying, if any.
             *
             * @param textOffset - The empty space around the text, in pixels.
             */
            void fitToText(int textOffset = 5);

            /**
             * Fits the text of this button, if any, to this button.
             *
             * @param textOffset - The empty space around the text, in pixels.
             */
            void fitText(int textOffset = 5);

            /**
             * Registers the given function to be called when this button is
             * clicked.
             *
             * @param callback - A pointer to the callback function. The
             * function receives this button as its only argument.
             */
            void setCallback(void (*callback)(Widget *));

            /**
             * Calls the callback function registered with setCallback().
             *
             * @param button - The mouse button that was released.
             * @param x - The x position of the mouse, relative to the left
             * edge of this button.
             * @param y - The y position of the mouse, relative to the top
             * edge of this button.
             */
            void mouseButtonReleased(sf::Mouse::Button button, int x, int y);

            /**
             * Draws this button to the given RenderWindow.
             *
             * @param window - The window to draw to.
             */
            virtual void draw(sf::RenderWindow & window);

        private:
            sf::Text   * mText;
            sf::Sprite * mUp;
            sf::Sprite * mOver;
            sf::Sprite * mDown;
            void  (*mCallback)(Widget *);
    };

} }

#endif // BUTTON_HPP_INCLUDED
