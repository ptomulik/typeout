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

# if BOOST_VERSION >= 105000ul // 1.50

#   ifndef TYPEOUT_NO_STD_HDR_ARRAY
#     ifdef BOOST_NO_CXX11_HDR_ARRAY
#       define TYPEOUT_NO_STD_HDR_ARRAY 1
#     else
#       define TYPEOUT_NO_STD_HDR_ARRAY 0
#     endif
#   endif
/* as for now boost has no test macros for <atomic> */
#   ifndef TYPEOUT_NO_STD_HDR_ATOMIC
#     ifdef BOOST_NO_CXX11_HDR_ARRAY
#       define TYPEOUT_NO_STD_HDR_ATOMIC 1
#     else
#       define TYPEOUT_NO_STD_HDR_ATOMIC 0
#     endif
#   endif
#   ifndef TYPEOUT_NO_STD_HDR_CHRONO
#     ifdef BOOST_NO_CXX11_HDR_CHRONO
#       define TYPEOUT_NO_STD_HDR_CHRONO 1
#     else
#       define TYPEOUT_NO_STD_HDR_CHRONO 0
#     endif
#   endif
#   ifndef TYPEOUT_NO_STD_HDR_CONDITION_VARIABLE
#     ifdef BOOST_NO_CXX11_HDR_CONDITION_VARIABLE
#       define TYPEOUT_NO_STD_HDR_CONDITION_VARIABLE 1
#     else
#       define TYPEOUT_NO_STD_HDR_CONDITION_VARIABLE 0
#     endif
#   endif

#   ifndef TYPEOUT_NO_STD_HDR_RATIO
#     ifdef BOOST_NO_CXX11_HDR_RATIO
#       define TYPEOUT_NO_STD_HDR_RATIO 1
#     else
#       define TYPEOUT_NO_STD_HDR_RATIO 0
#     endif
#   endif

# else // BOOST_VERSION < 1.50

#   ifndef TYPEOUT_NO_STD_HDR_ARRAY
#     ifdef BOOST_NO_0X_HDR_ARRAY
#       define TYPEOUT_NO_STD_HDR_ARRAY 1
#     else
#       define TYPEOUT_NO_STD_HDR_ARRAY 0
#     endif
#   endif
/* as for now boost has no test macros for <atomic> */
#   ifndef TYPEOUT_NO_STD_HDR_ATOMIC
#     ifdef BOOST_NO_0X_HDR_ARRAY
#       define TYPEOUT_NO_STD_HDR_ATOMIC 1
#     else
#       define TYPEOUT_NO_STD_HDR_ATOMIC 0
#     endif
#   endif
#   ifndef TYPEOUT_NO_STD_HDR_CHRONO
#     ifdef BOOST_NO_0X_HDR_CHRONO
#       define TYPEOUT_NO_STD_HDR_CHRONO 1
#     else
#       define TYPEOUT_NO_STD_HDR_CHRONO 0
#     endif
#   endif
#   ifndef TYPEOUT_NO_STD_HDR_CONDITION_VARIABLE
#     ifdef BOOST_NO_0X_HDR_CONDITION_VARIABLE
#       define TYPEOUT_NO_STD_HDR_CONDITION_VARIABLE 1
#     else
#       define TYPEOUT_NO_STD_HDR_CONDITION_VARIABLE 0
#     endif
#   endif

#   ifndef TYPEOUT_NO_STD_HDR_RATIO
#     ifdef BOOST_NO_0X_HDR_RATIO
#       define TYPEOUT_NO_STD_HDR_RATIO 1
#     else
#       define TYPEOUT_NO_STD_HDR_RATIO 0
#     endif
#   endif

# endif

# if BOOST_VERSION >= 105100ul // 1.51

