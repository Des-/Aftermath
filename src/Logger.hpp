//      Logger.hpp -- Logs to a file.
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

#ifndef LOGGER_HPP_INCLUDED
#define LOGGER_HPP_INCLUDED

#include <fstream>
#include <string>

/**
 * @file App.hpp
 *
 * Logs to a file.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath { namespace Engine {

    /**
     * A Logger acts as a selective output stream. Logging can be stopped and
     * resumed at will.
     */
    class Logger {
        public:
            /**
             * Consructs a new Logger without a log file.
             */
            Logger();

            /**
             * Opens the given file for logging.
             *
             * @param logFile - The file to log to.
             */
            void open(const std::string & logFile);

            /**
             * Closes the log file of this Logger.
             */
            void close();

            /**
             * Temporarily stops logging. Logging can be resumed by calling
             * open() or resume().
             */
            void stop();

            /**
             * Resumes logging after a call to stop().
             */
            void resume();

            /**
             * @return true if this logger has an open log file; false
             * otherwise.
             */
            bool isOpen() const;

            /**
             * @return true if this logger has an open log file and is not
             * temporarily stopped by a call to stop(); false otherwise.
             */
            bool isLogging() const;

            /**
             * Stream operator. Writes value to the log if this Logger is
             * actively logging.
             *
             * @param value - The value to log.
             */
            template <typename T>
            Logger & operator <<(const T & value) {
                if (isLogging()) mStream << value;
                return *this;
            }

            /**
             * Overloaded stream operator for stream manipulators.
             */
            Logger & operator <<(std::ostream & (*manip)(std::ostream &)) {
                if (isLogging()) mStream << manip;
                return *this;
            }


        private:
            bool mLogging;
            std::ofstream mStream;
    };

} }

#endif // LOGGER_HPP_INCLUDED
