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
             * Constructs a new NamedType type with the given name,
             * description, and image.
             *
             * @param name - The name of the new type.
             * @param description - A brief description of the type.
             * @param image - The image path of this named type.
             */
            NamedType(const std::string & name, const std::string &
                description, const std::string & image);

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
             * Gets the image path of this type.
             *
             * @return A constant reference this type's image path.
             */
            const std::string & getImage() const;

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
             * Sets the image path of this type.
             *
             * @param image - The path to the new image of this type.
             */
            void setImage(const std::string & image);

        private:
            std::string mName;
            std::string mDescription;
            std::string mImage;
    };

}

#endif // NAMEDTYPE_HPP_INCLUDED