#   ifndef TYPEOUT_SUPPORT_RVALUE_REFERENCES
#     ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
#       define TYPEOUT_SUPPORT_RVALUE_REFERENCES 1
#     else
#       define TYPEOUT_SUPPORT_RVALUE_REFERENCES 0
#     endif
#   endif
#   ifndef TYPEOUT_SUPPORT_VARIADIC_TEMPLATES
#     ifndef BOOST_NO_CXX11_VARIADIC_TEMPLATES
#       define TYPEOUT_SUPPORT_VARIADIC_TEMPLATES 1
#     else
#       define TYPEOUT_SUPPORT_VARIADIC_TEMPLATES 0
#     endif
#   endif
#   ifndef TYPEOUT_SUPPORT_CHAR16_T
#     ifndef BOOST_NO_CXX11_CHAR16_T
#       define TYPEOUT_SUPPORT_CHAR16_T 1
#     else
#       define TYPEOUT_SUPPORT_CHAR16_T 0
#     endif
#   endif
#   ifndef TYPEOUT_SUPPORT_CHAR32_T
#     ifndef BOOST_NO_CXX11_CHAR32_T
#       define TYPEOUT_SUPPORT_CHAR32_T 1
#     else
#       define TYPEOUT_SUPPORT_CHAR32_T 0
#     endif
#   endif

# else // BOOST_VERSION < 1.51

#   ifndef TYPEOUT_SUPPORT_RVALUE_REFERENCES
#     ifndef BOOST_NO_RVALUE_REFERENCES
#       define TYPEOUT_SUPPORT_RVALUE_REFERENCES 1
#     else
#       define TYPEOUT_SUPPORT_RVALUE_REFERENCES 0
#     endif
#   endif
#   ifndef TYPEOUT_SUPPORT_VARIADIC_TEMPLATES
#     ifndef BOOST_NO_VARIADIC_TEMPLATES
#       define TYPEOUT_SUPPORT_VARIADIC_TEMPLATES 1
#     else
#       define TYPEOUT_SUPPORT_VARIADIC_TEMPLATES 0
#     endif
#   endif
#   ifndef TYPEOUT_SUPPORT_CHAR16_T
#     ifndef BOOST_NO_CHAR16_T
#       define TYPEOUT_SUPPORT_CHAR16_T 1
#     else
#       define TYPEOUT_SUPPORT_CHAR16_T 0
#     endif
#   endif
#   ifndef TYPEOUT_SUPPORT_CHAR32_T
#     ifndef BOOST_NO_CHAR32_T
#       define TYPEOUT_SUPPORT_CHAR32_T 1
#     else
#       define TYPEOUT_SUPPORT_CHAR32_T 0
#     endif
#   endif

# endif // BOOST_VERSION >= 1.51

#ifndef TYPEOUT_NO_STD_HDR_CWCHAR
# ifdef BOOST_NO_CWCHAR
#   define TYPEOUT_NO_STD_HDR_CWCHAR 1
# else
#   define TYPEOUT_NO_STD_HDR_CWCHAR 0
# endif
#endif

# ifndef TYPEOUT_SUPPORT_STD_ARRAY
#   define TYPEOUT_SUPPORT_STD_ARRAY !TYPEOUT_NO_STD_HDR_ARRAY
# endif
# ifndef TYPEOUT_SUPPORT_STD_ATOMIC
#   define TYPEOUT_SUPPORT_STD_ATOMIC !TYPEOUT_NO_STD_HDR_ATOMIC
# endif
# ifndef TYPEOUT_SUPPORT_STD_BITSET
#   define TYPEOUT_SUPPORT_STD_BITSET 1
# endif
# ifndef TYPEOUT_SUPPORT_STD_CHRONO
#   define TYPEOUT_SUPPORT_STD_CHRONO !TYPEOUT_NO_STD_HDR_CHRONO
# endif
# ifndef TYPEOUT_SUPPORT_STD_CLOCALE
#   define TYPEOUT_SUPPORT_STD_CLOCALE 1
# endif
# ifndef TYPEOUT_SUPPORT_STD_CMATH
#   define TYPEOUT_SUPPORT_STD_CMATH 1
# endif
# ifndef TYPEOUT_SUPPORT_STD_COMPLEX
#   define TYPEOUT_SUPPORT_STD_COMPLEX 1
# endif
# ifndef TYPEOUT_SUPPORT_STD_CONDITION_VARIABLE
#   define TYPEOUT_SUPPORT_STD_CONDITION_VARIABLE !TYPEOUT_NO_STD_HDR_CONDITION_VARIABLE
# endif
# ifndef TYPEOUT_SUPPORT_STD_CTIME
#   define TYPEOUT_SUPPORT_STD_CTIME 1
# endif
# ifndef TYPEOUT_SUPPORT_STD_CWCHAR
#   define TYPEOUT_SUPPORT_STD_CWCHAR !TYPEOUT_NO_STD_HDR_CWCHAR
# endif
# ifndef TYPEOUT_SUPPORT_STD_DEQUE
#   define TYPEOUT_SUPPORT_STD_DEQUE 1
# endif

