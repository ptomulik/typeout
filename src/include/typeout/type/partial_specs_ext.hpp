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

// typeout/type/partial_specs_ext.hpp

/** // doc: typeout/type/partial_specs_ext.hpp {{{ 
 * \file typeout/type/partial_specs_ext.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TYPEOUT_TYPE_PARTIAL_SPECS_EXT_HPP_INCLUDED
#define TYPEOUT_TYPE_PARTIAL_SPECS_EXT_HPP_INCLUDED

#include <typeout/config.hpp>
#include <typeout/type.hpp>
#include <typeout/stream.hpp>

namespace typeout {

namespace _type {

// we need such a helper to print extents in correct order
// (without helper, the extents are printed in reverse).
template <typename E, std::size_t N>
struct _extents_helper
{
  template <typename Ostream>
  static void write(Ostream& os)
  { os << "[" << N << "]";  E::write(os);}
};

template <typename E>
struct _extents_helper<E,0>
{
  template <typename Ostream>
  static void write(Ostream& os)
  { os << "[]";  E::write(os);}
};

template <std::size_t N>
struct _extents_helper<void,N>
{
  template <typename Ostream>
  static void write(Ostream& os)
  { os << "[" << N << "]"; }
};

template <>
struct _extents_helper<void,0>
{
  template <typename Ostream>
  static void write(Ostream& os)
  { os << "[]"; }
};

template <typename T, std::size_t N>
struct _array_helper
{
  typedef _extents_helper<void,N> extents; 
  typedef T type_noext;
};

// array helper, to strip out and reverse array extents
template <typename T, std::size_t N, std::size_t M>
struct _array_helper<T[N],M>
{
  typedef typename _array_helper<T,N>::type_noext type_noext;
  typedef _extents_helper<typename _array_helper<T,N>::extents,M> extents; 
};

template <typename T>
struct _ <T[]>
{
  typedef typename _array_helper<T,0>::type_noext type_noext;
  typedef typename _array_helper<T,0>::extents extents;
  template <typename Ostream>
  static void write(Ostream& os)
  { _<type_noext>::write(os); extents::write(os); }
};

template <typename T>
struct _ <T const []>
{
  typedef typename _array_helper<T,0>::type_noext const type_noext;
  typedef typename _array_helper<T,0>::extents extents;
  template <typename Ostream>
  static void write(Ostream& os)
  { _<type_noext>::write(os); extents::write(os); }
};

template <typename T>
struct _ <T volatile []>
{
  typedef typename _array_helper<T,0>::type_noext volatile type_noext;
  typedef typename _array_helper<T,0>::extents extents;
  template <typename Ostream>
  static void write(Ostream& os)
  { _<type_noext>::write(os); extents::write(os); }
};

template <typename T>
struct _ <T const volatile []>
{
  typedef typename _array_helper<T,0>::type_noext const volatile type_noext;
  typedef typename _array_helper<T,0>::extents extents;
  template <typename Ostream>
  static void write(Ostream& os)
  { _<type_noext>::write(os); extents::write(os); }
};

template <typename T, std::size_t N>
struct _ <T[N]>
{
  typedef typename _array_helper<T,N>::type_noext type_noext;
  typedef typename _array_helper<T,N>::extents extents;
  template <typename Ostream>
  static void write(Ostream& os)
  { _<type_noext>::write(os); extents::write(os); }
};

template <typename T, std::size_t N>
struct _ <T const[N]>
{
  typedef typename _array_helper<T,N>::type_noext const type_noext;
  typedef typename _array_helper<T,N>::extents extents;
  template <typename Ostream>
  static void write(Ostream& os)
  { _<type_noext>::write(os); extents::write(os); }
};

template <typename T, std::size_t N>
struct _ <T volatile[N]>
{
  typedef typename _array_helper<T,N>::type_noext volatile type_noext;
  typedef typename _array_helper<T,N>::extents extents;
  template <typename Ostream>
  static void write(Ostream& os)
  { _<type_noext>::write(os); extents::write(os); }
};

template <typename T, std::size_t N>
struct _ <T const volatile[N]>
{
  typedef typename _array_helper<T,N>::type_noext const volatile type_noext;
  typedef typename _array_helper<T,N>::extents extents;
  template <typename Ostream>
  static void write(Ostream& os)
  { _<type_noext>::write(os); extents::write(os); }
};


} /* namespace _type */

} /* namespace typeout */


#endif /* TYPEOUT_TYPE_PARTIAL_SPECS_EXT_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
