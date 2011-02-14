//      MerchantMarine.hpp -- The capacity of international trade.
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

#ifndef MERCHANTMARINE_HPP_INCLUDED
#define MERCHANTMARINE_HPP_INCLUDED

#include <string>

#include "NamedType.hpp"
#include "Transferable.hpp"

/**
 * @file MerchantMarine.hpp
 *
 * The capacity of international trade.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * MerchantMarine is the max amount of any one product type to be traded
     * internationally per turn.
     */
    class MerchantMarine : public NamedType, public Transferable {
        public:
            /**
             * Constructs a new MerchantMarine with the given name,
             * description, and image.
             *
             * @param name - The name of the new type.
             * @param description - A description of the new type.
             * @param image - The image of the new type.
             */
            MerchantMarine(const std::string & name, const std::string &
                description, const std::string & image);

            /**
             * Gives the specified amount of merchant marine to the given
             * player.
             *
             * @param player - The player to give to.
             * @param amount - The amount to give.
             */
            void giveTo(Player & player, int amount = 0) const;

            /**
             * Checks if the given player can receive the given amount of
             * merchant marine. This should return true.
             *
             * @param player - The player to give to.
             * @param amount - The amount to give.
             *
             * @return true if amount is non-negative; false otherwise.
             */
            bool canGiveTo(const Player & player, int amount = 0) const;

            /**
             * Takes the given amount of merchant marine from the specified
             * player.
             *
             * @param player - The player to take from.
             * @param amount - The amount to take.
             */
            void takeFrom(Player & player, int amount = 0) const;

            /**
             * Checks if the given player has enough merchant marine.
             *
             * @param player - The player to check.
             * @param amount - The amount to check for.
             *
             * @return true if the given player's merchant marine >= amount
             * >= 0; false otherwise.
             */
            bool canTakeFrom(const Player & player, int amount = 0) const;
    };

}

#endif // MERCHANTMARINE_HPP_INCLUDED



