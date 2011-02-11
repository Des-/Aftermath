//      Terrain.cpp -- A terrain type for tiles.
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

#include "Terrain.hpp"

using namespace Aftermath;

Terrain::Terrain(const std::string & name, const std::string & description,
    bool isLand, bool isSea, const Image & image,
    const std::map <const Resource *, double> * probabilities) :
        NamedType(name, description, image), mLand(isLand), mSea(isSea),
        mProbabilities(probabilities) {}

Terrain::~Terrain() {
    delete mProbabilities;
}

bool Terrain::isLandTerrain() const {
    return mLand;
}

bool Terrain::isSeaTerrain() const {
    return mSea;
}

double Terrain::getProbability(const Resource * resource) const {
    iterator itr = mProbabilities->find(resource);
    if (itr != mProbabilities->end()) return itr->second;
    else return 0.0;
}

Terrain::iterator Terrain::begin() const {
    return mProbabilities->begin();
}

Terrain::iterator Terrain::end() const {
    return mProbabilities->end();
}
