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

// typeout/tvalue/partial_specs_cv.hpp

/** // doc: typeout/tvalue/partial_specs_cv.hpp {{{ 
 * \file typeout/tvalue/partial_specs_cv.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TYPEOUT_TVALUE_PARTIAL_SPECS_CV_HPP_INCLUDED
#define TYPEOUT_TVALUE_PARTIAL_SPECS_CV_HPP_INCLUDED

#include <typeout/config.hpp>
#include <typeout/tvalue/class.hpp>

namespace typeout {
namespace _tvalue {
/*
template <typename T, T const t>
struct _<T const, t>
{
  template <class Ostream>
  static void write(Ostream& os)
  { _<T,t>::write(os); }
};

template <typename T, T volatile t>
struct _<T volatile, t>
{
  template <class Ostream>
  static void write(Ostream& os)
  { _<T,t>::write(os); }
};

template <typename T, T const volatile t>
struct _<T const volatile, t>
{
  template <class Ostream>
  static void write(Ostream& os)
  { _<T,t>::write(os); }
};
*/
} /*namespace _tvalue */
} /* namespace typeout */

#endif /* TYPEOUT_TVALUE_PARTIAL_SPECS_CV_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
