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

#include "MenuState.hpp"

using namespace Aftermath::Engine;

MenuState::MenuState(App & app) : State(std::string("Menu"), app) {}

MenuState::~MenuState() {}

void MenuState::init() {
    State::init();

    mMenuText1 = mApp.getMod().newText("Play Game", "menu.ttf");
    mMenuText2 = mApp.getMod().newText("Exit", "menu.ttf");

    // Position the string
    mMenuText1->SetColor(sf::Color(255,255,255));
    mMenuText1->Move(400.f, 300.f);

    mMenuText2->SetColor(sf::Color(255,255,255));
    mMenuText2->Move(400.f, 400.f);

    // Load menu image
    mMenuSprite = mApp.getMod().newSprite("gui/main_menu.png");
}

void MenuState::handleEvent(sf::Event event) {
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
}

void MenuState::update() {}

void MenuState::draw() {
    mApp.getWindow().Clear();
    mApp.getWindow().Draw(*mMenuSprite);
    mApp.getWindow().Draw(*mMenuText1);
    mApp.getWindow().Draw(*mMenuText2);
}

void MenuState::cleanup() {
    delete mMenuSprite;
    mMenuSprite = NULL;
    delete mMenuText1;
    mMenuText1 = NULL;
    delete mMenuText2;
    mMenuText2 = NULL;
    State::Cleanup();
}
