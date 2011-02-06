//      TileMap.cpp -- A two-dimensional map of tiles.
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
#include "TileMap.hpp"

using namespace Aftermath;

TileMap::TileMap(const std::string & name, unsigned rows, unsigned columns) :
    Array2D<Tile>(rows, columns), mName(name) {}

TileMap::~TileMap() {
    iterator itr;
    for (itr = begin(); itr != end(); ++itr) delete *itr;
}

const std::string & TileMap::getName() const {
    return mName;
}
