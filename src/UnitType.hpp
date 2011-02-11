//      UnitType.hpp -- A type of unit.
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

#ifndef UNITTYPE_HPP_INCLUDED
#define UNITTYPE_HPP_INCLUDED

#include <string>
#include <vector>

#include "Graphics.hpp"
#include "NamedType.hpp"
#include "Transferable.hpp"

namespace Aftermath { class Player;
                      class UnitLevel; }

/**
 * @file UnitType.hpp
 *
 * A type of unit.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * A UnitType is an immutable type of TileGroupUnit. They include the
     * name, description, strength, and image of the particular type of unit.
     */
    class UnitType : public NamedType, public Transferable {
        public:
            /**
             * Constructs a new UnitType with the given name, description,
             * levels, and image.
             *
             * @param name - The name of the new type.
             * @param description - The description of the new type.
             * @param isLand - Whether or not this type can travel on land.
             * @param isSea - Whether or not this type can travel on sea.
             * @param image - The image of the new type.
             * @param levels - The levels of the new type.
             */
            UnitType(const std::string & name,
                const std::string & description, bool isLand, bool isSea,
                const Image & image, const std::vector<const UnitLevel *>
                * levels);

            /**
             * Frees this UnitType and its levels.
             */
            ~UnitType();

            /**
             * Retrieves whether or not this unit can travel on land.
             *
             * @return true if this unit can travel on land, false otherwise.
             */
            bool isLandUnit() const;

            /**
             * Retrieves whether or not this unit can travel on water.
             *
             * @return true if this unit can travel on water, false otherwise.
             */
            bool isSeaUnit() const;

            /**
             * Gets this type's levels. A TileGroupUnit will have one of these
             * levels and can be upgraded for the right price.
             *
             * @return A vector of this type's levels.
             */
            const std::vector<const UnitLevel *> & getLevels() const;

            /**
             * Gets the level that this UnitType starts at for the given
             * player. This takes into account the player's technology.
             *
             * @param player - The player to check.
             *
             * @return The level that this UnitType starts at.
             */
            int getStartingLevel(const Player & player) const;

            /**
             * Constructs one TileGroupUnit of this type and gives it to the
             * given player. The unit appears at the given player's capital
             * province, or in its harbor if this is a naval type.
             *
             * @param player - The player to pay for and receive the unit.
             * @param amount - The amount of units to give the player.
             */
            void giveTo(Player & player, int amount = 0) const;

            /**
             * Checks if the given player can receive a TileGroupUnit of this
             * type. This should always return true, because there is nothing
             * preventing a player from receiving a unit.
             *
             * @param player - The player to give to.
             * @param amount - The amount to give.
             *
             * @return true if amount is non-negative; false otherwise.
             */
            bool canGiveTo(const Player & player, int amount = 0) const;

            /**
             * Taking a TileGroupUnit from a player is undefined and thus this
             * function does nothing.
             *
             * @param player - The player to take from.
             * @param amount - The amount to take.
             */
            void takeFrom(Player & player, int amount = 0) const;

            /**
             * Taking a TileGroupUnit from a player does nothing.
             *
             * @param player - The player to take from.
             * @param amount - The amount to take.
             *
             * @return true.
             */
            bool canTakeFrom(const Player & player, int amount = 0) const;

        private:
            bool mLand;
            bool mSea;
            const std::vector<const UnitLevel *> * mLevels;
    };

}

#endif // UNITTYPE_HPP_INCLUDED
