//      ProductionCenterType.cpp -- A type of a ProductionCenter.
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

#include "Industry.hpp"
#include "Player.hpp"
#include "ProductionCenter.hpp"
#include "ProductionCenterType.hpp"

using namespace Aftermath;

ProductionCenterType::ProductionCenterType(const std::string & name,
    const std::string & description, const Image * image,
    const std::vector <const ProductionLevel *> & levels,
    const Collection<const ProductionFormula *> & formulas) :
        NamedType(name, description, image), mLevels(levels),
        mFormulas(formulas) {}

void ProductionCenterType::giveTo(Player & player, int amount) const {
    player.getIndustry().add(new ProductionCenter(this));
}

bool ProductionCenterType::canGiveTo(const Player & player, int amount)
        const {
    return amount >= 0;
}

void ProductionCenterType::takeFrom(Player & player, int amount) const {}

bool ProductionCenterType::canTakeFrom(const Player & player, int amount)
        const {
    return true;
}
