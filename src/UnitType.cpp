//      UnitType.cpp -- A type of unit.
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

#include "Player.hpp"
#include "TileGroup.hpp"
#include "TileGroupUnit.hpp"
#include "UnitLevel.hpp"
#include "UnitType.hpp"

using namespace Aftermath;

UnitType::UnitType(const std::string & name, const std::string & description,
    bool isLand, bool isSea, const std::string & image, const std::vector
    <const UnitLevel *> * levels) : NamedType(name, description, image),
    mLand(isLand), mSea(isSea), mLevels(levels) {}

UnitType::~UnitType() {
    std::vector<const UnitLevel *>::const_iterator itr;
    for (itr = mLevels->begin(); itr != mLevels->end(); ++itr)
        delete *itr;
    delete mLevels;
}

bool UnitType::isLandUnit() const {
    return mLand;
}

bool UnitType::isSeaUnit() const {
    return mSea;
}

const std::vector<const UnitLevel *> & UnitType::getLevels() const {
    return *mLevels;
}

int UnitType::getStartingLevel(const Player & player) const {
    std::vector<const UnitLevel *>::const_iterator itr;
    for (itr = mLevels->begin(); itr != mLevels->end() &&
                                player.canTake((*itr)->getAutoCost()); ++itr);
    return itr - mLevels->begin();
}

void UnitType::giveTo(Player & player, int amount) const {
    while (amount-- > 0) {
        TileGroupUnit * unit = new TileGroupUnit(this, player);
        int level = getStartingLevel(player);
        while (level-- > 0) unit->finishUpgrade();
        if (isLandUnit()) player.getCapital()->getUnits().add(unit);
        else if (isSeaUnit()) player.getHarbor()->getUnits().add(unit);
        else delete unit;
    }
}

bool UnitType::canGiveTo(const Player & player, int amount) const {
    return amount >= 0;
}

void UnitType::takeFrom(Player & player, int amount) const {}

bool UnitType::canTakeFrom(const Player & player, int amount) const {
    return true;
}
