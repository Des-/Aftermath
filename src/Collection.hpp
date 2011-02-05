//      Collection.hpp -- A generic collection.
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

#ifndef COLLECTION_HPP_INCLUDED
#define COLLECTION_HPP_INCLUDED

#include <set>

/**
 * @file Collection.hpp
 *
 * A generic collection.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * Collection is a generic collection class for groups of objects.
     * Collections support adding, removing, and iteration.
     *
     * @param T - The type of objects to store in this collection.
     */
    template <typename T>
    class Collection {
        public:
            typedef std::set<T>::iterator iterator;
            typedef std::set<const T>::const_iterator const_iterator;

            /**
             * Virtual collection destructor. Does nothing.
             */
            virtual ~Collection();

            /**
             * Adds an element to this collection. If the element is already
             * in this Collection, then this function does nothing.
             *
             * @param element - The element to add.
             */
            virtual void add(const T & element);

            /**
             * Removes an element from this collection.
             *
             * @param element - The element to remove.
             */
            virtual void remove(const T & element);

            /**
             * Removes all elements from this collection.
             */
            void clear();

            /**
             * Finds if this collection contains the given element.
             *
             * @param element - The element to search for.
             *
             * @return true if this collection contains the element, false
             * otherwise.
             */
            bool contains(const T & element) const;

            /**
             * Returns an iterator at the first element in this collection.
             *
             * @return An iterator starting at the first element.
             */
            iterator begin();

            /**
             * Returns a const iterator to the first element.
             *
             * @see begin()
             */
            const_iterator begin() const;

            /**
             * Returns an iterator past the last element in this collection.
             *
             * @return An iterator past the end of this collection.
             */
            iterator end();

            /**
             * Returns a const iterator past the last element.
             *
             * @see end()
             */
            const_iterator end() const;

            /**
             * Gets the number of elements in this Collection.
             *
             * @return The number of elements, as an unsigned integer.
             */
            unsigned size() const;

        private:
            std::set<T> mElements;
    };

    template <typename T>
    virtual Collection<T>::~Collection() {}

    template <typename T>
    virtual void Collection<T>::add(const T & element) {
        mElements.insert(element);
    }

    template <typename T>
    virtual void Collection<T>::remove(const T & element) {
        mElements.erase(element);
    }

    template <typename T>
    void Collection<T>::clear() {
        mElements.clear();
    }

    template <typename T>
    inline bool Collection<T>::contains(const T & element) const {
        return mElements.find(element) != end();
    }

    template <typename T>
    inline Collection<T>::iterator Collection<T>::begin() {
        return mElements.begin();
    }

    template <typename T>
    inline Collection<T>::const_iterator Collection<T>::begin() const {
        return mElements.begin();
    }

    template <typename T>
    inline Collection<T>::iterator Collection<T>::end() {
        return mElements.end();
    }

    template <typename T>
    inline Collection<T>::const_iterator Collection<T>::end() const {
        return mElements.end();
    }

    template <typename T>
    inline unsigned Collection<T>::size() const {
        return mElements.size();
    }

}

#endif // COLLECTION_HPP_INCLUDED
