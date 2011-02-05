//      Move.hpp -- An abstract move made by a player.
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

#ifndef MOVE_HPP_INCLUDED
#define MOVE_HPP_INCLUDED

#include "Game.hpp"

/**
 * @file Move.hpp
 *
 * An abstract move made by a player.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * Move is an entirely abstract interface for defining a type of move that
     * can be applied to a Game.
     */
    class Move {
        public:
            /**
             * Virtual destructor for Move.
             */
            virtual ~Move();

            /**
             * Checks whether or not this Move would be a legal move in the
             * given Game.
             *
             * @param game - The game to test for legality in.
             *
             * @return true if this move is legal, false otherwise.
             */
            virtual bool isLegal(const Game & game) const = 0;

            /**
             * Applies this move to the given game. This function modifies the
             * given game appropriately.
             *
             * @param game - The game to apply this move to.
             */
            virtual void apply(Game & game) const = 0;
    };

}

#endif // MOVE_HPP_INCLUDED
