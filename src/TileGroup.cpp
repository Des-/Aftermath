//      TileGroup.cpp -- A group of Tiles.
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

#include "Tile.hpp"
#include "TileGroup.hpp"
#include "TileGroupUnit.hpp"

using namespace Aftermath;

TileGroup::TileGroup(const std::string & name) : mName(name) {}

TileGroup::~TileGroup() {
    SelectiveCollection<TileGroupUnit *>::iterator itr;
    for (itr = getUnits().begin(); itr != getUnits().end(); ++itr)
        delete *itr;
}

const std::string & TileGroup::getName() const {
    return mName;
}

void TileGroup::setName(const std::string & name) {
    mName = name;
}

SelectiveCollection<TileGroupUnit *> & TileGroup::getUnits() {
    return *mUnits;
}

const SelectiveCollection<const TileGroupUnit *> & TileGroup::getUnits()
        const {
    return *((SelectiveCollection<const TileGroupUnit *> *) ((void*) mUnits));
}

void TileGroup::add(Tile *& tile) {
    SelectiveCollection<Tile *>::add(tile);
    tile->setTileGroup(this);
}
