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

namespace Aftermath { class GameSettings;
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
     * A class to represent an ongoing game's state. Use playTurn() to advance
     * the Game's turn.
     *
     * add() and remove() add and remove players from the game.
     */
    class Game : public Collection<Player *> {
        public:
            /**
             * Constructs a zero-player Game with the given map, starting from
             * the given turn. The game might need to start on a different
             * turn when loading a saved game. Add players to the Game with
             * the addPlayer() function.
             *
             * @param map - The TileMap to start the game with.
             * @param settings - The current GameSettings.
             * @param turn - The turn to start the game at. Default is 0.
             */
            Game(TileMap * map, const GameSettings & settings, int turn = 0);

            /**
             * Destructs this Game object, its Map, and its Player objects.
             */
            ~Game();

            /**
             * Advances this Game's turn. This plays through each player's
             * turn and handles and pre- and post-turn actions.
             */
            void playTurn();

            /**
             * Returns the number of times playTurn() has been called.
             *
             * @return The current turn of the Game, as an int.
             */
            int getTurn() const;

            /**
             * @return The current historical date in the game.
             */
            int getDate() const;

            /**
             * @return The current GameSettings.
             */
            const GameSettings & getSettings() const;

        private:
            TileMap * mMap;
            const GameSettings & mSettings;
            int mTurn;
    };

}

#endif // GAME_HPP_INCLUDED
