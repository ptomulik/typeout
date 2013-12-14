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

// typeout/stream/ostream.hpp

/** // doc: typeout/stream/ostream.hpp {{{ 
 * \file typeout/stream/ostream.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TYPEOUT_STREAM_OSTREAM_HPP_INCLUDED
#define TYPEOUT_STREAM_OSTREAM_HPP_INCLUDED

#include <typeout/config.hpp>
#include <typeout/type/class.hpp>
#include <typeout/tvalue/class.hpp>
#include <ostream>

namespace typeout {
namespace _ostream {
template <typename T, class CharT, class Traits>
std::basic_ostream<CharT, Traits>& 
_ (std::basic_ostream<CharT, Traits>& os)
{
  ::typeout::_type::_<T>::write(os);
  return os;
}

template <typename T, T t, class CharT, class Traits>
std::basic_ostream<CharT, Traits>& 
_ (std::basic_ostream<CharT, Traits>& os)
{
  ::typeout::_tvalue::_<T>::write(os,t);
  return os;
}
} /* namespace _ostream */
} /* namespace typeout */

#endif /* TYPEOUT_STREAM_OSTREAM_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
