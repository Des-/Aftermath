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

#include "App.hpp"
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

#define FONT_DIR "/fonts/"
#define IMAGE_DIR "/images/"
#define MOD_IMAGE "icon.png"

Mod::Mod(Engine::App & app) : NamedType("", "", ""), mApp(app),
        mLoaded(false) {
    mApp.getLogger() << "Mod constructed" << std::endl;
}

Mod::~Mod() {
    mApp.getLogger() << "Freeing Mod" << std::endl;
    delete mDate;
    delete mLabor;
    delete mMerchantMarine;
    delete mMoney;
    delete mTransportCapacity;

    #define DELETE_EACH(T, MAP) { \
        std::map<std::string, T *>::iterator itr; \
        for (itr = MAP.begin(); itr != MAP.end(); ++itr) delete itr->second; \
    }

    DELETE_EACH(const Nation, mNations);
    DELETE_EACH(const ProductionCenterType, mProductionCenterTypes);
    DELETE_EACH(const Resource, mResources);
    DELETE_EACH(const SpecialistType, mSpecialistTypes);
    DELETE_EACH(const Technology, mTechnology);
    DELETE_EACH(const Terrain, mTerrain);
    DELETE_EACH(const TileAction, mTileActions);
    DELETE_EACH(const UnitType, mUnitTypes);
    DELETE_EACH(const WorkerType, mWorkerTypes);
    DELETE_EACH(sf::Image, mImages);
    DELETE_EACH(sf::Font, mFonts);

    #undef DELETE_EACH
}

bool Mod::load(const std::string & path) {
    mApp.getLogger() << "Loading mod: '" << path << "'" << std::endl;
    mDirectory = path;
    // TODO
    return false;
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

sf::Sprite * Mod::newSprite(const std::string & imagePath) {
    sf::Image * img = mImages[imagePath];
    if (img == NULL) {
        img = new sf::Image();
        if(img->LoadFromFile(mDirectory + IMAGE_DIR + imagePath))
             mApp.getLogger() << "Image loaded: '" << imagePath << "'"
                              << std::endl;
        else mApp.getLogger() << "Error loading image: '" << imagePath << "'"
                              << std::endl;
        mImages[imagePath] = img;
    }
    return new sf::Sprite(*img);
}

sf::Text * Mod::newText(const std::string & string, const std::string &
        fontPath, unsigned int characterSize) {
    sf::Font * font = mFonts[fontPath];
    if (font == NULL) {
        font = new sf::Font();
        if(font->LoadFromFile(mDirectory + FONT_DIR + fontPath))
             mApp.getLogger() << "Font loaded: '" << fontPath << "'"
                              << std::endl;
        else mApp.getLogger() << "Error loading font: '" << fontPath << "'"
                              << std::endl;
        mFonts[fontPath] = font;
    }
    return new sf::Text(string, *font, characterSize);
}
