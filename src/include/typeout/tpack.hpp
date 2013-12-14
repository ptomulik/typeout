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

// typeout/tpack.hpp

/** // doc: typeout/tpack.hpp {{{ 
 * \file typeout/tpack.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TYPEOUT_TPACK_HPP_INCLUDED
#define TYPEOUT_TPACK_HPP_INCLUDED

#include <typeout/type/class.hpp>

namespace typeout {
namespace _tpack {

template <class...> struct _;

template <class T, class...Tail>
struct _<T,Tail...>
{
  template<typename Ostream>
  static void write(Ostream& os)
  { _<T>::write(os); os << ", "; _<Tail...>::write(os); }
};
template <class T>
struct _<T>
{
  template<typename Ostream>
  static void write(Ostream& os)
  { _type::_<T>::write(os); }
};
template <>
struct _<>
{
  template<typename Ostream>
  static void write(Ostream&) { }
};

} /* namespace _tpack */
} /* namespace typeout */

#endif /* TYPEOUT_TPACK_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
