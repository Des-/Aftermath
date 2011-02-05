//      TileGroup.hpp -- A group of Tiles.
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

#ifndef TILEGROUP_HPP_INCLUDED
#define TILEGROUP_HPP_INCLUDED

#include <string>

#include "Player.hpp"
#include "SelectiveCollection.hpp"
#include "Tile.hpp"
#include "TileGroupUnit.hpp"

/**
 * @file TileGroup.hpp
 *
 * A group of Tiles.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * TileGroups are a named collections of Tiles. Each TileGroup has its own
     * SelectiveCollection of TileGroupUnit objects.
     */
    class TileGroup : SelectiveCollection<Tile *> {
        public:

            /**
             * Constructs a TileGroup with the given name and no unit list.
             */
            TileGroup(const std::string & name);

            /**
             * Destructor frees the list of TileGroupUnits.
             */
            virtual ~TileGroup();

            /**
             * Gets the name of this TileGroup.
             *
             * @return A std::string that is the name of this group.
             */
            const std::string & getName() const;

            /**
             * Set the name of this TileGroup.
             *
             * @param name - The new name of this TileGroup.
             */
            void setName(const std::string & name);

            /**
             * Gets the collection of TileGroupUnits in this TileGroup.
             *
             * @return A SelectiveCollection of all units in this TileGroup.
             * This list can be modified with add() and remove().
             */
            SelectiveCollection<TileGroupUnit *> & getUnits();

            /**
             * Gets the const collection of TileGroupUnits in this TileGroup.
             *
             * @see getUnits()
             */
            const SelectiveCollection<const TileGroupUnit *> &
                getUnits() const;

            /**
             * If canAdd(tile) returns true, and the Tile isn't already in
             * this TileGroup, this function adds the tile to this group and
             * removes it from its current group (if any).
             *
             * @param tile - The tile to add.
             */
            void add(Tile *& tile);

            /**
             * Gets whether this TileGroup is a land-based group.
             *
             * @return true if this group is a land group, false otherwise.
             */
            virtual bool isLand() = 0;

            /**
             * Returns whether or not this TileGroup is a sea-based group.
             *
             * @return true if this group is a sea group, false otherwise.
             */
            virtual bool isSea() = 0;

            /**
             * Gets the owning Player of this TileGroup.
             *
             * @return The Player that controls this TileGroup, or NULL if the
             * controlling Player has not been set yet.
             */
            virtual Player * getOwner() = 0;

            /**
             * Gets the const owner of this TileGroup.
             *
             * @see getOwner()
             */
            virtual const Player * getOwner() const = 0;

            /**
             * Sets the Player that this TileGroup belongs to. If this
             * TileGroup is a Sea, this function does nothing.
             */
            virtual void setOwner(Player * owner) = 0;

            /**
             * Gets the capital Tile of this TileGroup.
             *
             * @return The Tile specified as capital by the setCapital()
             * function, or NULL if the captial has not been set.
             */
            virtual Tile * getCapital() = 0;

            /**
             * Gets the const capital Tile of this TileGroup.
             *
             * @see getCapital()
             */
            virtual const Tile * getCapital() const = 0;

            /**
             * Sets the capital Tile of this TileGroup. The function does not
             * add the capital to this TileGroup, it is assumed that the given
             * Tile is already a part of the group. If this TileGroup is a
             * Sea, this function has no effect.
             *
             * @param capital - The new capital of this TileGroup.
             */
            virtual void setCapital(Tile * capital) = 0;

        protected:
            /**
             * The unit list. This should be initialized in any derived
             * class's constructor.
             */
            SelectiveCollection<TileGroupUnit *> * mUnits;

        private:
            std::string mName;
    };

}

#endif // TILEGROUP_HPP_INCLUDED

