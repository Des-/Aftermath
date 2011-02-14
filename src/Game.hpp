//      Game.hpp -- An Aftermath game.
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

#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include "Collection.hpp"

namespace Aftermath { class Mod;
                      class Player;
                      class TileMap; }

/**
 * @file Game.hpp
 *
 * An Aftermath game.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * A class to represent an ongoing game's state. Use nextTurn() to advance
     * to the next player's turn.
     *
     * add() and remove() add and remove players from the game.
     */
    class Game : public Collection<Player *> {
        public:
            /**
             * Constructs a zero-player Game with the given map. Add players
             * to the Game with the addPlayer() function.
             *
             * @param map - The TileMap to start the game with.
             * @param mod - The Mod for this game to run.
             */
            Game(TileMap * map, const Mod & mod);

            /**
             * Destructs this Game object, its Map, and its Player objects.
             */
            ~Game();

            /**
             * Starts or resumes this game.
             *
             * @param player - The player to move first.
             * @param turn - The turn to start at.
             */
            void start(Player * player, int turn = 0);

            /**
             * Moves play to the next player's turn.
             */
            void nextTurn();

            /**
             * @return The player whose turn it currently is.
             */
            const Player & getPlayer();

            /**
             * Returns the number of times each player has had a turn. This
             * advances every size() calls to nextTurn().
             *
             * @return The current turn of the Game, as an int.
             */
            int getTurn() const;

            /**
             * @return The current historical date in the game.
             */
            int getDate() const;

            /**
             * @return The mod that this game is running.
             */
            const Mod & getMod() const;

        private:
            TileMap * mMap;
            const Mod & mMod;
            int mTurn;
            iterator mPlayer;

            void beginTurn(Player & player);
            void endTurn(Player & player);
            void beginTurn();
    };

}

#endif // GAME_HPP_INCLUDED
