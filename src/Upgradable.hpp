//      Upgradable.hpp -- A type that can be upgraded.
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

#ifndef UPGRADABLE_HPP_INCLUDED
#define UPGRADABLE_HPP_INCLUDED

#include <vector>

#include "Count.hpp"

namespace Aftermath { class NamedType; }

/**
 * @file Upgradable.hpp
 *
 * A type that can be upgraded.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * An Upgradable object can be upgraded by a Player for the proper amount
     * of Resources and money. There are two methods of upgrading: upgrade()
     * will upgrade immediately and offer no chance to cancel the upgrade.
     * This is suitable for upgrades that happen in one turn like unit
     * upgrades. startUpgrade() starts a turn-long upgrade, which can be
     * cancelled at any time with cancelUpgrade(). A turn-long upgrade must
     * be completed the next turn with finishUpgrade().
     *
     * @param LevelType - The type of level to upgrade from and to. This
     * should be a derived class of Level.
     */
    template <class LevelType>
    class Upgradable {
        public:
            /**
             * Constructs a new Upgradable at level 0 and with the given set
             * of levels.
             *
             * @param levels - The levels to upgrade through, starting at 0.
             */
            Upgradable(const std::vector<const LevelType *> & levels) :
                 mUpgrading(false), mLevel(0), mLevels(levels) {};

            /**
             * Virtual destructor for this Upgradable. This does nothing.
             */
            virtual ~Upgradable() {};

            /**
             * Gets the current level of this Upgradable. This will be in the
             * set of levels that was passed to this Upgradable's constructor.
             *
             * @return The current level of this Upgradable.
             */
            const LevelType & getLevel() const {
                return *(mLevels[mLevel]);
            }

            /**
             * Gets the next level of this Upgradable. This will be in the
             * set of levels that was passed to this Upgradable's constructor.
             *
             * @return The next level of this Upgradable.
             */
            const LevelType & getNextLevel() const {
                return *(mLevels[mLevel + 1]);
            }

            /**
             * Returns whether not this Upgradable is on its last level.
             *
             * @return true if there is a next level, false otherwise.
             */
            bool hasNextLevel() const {
                return mLevel + 1 < mLevels.size();
            }

            /**
             * Gets the cost of the next upgrade. This function calls
             * Level::getCost() on the next level.
             *
             * @return The cost of the next upgrade.
             */
            const Count<const NamedType *> & getCost() const {
                return mLevels[mLevel + 1]->getCost();
            }

            /**
             * Gets whether the given player has the capacity to upgrade this
             * Upgradable. This takes into account current Resource count,
             * available money, required technology, and presence of the next
             * level.
             *
             * @param player - The Player to do the upgrading.
             *
             * @return true if the given player has enough resources, money,
             * and technology, there is a next level, and this Upgradable is
             * not currently upgrading; false otherwise.
             */
            template <class PlayerType>
            bool canUpgrade(const PlayerType & player) const {
                return  !getUpgrading() &&
                        hasNextLevel() &&
                        player.canTake(getCost());
            }

            /**
             * Upgrades immediately, deducting the required resources and
             * money from the given player. This is suitable for immediate
             * upgrades like army units.
             *
             * @param player - The player to pay for the upgrade.
             */
            template <class PlayerType>
            void upgrade(PlayerType & player) {
                startUpgrade(player);
                finishUpgrade();
            }

            /**
             * Returns whether this Upgradable is currently in the process of
             * a turn-long upgrade.
             *
             * @return true if startUpgrade() was called without a following
             * cancelUpgrade() or finishUpgrade(); false otherwise.
             */
            bool getUpgrading() const {
                return mUpgrading;
            }

            /**
             * Starts a turn-long upgrade, deducting the required resoures and
             * money from the given player. This upgrade can be finished with
             * finishUpgrade() or cancelled with cancelUpgrade().
             *
             * @param player - The player to pay for the upgrade.
             */
            template <class PlayerType>
            void startUpgrade(PlayerType & player) {
                mUpgrading = true;
                player.take(getCost());
            }

            /**
             * Cancels a turn-long upgrade, refunding the required money and
             * resources.
             *
             * @param player - The player to refund.
             */
            template <class PlayerType>
            void cancelUpgrade(PlayerType & player) {
                player.give(getCost());
                mUpgrading = false;
            }

            /**
             * Completes a turn-long upgrade. This actually advances this
             * Upgradable's level.
             */
            virtual void finishUpgrade() {
                mUpgrading = false;
                ++mLevel;
            }

        private:
            bool mUpgrading;
            int mLevel;
            const std::vector<const LevelType *> & mLevels;
    };

}

#endif // UPGRADABLE_HPP_INCLUDED
