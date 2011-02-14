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
#include "Mod.hpp"
#include "Player.hpp"
#include "TileMap.hpp"

using namespace Aftermath;

Game::Game(TileMap * map, const Mod & mod) :
    mMap(map), mMod(mod) {}

Game::~Game() {
    delete mMap;
    iterator itr;
    for (itr = begin(); itr != end(); ++itr) delete *itr;
}

void Game::start(Player * player, int turn) {
    mTurn = turn;
    mPlayer = find(player);
    beginTurn();
    beginTurn(**mPlayer);
}

void Game::nextTurn() {
    endTurn(**mPlayer);
    ++mPlayer;
    if (mPlayer == end()) {
        ++mTurn;
        beginTurn();
        mPlayer = begin();
    }
    beginTurn(**mPlayer);
}

int Game::getTurn() const {
    return mTurn;
}

int Game::getDate() const {
    return mTurn * getMod().getDatePerTurn() + getMod().getStartDate();
}

const Mod & Game::getMod() const {
    return mMod;
}

// Begins a player's turn
void Game::beginTurn(Player & player) {
    // TODO
}

// Ends a player's turn
void Game::endTurn(Player & player) {
    // TODO
}

// Begins a game turn
void Game::beginTurn() {
    // TODO
}
