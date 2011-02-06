//      Transferable.hpp -- A type that can be given and taken from a player.
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

#ifndef TRANSFERABLE_HPP_INCLUDED
#define TRANSFERABLE_HPP_INCLUDED

namespace Aftermath { class Player; }

/**
 * @file Transferable.hpp
 *
 * A type that can be given and taken from a player.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * Transferable is an interface for something that can be given to or
     * taken from a player or is conditionally able to prevent or enable
     * production. This includes resources, technologies, and dates.
     */
    class Transferable {
        public:
            /**
             * Gives an amount of this type to the given player. This can mean
             * anything from adding a Resource to the player's stockpile to
             * adding a TileGroupUnit to the player's capital.
             *
             * @param player - The player to give this type to.
             * @param amount - The amount to add.
             */
            virtual void giveTo(Player & player, int amount = 0) const = 0;

            /**
             * Checks if this type can be successfully given to the specified
             * player. This could mean checking if the given player has the
             * required technology.
             *
             * @param player - The player to give to.
             * @param amount - The amount to give.
             *
             * @see canTakeFrom()
             */
            virtual bool canGiveTo(const Player & player, int amount = 0)
                const = 0;

            /**
             * Takes an amount of this type from the given player.
             *
             * @param player - The player to take this type from.
             * @param amount - The amount to take.
             *
             * @see giveTo()
             */
            virtual void takeFrom(Player & player, int amount = 0) const = 0;

            /**
             * Checks if this type can be successfully taken from the given
             * player. This means checking if the given player has the given
             * technology or amount of resource.
             *
             * @param player - The player to take from.
             * @param amount - The amount to take.
             */
            virtual bool canTakeFrom(const Player & player, int amount = 0)
                const = 0;
    };

}

#endif // TRANSFERABLE_HPP_INCLUDED
