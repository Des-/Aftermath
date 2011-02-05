//      Treaty.hpp -- The diplomatic relationship between two players.
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

#ifndef TREATY_HPP_INCLUDED
#define TREATY_HPP_INCLUDED

namespace Aftermath { class Treaty; }

/**
 * @file Treaty.hpp
 *
 * The diplomatic relationship between two players.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * A type of diplomatic mission.
     */
    enum Mission {
        WAR,             /**< Denotes that two players are at war.       */
        PEACE,           /**< Denotes that two players are at peace.     */
        TRADE_CONSULATE, /**< Denotes that two players have a consulate. */
        EMBASSY,         /**< Denotes that two players have an embassy.  */
        PACT,            /**< Denotes that two players have a pact.      */
        ALLIANCE,        /**< Denotes that two players have an alliance. */
        EMPIRE,          /**< Denotes that p2 is a part of p1's empire.  */
        COLONY           /**< Denotes that p1 is a part of p2's empire.  */
    };

    /**
     * The diplomatic relationship between two players. This includes
     * war, peace, trade agreements, political agreements, and friendliness.
     * This can be thought of as an agreement between two players, p1 and p2.
     * p1 has a treaty with p2 and p2 has separate a treaty with p1.
     */
    class Treaty {
        public:
            /**
             * Constructs a new treaty. The treaty starts with the two players
             * at peace and with no special agreements. The relationship level
             * starts at 40.
             */
            Treaty();

            /**
             * Gets the current mission of this treaty.
             *
             * @return The Mission. For instance, PEACE or PACT.
             */
            enum Mission getMission() const;

            /**
             * Set the current mission of this treaty.
             *
             * @param mission - The new diplomatic mission of this treaty.
             */
            void setMission(enum Mission mission);

            /**
             * Gets the amount of money that p1 is gifting to p2 this turn.
             *
             * @return The money granted from p1 to p2.
             */
            int getGrant() const;

            /**
             * Sets the amount of money that p1 is gifting to p2 this turn.
             *
             * @param grant - The new grant amount.
             */
            void setGrant(int grant);

            /**
             * Gets the trade subsidy that p1 has issued to p2.
             *
             * @return The trade subsidy, as a percent from 0-100.
             */
            int getSubsidy() const;

            /**
             * Sets the trade subsidy that p1 issues to p2.
             *
             * @param subsidy - The new subsidy percentage.
             */
            void setSubsidy(int subsidy);

            /**
             * Gets whether or not p1 is boycotting p2.
             *
             * @return true if p1 is boycotting p2, false otherwise.
             */
            bool getBoycott() const;

            /**
             * Sets whether or not p1 is boycotting p2.
             *
             * @param boycott - true means boycott, false means allow trade.
             */
            void setBoycott(bool boycott) const;

            /**
             * Gets the relationship level between p1 and p2.
             *
             * @return A number from 0 to 100 indicating the friendliness of
             * the relationship between p1 and p2. 0 means hostile and 100
             * means best buddies.
             */
            int getRelationship() const;

            /**
             * Sets the relationship level between p1 and p2.
             *
             * @param relationship - A number from 0 to 100 indicating the
             * friendliness of the relationship between p1 and p2.
             */
            void setRelationship(int relationship);

        private:
            enum Mission mMission;
            int mGrant;
            int mSubsidy;
            bool mBoycott;
            int mRelationship;
    };

}

#endif // TREATY_HPP_INCLUDED
