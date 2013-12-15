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

// typeout/value/fptr.hpp

/** // doc: typeout/value/fptr.hpp {{{ 
 * \file typeout/value/fptr.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TYPEOUT_TVALUE_FPTR_HPP_INCLUDED
#define TYPEOUT_TVALUE_FPTR_HPP_INCLUDED

#include <typeout/value/info.hpp>
#include <typeout/type/fptr.hpp>

#include <map>
#include <string>

#include <boost/preprocessor/stringize.hpp>
/** // doc: TYPEOUT_REG_FPTR_AS(fptr,name) {{{
 * \todo Write documentation
 */ // }}}
#define TYPEOUT_REG_FPTR_AS(fptr,name) \
  ::typeout::_value::reg_fptr(fptr,name)

/** // doc: TYPEOUT_REG_FPTR(name) {{{
 * \todo Write documentation
 */ // }}}
#define TYPEOUT_REG_FPTR(fptr) \
  TYPEOUT_REG_FPTR_AS(fptr,BOOST_PP_STRINGIZE(fptr))

namespace typeout {
namespace _value {

template <typename T, typename... Args>
struct info<T(*)(Args...)>
{
  typedef T(*type)(Args...);
  typedef std::string name_type;

  static std::map<type, name_type>& instances()
  {
    static std::map<type,name_type> _instances;
    return _instances; 
  }

  template <class Ostream>
  static Ostream& write_resolved(Ostream& os, type f)
  {
    auto it = instances().find(f);
    if(it == instances().end())
      _type::info<type>::write(os << "(") << ")" 
        << reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(f));
    else 
      os << it->second;
    return os;
  }

  template <class Ostream>
  static Ostream& write(Ostream& os, type f)
  { return write_resolved(os,f); }
private:
  static std::map<type,name_type> _instances;
};

template<typename T, typename...Args>
void reg_fptr(T(*fptr)(Args...), std::string const& name)
{
  typedef info<T(*)(Args...)> X; 
  X::instances().insert(std::make_pair(fptr,name));
}

} /* namespace _value */
} /* namespace typeout */

#endif /* TYPEOUT_TVALUE_FPTR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
