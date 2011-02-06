//      WorkerType.cpp -- A type of laborer.
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
#include "WorkerType.hpp"

using namespace Aftermath;

WorkerType::WorkerType(const std::string & name, const std::string &
    description, const Image * image, int labor) :
        NamedType(name, description, image), mLabor(labor) {}

int WorkerType::getLabor() const {
    return mLabor;
}

void WorkerType::giveTo(Player & player, int amount) const {
    player.getIndustry().addWorkers(this, amount);
}

bool WorkerType::canGiveTo(const Player & player, int amount) const {
    return amount >= 0;
}

void WorkerType::takeFrom(Player & player, int amount) const {
    player.getIndustry().removeWorkers(this, amount);
}

bool WorkerType::canTakeFrom(const Player & player, int amount) const {
    return player.getIndustry().countWorkers(this) >= amount && amount >= 0;
}
