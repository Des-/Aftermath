//      App.hpp -- The game application.
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

#ifndef APP_HPP_INCLUDED
#define APP_HPP_INCLUDED

#include <string>

#include <libconfig.h++>

#include <SFML/Graphics/RenderWindow.hpp>

#include "Logger.hpp"
#include "Mod.hpp"
#include "StateManager.hpp"

/**
 * @file App.hpp
 *
 * The game application.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath { namespace Engine {

    /**
     * An App is an instance of the game application.
     */
    class App {
        public:
            /**
             * Creates a new application with the given window title.
             *
             * @param title - The title of this application's window.
             */
            App(const std::string & title);

            /**
             * Handles the given command line arguments.
             *
             * @param argc - The number of arguments.
             * @param argv - The arguments themselves.
             */
            void handleArgs(int argc, char *argv[]);

            /**
             * Initializes the application.
             */
            void init();

            /**
             * Runs the game engine until the application is exited.
             */
            void run();

            /**
             * Releases the application's resources.
             */
            void cleanup();

            /**
             * @return The exit code of the application.
             */
            int getExitCode() const;

            /**
             * @return true if the application is running; false otherwise.
             */
            bool isRunning() const;

            /**
             * Stops the application.
             */
            void stopRunning(int exitCode);

            /**
             * @return The configuration of the application.
             */
            libconfig::Config & getConfig();

            /**
             * @return The frequency of this App's loop, in Hertz.
             */
            float getLoopFrequency() const;

            /**
             * Sets the frequency of this App's loop, in Hertz.
             */
            void setLoopFrequency(float frequency);

            /**
             * @return The Logger of this App, used to write to the log file.
             */
            Logger & getLogger();

            /**
             * @return The StateManager of this App, used to manage multiple
             * game states.
             */
            StateManager & getStateManager();

            /**
             * @return The RenderWindow of this App, used in rendering to the
             * screen.
             */
            sf::RenderWindow & getWindow();

            /**
             * @return The Mod that this App is using.
             */
            Mod & getMod();

        private:
            bool mRunning;
            float mLoopPeriod;
            int mExitCode;
            libconfig::Config mConfig;
            Logger mLogger;
            std::string mTitle;
            sf::RenderWindow mWindow;
            StateManager mStateManager;
            Mod mMod;
    };

} }

#endif // APP_HPP_INCLUDED
