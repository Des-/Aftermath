//      SplashState.cpp -- A splash screen.
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

#include "SplashState.hpp"

using namespace Aftermath::Engine;

SplashState::SplashState(const std::string & id, float time, const std::string
    & image, App & app) : State(id, app), mTime(time), mImage(image) {}

SplashState::~SplashState() {}

void SplashState::init() {
    State::init();
    mSplashSprite = mApp.getMod().newSprite(mImage);
}

void SplashState::handleEvent(sf::Event event) {}

void SplashState::update() {
    if(!isPaused() && getElapsedTime() > mTime)
        mApp.getStateManager().removeActiveState();
}

void SplashState::draw() {
    mApp.getWindow().Clear();
    mApp.getWindow().Draw(*mSplashSprite);
}

void SplashState::cleanup() {
    delete mSplashSprite;
    State::Cleanup();
}
