//      Widget.cpp -- A widget to work with a WidgetState.
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

#include "Widget.hpp"

using namespace Aftermath::Engine;

Widget::Widget() : mX(0), mY(0), mWidth(0), mHeight(0), mMouseOver(false),
        mMousePressing(false), mMouseFocused(false), mState(NULL) {}

Widget::~Widget() {}

State * Widget::getState() {
    return mState;
}

void Widget::setState(State * state) {
    mState = state;
}

float Widget::getX() const {
    return mX;
}

void Widget::setX(float x) {
    mX = x;
}

float Widget::getY() const {
    return mY;
}

void Widget::setY(float y) {
    mY = y;
}

void Widget::setPosition(float x, float y) {
    setX(x);
    setY(y);
}

void Widget::move(float dx, float dy) {
    mX += dx;
    mY += dy;
}

float Widget::getWidth() const {
    return mWidth;
}

void Widget::setWidth(float width) {
    mWidth = width;
}

float Widget::getHeight() const {
    return mHeight;
}

void Widget::setHeight(float height) {
    mHeight = height;
}

void Widget::setSize(float width, float height) {
    setWidth(width);
    setHeight(height);
}

bool Widget::contains(float x, float y) const {
    return x >= mX && x - mX < mWidth && y >= mY && y - mY < mHeight;
}

bool Widget::isMouseOver() const {
    return mMouseOver;
}

bool Widget::isMousePressing() const {
    return mMousePressing;
}

bool Widget::isMouseFocused() const {
    return mMouseFocused;
}

void Widget::handleEvent(sf::Event & event) {
    switch (event.Type) {
        case sf::Event::MouseMoved:
            if (contains(event.MouseMove.X, event.MouseMove.Y)) {
                if (!mMouseOver) { // If entered
                    mMouseOver = true;
                    mouseEntered(event.MouseMove.X - mX,
                                 event.MouseMove.Y - mY);
                } else { // If on widget, but already entered
                    mouseMoved(event.MouseMove.X - mX,
                        event.MouseMove.Y - mY);
                }
            } else if (mMouseOver) { // If exited
                mMouseOver = false;
                mouseExited(event.MouseMove.X - mX,
                            event.MouseMove.Y - mY);
            }
            break;
        case sf::Event::MouseWheelMoved:
            if (mMouseOver)
                mouseWheelMoved(event.MouseWheel.Delta,
                        event.MouseWheel.X, event.MouseWheel.Y);
            break;
        case sf::Event::MouseButtonPressed:
            if ((mMousePressing = mMouseFocused = mMouseOver)) {
                mouseButtonPressed(event.MouseButton.Button,
                        event.MouseButton.X, event.MouseButton.Y);
            }
            break;
        case sf::Event::MouseButtonReleased:
            mMousePressing = false;
            if (mMouseOver)
                mouseButtonReleased(event.MouseButton.Button,
                        event.MouseButton.X, event.MouseButton.Y);
            break;
        case sf::Event::KeyPressed:
            keyPressed(event.Key.Code, event.Key.Alt,
                    event.Key.Control, event.Key.Shift);
            break;
        case sf::Event::KeyReleased:
            keyReleased(event.Key.Code ,event.Key.Alt,
                    event.Key.Control, event.Key.Shift);
            break;
        case sf::Event::TextEntered:
            textEntered(event.Text.Unicode);
            break;
        default: break;
    }
}
