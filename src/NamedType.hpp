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

// TODO: Decide for certain what graphics library to use.
#include <SFML/Graphics/Image.hpp>

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
     * unit types, and nations. This type should be immutable.
     */
    class NamedType {
        public:
            /**
             * Constructs a new NamedType type with the given name,
             * description, and image.
             *
             * @param name - The name of the new type.
             * @param description - A brief description of the type.
             * @param image - The image of the type.
             */
            Type(const std::string & name, const std::string &
                description, const sf::Image * image);

            /**
             * Virtual destructor for NamedType. Frees the image of this type.
             */
            virtual ~Type();

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
            const sf::Image & getImage() const;

        private:
            std::string mName;
            std::string mDescription;
            const sf::Image * mImage;
    };

}

#endif // NAMEDTYPE_HPP_INCLUDED