# ifndef TYPEOUT_SUPPORT_STD_MEMORY
#   define TYPEOUT_SUPPORT_STD_MEMORY 1
# endif

# ifndef TYPEOUT_SUPPORT_STD_SMART_PTR
#   if BOOST_VERSION >= 105000ul
#     define TYPEOUT_SUPPORT_STD_SMART_PTR \
        (TYPEOUT_SUPPORT_STD_MEMORY && !defined(BOOST_NO_CXX11_SMART_PTR))
#   else
      /* FIXME: we need some way to check availability of smart pointers */
#     define TYPEOUT_SUPPORT_STD_SMART_PTR TYPEOUT_SUPPORT_STD_MEMORY
#   endif
# endif

# ifndef TYPEOUT_SUPPORT_CXX11_ALLOCATOR
#   if BOOST_VERSION >= 105000ul
#     define TYPEOUT_SUPPORT_CXX11_ALLOCATOR \
        (TYPEOUT_SUPPORT_STD_MEMORY && !defined(BOOST_NO_CXX11_ALLOCATOR))
#   else
      /* FIXME: we need some way to check availability of c++11 allocators */
#     define TYPEOUT_SUPPORT_CXX11_ALLOCATOR TYPEOUT_SUPPORT_STD_MEMORY
#   endif
# endif

# ifndef TYPEOUT_SUPPORT_STD_RATIO
#   define TYPEOUT_SUPPORT_STD_RATIO !TYPEOUT_NO_STD_HDR_RATIO
# endif


#else // TYPEOUT_IS_COMPILING_DOCS

/** \ingroup typeout_config
 * @{ */
/** // doc: TYPEOUT_NO_STD_HDR_ARRAY {{{
 * \brief Do we have &lt;array&gt; header?
 *
 * This constant tells whether the \c &lt;array&gt; header is available.
 *
 * The directive is always defined as either \c 0 or \c 1. If not provided by
 * user, the value is guessed. If the currently used standard library does not
 * provide the \c &lt;array&gt; header, the constant is set to \c 1. Otherwise
 * it is set to \c 0. You may prevent the \c typeout from guessing by defining
 * this macro prior to including \c typeout's header(s).
 *
 * \hideinitializer
 */ // }}}
# define TYPEOUT_NO_STD_HDR_ARRAY
/** // doc: TYPEOUT_NO_STD_HDR_ATOMIC {{{
 * \brief Do we have &lt;atomic&gt; header?
 *
 * This constant tells whether the \c &lt;atomic&gt; header is available.
 *
 * The directive is always defined as either \c 0 or \c 1. If not provided by
 * user, the value is guessed. If the currently used standard library does not
 * provide the \c &lt;atomic&gt; header, the constant is set to \c 1. Otherwise
 * it is set to \c 0. You may prevent the \c typeout from guessing by defining
 * this macro prior to including \c typeout's header(s).
 *
 * \hideinitializer
 */ // }}}
# define TYPEOUT_NO_STD_HDR_ATOMIC
/** // doc: TYPEOUT_NO_STD_HDR_CHRONO {{{
 * \brief Do we have &lt;chrono&gt; header?
 *
 * This constant tells whether the \c &lt;chrono&gt; header is available.
 *
 * The directive is always defined as either \c 0 or \c 1. If not provided by
 * user, the value is guessed. If the currently used standard library does not
 * provide the \c &lt;chrono&gt; header, the constant is set to \c 1. Otherwise
 * it is set to \c 0. You may prevent the \c typeout from guessing by defining
 * this macro prior to including \c typeout's header(s).
 *
 * \hideinitializer
 */ // }}}
# define TYPEOUT_NO_STD_HDR_CHRONO
/** // doc: TYPEOUT_NO_STD_HDR_CONDITION_VARIABLE {{{
 * \brief Do we have &lt;condition_variable&gt; header?
 *
 * This constant tells whether the \c &lt;condition_variable&gt; header is
 * available.
 *
 * The directive is always defined as either \c 0 or \c 1. If not provided by
 * user, the value is guessed. If the currently used standard library does not
 * provide the \c &lt;condition_variable&gt; header, the constant is set to 
 * \c 1. Otherwise it is set to \c 0. You may prevent the \c typeout from
 * guessing by defining this macro prior to including \c typeout's header(s).
 *
 * \hideinitializer
 */ // }}}
