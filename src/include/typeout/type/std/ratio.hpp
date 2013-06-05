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

// typeout/type/std/ratio.hpp

/** // doc: typeout/type/std/ratio.hpp {{{ 
 * \file typeout/type/std/ratio.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TYPEOUT_TYPE_STD_RATIO_HPP_INCLUDED
#define TYPEOUT_TYPE_STD_RATIO_HPP_INCLUDED

#include <typeout/config.hpp>
#include <typeout/reg_tclass.hpp>
#include <typeout/reg_type.hpp>

#if !TYPEOUT_NO_STD_HDR_RATIO
#include <ratio>
# if TYPEOUT_SUPPORT_STD_RATIO
TYPEOUT_REG_TCLASS(std::ratio,(const(std::intmax_t))(const(std::intmax_t)))
//TYPEOUT_REG_TYPE(std::yocto)
//TYPEOUT_REG_TYPE(std::zepto)
TYPEOUT_REG_TYPE(std::atto)
TYPEOUT_REG_TYPE(std::femto)
TYPEOUT_REG_TYPE(std::pico)
TYPEOUT_REG_TYPE(std::nano)
TYPEOUT_REG_TYPE(std::micro)
TYPEOUT_REG_TYPE(std::milli)
TYPEOUT_REG_TYPE(std::centi)
TYPEOUT_REG_TYPE(std::deci)
TYPEOUT_REG_TYPE(std::deca)
TYPEOUT_REG_TYPE(std::hecto)
TYPEOUT_REG_TYPE(std::kilo)
TYPEOUT_REG_TYPE(std::mega)
TYPEOUT_REG_TYPE(std::giga)
TYPEOUT_REG_TYPE(std::tera)
TYPEOUT_REG_TYPE(std::peta)
TYPEOUT_REG_TYPE(std::exa)
//TYPEOUT_REG_TYPE(std::zetta)
//TYPEOUT_REG_TYPE(std::yotta)
# endif /* TYPEOUT_SUPPORT_STD_RATIO */
#endif /* TYPEOUT_NO_STD_HDR_RATIO */

#endif /* TYPEOUT_TYPE_STD_RATIO_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
