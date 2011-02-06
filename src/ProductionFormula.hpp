//      ProductionFormula.hpp -- A formula with inputs and outputs.
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

#ifndef PRODUCTIONFORMULA_HPP_INCLUDED
#define PRODUCTIONFORMULA_HPP_INCLUDED

#include <map>

#include "Count.hpp"

namespace Aftermath { class Resource;
                      class Transferable; }

/**
 * @file ProductionFormula.hpp
 *
 * A formula with inputs and outputs.
 *
 * @author Kevin Harrison <keharriso@gmail.com>
 */

namespace Aftermath {

    /**
     * ProductionFormulas hold information about the requirements to produce
     * a specified list of products (Transferables).
     */
    class ProductionFormula {
        public:
            /**
             * Constructs a new ProductionFormula with the specified costs and
             * outputs.
             *
             * @param input - The elements required for production.
             * @param output - The elements created by production.
             */
            ProductionFormula(const Count<const Transferable *> * input,
                const Count<const Transferable *> * output);

            /**
             * Frees the costs and outputs of this ProductionFormula.
             */
            ~ProductionFormula();

            /**
             * @return The cost of this production formula.
             */
            const Count<const Transferable *> & getInput() const;

            /**
             * @return The products produced by this formula.
             */
            const Count<const Transferable *> & getOutput() const;

        private:
            const Count<const Transferable *> * mInput;
            const Count<const Transferable *> * mOutput;
    };

}

#endif // PRODUCTIONFORMULA_HPP_INCLUDED