# define TYPEOUT_NO_STD_HDR_CONDITION_VARIABLE
/** // doc: TYPEOUT_NO_STD_HDR_RATIO {{{
 * \brief Do we have &lt;ratio&gt; header?
 *
 * This constant tells whether the '\c &lt;ratio&gt; header is available.
 *
 * The directive is always defined as either \c 0 or \c 1. If not provided by
 * user, the value is guessed. If the currently used standard library does not
 * provide the \c &lt;ratio&gt; header, the constant is set to \c 1. Otherwise
 * it is set to \c 0. You may prevent the \c typeout from guessing by defining
 * this macro prior to including \c typeout's header(s).
 *
 * \hideinitializer
 */ // }}}
# define TYPEOUT_NO_STD_HDR_RATIO 
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
# define TYPEOUT_SUPPORT_RVALUE_REFERENCES 
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
# define TYPEOUT_SUPPORT_VARIADIC_TEMPLATES 
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
 */ // }}}
# define TYPEOUT_SUPPORT_CHAR16_T 
/** // doc: TYPEOUT_SUPPORT_CHAR32_T {{{
 * \brief Whether to support c++11 \c std::array.
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
 */ // }}}
# define TYPEOUT_SUPPORT_CHAR32_T 
/** // doc: TYPEOUT_SUPPORT_STD_ARRAY {{{
 * \brief Whether to support c++11 \c .
 *
 * This directive tells the \c typeout whether to enable code that involves
 * \c std::array.
 *
 * The directive is always defined as either \c 0 or \c 1. If not provided by
 * user, the value is guessed. If \c TYPEOUT_NO_STD_HDR_ARRAY is zero, then
 * support for \c std::array is enabled. Otherwise the constant
 * TYPEOUT_SUPPORT_STD_ARRAY is set to \c 0. You may prevent the \c typeout
 * from guessing by defining this macro prior to including \c typeout's
 * header(s).
 *
 * <b>Example 1</b>:
 * \code
 * // Disable library code that uses std::array
 * #define TYPEOUT_SUPPORT_STD_ARRAY 0 
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/array.hpp>
 * // NOTE: support for std:array was disabled, so for example this code
 * //   std::cout << typeout::_<std::array<int, 2> > << std::endl;
 * // will not compile here.
 * \endcode
 *
 * <b>Example 2</b>:
 * \code
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/array.hpp>
 * // ...
 * #if TYPEOUT_SUPPORT_STD_ARRAY
 * // test case with std::array ...
 * #endif
 * \endcode
 *
 * \hideinitializer
 */ // }}}
# define TYPEOUT_SUPPORT_STD_ARRAY 
/** // doc: TYPEOUT_SUPPORT_STD_ATOMIC {{{
 * \brief Whether to support c++11 \c std::atomic.
 *
 * This directive tells the \c typeout whether to enable code that involves
 * \c std::atomic.
 *
 * The directive is always defined as either \c 0 or \c 1. If not provided by
 * user, the value is guessed. If \c TYPEOUT_NO_STD_HDR_ATOMIC is zero, then
 * support for \c std::atomic is enabled. Otherwise the constant
 * TYPEOUT_SUPPORT_STD_ATOMIC is set to \c 0. You may prevent the \c typeout
 * from guessing by defining this macro prior to including \c typeout's
 * header(s).
 *
 * <b>Example 1</b>:
 * \code
 * // Disable library code that uses std::atomic.
 * #define TYPEOUT_SUPPORT_STD_ATOMIC 0 
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/atomic.hpp>
 * // NOTE: support for std::atomic was disabled, so for example this code
 * //   std::cout << typeout::_<std::atomic<int> > << std::endl;
 * // will not compile here.
 * \endcode
 *
 * <b>Example 2</b>:
 * \code
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/atomic.hpp>
 * // ...
 * #if TYPEOUT_SUPPORT_STD_ATOMIC
 * // test case with std::atomic ...
 * #endif
 * \endcode
 *
 * \hideinitializer
 */ // }}}
