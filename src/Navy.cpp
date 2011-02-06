//      Navy.cpp -- A navy of sea units.
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

#include "Navy.hpp"
#include "TileGroupUnit.hpp"
#include "UnitType.hpp"

using namespace Aftermath;

Navy::~Navy() {
    iterator itr;
    for (itr = begin(); itr != end(); ++itr) delete *itr;
}

bool Navy::canAdd(const TileGroupUnit *& unit) const {
    return unit->getType().isSeaUnit();
}
