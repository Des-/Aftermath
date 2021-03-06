//      TileGroupUnit.hpp -- A unit that resides in a TileGroup.
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

#ifndef TILEGROUPUNIT_HPP_INCLUDED
#define TILEGROUPUNIT_HPP_INCLUDED

#include "Upgradable.hpp"

namespace Aftermath { class Player;
                      class UnitLevel;
                      class UnitType; }

/**
 * @file TileGroupUnit.hpp
 *
 * A unit that resides in a TileGroup.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * A TileGroupUnit is a unit that travels across TileGroups. They are
     * primarily Army or Navy units.
     */
    class TileGroupUnit : public Upgradable<UnitLevel> {
        public:
            /**
             * Constructs a new TileGroupUnit of the given UnitType and adds
             * its merchant marine capacity to its owner.
             *
             * @param type - The unit type of this unit.
             * @param owner - The owner of this unit.
             */
            TileGroupUnit(const UnitType * type, Player & owner);

            /**
             * Frees this TileGroupUnit and removes its merchant marine
             * capacity from its owner.
             */
            ~TileGroupUnit();

            /**
             * Gets the UnitType of this unit.
             *
             * @return A reference to the type of this unit.
             */
            const UnitType & getType() const;

            /**
             * Gets the amount of damage that this unit can sustain. When
             * the unit has no more toughness, the unit is destroyed.
             *
             * @return The toughness of this unit, as an int.
             */
            int getToughness() const;

            /**
             * Sets the current toughness of this unit.
             *
             * @param toughness - The new toughness level.
             */
            void setToughness(int toughness);

            /**
             * Adds the given amount of toughness to this unit.
             *
             * @param toughness - The amount of toughness to add. This can be
             * negative.
             */
            void addToughness(int toughness);

            /**
             * @return The owner of this TileGroupUnit.
             */
            const Player & getOwner() const;

            /**
             * Upgrades to the next level and updates the owner's merchant
             * marine capacity.
             */
            void finishUpgrade();

        private:
            int mToughness;
            const UnitType * mType;
            Player & mOwner;
    };

}

#endif // TILEGROUPUNIT_HPP_INCLUDED