# define TYPEOUT_SUPPORT_STD_ATOMIC 
/** // doc: TYPEOUT_SUPPORT_STD_BITSET {{{
 * \brief Whether to support c++11 \c std::deque.
 *
 * This directive tells the \c typeout whether to enable code that involves
 * \c std::deque.
 *
 * The directive is always defined as either \c 0 or \c 1. If not provided by
 * user, the value is set to \c 1. You may change the default by defining this
 * macro prior to including \c typeout's header(s).
 *
 * <b>Example 1</b>:
 * \code
 * // Disable library code that uses std::deque.
 * #define TYPEOUT_SUPPORT_STD_BITSET 0 
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/deque.hpp>
 * // NOTE: support for std::deque was disabled, so for example this code
 * //   std::cout << typeout::_<std::deque<2> > << std::endl;
 * // will not compile here.
 * \endcode
 *
 * <b>Example 2</b>:
 * \code
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/deque.hpp>
 * // ...
 * #if TYPEOUT_SUPPORT_STD_BITSET
 * // test case with std::deque ...
 * #endif
 * \endcode
 *
 * \hideinitializer
 */ // }}}
# define TYPEOUT_SUPPORT_STD_BITSET 
/** // doc: TYPEOUT_SUPPORT_STD_CHRONO {{{
 * \brief Whether to support types from c++x11 \c &lt;chrono&gt; header.
 *
 * This directive tells the \c typeout whether to enable code that involves
 * types from \c &lt;chrono&gt; header.
 *
 * The directive is always defined as either \c 0 or \c 1. If not provided by
 * user, the value is guessed. If \c TYPEOUT_NO_STD_HDR_CHRONO is zero, then
 * support for \c std::chrono is enabled. Otherwise the constant
 * TYPEOUT_SUPPORT_STD_CHRONO is set to \c 0. You may prevent the \c typeout
 * from guessing by defining this macro prior to including \c typeout's
 * header(s).
 *
 * <b>Example 1</b>:
 * \code
 * // Disable library code that uses <chrono>.
 * #define TYPEOUT_SUPPORT_STD_CHRONO 0 
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/chrono.hpp>
 * // NOTE: support for &lt;chrono&gt; was disabled, so for example this code
 * //   std::cout << typeout::_< std::chrono::duration<int, std::centi> > << std::endl;
 * // will not compile here.
 * \endcode
 *
 * <b>Example 2</b>:
 * \code
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/chrono.hpp>
 * // ...
 * #if TYPEOUT_SUPPORT_STD_CHRONO
 * // test case with <chrono> stuff ...
 * #endif
 * \endcode
 *
 * \hideinitializer
 */ // }}}
# define TYPEOUT_SUPPORT_STD_CHRONO
/** // doc: TYPEOUT_SUPPORT_STD_CLOCALE {{{
 * \brief Whether to support things from &lt;clocale&gt; header.
 *
 * This directive tells the \c typeout whether to enable code that involves
 * types from &lt;clocale&gt; header.
 *
 * The directive is always defined as either \c 0 or \c 1. If not provided by
 * user, the value is set to \c 1. You may change the default by defining this
 * macro prior to including \c typeout's header(s).
 *
 * <b>Example 1</b>:
 * \code
 * // Disable library code that uses char32_t.
 * #define TYPEOUT_SUPPORT_STD_CLOCALE 0 
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/clocale.hpp>
 * // NOTE: support for <clocale> header was disabled, so for example
 * // this code
 * //   std::cout << typeout::_<std::lconv> << std::endl;
 * // will not compile here.
 * \endcode
 *
 * <b>Example 2</b>:
 * \code
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/clocale.hpp>
 * // ...
 * #if TYPEOUT_SUPPORT_STD_CLOCALE
 * // test case ... 
 * #endif
 * \endcode
 *
 * \hideinitializer
 */ // }}}
