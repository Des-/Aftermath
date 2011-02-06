//      TransportNetwork.hpp -- A player's network of resource transport.
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

#ifndef TRANSPORTNETWORK_HPP_INCLUDED
#define TRANSPORTNETWORK_HPP_INCLUDED

#include "Collection.hpp"
#include "Count.hpp"

namespace Aftermath { class Player;
                      class Resource; }

/**
 * @file TransportNetwork.hpp
 *
 * A player's network of resource transport.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * A TransportNetwork handles all of the resources connected to a player's
     * capital by their network of railroads and ports. It also handles the
     * merchant marine and actual turn-to-turn shipping of resources.
     */
    class TransportNetwork {
        public:
            /**
             * Gets the amount of the given resource type that is connected to
             * this transport network.
             *
             * @param resource - The type of resource to check.
             *
             * @return The available units of the given resource, as an int.
             */
            int getAvailable(const Resource * resource) const;

            /**
             * Adds the given resource to this TransportNetwork.
             *
             * @param resource - The type of resource to add.
             * @param amount - The amount to add.
             */
            void addAvailable(const Resource * resource, int amount);

            /**
             * Removes the given resource from this TransportNetwork.
             *
             * @param resource - The type of resource to remove.
             * @param amount - The amount to remove.
             */
            void removeAvailable(const Resource * resource, int amount);

            /**
             * Gets the amount of the given type of resource that is being
             * transported across this transport network.
             *
             * @param resource - The type of resource to check.
             *
             * @return The number of units of the given resource that is being
             * transported.
             */
            int getTransporting(const Resource * resource) const;

            /**
             * Starts to transport the given resource.
             *
             * @param resource - The type of resource to transport.
             * @param amount - The amount to transport.
             */
            void startTransporting(const Resource * resource, int amount);

            /**
             * Stops transporting one unit of the given resource.
             *
             * @param resource - The type of resource to stop transporting.
             * @param amount - The amount to stop transporting.
             */
            void stopTransporting(const Resource * resource, int amount);

            /**
             * Ships the resources in the transport queue to the given player.
             * This should be called at the start of every player's turn.
             *
             * @param player - The player to ship the resources to.
             */
            void finishTransporting(Player & player);

            /**
             * Gets the total units of resources that are being transported.
             * If this would go above getCapacity(), then transporting a new
             * item is illegal.
             *
             * @return The total units being transported this turn.
             */
            int getTotalTransporting() const;

            /**
             * Gets the amount of the resource type that is being traded
             * internationally.
             *
             * @param resource - The resource to check for.
             *
             * @return The units of the resource type that are being offered
             * for sale.
             */
            int getTrading(const Resource * resource) const;

            /**
             * Adds to the amount of the given resource type that is
             * being traded. Also takes from the given player.
             *
             * @param player - The player to sell the resource.
             * @param resource - The resource to sell.
             * @param amount - The amount to sell.
             */
            void startTrading(Player & player, const Resource * resource, int
                amount);

            /**
             * Subtracts from the amount of the given resource type
             * that is being traded. Also refunds the resources to the given
             * player.
             *
             * @param player - The player to refund.
             * @param resource - The resource to cancel selling.
             * @param amount - The amount to cancel selling.
             */
            void stopTrading(Player & player, const Resource * resource, int
                amount);

            /**
             * Gives the given player an amount of the given resource and
             * takes the resource off of the trading queue. This does NOT
             * pay the selling player, it only gives the resource to the
             * buyer.
             *
             * @param player - The player to sell to.
             * @param resource - The resource to sell.
             * @param amount - The amount to sell.
             */
            void finishTrade(Player & player, const Resource * resource, int
                amount);

            /**
             * @return The collection of resources that are being bid on.
             */
            const Collection<const Resource *> & getBidding() const;

            /**
             * Starts bidding on the given resource.
             *
             * @param resource - The resource to bid for.
             */
            void startBidding(const Resource * resource);

            /**
             * Stops bidding on the given resource.
             *
             * @param resource - The resource to stop bidding for.
             */
            void cancelBidding(const Resource * resource);

           /**
             * Gets the capacity of this TransportNetwork, in units. This
             * represents the maximum amount of resources that can be
             * transported in one turn.
             *
             * @return The capacity in units, as an int.
             */
            int getCapacity() const;

            /**
             * Adds to the total capacity of this TransportNetwork. This
             * changes the maximum amount of resources that can be transported
             * in one turn.
             *
             * @param capacity - The capacity to add.
             */
            void addCapacity(int capacity);

            /**
             * Gets the capacity of the merchant marine. This represents the
             * amount of any single resource type that can be traded
             * internationally.
             */
            int getMerchantMarine() const;

            /**
             * Adds to the merchant marine capacity. This changes the amount
             * of any single resource type that can be traded internationally.
             *
             * @param capacity - The capacity to add. This can be negative.
             */
            void addMerchantMarine(int capacity);

        private:
            Count<const Resource *> mTransporting;
            Count<const Resource *> mAvailable;
            Count<const Resource *> mTrading;
            Collection<const Resource *> mBidding;
            int mCapacity;
            int mMarine;
    };

}

#endif // TRANSPORTNETWORK_HPP_INCLUDED
