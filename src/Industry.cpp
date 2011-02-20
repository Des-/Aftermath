//      Industry.cpp -- A player's production capabilities.
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
#include "ProductionCenter.hpp"
#include "WorkerType.hpp"

using namespace Aftermath;

Industry::Industry() {}

Industry::~Industry() {
    iterator itr;
    for (itr = begin(); itr != end(); ++itr) delete *itr;
}

int Industry::countWorkers(const WorkerType * type) const {
    return mWorkers.getCount(type);
}

void Industry::addWorkers(const WorkerType * type, int amount) {
    mWorkers[type] += amount;
}

void Industry::removeWorkers(const WorkerType * type, int amount) {
    mWorkers[type] -= amount;
}

int Industry::getMaxLabor() const {
    int max = 0;
    Count<const WorkerType *>::const_iterator itr;
    for (itr = mWorkers.begin(); itr != mWorkers.end(); ++itr)
        max += itr->second * itr->first->getLabor();
    return max;
}

int Industry::getAllocatedLabor() const {
    return mAllocated;
}

int Industry::getFreeLabor() const {
    return getMaxLabor() - getAllocatedLabor();
}

void Industry::allocateLabor(int amount) {
    mAllocated += amount;
}
