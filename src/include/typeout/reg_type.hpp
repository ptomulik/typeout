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

// typeout/reg_type.hpp

/** // doc: typeout/reg_type.hpp {{{ 
 * \file typeout/reg_type.hpp
 * \brief Preprocessor macro(s) to register new types.
 */ // }}}
#ifndef TYPEOUT_REG_TYPE_HPP_INCLUDED
#define TYPEOUT_REG_TYPE_HPP_INCLUDED

#include <typeout/config.hpp>
#include <typeout/type/class.hpp>
#include <boost/preprocessor/stringize.hpp>

/** \ingroup typeout_reg_type
 * @{ */

/** // doc: TYPEOUT_REG_TYPE_AS {{{
 * \brief Register new type using custom name
 * \param type Fully qualified type name, for example <tt>std::size_t</tt>.
 *        It may be a type defined with typedef or alias created with 
 *        \c using keyword.
 * \param as Runtime name of the registered type. Should be string or
 *        expression that yields string at runtime.
 *
 * \note Must be invoked at global scope (not within any namespace).
 * \note Don't put semicolon after this macro.
 *
 * <b>Example</b>:
 * \snippet reg_type_as1.cpp Program
 *
 * \note The \c as argument may be a name or variable or expression that yields
 *       string at runtime (plain C string, \c std::string or whatever type is
 *       compatible with output streams being in use).
 *
 * <b>Example</b>:
 * \snippet reg_type_as2.cpp Program
 *
 * \hideinitializer
 */ // }}}
#define TYPEOUT_REG_TYPE_AS(type,as) \
namespace typeout {  \
namespace _type { \
template <> struct _ <type> \
{ \
  template <typename Ostream> \
  static void write(Ostream& os) \
  { os << (as); } \
}; \
} \
} /* namespace typeout */

/** // doc: TYPEOUT_REG_TYPE {{{
 * \brief Register new type 
 * \param type Fully qualified type name, for example <tt>std::size_t</tt>.
 *        The macro accepts types defined with \c typedef and aliases created
 *        with \c using keyword, see notes below.
 *
 * \note Must be invoked at global scope (not within any namespace).
 * \note Don't put semicolon after this macro.
 * \note If you register a type created with \c typedef or alias created with
 *       the \c using keyword, the name presented at runtime will be the alias
 *       name, not the original type name.
 *
 * <b>Example</b>:
 * \snippet reg_type1.cpp Program
 *
 * \hideinitializer
 */ // }}}
#define TYPEOUT_REG_TYPE(type) \
  TYPEOUT_REG_TYPE_AS(type,BOOST_PP_STRINGIZE(type))

/** @} */

#endif /* TYPEOUT_REG_TYPE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
