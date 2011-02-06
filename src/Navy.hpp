//      Navy.hpp -- A navy of sea units.
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

#ifndef NAVY_HPP_INCLUDED
#define NAVY_HPP_INCLUDED

#include "SelectiveCollection.hpp"

namespace Aftermath { class TileGroupUnit; }

/**
 * @file Navy.hpp
 *
 * A navy of sea units.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * A Navy is a number of TileGroupUnits that travel on water.
     */
    class Navy : public SelectiveCollection<TileGroupUnit *> {
        public:
            /**
             * Destructor for Navy. Frees all units.
             */
            ~Navy();

            /**
             * Gets whether this Navy can support adding the given unit.
             *
             * @return true if UnitType::isSeaUnit() returns true,
             * false otherwise.
             */
            bool canAdd(const TileGroupUnit *& unit) const;
    };

}

#endif // NAVY_HPP_INCLUDED
