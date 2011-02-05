//      GameSettings.hpp -- A game's global settings.
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

#ifndef GAMESETTINGS_HPP_INCLUDED
#define GAMESETTINGS_HPP_INCLUDED

namespace Aftermath { class GameSettings; }

#include <map>
#include <string>

#include "Mod.hpp"

/**
 * @file GameSettings.hpp
 *
 * A game's global settings.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * A GameSettings object holds all of the settings for a run of the game.
     * It holds these settings like a map and can be treated as such. The
     * GameSettings also has a Mod.
     */
    class GameSettings : public std::map<std::string, std::string> {
        public:
            /**
             * Constructs a new GameSettings with the given Mod.
             *
             * @param mod - The mod of this GameSettings.
             */
            GameSettings(const Mod * mod);

            /**
             * Frees this GameSettings object and its Mod.
             */
            ~GameSettings();

            /**
             * Gets the Mod of this GameSettings.
             */
            const Mod & getMod();

        private:
            const Mod * mMod;
    };

}

#endif // GAMESETTINGS_HPP_INCLUDED
