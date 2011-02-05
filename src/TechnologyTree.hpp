//      TechnologyTree.hpp -- The technological advances made by a player.
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

#ifndef TECHNOLOGYTREE_HPP_INCLUDED
#define TECHNOLOGYTREE_HPP_INCLUDED

namespace Aftermath { class TechnologyTree; }

#include "Collection.hpp"
#include "ProductionCenter.hpp"
#include "Technology.hpp"

/**
 * @file TechnologyTree.hpp
 *
 * The technological advances made by a player.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * A TechnologyTree keeps track of what technologies a player has
     * researched and what technologies a player can research. Note that
     * adding a technology to this tree will not deduct its research cost.
     */
    class TechnologyTree : public Collection<const Technology *> {
        public:
            /**
             * Constructs a new TechnologyTree with no technologies.
             */
            TechnologyTree();

            /**
             * Frees this TechnologyTree.
             */
            ~TechnologyTree();

            /**
             * Starts research of the given technology. This deducts the
             * necessary research cost and adds the technology to the queue.
             *
             * @param player - The player to pay for the research.
             * @param technology - The technology to start research of.
             */
            void startResearch(Player & player, const Technology *
                technology);

            /**
             * Cancels a research currently in the research queue. This
             * refunds the resource cost.
             *
             * @param player - The player to refund.
             * @param technology - The technology to cancel the research of.
             */
            void cancelResearch(Player & player, const Technology *
                technology);

            /**
             * Finishes the research that has been started. This adds all
             * researched technologies to this TechnologyTree and clears
             * the research queue. This should be called at the beginning of
             * each player's turn.
             */
            void finishResearch();

        private:
            Collection<const Technology *> mResearching;
    };

}

#endif // TECHNOLOGYTREE_HPP_INCLUDED
