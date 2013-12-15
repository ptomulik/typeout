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

// typeout/value/fundamental.hpp

/** // doc: typeout/value/fundamental.hpp {{{ 
 * \file typeout/value/fundamental.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TYPEOUT_TVALUE_FUNDAMENTAL_HPP_INCLUDED
#define TYPEOUT_TVALUE_FUNDAMENTAL_HPP_INCLUDED

#include <typeout/config.hpp>
#include <typeout/value/info.hpp>

namespace typeout {
namespace _value {

template <>
struct info<bool>
{
  template <class Ostream>
  static Ostream& write(Ostream& os, bool x)
  { os << x ? "true" : "false"; return os; }
};

template <>
struct info<char>
{
  template <class Ostream>
  static Ostream& write(Ostream& os, char t)
  { os << "\'" << t << "\'"; return os; }
};

#if TYPEOUT_SUPPORT_CHAR16_T
template <>
struct info<char16_t>
{
  template <class Ostream>
  static Ostream& write(Ostream& os,char16_t t)
  { os << "(char16_t)\'" << t << "\'"; return os; }
};
#endif

#if TYPEOUT_SUPPORT_CHAR32_T
template <>
struct info<char32_t>
{
  template <class Ostream>
  static Ostream& write(Ostream& os, char32_t t)
  { os << "(char32_t)\'" << t << "\'"; return os; }
};
#endif

template <>
struct info<wchar_t>
{
  template <class Ostream>
  static Ostream& write(Ostream& os, wchar_t t)
  { os << "L\'" << t << "\'"; return os; }
};

template <>
struct info<signed char>
{
  template <class Ostream>
  static Ostream& write(Ostream& os, signed char t)
  { os << "\'" << t << "\'"; return os; }
};

template <>
struct info<short int>
{
  template <class Ostream>
  static Ostream& write(Ostream& os, short int t)
  { os << "(short int)" << t; return os; }
};

template <>
struct info<int>
{
  template <class Ostream>
  static Ostream& write(Ostream& os, int t)
  { os <<  t; return os; }
};

template <>
struct info<long int>
{
  template <class Ostream>
  static Ostream& write(Ostream& os, long int t)
  { os << t << "l"; return os; }
};

template <>
struct info<long long int>
{
  template <class Ostream>
  static Ostream& write(Ostream& os, long long int t)
  { os << t << "ll"; return os; }
};

template <>
struct info<unsigned char>
{
  template <class Ostream>
  static Ostream& write(Ostream& os, unsigned char t)
  { os << "(unsigned char)\'" << t << "\'"; return os; }
};

template <>
struct info<unsigned int>
{
  template <class Ostream>
  static Ostream& write(Ostream& os, unsigned int t)
  { os << t << "u"; return os; }
};

template <>
struct info<unsigned long int>
{
  template <class Ostream>
  static Ostream& write(Ostream& os, unsigned long int t)
  { os << t << "ul"; return os; }
};
} /* namespace _value */
} /* namespace typeout */

#endif /* TYPEOUT_TVALUE_FUNDAMENTAL_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
