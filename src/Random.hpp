//      Random.hpp -- An interface for generating random numbers.
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

#ifndef RANDOM_HPP_INCLUDED
#define RANDOM_HPP_INCLUDED

/**
 * @file Random.hpp
 *
 * An interface for generating random numbers.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath { namespace Random {

    /** @return A random double (64 bits of randomness). */
    double Double();

    /** @return A random double between min and max, inclusive. */
    double Double(double min, double max);

    /** @return A random float (32 bits of randomness). */
    float Float();

    /** @return A random float between min and max, inclusive. */
    float Float(float min, float max);

    /** @return A random int (32 bits of randomness). */
    int Int();

    /** @return A random int between min and max, inclusive. */
    int Int(int min, int max);

    /** @return A random long (64 bits of randomness). */
    long Long();

    /** @return A random long between min and max, inclusive. */
    long Long(long min, long max);

    /** @return A random uint (32 bits of randomness). */
    unsigned int UInt();

    /** @return A random uint between min and max, inclusive */
    unsigned int UInt(unsigned int min, unsigned int max);

    /** @return A random ulong (64 bits of randomness). */
    unsigned long ULong();

    /** @return A random ulong between min and max, inclusive. */
    unsigned long ULong(unsigned long min, unsigned long max);

} }

#endif // RANDOM_HPP_INCLUDED
