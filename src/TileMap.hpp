//      TileMap.hpp -- A two-dimensional map of tiles.
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

#ifndef TILEMAP_HPP_INCLUDED
#define TILEMAP_HPP_INCLUDED

#include <string>

#include "Array2D.hpp"
#include "Collection.hpp"

namespace Aftermath { class Tile;
                      class TileGroup; }

/**
 * @file TileMap.hpp
 *
 * A two-dimensional map of tiles.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * A TileMap is a map of tiles, each belonging to a TileGroup.
     *
     * add() and remove() add and remove TileGroups.
     */
    class TileMap : public Array2D<Tile>, public Collection<TileGroup *> {
        public:
            /**
             * Constructs a new TileMap with the given dimensions and no
             * TileGroup objects.
             *
             * @param name - The name of the new map.
             * @param rows - The number of rows in the new map.
             * @param columns - The number of columns in the new map.
             */
            TileMap(const std::string & name, unsigned rows,
                unsigned columns);

            /**
             * Destructs this TileMap and all Tiles and TileGroups in the map.
             */
            ~TileMap();

            /**
             * Gets the name of this TileMap.
             *
             * @return A std::string that is the name of this map.
             */
            const std::string & getName() const;

        private:
            std::string mName;
    };

}

#endif // TILEMAP_HPP_INCLUDED
