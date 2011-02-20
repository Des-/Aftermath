//      MenuState.cpp -- The main menu screen.
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
#include "MenuState.hpp"

using namespace Aftermath::Engine;

MenuState::MenuState(App & app) : WidgetState(std::string("Menu"), app) {}

MenuState::~MenuState() {}

void MenuState::init() {
    State::init();

    add(new Button(mApp.getMod().newSprite("gui/menu_button_up.png"),
        mApp.getMod().newSprite("gui/menu_button_over.png"),
        mApp.getMod().newSprite("gui/menu_button_down.png"),
        mApp.getMod().newText("Play", "menu.ttf"),
        400, 300,
        100, 50,
        &MenuState::playClicked));

    add(new Button(mApp.getMod().newSprite("gui/menu_button_up.png"),
        mApp.getMod().newSprite("gui/menu_button_over.png"),
        mApp.getMod().newSprite("gui/menu_button_down.png"),
        mApp.getMod().newText("Exit", "menu.ttf"),
        400, 400,
        100, 50,
        &MenuState::exitClicked));

    // Load menu image
    mMenuSprite = mApp.getMod().newSprite("gui/main_menu.png");
}

void MenuState::handleEvent(sf::Event & event) {
    switch (event.Type) {
        case sf::Event::KeyPressed:
            switch (event.Key.Code) {
                case sf::Key::Escape:
                    mApp.stopRunning(0);
                    break;
                default: break;
            }
            break;
        default: break;
    }
    WidgetState::handleEvent(event);
}

void MenuState::draw() {
    mApp.getWindow().Clear();
    mApp.getWindow().Draw(*mMenuSprite);
    WidgetState::draw();
}

void MenuState::cleanup() {
    delete mMenuSprite;
    mMenuSprite = NULL;
    WidgetState::cleanup();
}
