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
             * @param flag - The flag image of the new nation.
             * @param r - The red component of the national color.
             * @param g - The green component of the national color.
             * @param b - The blue component of the national color.
             * @param a - The alpha component of the national color.
             */
            Nation(const std::string & name, const std::string & description,
                const std::string & flag, unsigned char r, unsigned char g,
                unsigned char b, unsigned char a);

            /**
             * @return The red component of the national color.
             */
            unsigned char getRed() const;

            /**
             * @return The green component of the national color.
             */
            unsigned char getGreen() const;

            /**
             * @return The blue component of the national color.
             */
            unsigned char getBlue() const;

            /**
             * @return The alpha component of the national color.
             */
            unsigned char getAlpha() const;

        private:
            unsigned char mR, mG, mB, mA;
    };

}

#endif // NATION_HPP_INCLUDED
