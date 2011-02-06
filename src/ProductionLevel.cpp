//      ProductionLevel.cpp -- The level of a ProductionCenter.
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

#include "ProductionLevel.hpp"

using namespace Aftermath;

ProductionLevel::ProductionLevel(const std::string & name, const std::string &
    description, const Image * image, const Count<const Transferable *> *
    cost, int maxOutput) : NamedType(name, description, image), Level(cost),
        mMaxOutput(maxOutput) {}

int ProductionLevel::getMaxOutput() const {
    return mMaxOutput;
}
