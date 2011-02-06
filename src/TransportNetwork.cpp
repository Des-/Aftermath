//      TransportNetwork.cpp -- A player's network of resource transport.
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

#include "Player.hpp"
#include "TransportNetwork.hpp"

using namespace Aftermath;

int TransportNetwork::getAvailable(const Resource * resource) const {
    return mAvailable.getCount(resource);
}

void TransportNetwork::addAvailable(const Resource * resource, int amount) {
    mAvailable[resource] += amount;
}

void TransportNetwork::removeAvailable(const Resource * resource,
        int amount) {
    mAvailable[resource] -= amount;
}

int TransportNetwork::getTransporting(const Resource * resource) const {
    return mTransporting.getCount(resource);
}

void TransportNetwork::startTransporting(const Resource * resource,
        int amount) {
    mTransporting[resource] += amount;
}

void TransportNetwork::stopTransporting(const Resource * resource,
        int amount) {
    mTransporting[resource] -= amount;
}

void TransportNetwork::finishTransporting(Player & player) {
    player.give(*((Count<const Transferable *> *) &mTransporting));
}

int TransportNetwork::getTotalTransporting() const {
    return mTransporting.getTotal();
}

int TransportNetwork::getTrading(const Resource * resource) const {
    return mTrading.getCount(resource);
}

void TransportNetwork::startTrading(Player & player, const Resource *
        resource, int amount) {
    player.take((const Transferable *) resource, amount);
    mTrading[resource] += amount;
}

void TransportNetwork::stopTrading(Player & player, const Resource * resource,
        int amount) {
    player.give((const Transferable *) resource, amount);
    mTrading[resource] -= amount;
}

void TransportNetwork::finishTrade(Player & player, const Resource * resource,
        int amount) {
    player.give((const Transferable *) resource, amount);
    mTrading[resource] -= amount;
}

const Collection<const Resource *> & TransportNetwork::getBidding() const {
    return mBidding;
}

void TransportNetwork::startBidding(const Resource * resource) {
    mBidding.add(resource);
}

void TransportNetwork::cancelBidding(const Resource * resource) {
    mBidding.add(resource);
}

int TransportNetwork::getCapacity() const {
    return mCapacity;
}

void TransportNetwork::addCapacity(int capacity) {
    mCapacity += capacity;
}

int TransportNetwork::getMerchantMarine() const {
    return mMarine;
}

void TransportNetwork::addMerchantMarine(int capacity) {
    mMarine += capacity;
}

