//      Random.cpp -- An interface for generating random numbers.
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

#include <climits>
#include <ctime>

#include "Random.hpp"

using namespace Aftermath;

static unsigned long x = 123456789UL;
static unsigned long y = 362436069UL;
static unsigned long z = 521288629UL;
static unsigned long w = 88675123UL;

unsigned long xorShift() {
  unsigned long t;
  t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
}

void Random::init() {
    w = time(NULL);
    x ^= xorShift();
    y ^= xorShift();
    z ^= xorShift();
    w ^= x;
}

unsigned long Random::ULong() {
    return xorShift();
}

unsigned long Random::ULong(unsigned long min, unsigned long max) {
    return min + (Random::ULong() % (max - min + 1));
}

unsigned int Random::UInt() {
    return (unsigned int) Random::ULong();
}

unsigned int Random::UInt(unsigned int min, unsigned int max) {
    return min + (Random::UInt() % (max - min + 1));
}

double Random::Double() {
    return (double) Random::ULong() / ULONG_MAX;
}

double Random::Double(double min, double max) {
    return Random::Double() * (max - min) + min;
}

float Random::Float() {
    return (float) Random::ULong() / ULONG_MAX;
}

float Random::Float(float min, float max) {
    return Random::Float() * (max - min) + min;
}
