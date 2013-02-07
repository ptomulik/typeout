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

// typeout/type/partial_specs_ref.hpp

/** // doc: typeout/type/partial_specs_ref.hpp {{{ 
 * \file typeout/type/partial_specs_ref.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TYPEOUT_TYPE_PARTIAL_SPECS_REF_HPP_INCLUDED
#define TYPEOUT_TYPE_PARTIAL_SPECS_REF_HPP_INCLUDED

#include <typeout/config.hpp>
#include <typeout/type.hpp>
#include <typeout/stream.hpp>

namespace typeout {

namespace _type {

template <typename T>
struct _ <T&>
{
  template <typename Ostream>
  static void write(Ostream& os)
  { _<T>::write(os); os << "&"; }
};

#if TYPEOUT_SUPPORT_RVALUE_REFERENCES
template <typename T>
struct _ <T&&>
{
  template <typename Ostream>
  static void write(Ostream& os)
  { _<T>::write(os); os << "&&"; }
};
#endif /* TYPEOUT_SUPPORT_RVALUE_REFERENCES */

} /* namespace _type */

} /* namespace typeout */


#endif /* TYPEOUT_TYPE_PARTIAL_SPECS_REF_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
