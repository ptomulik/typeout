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
struct _<bool>
{
  template <class Ostream>
  static void write(Ostream& os, bool x)
  { os << x ? "true" : "false"; }
};

template <>
struct _<char>
{
  template <class Ostream>
  static void write(Ostream& os, char t)
  { os << "\'" << t << "\'"; }
};

#if TYPEOUT_SUPPORT_CHAR16_T
template <>
struct _<char16_t>
{
  template <class Ostream>
  static void write(Ostream& os,char16_t t)
  { os << "(char16_t)\'" << t << "\'"; }
};
#endif

#if TYPEOUT_SUPPORT_CHAR32_T
template <>
struct _<char32_t>
{
  template <class Ostream>
  static void write(Ostream& os, char32_t t)
  { os << "(char32_t)\'" << t << "\'"; }
};
#endif

template <>
struct _<wchar_t>
{
  template <class Ostream>
  static void write(Ostream& os, wchar_t t)
  { os << "L\'" << t << "\'"; }
};

template <>
struct _<signed char>
{
  template <class Ostream>
  static void write(Ostream& os, signed char t)
  { os << "\'" << t << "\'"; }
};

template <>
struct _<short int>
{
  template <class Ostream>
  static void write(Ostream& os, short int t)
  { os << "(short int)" << t; }
};

template <>
struct _<int>
{
  template <class Ostream>
  static void write(Ostream& os, int t)
  { os <<  t; }
};

template <>
struct _<long int>
{
  template <class Ostream>
  static void write(Ostream& os, long int t)
  { os << t << "l"; }
};

template <>
struct _<long long int>
{
  template <class Ostream>
  static void write(Ostream& os, long long int t)
  { os << t << "ll"; }
};

template <>
struct _<unsigned char>
{
  template <class Ostream>
  static void write(Ostream& os, unsigned char t)
  { os << "(unsigned char)\'" << t << "\'"; }
};

template <>
struct _<unsigned int>
{
  template <class Ostream>
  static void write(Ostream& os, unsigned int t)
  { os << t << "u"; }
};

template <>
struct _<unsigned long int>
{
  template <class Ostream>
  static void write(Ostream& os, unsigned long int t)
  { os << t << "ul"; }
};
} /* namespace _tvalue */
} /* namespace typeout */

#endif /* TYPEOUT_TVALUE_FUNDAMENTAL_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
