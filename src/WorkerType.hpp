//      WorkerType.hpp -- A type of laborer.
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

#ifndef WORKERTYPE_HPP_INCLUDED
#define WORKERTYPE_HPP_INCLUDED

#include <string>

#include "NamedType.hpp"
#include "Transferable.hpp"

namespace Aftermath { class Player; }

/**
 * @file WorkerType.hpp
 *
 * A type of laborer.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * A WorkerType is a type of laborer that can work for a Player to
     * manufacture products using labor.
     */
    class WorkerType : public NamedType, public Transferable {
        public:
            /**
             * Constructs a new WorkerType with the given name, description,
             * and image.
             *
             * @param name - The name of the new worker type.
             * @param description - A description of the new worker type.
             * @param image - The image of the new worker type.
             * @param labor - The amount of labor for this type to provide.
             */
            WorkerType(const std::string & name, const std::string &
                description, const std::string & image, int labor);

            /**
             * @return The amount of labor this type provides.
             */
            int getLabor() const;

            /**
             * Adds a number of workers of this type to the given player.
             *
             * @param player - The player to give to.
             * @param amount - The amount to give.
             */
            void giveTo(Player & player, int amount = 0) const;

            /**
             * Checks if the given player can receive the given amount of
             * workers. This should return true.
             *
             * @param player - The player to give to.
             * @param amount - The amount to give.
             *
             * @return true if amount is non-negative; false otherwise.
             */
            bool canGiveTo(const Player & player, int amount = 0) const;

            /**
             * Takes the given amount of this worker type from a player.
             *
             * @param player - The player to take from.
             * @param amount - The amount to take.
             */
            void takeFrom(Player & player, int amount = 0) const;

            /**
             * Checks if the given player has enough workers.
             *
             * @param player - The player to check.
             * @param amount - The amount to check for.
             *
             * @return true if the given player's workers of this type >=
             * amount >= 0; false otherwise.
             */
            bool canTakeFrom(const Player & player, int amount = 0) const;

        private:
            int mLabor;
    };

}

#endif // WORKERTYPE_HPP_INCLUDED

