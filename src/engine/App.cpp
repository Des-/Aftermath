//      App.cpp -- The game application.
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

#include "App.hpp"
#include "MenuState.hpp"
#include "SplashState.hpp"

using namespace Aftermath::Engine;

#define MOD_FOLDER              "mods/"
#define CONFIG_FILE             "settings.cfg"
#define DEFAULT_LOG             "log.txt"
#define DEFAULT_LOOP_PERIOD     0.1f
#define DEFAULT_WIDTH           640u
#define DEFAULT_HEIGHT          480u
#define DEFAULT_BPP             32u
#define DEFAULT_SYLE            sf::Style::Default
#define DEFAULT_DEPTH           24u
#define DEFAULT_STENCIL         8u
#define DEFAULT_ANTIALIASING    0u
#define DEFAULT_MAJOR           2u
#define DEFAULT_MINOR           0u

#define DEFAULT_MOD             "Aix-La-Chapelle"
#define MOD                     "application.game.mod"
#define LOGGING_OPTION          "application.logging.enabled"
#define LOG_FILE                "application.logging.file"
#define VIDEO                   "application.video"

App::App(const std::string & title) : mRunning(false), mTitle(title),
    mStateManager(*this), mMod(*this) {}

void App::handleArgs(int argc, char * argv[]) {}

void App::init() {
    mRunning = false;
    mLoopPeriod = DEFAULT_LOOP_PERIOD;
    mExitCode = 0;
    try {
        // Read application config file
        mConfig.readFile(CONFIG_FILE);
        // Set up logging
        if (mConfig.lookup(LOGGING_OPTION)) {
            mLogger.open((const char *) mConfig.lookup(LOG_FILE));
            mLogger << "Config file loaded: '" << CONFIG_FILE << "'"
                    << std::endl;
        }
    } catch (libconfig::FileIOException & e) {
        // Error reading config file
        mLogger.open(DEFAULT_LOG);
        mLogger << "Error reading config file: '" << CONFIG_FILE << "'"
                << std::endl;
    } catch (libconfig::ParseException & e) {
        // Error parsing config file
        mLogger.open(DEFAULT_LOG);
        mLogger << "Error parsing config file: '" << CONFIG_FILE << "'"
                << std::endl << "line " << e.getLine() << ": " << e.getError()
                << std::endl;
    } catch (libconfig::SettingException & e) {
        // Error reading log file setting
        mLogger.open(DEFAULT_LOG);
        mLogger << "Config file loaded: '" << CONFIG_FILE << "'" << std::endl
                << "Error reading log file setting: " << LOG_FILE << std::endl
                << "Using default log file: " << DEFAULT_LOG << std::endl;
    }
    // Read mod information
    std::string mod = DEFAULT_MOD;
    if (!mConfig.lookupValue(MOD, mod))
        mLogger << "Mod configuration not found, using default" << std::endl;
    if (!mMod.load(MOD_FOLDER + mod))
        mLogger << "Error loading mod" << std::endl;
    // Read window config
    sf::VideoMode mode(DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_BPP);
    unsigned long style = DEFAULT_SYLE;
    sf::ContextSettings settings(DEFAULT_DEPTH, DEFAULT_STENCIL,
        DEFAULT_ANTIALIASING, DEFAULT_MAJOR, DEFAULT_MINOR);
    bool vsync = false;
    bool fullscreen = false;
    try {
        libconfig::Setting & video = mConfig.lookup(VIDEO);
        video.lookupValue("width", mode.Width);
        video.lookupValue("height", mode.Height);
        video.lookupValue("bpp", mode.BitsPerPixel);
        video.lookupValue("depth", settings.DepthBits);
        video.lookupValue("stencil", settings.StencilBits);
        video.lookupValue("antialiasing", settings.AntialiasingLevel);
        video.lookupValue("vsync", vsync);
        video.lookupValue("fullscreen", fullscreen);
    } catch (libconfig::SettingException & e) {
        mLogger << "Video settings not found: '" << VIDEO << "'" << std::endl
                << "Using default video settings" << std::endl;
    }
    if (fullscreen) {
        style = sf::Style::Fullscreen;
        if (!mode.IsValid()) {
            mLogger << "Video settings invalid, using defaults" << std::endl;
            mode.Width = DEFAULT_WIDTH;
            mode.Height = DEFAULT_HEIGHT;
            mode.BitsPerPixel = DEFAULT_BPP;
        }
    }

    // Create window
    mWindow.Create(mode, mTitle, style, settings);
    mLogger << "Window created" << std::endl;

    // Initialize states
    mStateManager.addState(new(std::nothrow) MenuState(*this));
    mStateManager.addState(new(std::nothrow) SplashState("InitialSplash",
        3.0f, "gui/splash.png", *this));
}

void App::run() {
    mLogger << "App running" << std::endl;
    mRunning = true;

    sf::Clock updateClock;
    updateClock.Reset();

    float nextUpdate = updateClock.GetElapsedTime();

    if(mStateManager.isEmpty()) {
        // There is no active state
        mLogger << "No active state" << std::endl;
    }

    while(isRunning() && mWindow.IsOpened() && !mStateManager.isEmpty()) {
        State * state = mStateManager.getActiveState();

        // Create a fixed rate Update loop
        while(updateClock.GetElapsedTime() > nextUpdate) {
            // Handle some events and let the current active state handle the rest
            sf::Event event;
            while(mWindow.GetEvent(event)) {
                // Switch on Event Type
                switch(event.Type) {
                    case sf::Event::Closed:       // Window closed
                        stopRunning(0);
                        break;
                    case sf::Event::GainedFocus:  // Window gained focus
                        state->resume();
                        break;
                    case sf::Event::LostFocus:    // Window lost focus
                        state->pause();
                        break;
                    case sf::Event::Resized:      // Window resized
                        break;
                    default:
                        // Let the currently active state handle it
                        state->handleEvent(event);
                }
            }
            state->update();
            nextUpdate += mLoopPeriod;
        }

        // Let the current active state draw itself
        state->draw();

        // Display Render window to the screen
        mWindow.Display();

        // Handle Cleanup of any recently removed states
        mStateManager.cleanup();
    }
    mLogger << "App stopped" << std::endl;
}

void App::cleanup() {
    // Close the Render window if it is still open
    if(mWindow.IsOpened()) {
        mWindow.ShowMouseCursor(true);
        mWindow.Close();
    }
    // Output to log file
    mLogger << "Cleanup completed" << std::endl;
}

int App::getExitCode() const {
    return mExitCode;
}

bool App::isRunning() const {
    return mRunning;
}

void App::stopRunning(int exitCode) {
    mExitCode = exitCode;
    mRunning = false;
}

libconfig::Config & App::getConfig() {
    return mConfig;
}

float App::getLoopFrequency() const {
    return 1.0f / mLoopPeriod;
}

void App::setLoopFrequency(float frequency) {
    mLoopPeriod = 1.0f / frequency;
}

Logger & App::getLogger() {
    return mLogger;
}

StateManager & App::getStateManager() {
    return mStateManager;
}

sf::RenderWindow & App::getWindow() {
    return mWindow;
}

Aftermath::Mod & App::getMod() {
    return mMod;
}
