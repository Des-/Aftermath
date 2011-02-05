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

namespace Aftermath { class Labor; }

#include <string>

// TODO: Decide for certain what graphics library to use.
#include <SFML/Graphics/Image.hpp>

#include "NamedType.hpp"
#include "Player.hpp"
#include "Transferable.hpp"

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
                const sf::Image * image);

            /**
             * Gives the specified amount of labor to the given player.
             *
             * @param player - The player to give to.
             * @param amount - The amount to give.
             */
            void giveTo(Player & player, int amount = 0) const;

            /**
             * Checks if the given player can receive the given amount of
             * labor. This checks against the player's max labor.
             *
             * @param player - The player to give to.
             * @param amount - The amount to give.
             *
             * @return true if amount >= 0 and does not push player's labor
             * above the max labor; false otherwise.
             */
            bool canGiveTo(const Player & player, int amount = 0) const;

            /**
             * Takes the given amount of labor from the specified player.
             *
             * @param player - The player to take from.
             * @param amount - The amount to take.
             */
            void takeFrom(Player & player, int amount = 0) const;

            /**
             * Checks if the given player has enough labor.
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
