//      Game.cpp -- An Aftermath game.
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

#include "Game.hpp"
#include "GameSettings.hpp"
#include "Mod.hpp"
#include "Player.hpp"
#include "TileMap.hpp"

using namespace Aftermath;

class Mod;

Game::Game(TileMap * map, const GameSettings & settings, int turn) :
    mMap(map), mSettings(settings), mTurn(turn) {}

Game::~Game() {
    delete mMap;
    iterator itr;
    for (itr = begin(); itr != end(); ++itr) delete *itr;
}

void Game::playTurn() {
    // TODO
}

int Game::getTurn() const {
    return mTurn;
}

int Game::getDate() const {
    const Mod & mod = getSettings().getMod();
    return mTurn * mod.getDatePerTurn() + mod.getStartDate();
}

const GameSettings & Game::getSettings() const {
    return mSettings;
}
