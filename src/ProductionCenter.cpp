//      ProductionCenter.cpp -- A center of production.
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
#include "ProductionCenter.hpp"
#include "ProductionCenterType.hpp"
#include "ProductionFormula.hpp"
#include "ProductionLevel.hpp"

using namespace Aftermath;

ProductionCenter::ProductionCenter(const ProductionCenterType * type) :
    Upgradable<ProductionLevel>(type->getLevels()), mType(type) {}

const ProductionCenterType & ProductionCenter::getType() const {
    return *mType;
}

int ProductionCenter::getProducing(const ProductionFormula * formula) const {
    Count<const ProductionFormula *>::const_iterator itr;
    itr = mProducing.find(formula);
    if (itr != mProducing.end()) return itr->second;
    else return 0;
}

bool ProductionCenter::canProduce(const Player & player, const
        ProductionFormula * formula) const {
    const Count<const Transferable *> & output = formula->getOutput();
    Count<const Transferable *>::const_iterator itr;
    int producing = getProducing(formula) + 1;
    for (itr = output.begin(); itr != output.end(); ++itr)
        if (itr->second * producing > getLevel().getMaxOutput())
            return false;
    return getType().getFormulas().contains(formula) &&
           player.canTake(formula->getInput()) &&
           player.canGive(formula->getOutput());
}

void ProductionCenter::startProduction(Player & player, const
        ProductionFormula * formula) {
    ++mProducing[formula];
    player.take(formula->getInput());
}

void ProductionCenter::cancelProduction(Player & player, const
        ProductionFormula * formula) {
    if (getProducing(formula) > 0) --mProducing[formula];
    player.give(formula->getInput());
}

void ProductionCenter::finishProduction(Player & player) {
    Count<const ProductionFormula *>::iterator itr;
    for (itr = mProducing.begin(); itr != mProducing.end(); ++itr) {
        int i;
        for (i = 0; i < itr->second; ++i) {
            if (getProducing(itr->first) > 0) --mProducing[itr->first];
            player.give(itr->first->getOutput());
        }
    }
}
