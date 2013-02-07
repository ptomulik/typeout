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

// typeout/config.hpp

/** // doc: typeout/config.hpp {{{ 
 * \file typeout/config.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TYPEOUT_CONFIG_HPP_INCLUDED
#define TYPEOUT_CONFIG_HPP_INCLUDED

#include <boost/version.hpp>
#include <boost/config.hpp>

#ifndef TYPEOUT_IS_COMPILING_DOCS
# ifdef DOXYGEN
#   define TYPEOUT_IS_COMPILING_DOCS 1
# else
#   define TYPEOUT_IS_COMPILING_DOCS 0
# endif
#endif

#if !TYPEOUT_IS_COMPILING_DOCS

# if BOOST_VERSION >= 105100ul // 1.51

#   ifndef TYPEOUT_SUPPORT_RVALUE_REFERENCES
#     define TYPEOUT_SUPPORT_RVALUE_REFERENCES !BOOST_NO_CXX11_RVALUE_REFERENCES
#   endif
#   ifndef TYPEOUT_SUPPORT_VARIADIC_TEMPLATES
#     define TYPEOUT_SUPPORT_VARIADIC_TEMPLATES !BOOST_NO_CXX11_VARIADIC_TEMPLATES
#   endif
#   ifndef TYPEOUT_SUPPORT_CHAR16_T
#     define TYPEOUT_SUPPORT_CHAR16_T !BOOST_NO_CXX11_CHAR16_T
#   endif
#   ifndef TYPEOUT_SUPPORT_CHAR32_T
#     define TYPEOUT_SUPPORT_CHAR32_T !BOOST_NO_CXX11_CHAR32_T
#   endif

# else // BOOST_VERSION < 1.51

#   ifndef TYPEOUT_SUPPORT_RVALUE_REFERENCES
#     define TYPEOUT_SUPPORT_RVALUE_REFERENCES !BOOST_NO_RVALUE_REFERENCES
#   endif
#   ifndef TYPEOUT_SUPPORT_VARIADIC_TEMPLATES
#     define TYPEOUT_SUPPORT_VARIADIC_TEMPLATES !BOOST_NO_VARIADIC_TEMPLATES
#   endif
#   ifndef TYPEOUT_SUPPORT_CHAR16_T
#     define TYPEOUT_SUPPORT_CHAR16_T !BOOST_NO_CHAR16_T
#   endif
#   ifndef TYPEOUT_SUPPORT_CHAR32_T
#     define TYPEOUT_SUPPORT_CHAR32_T !BOOST_NO_CHAR32_T
#   endif

# endif // BOOST_VERSION >= 1.51

#else // TYPEOUT_IS_COMPILING_DOCS

/** \ingroup typeout_config
 * @{ */
/** // doc: TYPEOUT_SUPPORT_RVALUE_REFERENCES {{{
 * \brief Whether to support c++11 rvalue references.
 *
 * This directive tells the \c typeout whether to enable code that involves
 * rvalue references.
 *
 * The directive is always defined as either \c 0 or \c 1. If not provided by
 * user, the value is guessed. If the currently used compiler supports rvalue
 * references (and appropriate compiler flags are enabled, e.g. \c -std=c++11
 * in \c g++) the macro is defined as \c 1. Otherwise it is set to \c 0. You
 * may prevent the \c typeout from guessing by defining this macro prior to
 * including \c typeout's header(s).
 *
 * <b>Example 1</b>:
 * \code
 * // Disable library code that uses rvalue references.
 * #define TYPEOUT_SUPPORT_RVALUE_REFERENCES 0 
 * #include <typeout/typeout.hpp>
 * // NOTE: suport for rvalue references was disabled, so for example this
 * //   std::cout << typeout::_<char&&> << std::endl;
 * // will not compile here.
 * \endcode
 *
 * <b>Example 2</b>:
 * \code
 * #include <typeout/typeout.hpp>
 * // ...
 * #if TYPEOUT_SUPPORT_RVALUE_REFERENCES
 * // test case with rvalue references ...
 * #endif
 * \endcode
 *
 * \hideinitializer
 */ // }}}
