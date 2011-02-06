//      Graphics.hpp -- An interface for graphical elements.
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

#ifndef GRAPHICS_HPP_INCLUDED
#define GRAPHICS_HPP_INCLUDED

// TODO: Decide for certain what graphics library to use.
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>

/**
 * @file Graphics.hpp
 *
 * An interface for graphical elements.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    typedef sf::Color Color;
    typedef sf::Image Image;

}

#endif // GRAPHICS_HPP_INCLUDED

