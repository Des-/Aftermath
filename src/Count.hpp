//      Count.hpp -- A generic count of elements.
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

#ifndef COUNT_HPP_INCLUDED
#define COUNT_HPP_INCLUDED

#include <map>

/**
 * @file Count.hpp
 *
 * A generic count of elements.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * A Count is just a mapping from elements to integers.
     *
     * @param T - The type of elements to count.
     */
    template <typename T>
    class Count : public std::map<T, int> {}

}

#endif // COUNT_HPP_INCLUDED
