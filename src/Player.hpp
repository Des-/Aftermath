//      Player.hpp -- An Aftermath player.
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

#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include "Collection.hpp"
#include "Count.hpp"
#include "SelectiveCollection.hpp"

#include <string>

namespace Aftermath { class Game;
                      class GameSettings;
                      class Industry;
                      class Move;
                      class Nation;
                      class Resource;
                      class Technology;
                      class Tile;
                      class TileGroup;
                      class TileUnit;
                      class Transferable;
                      class TransportNetwork;
                      class Treaty; }

/**
 * @file Player.hpp
 *
 * An Aftermath player.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * A Player object represents a player of the game. Players have their
     * own Nation, name, and method of making moves. That means Players can
     * be controlled by both humans and AI. Players also have Treaties with
     * other players, a list of TileGroups that they control, a stockpile
     * of Resources, a Collection of Technology, an Industry, and a
     * TransportNetwork. Players also keep track of which Tiles they have
     * surveyed.
     */
    class Player : public SelectiveCollection<TileGroup *> {
        public:
            /**
             * Constructs a new player with the given name and no nationality.
             *
             * @param name - The name of the new player.
             * @param game - The game for this player to belong to.
             * @param initFromSettings - Whether or not to initialize this
             * player using the given game settings. This adds starting
             * technologies and resources.
             */
            Player(const std::string & name, Game & game,
                bool initFromSettings = true);

            /**
             * Virtual destructor, frees tech, industry, and transport.
             */
            virtual ~Player();

            /**
             * Gets the name of this player. Players have names other than the
             * names of their nations.
             *
             * @return The name of this player.
             */
            const std::string & getName() const;

            /**
             * Sets the name of this player.
             *
             * @param name - The new name of this player.
             */
            void setName(const std::string & name);

            /**
             * Gets the Nation that this player controls.
             *
             * @return The nation of the player, or NULL if the nation has
             * not yet been set.
             */
            const Nation * getNation() const;

            /**
             * Sets the Nation that this player controls.
             *
             * @param nation - The new nation for this player to control.
             */
            void setNation(const Nation * nation);

            /**
             * Gets the next Move for this player to make.
             *
             * @param game - The game for this player to move in.
             *
             * @return The next move of this player, or NULL if the player
             * ends his or her turn.
             */
            virtual Move * getMove(const Game & game) = 0;

            /**
             * Gets the current diplomatic relationship that this player has
             * with the given player.
             *
             * @param player - The player to look for treaties with.
             *
             * @return A Treaty object representing the diplomatic
             * relationship between the two players, from this player's
             * perspective.
             */
            Treaty & getTreaty(const Player * player);

            /**
             * Gets the const Treaty object between these two players.
             *
             * @see getTreaty()
             */
            const Treaty & getTreaty(const Player * player) const;

            /**
             * Returns whether or not this TileGroup can be claimed by this
             * Player.
             *
             * @return true if TileGroup::isLand() returns true and this
             * player does not already control the given group.
             */
            bool canAdd(const TileGroup *& group) const;

            /**
             * Provides access to this Player's stockpile.
             *
             * @return A reference to this Player's stockpile.
             */
            Count<const Resource *> & getStockpile();

            /**
             * Provides const access to this Player's stockpile.
             *
             * @see getStockpile();
             */
            const Count<const Resource *> & getStockpile() const;

            /**
             * Provides access to this Player's technology.
             *
             * @return A reference to this Player's technology.
             */
            Collection<const Technology *> & getTechnology();

            /**
             * Provides const access to this Player's technology.
             *
             * @see getTechnology()
             */
            const Collection<const Technology *> & getTechnology() const;

            /**
             * Provides access to this Player's industry.
             *
             * @return A reference to this Player's Industry.
             */
            Industry & getIndustry();

            /**
             * Provides const access to this Player's industry.
             *
             * @see getIndustry()
             */
            const Industry & getIndustry() const;

            /**
             * Provides access to this Player's transport network.
             *
             * @return A reference to this Player's TransportNetwork.
             */
            TransportNetwork & getTransport();

            /**
             * Provides const access to this Player's transport network.
             *
             * @see getTransport()
             */
            const TransportNetwork & getTransport() const;

            /**
             * Gets the Tiles that have been surveyed by this Player.
             *
             * @return A Collection of the tiles that have been revealed.
             */
            Collection<Tile *> & getRevealed();

            /**
             * Gets the const Tiles that have been surveyed by this player.
             *
             * @see getRevealed()
             */
            const Collection<const Tile *> & getRevealed() const;

            /**
             * Gets the capital TileGroup of this Player.
             *
             * @return The TileGroup specified as capital by the setCapital()
             * function, or NULL if the captial has not been set.
             */
            TileGroup * getCapital();

            /**
             * Gets the const capital TileGroup of this Player.
             *
             * @see getCapital()
             */
            const TileGroup * getCapital() const;

            /**
             * Sets the capital TileGroup of this Player. The function does
             * not add the capital to this Player, it is assumed that the
             * given TileGroup is already owned by the player.
             *
             * @param capital - The new capital of this Player.
             */
            void setCapital(TileGroup * capital);

            /**
             * Gets the harbor TileGroup of this Player.
             *
             * @return The TileGroup specified as harbor by the setHarbor()
             * function, or NULL if the harbor has not been set.
             */
            TileGroup * getHarbor();

            /**
             * Gets the const harbor TileGroup of this Player.
             *
             * @see getHarbor()
             */
            const TileGroup * getHarbor() const;

            /**
             * Sets the harbor TileGroup of this Player. The function does
             * not add the harbor to this Player, it is assumed that the
             * given TileGroup is already owned by the player.
             *
             * @param harbor - The new harbor of this Player.
             */
            void setHarbor(TileGroup * harbor);

            /**
             * @return The amount of money that this Player has.
             */
            int getMoney() const;

            /**
             * Gives an amount of money to this Player.
             *
             * @param amount - The amount of money to add.
             */
            void giveMoney(int amount);

            /**
             * Takes an amount of money from this Player.
             *
             * @param amount - The amount of money to take.
             */
            void takeMoney(int amount);

            /**
             * @return The Game that this player belongs to.
             */
            Game & getGame();

            /**
             * @see getGame()
             */
            const Game & getGame() const;

            /**
             * Places the given TileUnit on a Tile controlled by this player.
             *
             * @param unit - The unit to place.
             *
             * @return true if the unit was successfully placed;
             * false otherwise.
             */
            bool placeTileUnit(const TileUnit * unit);

            /**
             * Takes an amount of the given transferable from this player.
             *
             * @param type - The type of transferable to take.
             * @param amount - The amount to take.
             */
            void take(const Transferable * type, int amount);

            /**
             * Takes an amount of various types from this Player. This could
             * be resources, workers,  labor, or other types.
             *
             * @param types - A Count of the types to take.
             */
            void take(const Count<const Transferable *> & types);

            /**
             * Gets if an amount of the specified type can be taken from this
             * player
             *
             * @param type - The type of transferable to take.
             * @param amount - The amount to take.
             *
             * @return true if the type can be take from this player; false
             * otherwise.
             */
            bool canTake(const Transferable * type, int amount) const;

            /**
             * Gets whether or not the given amount of types can be taken from
             * this Player. This could mean checking to see if the player has
             * the required resources or labor.
             *
             * @param types - A Count of the types to take.
             *
             * @return true if the given amount of types can be taken from
             * this Player; false otherwise.
             */
            bool canTake(const Count<const Transferable *> & types) const;

            /**
             * Gives this player an amount of the given transferable.
             *
             * @param type - The type of transferable to give.
             * @param amount - The amount to give.
             */
            void give(const Transferable * type, int amount);

            /**
             * Gives an amount of various types to this Player. This could be
             * resources, workers, labor, technology, or other types.
             *
             * @param types - A Count of the types to give.
             */
            void give(const Count<const Transferable *> & types);

            /**
             * Gets if an amount of the specified type can be given to this
             * player
             *
             * @param type - The type of transferable to give.
             * @param amount - The amount to give.
             *
             * @return true if this player can be given amount of type; false
             * otherwise.
             */
            bool canGive(const Transferable * type, int amount) const;

            /**
             * Gets whether or not the given amount of types can be given to
             * this Player. This could mean checking if the player has all of
             * the required technologies.
             *
             * @param types - A Count of the types to give.
             *
             * @return true if the given amount of types can be given to this
             * Player; false otherwise.
             */
            bool canGive(const Count<const Transferable *> & types) const;

        private:
            std::string mName;
            const Nation * mNation;
            std::map<const Player *, Treaty> mTreaties;
            Game & mGame;
            Collection<Tile *> mRevealed;
            Count<const Resource *> mStockpile;
            TileGroup * mCapital;
            TileGroup * mHarbor;
            int mMoney;
            Collection<const Technology *> mTechnology;
            Industry * mIndustry;
            TransportNetwork * mTransport;
    };

}

#endif // PLAYER_HPP_INCLUDED
