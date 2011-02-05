//      Industry.hpp -- A player's production capabilities.
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

#ifndef INDUSTRY_HPP_INCLUDED
#define INDUSTRY_HPP_INCLUDED

#include "Collection.hpp"
#include "Count.hpp"
#include "ProductionCenter.hpp"
#include "WorkerType.hpp"

/**
 * @file Industry.hpp
 *
 * A player's production capabilities.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * An Industry represents the production capabilities of a player. It has
     * a labor supply and a group of ProductionCenters for the workers to work
     * at.
     */
    class Industry : public Collection<ProductionCenter *> {
        public:
            /**
             * Constructs a new, empty Industry.
             */
            Industry();

            /**
             * Frees the ProductionCenters in this industry.
             */
            ~Industry();

            /**
             * @param type - The type of worker to count.
             *
             * @return The number of workers of the given type in the labor
             * pool.
             */
            int countWorkers(const WorkerType * type) const;

            /**
             * Adds a number of workers to the labor pool.
             *
             * @param type - The type of the workers to add.
             * @param amount - The amount of the workers to add.
             */
            void addWorkers(const WorkerType * type, int amount);

            /**
             * Removes a given number of workers from the labor pool.
             *
             * @param type - The type of workers to remove.
             * @param amount - The amount of workers to remove.
             */
            void removeWorkers(const WorkerType * type, int amount);

            /**
             * Gets the maximum labor output per turn. This is affected by the
             * supply of workers.
             *
             * @return The maximum labor output per turn.
             */
            int getMaxLabor() const;

            /**
             * @return The amount of labor that is being used this turn.
             */
            int getAllocatedLabor() const;

            /**
             * Gets the amount of labor that has yet to be allocated.
             *
             * @return getMaxLabor() minus getAllocatedLabor()
             */
            int getFreeLabor() const;

            /**
             * Allocates the given amount of labor.
             *
             * @param amount - The amount of labor to allocate. This can be
             * negative.
             */
            void allocateLabor(int amount);

        private:
            Count<const WorkerType *> mWorkers;
            int mAllocated;
    };

}

#endif // INDUSTRY_HPP_INCLUDED
