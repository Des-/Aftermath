//      Tile.hpp -- A map tile.
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

#ifndef TILE_HPP_INCLUDED
#define TILE_HPP_INCLUDED

namespace Aftermath { class Tile; }

#include "Resource.hpp"
#include "SelectiveCollection.hpp"
#include "Terrain.hpp"
#include "TileGroup.hpp"
#include "TileUnit.hpp"

/**
 * @file Tile.hpp
 *
 * A map tile.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * Tile objects are what game maps are made out of. They have their own
     * Terrain type, Resources, and room for a TileUnit. Tiles also belong to
     * TileGroups.
     */
    class Tile : public SelectiveCollection<Resource *> {
        public:
            /**
             * Constructs a new Tile object from the given Terrain info and
             * with a yield of one.
             *
             * @param terrain - The Terrain type of the new Tile.
             * @param genResources - If this is true, then the resources of
             * the tile are randomly generated based off of the terrain type.
             * Client maps should use false because they have to request the
             * resources from the server map with a prospector.
             */
            Tile(const Terrain * terrain, bool genResources = true);

            /**
             * Deletes this Tile object. This does not free the Terrain type
             * or Resources of this Tile, however, as there can be multiple
             * Tiles with the same Terrain type and resources.
             */
            ~Tile();

            /**
             * Gets the TileGroup that this Tile belongs to.
             *
             * @return A pointer to the TileGroup that this Tile belongs to.
             * NULL if this Tile does not belong to a group.
             */
            TileGroup * getTileGroup();

            /**
             * Gets const group of this Tile.
             *
             * @see getTileGroup()
             */
            const TileGroup * getTileGroup() const;

            /**
             * For use by TileGroup::add(). This function does NOT add
             * this Tile to the given group. To add this Tile to a group, use
             * TileGroup::add().
             *
             * @param group - The new TileGroup for this Tile to belong to.
             */
            void setTileGroup(TileGroup * group);

            /**
             * Gets the Terrain associated with this Tile object.
             *
             * @return A pointer to the Terrain of this Tile. This should be
             * the same pointer for all Tiles of the same Terrain.
             */
            const Terrain * getTerrain() const;

            /**
             * Sets the Terrain type of this Tile. If genResources is true,
             * the Resource list is randomly generated based off the Terrain
             * type given.
             *
             * @param terrain - The new Terrain type of this Tile.
             * @param genResources - Whether or not the randomly generate new
             * resources based off of the new terrain.
             */
            void setTerrain(const Terrain * terrain, bool genResources = true);

            /**
             * Gets the TileUnit of this Tile.
             *
             * @return The current TileUnit residing on this Tile, or NULL if
             * there is no TileUnit on this Tile.
             */
            TileUnit * getTileUnit();

            /**
             * Gets const TileUnit of this Tile.
             *
             * @see getTileUnit()
             */
            const TileUnit * getTileUnit() const;

            /**
             * Sets the TileUnit of this Tile.
             *
             * @param tileUnit - The TileUnit to reside on this Tile.
             */
            void setTileUnit(TileUnit * tileUnit);

            /**
             * Returns true if this Tile supports adding this type of
             * resource.
             *
             * @return true if this Tile's terrain type supports adding this
             * resource, false otherwise.
             */
            bool canAdd(const Resource *& resource) const;

            /**
             * Gets the amount of each resource present that this Tile
             * provides to a TransportNetwork.
             *
             * @return The per-resource yield of this tile.
             */
            int getYield() const;

            /**
             * Sets the per-resource yield of this tile to a given value.
             *
             * @param yield - The new resource yield of this tile.
             */
            void setYield(int yield);

            /**
             * Adds a given amount to the per-resource yield of this tile.
             *
             * @param yield - The amount of yield to add. This can be
             * negative.
             */
            void addYield(int yield);

        private:
            TileGroup * mTileGroup;
            const Terrain * mTerrain;
            TileUnit * mTileUnit;
            int mYield;
    };

}

#endif // TILE_HPP_INCLUDED
