//      Treaty.cpp -- The diplomatic relationship between two players.
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

#include "Treaty.hpp"

using namespace Aftermath;

Treaty::Treaty() : mMission(PEACE), mGrant(0), mSubsidy(0), mBoycott(false),
                   mRelationship(40) {}

enum Mission Treaty::getMission() const {
    return mMission;
}

void Treaty::setMission(enum Mission mission) {
    mMission = mission;
}

int Treaty::getGrant() const {
    return mGrant;
}

void Treaty::setGrant(int grant) {
    mGrant = grant;
}

int Treaty::getSubsidy() const {
    return mSubsidy;
}

void Treaty::setSubsidy(int subsidy) {
    mSubsidy = subsidy;
}

bool Treaty::getBoycott() const {
    return mBoycott;
}

void Treaty::setBoycott(bool boycott) {
    mBoycott = boycott;
}

int Treaty::getRelationship() const {
    return mRelationship;
}

void Treaty::setRelationship(int relationship) {
    mRelationship = relationship;
}
