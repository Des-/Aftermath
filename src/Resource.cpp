//      Resource.cpp -- A resource type.
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

#include "Count.hpp"
#include "Player.hpp"
#include "Resource.hpp"

using namespace Aftermath;

Resource::Resource(const std::string & name, const std::string & description,
    const std::string & image) : NamedType(name, description, image) {}

void Resource::giveTo(Player & player, int amount) const {
    player.getStockpile()[this] += amount;
}

bool Resource::canGiveTo(const Player & player, int amount) const {
    return amount >= 0;
}

void Resource::takeFrom(Player & player, int amount) const {
    player.getStockpile()[this] -= amount;
}

bool Resource::canTakeFrom(const Player & player, int amount) const {
    Count<const Resource *>::const_iterator itr;
    itr = player.getStockpile().find(this);
    return itr != player.getStockpile().end() && itr->second >= amount;
}
