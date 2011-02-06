//      TileGroupUnit.cpp -- A unit that resides in a TileGroup.
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
#include "MerchantMarine.hpp"
#include "Mod.hpp"
#include "Player.hpp"
#include "TileGroupUnit.hpp"
#include "UnitLevel.hpp"
#include "UnitType.hpp"

using namespace Aftermath;

inline void addMerchantMarine(Player & p, int n) {
    Count<const Transferable *> mm;
    mm[p.getGame().getSettings().getMod().getMerchantMarine()] = n;
    p.give(mm);
}

TileGroupUnit::TileGroupUnit(const UnitType * type, Player & owner) :
        Upgradable(type->getLevels()),
        mToughness(getLevel().getPower()), mType(type), mOwner(owner) {
    addMerchantMarine(owner, getLevel().getCargo());
}

TileGroupUnit::~TileGroupUnit() {
    addMerchantMarine(mOwner, -getLevel().getCargo());
}

const UnitType & TileGroupUnit::getType() const {
    return *mType;
}

int TileGroupUnit::getToughness() const {
    return mToughness;
}

void TileGroupUnit::setToughness(int toughness) {
    mToughness = toughness;
}

void TileGroupUnit::addToughness(int toughness) {
    mToughness += toughness;
}

const Player & TileGroupUnit::getOwner() const {
    return mOwner;
}

void TileGroupUnit::finishUpgrade() {
    addMerchantMarine(mOwner, -getLevel().getCargo());
    addMerchantMarine(mOwner, getNextLevel().getCargo());
    Upgradable<UnitLevel>::finishUpgrade();
}
