//      Sea.hpp -- A sea of ocean tiles.
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

#ifndef SEA_HPP_INCLUDED
#define SEA_HPP_INCLUDED

namespace Aftermath { class Sea; }

#include <string>

#include "Player.hpp"
#include "Tile.hpp"
#include "TileGroup.hpp"

/**
 * @file Sea.hpp
 *
 * A sea of ocean tiles.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * Seas are TileGroups that are without owners and without capitals. They
     * consist only of sea tiles and only sea units can traverse them.
     */
    class Sea : public TileGroup {
        public:
            /**
             * Constructs an empty sea with the given name.
             */
            Sea(const std::string & name);

            /**
             * Frees this Sea and all units on it. This does not free any
             * tiles that were once a part of this Sea.
             */
            ~Sea();

            /**
             * Returns whether or not this TileGroup is a land-based group.
             *
             * @return This function always returns false for a Sea.
             */
            bool isLand();

            /**
             * Returns whether or not this TileGroup is a sea-based group.
             *
             * @return This function always returns true for a Sea.
             */
            bool isSea();

            /**
             * This function does nothing for a Sea.
             *
             * @return NULL
             */
            Player * getOwner();

            /**
             * This function does nothing for a Sea.
             *
             * @return NULL
             */
            const Player * getOwner() const;

            /**
             * This function does nothing for a Sea.
             */
            void setOwner(Player * owner);

            /**
             * This function does nothing for a Sea.
             *
             * @return NULL
             */
            Tile * getCapital();

            /**
             * This function does nothing for a Sea.
             *
             * @return NULL
             */
            const Tile * getCapital() const;

            /**
             * This function does nothing for a Sea.
             */
            void setCapital(Tile * capital);

            /**
             * Tells whether or not the given tile can be successfully added
             * to this Sea.
             *
             * @param tile - The tile to check for support.
             *
             * @return true if the tile's Terrain::isSeaTerrain() returns
             * true and the tile is not already in this sea, false otherwise.
             */
            bool canAdd(const Tile *& tile) const;
    };

}

#endif // SEA_HPP_INCLUDED
