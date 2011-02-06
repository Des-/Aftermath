//      Player.cpp -- An Aftermath player.
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

#include "Game.hpp"
#include "GameSettings.hpp"
#include "Industry.hpp"
#include "Mod.hpp"
#include "Player.hpp"
#include "TileGroup.hpp"
#include "Transferable.hpp"
#include "TransportNetwork.hpp"
#include "Treaty.hpp"

using namespace Aftermath;

Player::Player(const std::string & name, Game & game, bool initFromSettings) :
        mName(name), mNation(NULL), mGame(game), mCapital(NULL),
        mHarbor(NULL),mMoney(0), mIndustry(new Industry()),
        mTransport(new TransportNetwork()) {
    give(game.getSettings().getMod().getStartingTypes());
}

Player::~Player() {
    delete mIndustry;
    delete mTransport;
}

const std::string & Player::getName() const {
    return mName;
}

void Player::setName(const std::string & name) {
    mName = name;
}

const Nation * Player::getNation() const {
    return mNation;
}

void Player::setNation(const Nation * nation) {
    mNation = nation;
}

Treaty & Player::getTreaty(const Player * player) {
    return mTreaties[player];
}

const Treaty & Player::getTreaty(const Player * player) const {
    return ((Player *) this)->getTreaty(player);
}

bool Player::canAdd(const TileGroup *& group) const {
    return group->isLand();
}

Count<const Resource *> & Player::getStockpile() {
    return mStockpile;
}

const Count<const Resource *> & Player::getStockpile() const {
    return mStockpile;
}

Collection<const Technology *> & Player::getTechnology() {
    return mTechnology;
}

const Collection<const Technology *> & Player::getTechnology() const {
    return mTechnology;
}

Industry & Player::getIndustry() {
    return *mIndustry;
}

const Industry & Player::getIndustry() const {
    return *mIndustry;
}

TransportNetwork & Player::getTransport() {
    return *mTransport;
}

const TransportNetwork & Player::getTransport() const {
    return *mTransport;
}

Collection<Tile *> & Player::getRevealed() {
    return mRevealed;
}

const Collection<const Tile *> & Player::getRevealed() const {
    return *((const Collection<const Tile *> *) ((void *) &mRevealed));
}

TileGroup * Player::getCapital() {
    return mCapital;
}

const TileGroup * Player::getCapital() const {
    return mCapital;
}

void Player::setCapital(TileGroup * capital) {
    mCapital = capital;
}

TileGroup * Player::getHarbor() {
    return mHarbor;
}

const TileGroup * Player::getHarbor() const {
    return mHarbor;
}

void Player::setHarbor(TileGroup * harbor) {
    mHarbor = harbor;
}

int Player::getMoney() const {
    return mMoney;
}

void Player::giveMoney(int amount) {
    mMoney += amount;
}

void Player::takeMoney(int amount) {
    mMoney -= amount;
}

Game & Player::getGame() {
    return mGame;
}

const Game & Player::getGame() const {
    return mGame;
}

bool Player::placeTileUnit(const TileUnit * unit) {
    // TODO
    return true;
}

void Player::take(const Transferable * type, int amount) {
    type->takeFrom(*this, amount);
}

void Player::take(const Count<const Transferable *> & types) {
    Count<const Transferable *>::const_iterator itr;
    for (itr = types.begin(); itr != types.end(); ++itr)
        take(itr->first, itr->second);
}

bool Player::canTake(const Transferable * type, int amount) const {
    return type->canTakeFrom(*this, amount);
}

bool Player::canTake(const Count<const Transferable *> & types) const {
    Count<const Transferable *>::const_iterator itr;
    for (itr = types.begin(); itr != types.end(); ++itr)
        if (!canTake(itr->first, itr->second)) return false;
    return true;
}

void Player::give(const Transferable * type, int amount) {
    type->giveTo(*this, amount);
}

void Player::give(const Count<const Transferable *> & types) {
    Count<const Transferable *>::const_iterator itr;
    for (itr = types.begin(); itr != types.end(); ++itr)
        give(itr->first, itr->second);
}

bool Player::canGive(const Transferable * type, int amount) const {
    return type->canGiveTo(*this, amount);
}

bool Player::canGive(const Count<const Transferable *> & types) const {
    Count<const Transferable *>::const_iterator itr;
    for (itr = types.begin(); itr != types.end(); ++itr)
        if (!canGive(itr->first, itr->second)) return false;
    return true;
}
