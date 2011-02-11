//      Mod.cpp -- A class to handle loading external data files.
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

#include "Date.hpp"
#include "Labor.hpp"
#include "MerchantMarine.hpp"
#include "Mod.hpp"
#include "Money.hpp"
#include "Nation.hpp"
#include "ProductionCenterType.hpp"
#include "Resource.hpp"
#include "SpecialistType.hpp"
#include "Technology.hpp"
#include "Terrain.hpp"
#include "TileAction.hpp"
#include "TransportCapacity.hpp"
#include "UnitType.hpp"
#include "WorkerType.hpp"

using namespace Aftermath;

Mod::Mod(const std::string & directory) : mDirectory(directory) {
    // TODO
}

Mod::~Mod() {
    delete mDate;
    delete mLabor;
    delete mMerchantMarine;
    delete mMoney;
    delete mTransportCapacity;

    #define DELETE_EACH(T, MAP) { \
        std::map<std::string, const T *>::iterator itr; \
        for (itr = MAP.begin(); itr != MAP.end(); ++itr) delete itr->second; \
    }

    DELETE_EACH(Nation, mNations);
    DELETE_EACH(ProductionCenterType, mProductionCenterTypes);
    DELETE_EACH(Resource, mResources);
    DELETE_EACH(SpecialistType, mSpecialistTypes);
    DELETE_EACH(Technology, mTechnology);
    DELETE_EACH(Terrain, mTerrain);
    DELETE_EACH(TileAction, mTileActions);
    DELETE_EACH(UnitType, mUnitTypes);
    DELETE_EACH(WorkerType, mWorkerTypes);
    DELETE_EACH(Image, mImages);

    #undef DELETE_EACH
}

const Date * Mod::getDate() const {
    return mDate;
}

const Labor * Mod::getLabor() const {
    return mLabor;
}

const MerchantMarine * Mod::getMerchantMarine() const {
    return mMerchantMarine;
}

const Money * Mod::getMoney() const {
    return mMoney;
}

const TransportCapacity * Mod::getTransportCapacity() const {
    return mTransportCapacity;
}

const std::map<std::string, const Nation *> & Mod::getNations() const {
    return mNations;
}

const std::map<std::string, const ProductionCenterType *> &
        Mod::getProductionCenterTypes() const {
    return mProductionCenterTypes;
}

const std::map<std::string, const Resource *> & Mod::getResources() const {
    return mResources;
}

const std::map<std::string, const SpecialistType *> &
        Mod::getSpecialistTypes() const {
    return mSpecialistTypes;
}

const std::map<std::string, const Technology *> & Mod::getTechnology() const {
    return mTechnology;
}

const std::map<std::string, const Terrain *> & Mod::getTerrain() const {
    return mTerrain;
}

const std::map<std::string, const TileAction *> &
        Mod::getTileActions() const {
    return mTileActions;
}

const std::map<std::string, const UnitType *> & Mod::getUnitTypes() const {
    return mUnitTypes;
}

const std::map<std::string, const WorkerType *> &
        Mod::getWorkerTypes() const {
    return mWorkerTypes;
}

const Count<const Transferable *> & Mod::getStartingTypes() const {
    return mStartingTypes;
}

int Mod::getMaxBids() const {
    return mMaxBids;
}

int Mod::getStartDate() const {
    return mStartDate;
}

int Mod::getDatePerTurn() const {
    return mDatePerTurn;
}

const Image & Mod::getImage(const std::string & imagePath) {
    // TODO
}
