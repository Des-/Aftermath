//      SelectiveCollection.hpp -- A collection that chooses whether or not to
//                                 accept elements.
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

#ifndef SELECTIVECOLLECTION_HPP_INCLUDED
#define SELECTIVECOLLECTION_HPP_INCLUDED

#include "Collection.hpp"

/**
 * @file SelectiveCollection.hpp
 *
 * A collection that chooses whether or not to accept elements.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * A SelectiveCollection is a type of collection that decides whether or
     * not to accept its elements.
     */
    template <typename T>
    class SelectiveCollection : public Collection<T> {
        public:
            /**
             * Virtual destructor for selective collections. Does nothing.
             */
            virtual ~SelectiveCollection();

            /**
             * Returns whether or not this collection supports adding the
             * given element. If canAdd() returns false, then attempting to
             * add() the given element does nothing.
             *
             * @param element - The element to test for support.
             *
             * @return true if this collection supports adding the given
             * element, false otherwise.
             */
            virtual bool canAdd(const T & element) const = 0;

            /**
             * Adds an element to this collection. If canAdd() returns false
             * for the given element, or the element already exists in this
             * collection, then this method does nothing.
             *
             * @param element - The element to add.
             */
            virtual void add(const T & element);
    };

    template <typename T>
    virtual SelectiveCollection<T>::~SelectiveCollection();

    template <typename T>
    virtual void SelectiveCollection<T>::add(const T & element) {
        if(canAdd(element))
            Collection<T>::add(element);
    }

}

#endif // SELECTIVECOLLECTION_HPP_INCLUDED
