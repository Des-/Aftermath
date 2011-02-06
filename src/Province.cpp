//      Province.cpp -- A province of land tiles.
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

#include "Province.hpp"
#include "Terrain.hpp"
#include "Tile.hpp"
#include "TileGroupUnit.hpp"

using namespace Aftermath;

Province::Province(const std::string & name) : TileGroup(name) {}

bool Province::isLand() const {
    return true;
}

bool Province::isSea() const {
    return false;
}

Player * Province::getOwner() {
    return mOwner;
}

const Player * Province::getOwner() const {
    return mOwner;
}

void Province::setOwner(Player * owner) {
    mOwner = owner;
}

Tile * Province::getCapital() {
    return mCapital;
}

const Tile * Province::getCapital() const {
    return mCapital;
}

void Province::setCapital(Tile * capital) {
    mCapital = capital;
}

bool Province::canAdd(const Tile *& tile) const {
    return tile->getTerrain()->isLandTerrain();
}
