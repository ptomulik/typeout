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

// typeout/type/fundamental.hpp

/** // doc: typeout/type/fundamental.hpp {{{ 
 * \file typeout/type/fundamental.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TYPEOUT_TYPE_FUNDAMENTAL_HPP_INCLUDED
#define TYPEOUT_TYPE_FUNDAMENTAL_HPP_INCLUDED

#include <typeout/config.hpp>
#include <typeout/type/class.hpp>
#include <typeout/reg_type.hpp>


/* void */
TYPEOUT_REG_TYPE(void)

/* Integral types */
TYPEOUT_REG_TYPE(bool)
TYPEOUT_REG_TYPE(char)

#if TYPEOUT_SUPPORT_CHAR16_T
TYPEOUT_REG_TYPE(char16_t)
#endif
#if TYPEOUT_SUPPORT_CHAR32_T
TYPEOUT_REG_TYPE(char32_t)
#endif

TYPEOUT_REG_TYPE(wchar_t)
TYPEOUT_REG_TYPE(signed char)
TYPEOUT_REG_TYPE(short int)
TYPEOUT_REG_TYPE(int)
TYPEOUT_REG_TYPE(long int)
TYPEOUT_REG_TYPE(long long int)
TYPEOUT_REG_TYPE(unsigned char)
TYPEOUT_REG_TYPE(unsigned short int)
TYPEOUT_REG_TYPE(unsigned int)
TYPEOUT_REG_TYPE(unsigned long int)
TYPEOUT_REG_TYPE(unsigned long long int)

/* floating point types */
TYPEOUT_REG_TYPE(float)
TYPEOUT_REG_TYPE(double)

#endif /* TYPEOUT_TYPE_FUNDAMENTAL_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
