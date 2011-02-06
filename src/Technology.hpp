//      Technology.hpp -- A technological advance.
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

#ifndef TECHNOLOGY_HPP_INCLUDED
#define TECHNOLOGY_HPP_INCLUDED

#include <string>

#include "Graphics.hpp"
#include "NamedType.hpp"
#include "Transferable.hpp"

namespace Aftermath { class Player; }

/**
 * @file Technology.hpp
 *
 * A technological advance.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * A Technology is a technological advance researched by a Player.
     */
    class Technology : public NamedType, public Transferable {
        public:
            /**
             * Constructs a new Technology with the given name, description,
             * and image.
             *
             * @param name - The name of the new technology.
             * @param description - A short description of the new technology.
             * @param image - The image of the new technology.
             */
            Technology(const std::string & name, const std::string &
                description, const Image * image);

            /**
             * This adds this technology to the given player's technology.
             *
             * @param player - The player to give to.
             * @param amount - The amount to give.
             */
            void giveTo(Player & player, int amount = 0) const;

            /**
             * A player should always be allowed to acquire new technology,
             * so this function should return true.
             *
             * @param player - The player to give to.
             * @param amount - The amount to give.
             *
             * @return true.
             */
            bool canGiveTo(const Player & player, int amount = 0) const;

            /**
             * Removes this technology from the given players' technology.
             *
             * @param player - The player to take from.
             * @param amount - The amount to take.
             */
            void takeFrom(Player & player, int amount = 0) const;

            /**
             * This method gets if the given player has this technology.
             *
             * @param player - The player whose game to check.
             * @param amount - The amount to check for.
             *
             * @return true if the given player has this technology and
             * amount is 1 or the given player does not have this technology
             * and the amount is 0; false otherwise.
             */
            bool canTakeFrom(const Player & player, int amount = 0) const;
    };

}

#endif // TECHNOLOGY_HPP_INCLUDED
