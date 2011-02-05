//      Level.hpp -- An Upgradable's level.
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

#ifndef LEVEL_HPP_INCLUDED
#define LEVEL_HPP_INCLUDED

#include "Count.hpp"
#include "NamedType.hpp"

/**
 * @file Level.hpp
 *
 * An Upgradable's level.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * An upgradable's level needs to hold certain information about the costs
     * of aquiring that level. This includes monetary, resource, and research
     * costs.
     */
    class Level {
        public:
            /**
             * Constructs a new Level with the given monetary, resource, and
             * research cost.
             *
             * @param cost - The monetary, resource, and technology cost.
             */
            Level(const Count<const NamedType *> * cost);

            /**
             * Virtual destructor for Level; this frees this level's cost.
             */
            virtual ~Level();

            /**
             * Gets the cost of upgrading to this level.
             *
             * @return A Count of the required types.
             */
            const Count<const NamedType *> & getCost() const;

        private:
            const Count<const NamedType *> * mCost;
    };

}

#endif // LEVEL_HPP_INCLUDED
