//      Nation.hpp -- The nation that a player controls.
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

#ifndef NATION_HPP_INCLUDED
#define NATION_HPP_INCLUDED

#include <string>

#include "Graphics.hpp"
#include "NamedType.hpp"

/**
 * @file Nation.hpp
 *
 * The nation that a player controls.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * Nation objects are immutable and are reused from game to game. They
     * represent the historical nation that a Player is controlling. This
     * includes name, description, color, and flag.
     */
    class Nation : public NamedType {
        public:
            /**
             * Constructs a new Nation with the given name, description,
             * color, and flag.
             *
             * @param name - The name of the new nation.
             * @param description - The description of the new nation.
             * @param color - The national color of the new nation (used for
             * coloring units, borders, and maps)
             * @param flag - The flag image of the new nation.
             */
            Nation(const std::string & name, const std::string & description,
                const Color & color, const Image & flag);

            /**
             * Gets the color of this nation. This is used for coloring units,
             * borders, and maps.
             *
             * @return The national color of this nation.
             */
            const Color & getColor() const;

        private:
            Color mColor;
    };

}

#endif // NATION_HPP_INCLUDED
