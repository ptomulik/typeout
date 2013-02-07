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

// typeout/tvalue/fundamental.hpp

/** // doc: typeout/tvalue/fundamental.hpp {{{ 
 * \file typeout/tvalue/fundamental.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TYPEOUT_TVALUE_FUNDAMENTAL_HPP_INCLUDED
#define TYPEOUT_TVALUE_FUNDAMENTAL_HPP_INCLUDED

#include <typeout/config.hpp>
#include <typeout/tvalue/class.hpp>

namespace typeout {
namespace _tvalue {

template <>
struct _<bool, true>
{
  template <class Ostream>
  static void write(Ostream& os)
  { os << "(bool)true"; }
};

template <>
struct _<bool, false>
{
  template <class Ostream>
  static void write(Ostream& os)
  { os << "(bool)false"; }
};

template <char t>
struct _<char, t>
{
  template <class Ostream>
  static void write(Ostream& os)
  { os << "(char)\'" << t << "\'"; }
};

#if TYPEOUT_SUPPORT_CHAR16_T
template <char16_t t>
struct _<char16_t, t>
{
  template <class Ostream>
  static void write(Ostream& os)
  { os << "(char16_t)\'" << t << "\'"; }
};
#endif

#if TYPEOUT_SUPPORT_CHAR32_T
template <char32_t t>
struct _<char32_t, t>
{
  template <class Ostream>
  static void write(Ostream& os)
  { os << "(char32_t)\'" << t << "\'"; }
};
#endif

template <wchar_t t>
struct _<wchar_t, t>
{
  template <class Ostream>
  static void write(Ostream& os)
  { os << "(wchar_t)\'" << t << "\'"; }
};

template <signed char t>
struct _<signed char, t>
{
  template <class Ostream>
  static void write(Ostream& os)
  { os << "(signed char)\'" << t << "\'"; }
};

template <short int t>
struct _<short int, t>
{
  template <class Ostream>
  static void write(Ostream& os)
  { os << "(short int)" << t; }
};

template <int t>
struct _<int, t>
{
  template <class Ostream>
  static void write(Ostream& os)
  { os << "(int)" << t; }
};

template <long int t>
struct _<long int, t>
{
  template <class Ostream>
  static void write(Ostream& os)
  { os << "(long int)" << t; }
};

template <long long int t>
struct _<long long int, t>
{
  template <class Ostream>
  static void write(Ostream& os)
  { os << "(long long int)" << t; }
};

template <unsigned char t>
struct _<unsigned char, t>
{
  template <class Ostream>
  static void write(Ostream& os)
  { os << "(unsigned char)\'" << t << "\'"; }
};

template <unsigned short int t>
struct _<unsigned short int, t>
{
  template <class Ostream>
  static void write(Ostream& os)
  { os << "(unsigned short int)" << t; }
};

template <unsigned int t>
struct _<unsigned int, t>
{
  template <class Ostream>
  static void write(Ostream& os)
  { os << "(unsigned int)" << t; }
};

template <unsigned long int t>
struct _<unsigned long int, t>
{
  template <class Ostream>
  static void write(Ostream& os)
  { os << "(unsigned long int)" << t; }
};

template <unsigned long long int t>
struct _<unsigned long long int, t>
{
  template <class Ostream>
  static void write(Ostream& os)
  { os << "(unsigned long long int)" << t; }
};

} /* namespace _tvalue */
} /* namespace typeout */

#endif /* TYPEOUT_TVALUE_FUNDAMENTAL_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
