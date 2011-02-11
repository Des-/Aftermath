//      TransportCapacity.hpp -- The capacity of a transport network.
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

#ifndef TRANSPORTCAPACITY_HPP_INCLUDED
#define TRANSPORTCAPACITY_HPP_INCLUDED

#include <string>

#include "Graphics.hpp"
#include "NamedType.hpp"
#include "Transferable.hpp"

namespace Aftermath { class Player; }

/**
 * @file TransportCapacity.hpp
 *
 * The capacity of a transport network.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * TransportCapacity is the capacity of a TransportNetwork to transport
     * goods.
     */
    class TransportCapacity : public NamedType, public Transferable {
        public:
            /**
             * Constructs a new TransportCapacity with the given name,
             * description, and image.
             *
             * @param name - The name of the new type.
             * @param description - A description of the new type.
             * @param image - The image of the new type.
             */
            TransportCapacity(const std::string & name, const std::string &
                description, const Image & image);

            /**
             * Gives the specified amount of transport capacity to the given
             * player.
             *
             * @param player - The player to give to.
             * @param amount - The amount to give.
             */
            void giveTo(Player & player, int amount = 0) const;

            /**
             * Checks if the given player can receive the given amount of
             * transport capacity. This should return true.
             *
             * @param player - The player to give to.
             * @param amount - The amount to give.
             *
             * @return true if amount is non-negative; false otherwise.
             */
            bool canGiveTo(const Player & player, int amount = 0) const;

            /**
             * Takes the given amount of transport capacity from the specified
             * player.
             *
             * @param player - The player to take from.
             * @param amount - The amount to take.
             */
            void takeFrom(Player & player, int amount = 0) const;

            /**
             * Checks if the given player has enough transport capacity.
             *
             * @param player - The player to check.
             * @param amount - The amount to check for.
             *
             * @return true if the given player's transport capacity >= amount
             * >= 0; false otherwise.
             */
            bool canTakeFrom(const Player & player, int amount = 0) const;
    };

}

#endif // TRANSPORTCAPACITY_HPP_INCLUDED


