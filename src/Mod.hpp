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

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Count.hpp"
#include "NamedType.hpp"

namespace Aftermath { class Date;
                      class Labor;
                      class MerchantMarine;
                      class Money;
                      class Nation;
                      class ProductionCenterType;
                      class Resource;
                      class SpecialistType;
                      class Technology;
                      class Terrain;
                      class TileAction;
                      class Transferable;
                      class TransportCapacity;
                      class UnitType;
                      class WorkerType;
                      namespace Engine { class App; } }

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
     * images, and more. It loads and manages the application's resources.
     */
    class Mod : public NamedType {
        public:
            /**
             * Constructs a new, empty Mod.
             *
             * @param app - The App using this mod.
             */
            Mod(Engine::App & app);

            /**
             * Frees this mod and all data that it loaded.
             */
            ~Mod();

            /**
             * Loads all assets from the given mod folder.
             *
             * @param path - The path to the root folder of the mod.
             *
             * @return true if loading was successful, false otherwise.
             */
            bool load(const std::string & path);

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
            const Count<const Transferable *> & getStartingTypes() const;

            /**
             * @return The max amount of bids that a country can hold at once.
             */
            int getMaxBids() const;

            /**
             * @return The starting date of this Mod.
             */
            int getStartDate() const;

            /**
             * @return The number that the game date advances by each turn.
             */
            int getDatePerTurn() const;

            /**
             * Searches for the image in this Mod's graphics cache. If the
             * image is not already in the cache, it is loaded from the given
             * path. The image is loaded from "<MOD_ROOT>/images/<imagePath>".
             *
             * @param imagePath - The path of the image to load, relative to
             * the Mod's "images" directory.
             *
             * @return A pointer to a new image from the given image path.
             */
            sf::Image * getImage(const std::string & imagePath);

            /**
             * Gets the image with getImage() and creates a new sprite.
             *
             * @param imagePath - The path of the image to load, relative to
             * the Mod's "images" directory.
             *
             * @return A pointer to a new sprite from the given image path.
             */
            sf::Sprite * newSprite(const std::string & imagePath);

            /**
             * Searches for the font in this Mod's font cache. If the font is
             * not already in the cache, it is loaded from the given path. The
             * font is loaded from "<MOD_ROOT>/fonts/<fontPath>".
             *
             * @param string - The text to display.
             * @param fontPath - Path to the font file, relative to the Mod's
             * "fonts" directory.
             * @param color - The color of the new text.
             * @param characterSize - The size of the font to display.
             */
            sf::Text * newText(const std::string & string,
                    const std::string & fontPath,
                    const sf::Color & color = sf::Color::Black,
                    unsigned int characterSize = 30);

            // TODO: Add sounds and music

        private:
            Engine::App & mApp;
            bool mLoaded;
            std::string mDirectory;

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

            std::map<std::string, sf::Image *> mImages;
            std::map<std::string, sf::Font *> mFonts;

            Count<const Transferable *> mStartingTypes;

            int mMaxBids;
            int mStartDate;
            int mDatePerTurn;
    };

}

#endif // MOD_HPP_INCLUDED
