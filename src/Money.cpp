//      Money.cpp -- Money used for purchasing products.
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

#include "Money.hpp"
#include "Player.hpp"

using namespace Aftermath;

Money::Money(const std::string & name, const std::string & description,
    const std::string & image) : NamedType(name, description, image) {}

void Money::giveTo(Player & player, int amount) const {
    player.giveMoney(amount);
}

bool Money::canGiveTo(const Player & player, int amount) const {
    return amount >= 0;
}

void Money::takeFrom(Player & player, int amount) const {
    player.takeMoney(amount);
}

bool Money::canTakeFrom(const Player & player, int amount) const {
    return player.getMoney() >= amount && amount >= 0;
}
