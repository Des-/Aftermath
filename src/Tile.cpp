//      Tile.cpp -- A map tile.
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

#include "Random.hpp"
#include "Terrain.hpp"
#include "Tile.hpp"
#include "TileUnit.hpp"

using namespace Aftermath;

Tile::Tile(const Terrain * terrain, bool genResources) :
        mTileGroup(NULL), mTileUnit(NULL), mYield(1) {
    setTerrain(terrain, genResources);
}

Tile::~Tile() {
    delete mTileUnit;
}

TileGroup * Tile::getTileGroup() {
    return mTileGroup;
}

const TileGroup * Tile::getTileGroup() const {
    return mTileGroup;
}

void Tile::setTileGroup(TileGroup * group) {
    mTileGroup = group;
}

const Terrain * Tile::getTerrain() const {
    return mTerrain;
}

void Tile::setTerrain(const Terrain * terrain, bool genResources) {
    mTerrain = terrain;
    if (genResources) {
        Terrain::iterator itr;
        for (itr = terrain->begin(); itr != terrain->end(); ++itr)
            if (Random::Double() <= itr->second) add(itr->first);
    }
}

TileUnit * Tile::getTileUnit() {
    return mTileUnit;
}

const TileUnit * Tile::getTileUnit() const {
    return mTileUnit;
}

void Tile::setTileUnit(TileUnit * unit) {
    mTileUnit = unit;
}

bool Tile::canAdd(const Resource *& resource) const {
    return getTerrain()->getProbability(resource) > 0.0;
}

int Tile::getYield() const {
    return mYield;
}

void Tile::setYield(int yield) {
    mYield = yield;
}

void Tile::addYield(int yield) {
    mYield += yield;
}
