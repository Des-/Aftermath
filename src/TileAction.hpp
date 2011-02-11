//      TileAction.hpp -- An action performed on a Tile by a TileUnit.
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

#ifndef TILEACTION_HPP_INCLUDED
#define TILEACTION_HPP_INCLUDED

#include <string>

#include "Graphics.hpp"
#include "NamedType.hpp"

namespace Aftermath { class Game;
                      class Tile;
                      class TileUnit; }

/**
 * @file TileAction.hpp
 *
 * An action performed on a Tile by a TileUnit.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * A TileAction is an action performed on a Tile by a TileUnit. This could
     * be improving the yield or constructing an improvement.
     */
    class TileAction : public NamedType {
        public:
            /**
             * Constructs a new TileAction with the given name,
             * description, and image.
             *
             * @param name - The name of the new type.
             * @param description - A brief description of the new type.
             * @param image - The image of the tile action.
             */
            TileAction(const std::string & name, const std::string &
                description, const Image & image);

            /**
             * This checks to see if this action can be performed on the given
             * tile. This checks the necessary costs for the action.
             *
             * @param unit - The unit to perform this action.
             * @param tile - The tile that this action is being performed on.
             *
             * @return true if this action can be performed on the given tile;
             * false otherwise.
             */
            virtual bool canPerform(const TileUnit & unit, const Tile & tile)
                const = 0;

            /**
             * Performs this action on the given tile. This deducts any costs
             * associated with performing the action.
             *
             * @param unit - The unit to perform this action.
             * @param tile - The tile that this action is being performed on.
             */
            virtual void perform(const TileUnit & unit, Tile & tile) = 0;
    };

}

#endif // TILEACTION_HPP_INCLUDED
