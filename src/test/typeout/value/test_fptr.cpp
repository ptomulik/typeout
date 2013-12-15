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

/** // doc: typeout/value/test_fptr.cpp {{{
 * \file typeout/value/test_fptr.cpp
 * \todo Write documentation
 */ // }}}
#include <typeout/test_config.hpp>
#if TYPEOUT_TEST_TYPE_FPTR_ENABLED

#include <typeout/value/fptr.hpp>
#include <typeout/type/fundamental.hpp>
#include <typeout/type/partial_specs.hpp>
#include <typeout/value/partial_specs.hpp>
#include <typeout/stream/string.hpp>

#include <boost/test/unit_test.hpp>

namespace foo { namespace bar {
  void fun1() {}
  char fun2(int*) { return '\x0';}
  template <typename T> void fun3(T) { }
  void fun4() {}
}}


BOOST_AUTO_TEST_SUITE(typeout)
BOOST_AUTO_TEST_SUITE(_value)
BOOST_AUTO_TEST_SUITE(fptr)

BOOST_AUTO_TEST_CASE(unregistered)
{
  using _string::_;
  BOOST_CHECK_EQUAL(_<void(*)()>((void(*)())0x123),"(void(*)())0x123");
  BOOST_CHECK_EQUAL((_<void(*)(void)>(0)),"(void(*)())0");
  BOOST_CHECK_EQUAL((_<void(*)(int)>(0)),"(void(*)(int))0");
  BOOST_CHECK_EQUAL((_<void(*)(int,char)>(0)),"(void(*)(int, char))0");
  BOOST_CHECK_EQUAL((_<void(*)(int&,char*)>(0)),"(void(*)(int&, char*))0");
  BOOST_CHECK_EQUAL((_<int(*)()>(0)), "(int(*)())0");
  BOOST_CHECK_EQUAL((_<char&(*)(int const&)>(0)), "(char&(*)(int const&))0");
}

BOOST_AUTO_TEST_CASE(registered)
{
  using _string::_;
  TYPEOUT_REG_FPTR(&foo::bar::fun1);
  TYPEOUT_REG_FPTR(&foo::bar::fun2);
  TYPEOUT_REG_FPTR(&foo::bar::fun3<int>);
  BOOST_CHECK_EQUAL(_(&foo::bar::fun1), "&foo::bar::fun1");
  BOOST_CHECK_EQUAL(_(&foo::bar::fun2), "&foo::bar::fun2");
  BOOST_CHECK_EQUAL(_(&foo::bar::fun3<int>), "&foo::bar::fun3<int>");
}

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()

#endif /* TYPEOUT_TEST_TYPE_FPTR_ENABLED */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
