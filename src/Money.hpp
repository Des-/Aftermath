//      Money.hpp -- Money used for purchasing products.
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

#ifndef MONEY_HPP_INCLUDED
#define MONEY_HPP_INCLUDED

#include <string>

#include "NamedType.hpp"
#include "Transferable.hpp"

/**
 * @file Money.hpp
 *
 * Money used for purchasing products.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * Money is used to purchase goods, technology, and upgrades. There should
     * only be one Money type per mod pack.
     */
    class Money : public NamedType, public Transferable {
        public:
            /**
             * Constructs a new Money with the given name, description,
             * and image.
             *
             * @param name - The name of the new money type.
             * @param description - A description of the new money type.
             * @param image - The image of the new money type.
             */
            Money(const std::string & name, const std::string & description,
                const std::string & image);

            /**
             * Gives the specified amount of money to the given player.
             *
             * @param player - The player to give to.
             * @param amount - The amount to give.
             */
            void giveTo(Player & player, int amount = 0) const;

            /**
             * Checks if the given player can receive the given amount of
             * money. This should return true.
             *
             * @param player - The player to give to.
             * @param amount - The amount to give.
             *
             * @return true if amount is non-negative; false otherwise.
             */
            bool canGiveTo(const Player & player, int amount = 0) const;

            /**
             * Takes the given amount of money from the specified player.
             *
             * @param player - The player to take from.
             * @param amount - The amount to take.
             */
            void takeFrom(Player & player, int amount = 0) const;

            /**
             * Checks if the given player has enough money.
             *
             * @param player - The player to check.
             * @param amount - The amount to check for.
             *
             * @return true if the given player's money >= amount >= 0; false
             * otherwise.
             */
            bool canTakeFrom(const Player & player, int amount = 0) const;

    };

}

#endif // MONEY_HPP_INCLUDED

