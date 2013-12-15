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

// typeout/type/fptr.hpp

/** // doc: typeout/type/fptr.hpp {{{ 
 * \file typeout/type/fptr.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TYPEOUT_TYPE_FPTR_HPP_INCLUDED
#define TYPEOUT_TYPE_FPTR_HPP_INCLUDED

#include <typeout/type/info.hpp>
#include <typeout/type/pack.hpp>

namespace typeout {
namespace _type {

/** // doc: info<T(*)(Args...)> {{{
 * \todo Write documentation
 */ // }}}
template <class T, class... Args>
struct info <T(*)(Args...)>
{
  template <typename Ostream>
  static Ostream& write(Ostream& os)
  { pack<Args...>::write( info<T>::write(os) << "(*)(" ) << ")"; return os; }
};

}
} /* namespace typeout */

#endif /* TYPEOUT_TYPE_FPTR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