# define TYPEOUT_SUPPORT_STD_CLOCALE 
/** // doc: TYPEOUT_SUPPORT_STD_CMATH {{{
 * \brief Whether to support things from &lt;cmath&gt; header.
 *
 * This directive tells the \c typeout whether to enable code that involves
 * types from &lt;cmath&gt; header.
 *
 * The directive is always defined as either \c 0 or \c 1. If not provided by
 * user, the value is set to \c 1. You may change the default by defining this
 * macro prior to including \c typeout's header(s).
 *
 * <b>Example 1</b>:
 * \code
 * // Disable library code that uses char32_t.
 * #define TYPEOUT_SUPPORT_STD_CMATH 0 
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/cmath.hpp>
 * // NOTE: support for <cmath> header was disabled, so for example
 * // this code
 * //   std::cout << typeout::_<std::div_t> << std::endl;
 * // will not compile here.
 * \endcode
 *
 * <b>Example 2</b>:
 * \code
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/cmath.hpp>
 * // ...
 * #if TYPEOUT_SUPPORT_STD_CMATH
 * // test case ... 
 * #endif
 * \endcode
 *
 * \hideinitializer
 */ // }}}
# define TYPEOUT_SUPPORT_STD_CMATH 
/** // doc: TYPEOUT_SUPPORT_STD_COMPLEX {{{
 * \brief Whether to support things from &lt;complex&gt; header.
 *
 * This directive tells the \c typeout whether to enable code that involves
 * types from &lt;complex&gt; header.
 *
 * The directive is always defined as either \c 0 or \c 1. If not provided by
 * user, the value is set to \c 1. You may change the default by defining this
 * macro prior to including \c typeout's header(s).
 *
 * <b>Example 1</b>:
 * \code
 * // Disable library code that uses char32_t.
 * #define TYPEOUT_SUPPORT_STD_COMPLEX 0 
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/complex.hpp>
 * // NOTE: support for <complex> header was disabled, so for example
 * // this code
 * //   std::cout << typeout::_<std::complex<float> > << std::endl;
 * // will not compile here.
 * \endcode
 *
 * <b>Example 2</b>:
 * \code
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/complex.hpp>
 * // ...
 * #if TYPEOUT_SUPPORT_STD_COMPLEX
 * // test case ... 
 * #endif
 * \endcode
 *
 * \hideinitializer
 */ // }}}
# define TYPEOUT_SUPPORT_STD_COMPLEX 
/** // doc: TYPEOUT_SUPPORT_STD_CONDITION_VARIABLE {{{
 * \brief Whether to support typed from c++x11 &lt;condition_variable&gt; header.
 *
 * This directive tells the \c typeout whether to enable support for types
 * from &lt;condition_variable&lt; header.
 *
 * The directive is always defined as either \c 0 or \c 1. If not provided by
 * user, the value is guessed. If \c TYPEOUT_NO_STD_HDR_CONDITION_VARIABLE is
 * zero, then support for \c std::condition_variable is enabled. Otherwise the
 * constant TYPEOUT_SUPPORT_STD_CONDITION_VARIABLE is set to \c 0. You may
 * prevent the \c typeout from guessing by defining this macro prior to
 * including \c typeout's header(s).
 *
 * <b>Example 1</b>:
 * \code
 * // Disable library code that uses &lt;condition_variable&gt;.
 * #define TYPEOUT_SUPPORT_STD_CONDITION_VARIABLE 0 
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/condition_variable.hpp>
 * // NOTE: support for <condition_variable>; was disabled, so for example
 * // this code
 * //   std::cout << typeout::_< std::condition_variable > << std::endl;
 * // will not compile here.
 * \endcode
 *
 * <b>Example 2</b>:
 * \code
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/condition_variable.hpp>
 * // ...
 * #if TYPEOUT_SUPPORT_STD_CONDITION_VARIABLE
 * // test case with <condition_variable> stuff ...
 * #endif
 * \endcode
 *
 * \hideinitializer
 */ // }}}
# define TYPEOUT_SUPPORT_STD_CONDITION_VARIABLE
/** // doc: TYPEOUT_SUPPORT_STD_CTIME {{{
 * \brief Whether to support things from &lt;ctime&gt; header.
 *
 * This directive tells the \c typeout whether to enable code that involves
 * types from &lt;ctime&gt; header.
 *
 * The directive is always defined as either \c 0 or \c 1. If not provided by
 * user, the value is set to \c 1. You may change the default by defining this
 * macro prior to including \c typeout's header(s).
 *
 * <b>Example 1</b>:
 * \code
 * // Disable library code that uses char32_t.
 * #define TYPEOUT_SUPPORT_STD_CTIME 0 
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/ctime.hpp>
 * // NOTE: support for <ctime> header was disabled, so for example
 * // this code
 * //   std::cout << typeout::_<std::tm> << std::endl;
 * // will not compile here.
 * \endcode
 *
 * <b>Example 2</b>:
 * \code
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/ctime.hpp>
 * // ...
 * #if TYPEOUT_SUPPORT_STD_CTIME
 * // test case ... 
 * #endif
 * \endcode
 *
 * \hideinitializer
 */ // }}}
