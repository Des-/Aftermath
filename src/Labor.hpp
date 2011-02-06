//      Labor.hpp -- Labor points for use in manufacturing.
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

#ifndef LABOR_HPP_INCLUDED
#define LABOR_HPP_INCLUDED

#include <string>

#include "Graphics.hpp"
#include "NamedType.hpp"
#include "Transferable.hpp"

namespace Aftermath { class Player; }

/**
 * @file Labor.hpp
 *
 * Labor points for use in manufacturing.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * Labor points represent manpower for use in manufacturing. There should
     * only be one Labor type per mod pack.
     */
    class Labor : public NamedType, public Transferable {
        public:
            /**
             * Constructs a new Labor with the given name, description,
             * and image.
             *
             * @param name - The name of the new labor type.
             * @param description - A description of the new labor type.
             * @param image - The image of the new labor type.
             */
            Labor(const std::string & name, const std::string & description,
                const Image * image);

            /**
             * Deallocates the given amount of labor.
             *
             * @param player - The player to give to.
             * @param amount - The amount to give.
             */
            void giveTo(Player & player, int amount = 0) const;

            /**
             * Gets if the given player has enough allocated labor to
             * deallocate.
             *
             * @param player - The player to give to.
             * @param amount - The amount to give.
             *
             * @return true if amount >= 0 and the player's allocated labor
             * will not drop below 0; false otherwise.
             */
            bool canGiveTo(const Player & player, int amount = 0) const;

            /**
             * Allocates the given amount of labor.
             *
             * @param player - The player to take from.
             * @param amount - The amount to take.
             */
            void takeFrom(Player & player, int amount = 0) const;

            /**
             * Checks if the given player has enough available labor to
             * allocate.
             *
             * @param player - The player to check.
             * @param amount - The amount to check for.
             *
             * @return true if the given player's labor >= amount >= 0; false
             * otherwise.
             */
            bool canTakeFrom(const Player & player, int amount = 0) const;
    };

}

#endif // LABOR_HPP_INCLUDED
