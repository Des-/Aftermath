//      Province.hpp -- A province of land tiles.
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

#ifndef PROVINCE_HPP_INCLUDED
#define PROVINCE_HPP_INCLUDED

#include <string>

#include "TileGroup.hpp"

namespace Aftermath { class Player;
                      class Tile; }

/**
 * @file Province.hpp
 *
 * A province of land tiles.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * Provinces are TileGroups that are controlled by Players. They have
     * room for an army of ProvinceUnits and have a single Tile designated as
     * a capital.
     */
    class Province : public TileGroup {
        public:
            /**
             * Constructs a province with the given name and an empty Army.
             */
            Province(const std::string & name);

            /**
             * Returns whether or not this TileGroup is a land-based group.
             *
             * @return This function always returns true for a Province.
             */
            bool isLand() const;

            /**
             * Returns whether or not this TileGroup is a sea-based group.
             *
             * @return This function always returns false for a Province.
             */
            bool isSea() const;

            /**
             * Gets the owning Player of this Province.
             *
             * @return The Player that controls this Province, or NULL if the
             * controlling Player has not been set yet.
             */
            Player * getOwner();

            /**
             * Gets the const owner of this Province.
             *
             * @see getOwner()
             */
            const Player * getOwner() const;

            /**
             * To be used by Player::addTileGroup(). setOwner() does NOT
             * add this Province to the given Player. Instead, use
             * Player::addProvince().
             */
            void setOwner(Player * owner);

            /**
             * Gets the capital Tile of this Province.
             *
             * @return The Tile specified as capital by the setCapital()
             * function, or NULL if the captial has not been set.
             */
            Tile * getCapital();

            /**
             * Gets the const capital Tile of this Province.
             *
             * @see getCapital()
             */
            const Tile * getCapital() const;

            /**
             * Sets the capital Tile of this Province. The function does not
             * add the capital to this Province, it is assumed that the given
             * Tile is already a part of the province.
             *
             * @param capital - The new capital of this Province.
             */
            void setCapital(Tile * capital);

            /**
             * Tells whether or not the given tile can be successfully added
             * to this Province.
             *
             * @param tile - The tile to check for support.
             *
             * @return true if the tile's Terrain::isLandTerrain() returns
             * true, false otherwise.
             */
            bool canAdd(const Tile *& tile) const;

        private:
            Player * mOwner;
            Tile * mCapital;
    };

}

#endif // PROVINCE_HPP_INCLUDED
