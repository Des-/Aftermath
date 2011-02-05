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

#include <string>

#include "Collection.hpp"
#include "Count.hpp"
#include "Game.hpp"
#include "GameSettings.hpp"
#include "Industry.hpp"
#include "Move.hpp"
#include "Nation.hpp"
#include "Resource.hpp"
#include "SelectiveCollection.hpp"
#include "TechnologyTree.hpp"
#include "Tile.hpp"
#include "TileGroup.hpp"
#include "TransportNetwork.hpp"
#include "Treaty.hpp"

/**
 * @file Player.hpp
 *
 * An Aftermath player.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * A Player object represents a player of the game. Players have their own
     * Nation, name, and method of making moves. That means Players can be
     * controlled by both humans and AI. Players also have Treaties with other
     * players, a list of TileGroups that they control, a stockpile of
     * Resources, a TechnologyTree, an Industry, and a TransportNetwork.
     * Players also keep track of which Tiles they have surveyed.
     */
    class Player : public SelectiveCollection<TileGroup *> {
        public:
            /**
             * Constructs a new player with the given name and no nationality.
             *
             * @param name - The name of the new player.
             * @param settings - The current GameSettings.
             * @param initFromSettings - Whether or not to initialize this
             * player using the given game settings. This adds starting
             * technologies and resources.
             */
            Player(const std::string & name, const GameSettings & settings,
                bool initFromSettings = true);

            /**
             * Destructs a player object and the Nation that they control.
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
            Move * getMove(const Game & game) = 0;

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
            Treaty & getTreaty(Player * player);

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
             * @return A reference to this Player's TechnologyTree.
             */
            TechnologyTree & getTechnology();


            /**
             * Provides const access to this Player's technology.
             *
             * @see getTechnology()
             */
            const TechnologyTree & getTechnology() const;

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
            Collection<Tile *> getRevealed();

            /**
             * Gets the const Tiles that have been surveyed by this player.
             *
             * @see getRevealed()
             */
            const Collection<const Tile *> getRevealed() const;

            /**
             * Takes an amount of various types from this Player. This could
             * be resources, workers,  labor, or other types.
             *
             * @param types - A Count of the types to take.
             */
            void take(const Count<const NamedType *> & types);

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
            bool canTake(const Count<const NamedType *> & types) const;

            /**
             * Gives an amount of various types to this Player. This could be
             * resources, workers, labor, technology, or other types.
             *
             * @param types - A Count of the types to give.
             */
            void give(const Count<const NamedType *> & types);

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
            bool canGive(const Count<const NamedType *> & types) const;

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
             * Sets the game that this player belongs to. This does NOT add
             * this player to the given game. To do that, use Game::add().
             *
             * @param game - The game for this player to belong to.
             */
            void setGame(Game & game);

        private:
            std::string mName;
            const Nation * mNation;
            std::map<Player *, Treaty> mTreaties;
            Game & mGame;
            Collection<Tile *> mRevealed;
            Count<const Resource *> mStockpile;
            TechnologyTree mTechnology;
            Industry mIndustry;
            TransportNetwork mTransport;
            TileGroup * mCapital;
            int mMoney;
    };

}

#endif // PLAYER_HPP_INCLUDED
