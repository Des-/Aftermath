//      Date.hpp -- A historical date type.
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

#ifndef DATE_HPP_INCLUDED
#define DATE_HPP_INCLUDED

#include <string>

#include "Graphics.hpp"
#include "NamedType.hpp"
#include "Transferable.hpp"

namespace Aftermath { class Player; }

/**
 * @file Date.hpp
 *
 * A historical date type.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * Date is a NamedType representing a historical date. This is especially
     * useful for restricting technology to a certain time period.
     */
    class Date : public NamedType, public Transferable {
        public:
            /**
             * Constructs a new Date with the given name, description,
             * and image.
             *
             * @param name - The name of the new date type.
             * @param description - A description of the new date type.
             * @param image - The image of the new date type.
             */
            Date(const std::string & name, const std::string & description,
                const Image * image);

            /**
             * Giving a date to a player is undefined and thus this function
             * does nothing.
             *
             * @param player - The player to give to.
             * @param amount - The amount to give.
             */
            void giveTo(Player & player, int amount = 0) const;

            /**
             * Giving a date to a player does nothing.
             *
             * @param player - The player to give to.
             * @param amount - The amount to give.
             *
             * @return true.
             */
            bool canGiveTo(const Player & player, int amount = 0) const;

            /**
             * Taking a date from a player does nothing.
             *
             * @param player - The player to take from.
             * @param amount - The amount to take.
             */
            void takeFrom(Player & player, int amount = 0) const;

            /**
             * This method gets if the current game date is at or past
             * the given date.
             *
             * @param player - The player whose game to check.
             * @param date - The date to check for.
             *
             * @return true if the current historical date is at or past the
             * given date; false otherwise.
             */
            bool canTakeFrom(const Player & player, int date = 0) const;
    };

}

#endif // DATE_HPP_INCLUDED
