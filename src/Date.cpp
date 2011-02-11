//      Date.cpp -- A historical date type.
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

#include "Date.hpp"
#include "Game.hpp"
#include "Player.hpp"

using namespace Aftermath;

Date::Date(const std::string & name, const std::string & description, const
    Image & image) : NamedType(name, description, image) {}

void Date::giveTo(Player & player, int amount) const {}

bool Date::canGiveTo(const Player & player, int amount) const {
    return false;
}

void Date::takeFrom(Player & player, int amount) const {}

bool Date::canTakeFrom(const Player & player, int date) const {
    return player.getGame().getDate() >= date;
}
