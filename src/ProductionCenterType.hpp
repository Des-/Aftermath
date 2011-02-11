//      ProductionCenterType.hpp -- A type of a ProductionCenter.
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

#ifndef PRODUCTIONCENTERTYPE_HPP_INCLUDED
#define PRODUCTIONCENTERTYPE_HPP_INCLUDED

#include <string>
#include <vector>

#include "Collection.hpp"
#include "Graphics.hpp"
#include "NamedType.hpp"
#include "Transferable.hpp"

namespace Aftermath { class Player;
                      class ProductionFormula;
                      class ProductionLevel; }

/**
 * @file ProductionCenterType.hpp
 *
 * A type of ProductionCenter.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * A ProductionCenterType is a type of ProductionCenter. This holds
     * information such as the production center's name, description, image,
     * and levels.
     */
    class ProductionCenterType : public NamedType, public Transferable {
        public:
            /**
             * Constructs a new ProductionCenterType with the given set of
             * levels and formulas.
             *
             * @param name - The name of this type of production center.
             * @param description - A brief description of this type.
             * @param image - The image of this type of production center.
             * @param levels - The levels of this ProductionCenterType.
             * @param formulas - The formulas that this ProductionCenterType
             * can use.
             */
            ProductionCenterType(const std::string & name, const std::string &
                description, const Image & image, const std::vector<const
                ProductionLevel *> & levels, const Collection<const
                ProductionFormula *> & formulas);

            /**
             * Adds a type of this ProductionCenter to the given player.
             *
             * @param player - The player to give to.
             * @param amount - The amount to give.
             */
            void giveTo(Player & player, int amount = 0) const;

            /**
             * Checks if the given player can receive the given amount of
             * this production center type. This should return true.
             *
             * @param player - The player to give to.
             * @param amount - The amount to give.
             *
             * @return true if amount is non-negative; false otherwise.
             */
            bool canGiveTo(const Player & player, int amount = 0) const;

            /**
             * Taking a ProductionCenter from a player is undefined, thus this
             * function does nothing.
             *
             * @param player - The player to take from.
             * @param amount - The amount to take.
             */
            void takeFrom(Player & player, int amount = 0) const;

            /**
             * Taking a ProductionCenter from a player does nothing.
             *
             * @param player - The player to check.
             * @param amount - The amount to check for.
             *
             * @return true.
             */
            bool canTakeFrom(const Player & player, int amount = 0) const;

            /**
             * @return The levels of this ProductionCenterType.
             */
            const std::vector<const ProductionLevel *> & getLevels() const;

            /**
             * @return The formulas that this ProductionCenterType can use.
             */
            const Collection<const ProductionFormula *> & getFormulas() const;

        private:
            const std::vector<const ProductionLevel *> & mLevels;
            const Collection<const ProductionFormula *> & mFormulas;
    };

}

#endif // PRODUCTIONCENTERTYPE_HPP_INCLUDED

