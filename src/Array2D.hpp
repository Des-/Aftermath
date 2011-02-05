//      Array2D.hpp -- A 2D array.
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

#ifndef ARRAY2D_HPP_INCLUDED
#define ARRAY2D_HPP_INCLUDED

#include <cstdlib>
#include <utility>

/**
 * @file Array2D.hpp
 *
 * A 2D array.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * A generic, 2D array. Access elements using the "(row, column)" member
     * access operator.
     *
     * @param T - The type of data to store in the array.
     */
    template <typename T>
    class Array2D {
        public:
            /**
             * Constructs a new Array2D with the specified dimensions.
             *
             * @param rows - The number of rows in the new array.
             * @param columns - The number of columns in the new array.
             */
            Array2D(unsigned rows, unsigned columns);

            /**
             * Deletes this Array2D and frees any memory used by it.
             */
            ~Array2D();

            /**
             * An operator for member access. Note that elements are not
             * accessed with "[i][j]", rather with "(i, j)". No bounds
             * checking is performed.
             *
             * @param row - The row of the element to access.
             * @param column - The column of the element to access.
             *
             * @return A reference to the desired element.
             */
            T & operator() (unsigned row, unsigned column);

            /**
             * const member access operator.
             *
             * @see operator()
             */
            const T & operator() (unsigned row, unsigned column) const;

            /**
             * Gets the first dimensional size of this array.
             *
             * @return The number of rows in this array.
             */
            unsigned rows() const;

            /**
             * Gets the second dimensional size of this array.
             *
             * @return The number of columns in this array.
             */
            unsigned columns() const;

            /**
             * Locates the given element in this 2D array.
             *
             * @return A pair of unsigned integers whose first value is the
             * row and second value is the column of the given element.
             */
            std::pair<unsigned, unsigned> locate(const T * element) const;

        private:
            T * mArray;
            unsigned mRows, mColumns;
    };

    template <typename T>
    inline Array2D<T>::Array2D(unsigned rows, unsigned columns) :
        mRows(rows), mColumns(columns),
        mArray((T *) malloc(sizeof(T) * rows * columns)) {}

    template <typename T>
    inline Array2D<T>::~Array2D() {
        free(mArray);
    }

    template <typename T>
    inline T & Array2D<T>::operator() (unsigned row, unsigned column) {
        return mArray[row * columns() + column];
    }

    template <typename T>
    inline const T & Array2D<T>::operator()
        (unsigned row, unsigned column) const {
        return mArray[row * columns() + column];
    }

    template <typename T>
    inline unsigned Array2D<T>::rows() const {
        return mRows;
    }

    template <typename T>
    inline unsigned Array2D<T>::columns() const {
        return mColumns;
    }

    template <typename T>
    inline std::pair<unsigned, unsigned> Array2D<T>::locate(const T * element)
        const {
        unsigned index = element - mArray;
        return std::pair<unsigned, unsigned>
            (index / columns(), index % columns());
    }

}

#endif // ARRAY2D_HPP_INCLUDED
