//      SpecialistType.hpp -- The specialist role of a TileUnit.
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

#ifndef SPECIALISTTYPE_HPP_INCLUDED
#define SPECIALISTTYPE_HPP_INCLUDED

#include <string>

#include "Collection.hpp"
#include "NamedType.hpp"
#include "Transferable.hpp"

namespace Aftermath { class Player;
                      class TileAction; }

/**
 * @file SpecialistType.hpp
 *
 * The specialist role of a TileUnit.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * A SpecialistType is the role of a TileUnit. SpecialistTypes have
     * actions that they can perform on Tiles called TileActions.
     */
    class SpecialistType : public NamedType, public Transferable,
                           public Collection<const TileAction *> {
        public:
            /**
             * Constructs a new SpecialistType with the given name,
             * description, and image. TileActions can then be added to the
             * SpecialistType.
             *
             * @param name - The name of the new type.
             * @param description - A brief description of the new type.
             * @param image - The image of the specialist.
             */
            SpecialistType(const std::string & name, const std::string &
                description, const Image * image);

            /**
             * Constructs one TileUnit of this type and gives it to the given
             * player.
             *
             * @param player - The player to pay for and receive the TileUnit.
             * @param amount - The amount of units to give the player.
             */
            void giveTo(Player & player, int amount = 0) const;

            /**
             * Checks if the given player can receive a specialist of this
             * type. This should always return true, because there is nothing
             * preventing a player from receiving a specialist.
             *
             * @param player - The player to give to.
             * @param amount - The amount to give.
             *
             * @return true if amount is non-negative; false otherwise.
             */
            bool canGiveTo(const Player & player, int amount = 0) const;

            /**
             * Taking a specialist from a player is undefined and thus this
             * function does nothing.
             *
             * @param player - The player to take from.
             * @param amount - The amount to take.
             */
            void takeFrom(Player & player, int amount = 0) const;

            /**
             * Taking a specialist from a player does nothing.
             *
             * @param player - The player to take from.
             * @param amount - The amount to take.
             *
             * @return true.
             */
            bool canTakeFrom(const Player & player, int amount = 0) const;
    };

}

#endif // SPECIALISTTYPE_HPP_INCLUDED
