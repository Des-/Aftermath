//      Nation.cpp -- The nation that a player controls.
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

#include "Nation.hpp"

using namespace Aftermath;

Nation::Nation(const std::string & name, const std::string & description,
        const std::string & flag, unsigned char r, unsigned char g,
        unsigned char b, unsigned char a) :
    NamedType(name, description, flag), mR(r), mG(g), mB(b), mA(a) {}

unsigned char Nation::getRed() const {
    return mR;
}

unsigned char Nation::getGreen() const {
    return mG;
}

unsigned char Nation::getBlue() const {
    return mB;
}

unsigned char Nation::getAlpha() const {
    return mA;
}
