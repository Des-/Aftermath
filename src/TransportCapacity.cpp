//      TransportCapacity.cpp -- The capacity of a transport network.
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
#include "TransportCapacity.hpp"
#include "TransportNetwork.hpp"

using namespace Aftermath;

TransportCapacity::TransportCapacity(const std::string & name, const
    std::string & description, const Image * image) :
        NamedType(name, description, image) {}

void TransportCapacity::giveTo(Player & player, int amount) const {
    player.getTransport().addCapacity(amount);
}

bool TransportCapacity::canGiveTo(const Player & player, int amount) const {
    return amount >= 0;
}

void TransportCapacity::takeFrom(Player & player, int amount) const {
    player.getTransport().addCapacity(-amount);
}

bool TransportCapacity::canTakeFrom(const Player & player, int amount) const {
    return player.getTransport().getCapacity() >= amount &&
           amount >= 0;
}
