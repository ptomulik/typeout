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

// typeout/stream/string.hpp

/** // doc: typeout/stream/string.hpp {{{
 * \file typeout/stream/string.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TYPEOUT_STREAM_STRING_HPP_INCLUDED
#define TYPEOUT_STREAM_STRING_HPP_INCLUDED

#include <typeout/type/pack.hpp>
#include <typeout/value/info.hpp>
#include <string>
#include <sstream>

namespace typeout {
namespace _string {

template <typename... Types>
std::string _ ()
{
  std::ostringstream ss;
  return _type::pack<Types...>::write(ss).str();
}

template <typename T>
std::string _ (T t)
{
  std::ostringstream ss;
  return _value::info<T>::write(ss,t).str();
}

} /* namespace _string */
} /* namespace typeout */

#endif /* TYPEOUT_STREAM_STRING_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