# define TYPEOUT_SUPPORT_STD_CTIME 
/** // doc: TYPEOUT_SUPPORT_STD_CWCHAR {{{
 * \brief Whether to support types from c++x11 \c &lt;cwchar&gt; header.
 *
 * This directive tells the \c typeout whether to enable code that involves
 * types from \c &lt;cwchar&gt; header.
 *
 * The directive is always defined as either \c 0 or \c 1. If not provided by
 * user, the value is guessed. If \c TYPEOUT_NO_STD_HDR_CWCHAR is zero, then
 * support for \c std::cwchar is enabled. Otherwise the constant
 * TYPEOUT_SUPPORT_STD_CWCHAR is set to \c 0. You may prevent the \c typeout
 * from guessing by defining this macro prior to including \c typeout's
 * header(s).
 *
 * <b>Example 1</b>:
 * \code
 * // Disable library code that uses <cwchar>.
 * #define TYPEOUT_SUPPORT_STD_CWCHAR 0 
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/cwchar.hpp>
 * // NOTE: support for &lt;cwchar&gt; was disabled, so for example this code
 * //   std::cout << typeout::_< std::mbstate_t > << std::endl;
 * // will not compile here.
 * \endcode
 *
 * <b>Example 2</b>:
 * \code
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/cwchar.hpp>
 * // ...
 * #if TYPEOUT_SUPPORT_STD_CWCHAR
 * // test case with <cwchar> stuff ...
 * #endif
 * \endcode
 *
 * \hideinitializer
 */ // }}}
# define TYPEOUT_SUPPORT_STD_CWCHAR
/** // doc: TYPEOUT_SUPPORT_STD_DEQUE {{{
 * \brief Whether to support c++11 \c std::deque.
 *
 * This directive tells the \c typeout whether to enable code that involves
 * \c std::deque.
 *
 * The directive is always defined as either \c 0 or \c 1. If not provided by
 * user, the value is set to \c 1. You may change the default by defining this
 * macro prior to including \c typeout's header(s).
 *
 * <b>Example 1</b>:
 * \code
 * // Disable library code that uses std::deque.
 * #define TYPEOUT_SUPPORT_STD_DEQUE 0 
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/deque.hpp>
 * // NOTE: support for std::deque was disabled, so for example this code
 * //   std::cout << typeout::_<std::deque<int> > << std::endl;
 * // will not compile here.
 * \endcode
 *
 * <b>Example 2</b>:
 * \code
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/deque.hpp>
 * // ...
 * #if TYPEOUT_SUPPORT_STD_DEQUE
 * // test case with std::deque ...
 * #endif
 * \endcode
 *
 * \hideinitializer
 */ // }}}
# define TYPEOUT_SUPPORT_STD_DEQUE 
/** // doc: TYPEOUT_SUPPORT_STD_MEMORY {{{
 * \brief Whether to support things from &lt;memory&gt; header.
 *
 * This directive tells the \c typeout whether to enable code that involves
 * types from &lt;memory&gt; header.
 *
 * The directive is always defined as either \c 0 or \c 1. If not provided by
 * user, the value is set to \c 1. You may change the default by defining this
 * macro prior to including \c typeout's header(s).
 *
 * <b>Example 1</b>:
 * \code
 * // Disable library code that uses char32_t.
 * #define TYPEOUT_SUPPORT_STD_MEMORY 0 
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/memory.hpp>
 * // NOTE: support for <memory> header was disabled, so for example
 * // this code
 * //   std::cout << typeout::_<std::allocator<float> > << std::endl;
 * // will not compile here.
 * \endcode
 *
 * <b>Example 2</b>:
 * \code
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/memory.hpp>
 * // ...
 * #if TYPEOUT_SUPPORT_STD_MEMORY
 * // test case ... 
 * #endif
 * \endcode
 *
 * \hideinitializer
 */ // }}}
