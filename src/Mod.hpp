//      Mod.hpp -- A class to handle loading external data files.
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

#ifndef MOD_HPP_INCLUDED
#define MOD_HPP_INCLUDED

#include <map>
#include <string>

#include "Collection.hpp"
#include "Date.hpp"
#include "Labor.hpp"
#include "MerchantMarine.hpp"
#include "Money.hpp"
#include "NamedType.hpp"
#include "Nation.hpp"
#include "ProductionCenterType.hpp"
#include "Resource.hpp"
#include "SpecialistType.hpp"
#include "Technology.hpp"
#include "Terrain.hpp"
#include "TileAction.hpp"
#include "TransportCapacity.hpp"
#include "UnitType.hpp"
#include "WorkerTypes.hpp"

/**
 * @file Mod.hpp
 *
 * A class to handle loading external data files.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * A Mod is a pack of tiles, resources, nations, units, technologies,
     * images, and more.
     */
    class Mod : public NamedType {
        public:
            /**
             * Constructs a new Mod and loads all data from the given root
             * directory.
             *
             * @param directory - The root directory of the Mod to load.
             */
            Mod(const std::string & directory);

            /**
             * Frees this mod and all data that it loaded.
             */
            ~Mod();

            /**
             * @return The single Date type of this Mod.
             */
            const Date * getDate() const;

            /**
             * @return The single Labor type of this Mod.
             */
            const Labor * getLabor() const;

            /**
             * @return The single MerchantMarine type of this Mod.
             */
            const MerchantMarine * getMerchantMarine() const;

            /**
             * @return The single Money type of this Mod.
             */
            const Money * getMoney() const;

            /**
             * @return The single TransportCapacity of this Mod.
             */
            const TransportCapacity * getTransportCapacity() const;

            /**
             * @return A map of all Nation types in this Mod (indexed by their
             * names).
             */
            const std::map<std::string, const Nation *> &
                getNations() const;

            /**
             * @return A map of all ProductionCenterTypes in this Mod (indexed
             * by their names).
             */
            const std::map<std::string, const ProductionCenterType *> &
                getProductionCenterTypes() const;

            /**
             * @return A map of all Resource types in this Mod (indexed by
             * their names).
             */
            const std::map<std::string, const Resource *> &
                getResources() const;

            /**
             * @return A map of all SpecialistTypes in this Mod (indexed by
             * thier names).
             */
            const std::map<std::string, const SpecialistType *> &
                getSpecialistTypes() const;

            /**
             * @return A map of all Technology types in this Mod (indexed by
             * their names).
             */
            const std::map<std::string, const Technology *> &
                getTechnology() const;

            /**
             * @return A map of all Terrain types in this Mod (indexed by
             * their names).
             */
            const std::map<std::string, const Terrain *> &
                getTerrain() const;

            /**
             * @return A map of all TileAction types in this Mod (indexed by
             * thier names).
             */
            const std::map<std::string, const TileAction *> &
                getTileActions() const;

            /**
             * @return A map of all UnitTypes in this Mod (indexed by their
             * names).
             */
            const std::map<std::string, const UnitType *> &
                getUnitTypes() const;

            /**
             * @return A map of all WorkerTypes in this Mod (indexed by their
             * names).
             */
            const std::map<std::string, const WorkerType *> &
                getWorkerTypes() const;

            /**
             * @return A Count of all types that a player starts out with on
             * a new map.
             */
            const Count<const NamedType *> & getStartingTypes() const;

            /**
             * @return The max amount of bids that a country can hold at once.
             */
            int getMaxBids() const;

        private:
            const Date * mDate;
            const Labor * mLabor;
            const MerchantMarine * mMerchantMarine;
            const Money * mMoney;
            const TransportCapacity * mTransportCapacity;
            std::map<std::string, const Nation *> mNations;
            std::map<std::string, const ProductionCenterType *>
                mProductionCenterTypes;
            std::map<std::string, const Resource *> mResources;
            std::map<std::string, const SpecialistType *> mSpecialistTypes;
            std::map<std::string, const Technology *> mTechnology;
            std::map<std::string, const Terrain *> mTerrain;
            std::map<std::string, const TileAction *> mTileActions;
            std::map<std::string, const UnitType *> mUnitTypes;
            std::map<std::string, const WorkerType *> mWorkerTypes;

            Count<const NamedType *> mStartingTypes;

            int mMaxBids;
    };

}

#endif // MOD_HPP_INCLUDED
