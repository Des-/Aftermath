//      Army.hpp -- An army of land units.
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

#ifndef ARMY_HPP_INCLUDED
#define ARMY_HPP_INCLUDED

#include "SelectiveCollection.hpp"
#include "TileGroupUnit.hpp"

/**
 * @file Army.hpp
 *
 * An army of land units.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * An Army is a number of TileGroupUnits that travel on land.
     */
    class Army : public SelectiveCollection<TileGroupUnit *> {
        public:
            /**
             * Destructor for Army. Frees all units.
             */
            ~Army();

            /**
             * Gets whether this Army can support adding the given unit.
             *
             * @return true if UnitType::isLandUnit() returns true,
             * false otherwise.
             */
            bool canAdd(const TileGroupUnit *& unit) const;
    };

}

#endif // ARMY_HPP_INCLUDED
