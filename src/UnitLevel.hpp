//      UnitLevel.hpp -- The level of a TileGroupUnit.
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

#ifndef UNITLEVEL_HPP_INCLUDED
#define UNITLEVEL_HPP_INCLUDED

#include <string>

#include "Count.hpp"
#include "Level.hpp"
#include "NamedType.hpp"

namespace Aftermath { class Transferable; }

/**
 * @file UnitLevel.hpp
 *
 * The level of a TileGroupUnit.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * A UnitLevel is the level of a TileGroupUnit. It has a cost that is
     * required for automatic upgrade at a ProductionCenter.
     */
    class UnitLevel : public NamedType, public Level {
        public:
            /**
             * Constructs a new UnitLevel with the given name,
             * description, and image. The level can be upgraded automatically
             * at a ProductionCenter for its auto upgrade cost.
             *
             * @param name - The name of the new level.
             * @param description - A brief description of the new level.
             * @param image - The image of the unit level.
             * @param upgradeCost - The cost to upgrade to this level.
             * @param autoUpgradeCost - The cost to automatically upgrade to
             * this level at a ProductionCenter (as the unit is built).
             * @param power - The power of this unit. This is used in combat.
             * @param cargo - The amount of cargo that this unit can carry.
             * This is added to the merchant marine of its owner.
             */
            UnitLevel(const std::string & name, const std::string &
                description, const std::string & image, const Count<const
                Transferable *> * upgradeCost, const Count<const Transferable
                *> * autoUpgradeCost, int power, int cargo);

            /**
             * Frees this level, its cost, and its auto cost.
             */
            ~UnitLevel();

            /**
             * Gets the cost that is required for a unit to upgrade to this
             * level automatially when built at a ProductionCenter. This
             * normally includes Technology objects, but not Resource objects.
             *
             * @return A Count of the types required to automatically upgrade.
             */
            const Count<const Transferable *> & getAutoCost() const;

            /**
             * Gets the power of this level. This is used to determine the
             * health and damage that this unit has and can inflict.
             *
             * @return The power of this level.
             */
            int getPower() const;

            /**
             * Gets the amount of merchant marine points added to the
             * controlling player of this unit.
             *
             * @return The cargo capacity of this unit.
             */
            int getCargo() const;

        private:
            const Count<const Transferable *> * mAutoCost;
            int mPower;
            int mCargo;
    };

}

#endif // UNITLEVEL_HPP_INCLUDED
