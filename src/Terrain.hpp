//      Terrain.hpp -- A terrain type for tiles.
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

#ifndef TERRAIN_HPP_INCLUDED
#define TERRAIN_HPP_INCLUDED

#include <map>
#include <string>

#include "Graphics.hpp"
#include "NamedType.hpp"

namespace Aftermath { class Resource; }

/**
 * @file Terrain.hpp
 *
 * A terrain type for tiles.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * A Terrain object represents a particular class of Tile, e.g. Mountains,
     * Hills, or Ocean. Terrain objects are immutable and reused for different
     * tiles.
     */
    class Terrain : public NamedType {
        public:
            typedef std::map<const Resource *, double>::const_iterator
                iterator;

            /**
             * Constructs a new terrain with the given name, description,
             * image, and resource probabilities.
             *
             * @param name - The name of this terrain type.
             * @param description - The description of this terrain type.
             * @param isLand - Is this terrain a land type.
             * @param isSea - Is this terrain a sea type.
             * @param image - The image of this terrain type, to be used by
             * all tiles of the same type.
             * @param probabilities - A map between resource types and their
             * probabilities for this tile. This is used when randomly
             * generating resources for tiles.
             */
            Terrain(const std::string & name, const std::string & description,
                bool isLand, bool isSea, const Image & image,
                const std::map <const Resource *, double> * probabilities);

            /**
             * Deletes this terrain and free its image and probabilities map.
             */
            ~Terrain();

            /**
             * Retrieves whether or not this terrain is of a land type.
             *
             * @return true if this terrain is a land terrain,
             * false otherwise.
             */
            bool isLandTerrain() const;

            /**
             * Retrieves whether or not this terrain is of a sea type.
             *
             * @return true if this terrain is a sea terrain, false otherwise.
             */
            bool isSeaTerrain() const;

            /**
             * Retrieves the probability that a particular Resource type is
             * generated on tiles of this terrain type.
             *
             * @return The probability, from 0 to 1, of the resource type.
             */
            double getProbability(const Resource * resource) const;

            /**
             * Returns an iterator pointing to the first resource probability
             * of this terrain type.
             *
             * @return An iterator of pair<Resource *, double> that points to
             * the beginning of the probability map.
             */
            iterator begin() const;

            /**
             * Returns an iterator pointing past the last resource probability
             * of this terrain type.
             *
             * @return An iterator of pair<Resource *, double> that points
             * past the end of the probability map.
             */
            iterator end() const;

        private:
            bool mLand;
            bool mSea;
            const std::map<const Resource *, double> * mProbabilities;
    };

}

#endif // TERRAIN_HPP_INCLUDED
