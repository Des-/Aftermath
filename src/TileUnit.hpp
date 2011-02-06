//      TileUnit.hpp -- A specialist that travels on Tiles.
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

#ifndef TILEUNIT_HPP_INCLUDED
#define TILEUNIT_HPP_INCLUDED

namespace Aftermath { class Player;
                      class SpecialistType; }

/**
 * @file TileUnit.hpp
 *
 * A specialist that travels on Tiles.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * A TileUnit is an instance of a SpecialistType that is owned by a
     * Player. They reside on a Tile and cannot stack.
     */
    class TileUnit {
        public:
            /**
             * Constructs a new TileUnit with the given owner and type.
             *
             * @param owner - The player to control this unit.
             * @param type - The type of this unit. This affects what tasks
             * the unit is able to perform.
             */
            TileUnit(Player & owner, const SpecialistType * type);

            /**
             * Gets the owner of this unit. The owner controls the movement
             * and actions of this TileUnit.
             *
             * @return The owner of this unit.
             */
            Player & getOwner();

            /**
             * Gets the const owner of this unit.
             *
             * @see getOwner()
             */
            const Player & getOwner() const;

            /**
             * Gets the type of this unit. This affects what actions this unit
             * is able to perform.
             *
             * @return The type of this unit.
             */
            const SpecialistType * getType() const;

        private:
            Player & mOwner;
            const SpecialistType * mType;
    };

}

#endif // TILEUNIT_HPP_INCLUDED
