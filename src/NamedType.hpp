//      NamedType.hpp -- A type with a name and an image.
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

#ifndef NAMEDTYPE_HPP_INCLUDED
#define NAMEDTYPE_HPP_INCLUDED

#include <string>

#include "Graphics.hpp"

/**
 * @file NamedType.hpp
 *
 * A type with a name and an image.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * NamedType is a base class for all named types like resource types,
     * unit types, and nations.
     */
    class NamedType {
        public:
            /**
             * Constructs a new NamedType with an empty name and description
             * and no image.
             */
            NamedType();

            /**
             * Constructs a new NamedType type with the given name,
             * description, and image.
             *
             * @param name - The name of the new type.
             * @param description - A brief description of the type.
             * @param image - The image of the type.
             */
            NamedType(const std::string & name, const std::string &
                description, const Image & image);

            /**
             * Virtual destructor for NamedType.
             */
            virtual ~NamedType();

            /**
             * Gets the name of this type.
             *
             * @return A constant reference to the name of this type.
             */
            const std::string & getName() const;

            /**
             * Gets the description of this type.
             *
             * @return A constant reference this type's brief description.
             */
            const std::string & getDescription() const;


            /**
             * Gets the image of this type.
             *
             * @return The image of this type.
             */
            const Image & getImage() const;

        protected:
            /**
             * Sets the name of this type.
             *
             * @param name - The new name of this type.
             */
            void setName(const std::string & name);

            /**
             * Sets the description of this type.
             *
             * @param description - The new description of this type.
             */
            void setDescription(const std::string & description);

            /**
             * Sets the image of this type.
             *
             * @param image - The new image of this type.
             */
            void setImage(const Image & image);

        private:
            std::string mName;
            std::string mDescription;
            const Image & mImage;
    };

}

#endif // NAMEDTYPE_HPP_INCLUDED
