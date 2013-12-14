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

/** // doc: typeout/tvalue/test_fptr.cpp {{{
 * \file typeout/tvalue/test_fptr.cpp
 * \todo Write documentation
 */ // }}}
#include <typeout/test_config.hpp>
#if TYPEOUT_TEST_TYPE_FPTR_ENABLED

#include <typeout/tvalue/class.hpp>
#include <typeout/type/fundamental.hpp>
#include <typeout/type/fptr.hpp>
//#include <typeout/tvalue/partial_specs.hpp>

#include <boost/test/unit_test.hpp>

#include <sstream>

BOOST_AUTO_TEST_SUITE(test_tvalue_fptr_unit)

template <typename T>
std::string _s()
{
  std::stringstream ss;
  typeout::_tvalue::_<T>::write(ss,(T)0);
  return ss.str();
}

BOOST_AUTO_TEST_CASE(type_names)
{
  BOOST_CHECK_EQUAL((_s<void(*)()>()),"(void(*)())0");
  /*
  BOOST_CHECK_EQUAL((_s<void(*)(void)>()),"(void(*)())0");
  BOOST_CHECK_EQUAL((_s<void(*)(int)>()),"(void(*)(int))0");
  BOOST_CHECK_EQUAL((_s<void(*)(int,char)>()),"void(*)(int, char)0");
  BOOST_CHECK_EQUAL((_s<void(*)(int&,char*)>()),"void(*)(int&, char*)0");
  BOOST_CHECK_EQUAL((_s<int(*)()>()), "int(*)()0");
  BOOST_CHECK_EQUAL((_s<char&(*)(int const&)>()), "char&(*)(int const&)0");
  */
}

BOOST_AUTO_TEST_SUITE_END()

#endif /* TYPEOUT_TEST_TYPE_FPTR_ENABLED */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
