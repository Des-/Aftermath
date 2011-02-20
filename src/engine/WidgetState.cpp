//      WidgetState.cpp -- A game state with widgets.
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
#include "WidgetState.hpp"

using namespace Aftermath::Engine;

WidgetState::WidgetState(const std::string & id, App & app) :
        State(id, app) {}

WidgetState::~WidgetState() {}

void WidgetState::init() {
    State::init();
}

void WidgetState::handleEvent(sf::Event & event) {
    sf::Vector2f mousePos;
    // Correct for window zoom
    switch (event.Type) {
        case sf::Event::MouseMoved:
            mousePos = mApp.getWindow().ConvertCoords(
                    event.MouseMove.X, event.MouseMove.Y);
            event.MouseMove.X = mousePos.x;
            event.MouseMove.Y = mousePos.y;
            break;
        case sf::Event::MouseWheelMoved:
            mousePos = mApp.getWindow().ConvertCoords(
                    event.MouseWheel.X, event.MouseWheel.Y);
            event.MouseWheel.X = mousePos.x;
            event.MouseWheel.Y = mousePos.y;
            break;
        case sf::Event::MouseButtonPressed:
            mousePos = mApp.getWindow().ConvertCoords(
                    event.MouseButton.X, event.MouseButton.Y);
            event.MouseButton.X = mousePos.x;
            event.MouseButton.Y = mousePos.y;
            break;
        case sf::Event::MouseButtonReleased:
            mousePos = mApp.getWindow().ConvertCoords(
                    event.MouseButton.X, event.MouseButton.Y);
            event.MouseButton.X = mousePos.x;
            event.MouseButton.Y = mousePos.y;
            break;
        default: break;
    }
    iterator itr;
    for (itr = begin(); itr != end(); ++itr)
        (*itr)->handleEvent(event); // Pass events on to widgets
}

void WidgetState::update() {
    iterator itr;
    for (itr = begin(); itr != end(); ++itr)
        (*itr)->update(); // Update widgets
}

void WidgetState::draw() {
    iterator itr;
    for (itr = begin(); itr != end(); ++itr)
        (*itr)->draw(mApp.getWindow()); // Draw widgets
}

void WidgetState::cleanup() {
    iterator itr;
    for (itr = begin(); itr != end(); ++itr) delete *itr;
    clear();
    State::cleanup();
}

void WidgetState::add(Widget * widget) {
    widget->setState(this);
    Collection<Widget *>::add(widget);
}