# define TYPEOUT_SUPPORT_RVALUE_REFERENCES 1
/** // doc: TYPEOUT_SUPPORT_VARIADIC_TEMPLATES {{{
 * \brief Whether to support c++11 rvalue references.
 *
 * This directive tells the \c typeout whether to enable code that involves
 * variadic templates.
 *
 * The directive is always defined as either \c 0 or \c 1. If not provided by
 * user, the value is guessed. If the currently used compiler supports variadic
 * templates (and appropriate compiler flags are enabled, e.g. \c -std=c++11 in
 * \c g++) the macro is defined as \c 1. Otherwise it is set to \c 0. You may
 * prevent the \c typeout from guessing by defining this macro prior to
 * including \c typeout's header(s).
 *
 * \hideinitializer
 */ // }}}
# define TYPEOUT_SUPPORT_VARIADIC_TEMPLATES 1
/** // doc: TYPEOUT_SUPPORT_CHAR16_T {{{
 * \brief Whether to support c++11 \c char16_t.
 *
 * This directive tells the \c typeout whether to enable code that involves
 * \c char16_t type.
 *
 * The directive is always defined as either \c 0 or \c 1. If not provided by
 * user, the value is guessed. If the currently used compiler supports char16_t
 * (and appropriate compiler flags are enabled, e.g. \c -std=c++11 in \c g++)
 * the macro is defined as \c 1. Otherwise it is set to \c 0. You may prevent
 * the \c typeout from guessing by defining this macro prior to including \c
 * typeout's header(s).
 *
 * <b>Example 1</b>:
 * \code
 * // Disable library code that uses char16_t.
 * #define TYPEOUT_SUPPORT_CHAR16_T 0 
 * #include <typeout/typeout.hpp>
 * // NOTE: support for char16_t was disabled, so for example this code
 * //   std::cout << typeout::_<char16_t> << std::endl;
 * // will not compile here.
 * \endcode
 *
 * <b>Example 2</b>:
 * \code
 * #include <typeout/typeout.hpp>
 * // ...
 * #if TYPEOUT_SUPPORT_CHAR16_T
 * // test case with char16_t ...
 * #endif
 * \endcode
 *
 * \hideinitializer
 * \hideinitializer
 */ // }}}
# define TYPEOUT_SUPPORT_CHAR16_T 1
/** // doc: TYPEOUT_SUPPORT_CHAR32_T {{{
 * \brief Whether to support c++11 \c char32_t.
 *
 * This directive tells the \c typeout whether to enable code that involves
 * \c char32_t type.
 *
 * The directive is always defined as either \c 0 or \c 1. If not provided by
 * user, the value is guessed. If the currently used compiler supports char32_t
 * (and appropriate compiler flags are enabled, e.g. \c -std=c++11 in \c g++)
 * the macro is defined as \c 1. Otherwise it is set to \c 0. You may prevent
 * the \c typeout from guessing by defining this macro prior to including \c
 * typeout's header(s).
 *
 * <b>Example 1</b>:
 * \code
 * // Disable library code that uses char32_t.
 * #define TYPEOUT_SUPPORT_CHAR32_T 0 
 * #include <typeout/typeout.hpp>
 * // NOTE: support for char32_t was disabled, so for example this code
 * //   std::cout << typeout::_<char32_t> << std::endl;
 * // will not compile here.
 * \endcode
 *
 * <b>Example 2</b>:
 * \code
 * #include <typeout/typeout.hpp>
 * // ...
 * #if TYPEOUT_SUPPORT_CHAR32_T
 * // test case with char32_t ...
 * #endif
 * \endcode
 *
 * \hideinitializer
 * \hideinitializer
 */ // }}}
# define TYPEOUT_SUPPORT_CHAR32_T 1
/** @} */

#endif // !TYPEOUT_IS_COMPILING_DOCS

#endif /* TYPEOUT_CONFIG_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
