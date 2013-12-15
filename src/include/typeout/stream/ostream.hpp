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
#include <typeout/type/pack.hpp>
#include <typeout/value/info.hpp>
#include <ostream>

namespace typeout {
namespace _ostream {

/** // doc: std::ostream& _<Types...> (std::ostream&) {{{
 * \todo Write documentation
 */ // }}}
template <typename...Types>
std::ostream& _ (std::ostream& os)
{ return _type::pack<Types...>::write(os); }
#if 0
/** // doc: std::ostream& _<T> (std::ostream&) {{{
 * \todo Write documentation
 */ // }}}
template <typename T>
std::ostream& _ (std::ostream& os)
{ return _type::_<std::ostream,T>::write(os); }
#endif
/** // doc: std::ostream& _<T,t> (std::ostream&) {{{
 * \todo Write documentation
 */ // }}}
template <typename T, T t>
std::ostream& _ (std::ostream& os)
{ return _value::info<T>::write(os,t); }

} /* namespace _ostream */
} /* namespace typeout */

#if 0
namespace std {
template <typename T>
ostream& operator << (ostream& os, typeout::_type::base<T> x)
{ return x.dump(os); }
} /* namespace std */
#endif

#endif /* TYPEOUT_STREAM_OSTREAM_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
