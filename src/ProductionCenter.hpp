//      ProductionCenter.hpp -- A center of production.
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

#ifndef PRODUCTIONCENTER_HPP_INCLUDED
#define PRODUCTIONCENTER_HPP_INCLUDED

namespace Aftermath { class ProductionCenter; }

#include "Count.hpp"
#include "Player.hpp"
#include "ProductionCenterType.hpp"
#include "ProductionFormula.hpp"
#include "ProductionLevel.hpp"
#include "Upgradable.hpp"

/**
 * @file ProductionCenter.hpp
 *
 * A center of production.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * ProductionCenters are upgradable centers of production. They convert
     * inputs to outputs with ProductionFormulas.
     */
    class ProductionCenter : public Upgradable<ProductionLevel> {
        public:
            /**
             * Constructs a new ProductionCenter of the given type.
             *
             * @param type - The type of ProductionCenter to construct.
             */
            ProductionCenter(const ProductionCenterType * type);

            /**
             * @return The type of this ProductionCenter.
             */
            const ProductionCenterType & getType() const;

            /**
             * Gets the number of times the given formula is being produced.
             *
             * @param formula - The formula to count.
             *
             * @return The number of the given formula that is currently in
             * production.
             */
            int getProducing(const ProductionFormula * formula) const;

            /**
             * Returns whether or not this production center can produce the
             * given formula and the player can pay for it.
             *
             * @param player - The player to start production.
             * @param formula - The formula to produce.
             *
             * @return true if the player can legally start production of the
             * given formula; false otherwise.
             */
            bool canProduce(const Player & player, const ProductionFormula *
                formula) const;

            /**
             * Starts the production of the given formula at this center. This
             * deducts the required resources from the given player.
             *
             * @param player - The player to start production.
             * @param formula - The formula to start production of.
             */
            void startProduction(Player & player, const ProductionFormula *
                formula);

            /**
             * Cancels production of the given formula at this center. This
             * refunds the required resources to the given player.
             *
             * @param player - The player to refund.
             * @param formula - The formula to cancel production of.
             */
            void cancelProduction(Player & player, const ProductionFormula *
                formula);

            /**
             * Finishes all production at this center. The given player will
             * be given all of the manufactured products.
             */
            void finishProduction(Player & player);

        private:
            const ProductionCenterType * mType;
            Count<const ProductionFormula *> mProducing;
    };

}

#endif // PRODUCTIONCENTER_HPP_INCLUDED
