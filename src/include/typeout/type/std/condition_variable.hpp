/*
 * @COPYRIGHT@
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE
 */

// typeout/type/std/condition_variable.hpp

/** // doc: typeout/type/std/condition_variable.hpp {{{
 * \file typeout/type/std/condition_variable.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TYPEOUT_TYPE_STD_CONDITION_VARIABLE_HPP_INCLUDED
#define TYPEOUT_TYPE_STD_CONDITION_VARIABLE_HPP_INCLUDED

#include <typeout/config.hpp>
#include <typeout/reg_type.hpp>

#if !TYPEOUT_NO_STD_HDR_CONDITION_VARIABLE
# include <condition_variable>
# if TYPEOUT_SUPPORT_STD_CONDITION_VARIABLE
TYPEOUT_REG_TYPE(std::condition_variable)
TYPEOUT_REG_TYPE(std::condition_variable_any)
# endif /* TYPEOUT_SUPPORT_STD_CONDITION_VARIABLE */
#endif /* !TYPEOUT_NO_STD_HDR_CONDITION_VARIABLE */

#endif /* TYPEOUT_TYPE_STD_CONDITION_VARIABLE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
