//      TileUnit.cpp -- A specialist that travels on Tiles.
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

#include "TileUnit.hpp"

using namespace Aftermath;

TileUnit::TileUnit(Player & owner, const SpecialistType * type) :
    mOwner(owner), mType(type) {}

Player & TileUnit::getOwner() {
    return mOwner;
}

const Player & TileUnit::getOwner() const {
    return mOwner;
}

const SpecialistType * TileUnit::getType() const {
    return mType;
}
