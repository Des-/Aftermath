//      Sea.cpp -- A sea of ocean tiles.
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

#include "Sea.hpp"
#include "Terrain.hpp"
#include "Tile.hpp"

using namespace Aftermath;

Sea::Sea(const std::string & name) : TileGroup(name) {}

bool Sea::isLand() const {
    return false;
}

bool Sea::isSea() const {
    return true;
}

Player * Sea::getOwner() {
    return NULL;
}

const Player * Sea::getOwner() const {
    return NULL;
}

void Sea::setOwner(Player * owner) {}

Tile * Sea::getCapital() {
    return NULL;
}

const Tile * Sea::getCapital() const {
    return NULL;
}

void Sea::setCapital(Tile * capital) {}

bool Sea::canAdd(const Tile *& tile) const {
    return tile->getTerrain()->isSeaTerrain();
}
