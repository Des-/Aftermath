//      ProductionLevel.hpp -- The level of a ProductionCenter.
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

#ifndef PRODUCTIONLEVEL_HPP_INCLUDED
#define PRODUCTIONLEVEL_HPP_INCLUDED

namespace Aftermath { class ProductionLevel; }

#include "Count.hpp"
#include "NamedType.hpp"

/**
 * @file ProductionLevel.hpp
 *
 * The level of a ProductionCenter.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * A ProductionLevel is the Level of a ProductionCenter. In addition to
     * the properties that a Level must have, a ProductionLevel has a max
     * output.
     */
    class ProductionLevel : public Level {
        public:
            /**
             * Constructs a new ProductionLevel with the given monetary,
             * resource, and research cost.
             *
             * @param cost - The cost of upgrading to this level.
             * @param maxOutput - The maximum output for any single product.
             */
            ProductionLevel(const Count<const NamedType *> * cost,
                int maxOutput);

            /**
             * The production of any single product cannot surpass the
             * production capacity.
             *
             * @return The maximum output possible for any single product.
             */
            int getMaxOutput() const;

        private:
            int mMaxOutput;
    };

}

#endif // PRODUCTIONLEVEL_HPP_INCLUDED