# define TYPEOUT_SUPPORT_STD_MEMORY 
/** // doc: TYPEOUT_SUPPORT_STD_SMART_PTR {{{
 * \brief Whether to support c++11 \c std::shared_ptr and \c std::unique_ptr.
 *
 * This directive tells the \c typeout whether to enable code that involves
 * \c std::shared_ptr and \c unique_ptr.
 *
 * The directive is always defined as either \c 0 or \c 1. If not provided by
 * user, the value is set to \c 1. You may change the default by defining this
 * macro prior to including \c typeout's header(s).
 *
 * <b>Example 1</b>:
 * \code
 * // Disable library code that uses std::shared_ptr and std::unique_ptr.
 * #define TYPEOUT_SUPPORT_STD_SMART_PTR 0 
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/memory.hpp>
 * // NOTE: support for std::shared_ptr was disabled, so for example this code
 * //   std::cout << typeout::_<std::shared_ptr<int> > << std::endl;
 * // will not compile here.
 * \endcode
 *
 * <b>Example 2</b>:
 * \code
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/memory.hpp>
 * // ...
 * #if TYPEOUT_SUPPORT_STD_SMART_PTR
 * // test case ...
 * #endif
 * \endcode
 *
 * \hideinitializer
 */ // }}}
# define TYPEOUT_SUPPORT_STD_SMART_PTR 
/** // doc: TYPEOUT_SUPPORT_CXX11_ALLOCATOR {{{
 * \brief Whether to support c++11 version of allocator.
 *
 * This directive tells the \c typeout whether to enable code that involves
 * \c std::shared_ptr and \c unique_ptr.
 *
 * The directive is always defined as either \c 0 or \c 1. If not provided by
 * user, its value is guessed. If TYPEOUT_SUPPORT_STD_MEMORY is zero, then
 * TYPEOUT_SUPPORT_CXX11_ALLOCATOR is also set to zero (if not previously
 * defined). You may change defaults by defining this constant by you own
 * before including any of \c typeout's headers.
 *
 * <b>Example 1</b>:
 * \code
 * // Disable library code that uses std::shared_ptr and std::unique_ptr.
 * #define TYPEOUT_SUPPORT_CXX11_ALLOCATOR 0 
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/memory.hpp>
 * // NOTE: support for std::allocator_traits was disabled, so for example 
 * // this code
 * //   std::cout << typeout::_<std::allocator_traits<std::allocator<int> > > << std::endl;
 * // will not compile here.
 * \endcode
 *
 * <b>Example 2</b>:
 * \code
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/memory.hpp>
 * // ...
 * #if TYPEOUT_SUPPORT_CXX11_ALLOCATOR
 * // test case ...
 * #endif
 * \endcode
 *
 * \hideinitializer
 */ // }}}
# define TYPEOUT_SUPPORT_CXX11_ALLOCATOR 
/** // doc: TYPEOUT_SUPPORT_STD_RATIO {{{
 * \brief Whether to support c++11 \c std::ratio.
 *
 * This directive tells the \c typeout whether to enable code that involves
 * \c std::ratio.
 *
 * The directive is always defined as either \c 0 or \c 1. If not provided by
 * user, the value is guessed. If \c TYPEOUT_NO_STD_HDR_RATIO is zero, then
 * support for \c std::ratio is enabled. Otherwise the constant
 * TYPEOUT_SUPPORT_STD_RATIO is set to \c 0. You may prevent the \c typeout
 * from guessing by defining this macro prior to including \c typeout's
 * header(s).
 *
 * <b>Example 1</b>:
 * \code
 * // Disable library code that uses std::ratio.
 * #define TYPEOUT_SUPPORT_STD_RATIO 0 
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/ratio.hpp>
 * // NOTE: support for std::ratio was disabled, so for example this code
 * //   std::cout << typeout::_<std::ratio<1> > << std::endl;
 * // will not compile here.
 * \endcode
 *
 * <b>Example 2</b>:
 * \code
 * #include <typeout/typeout.hpp>
 * #include <typeout/type/std/ratio.hpp>
 * // ...
 * #if TYPEOUT_SUPPORT_STD_RATIO
 * // test case with std::ratio ...
 * #endif
 * \endcode
 *
 * \hideinitializer
 */ // }}}
# define TYPEOUT_SUPPORT_STD_RATIO 
/** @} */

#endif // !TYPEOUT_IS_COMPILING_DOCS

#endif /* TYPEOUT_CONFIG_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
