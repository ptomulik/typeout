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

/** // doc: typeout/type/test_fundamental.cpp {{{
 * \file typeout/type/test_fundamental.cpp
 * \todo Write documentation
 */ // }}}
#include <typeout/test_config.hpp>
#if TYPEOUT_TEST_TYPE_FUNDAMENTAL_ENABLED

#include <typeout/type/fundamental.hpp>
#include <typeout/stream/string.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(typeout)
BOOST_AUTO_TEST_SUITE(_type)

// Check if the registration of fundamental types produced correct
// meta-classes.
BOOST_AUTO_TEST_CASE(fundamental)
{
  using _string::_;

  /* void */
  BOOST_CHECK_EQUAL(_<void>(),"void");

  /* Integral types */
  BOOST_CHECK_EQUAL(_<bool>(),"bool");
  BOOST_CHECK_EQUAL(_<char>(),"char");

#if TYPEOUT_SUPPORT_CHAR16_T
  BOOST_CHECK_EQUAL(_<char16_t>(),"char16_t");
#endif
#if TYPEOUT_SUPPORT_CHAR32_T
  BOOST_CHECK_EQUAL(_<char32_t>(),"char32_t");
#endif

  BOOST_CHECK_EQUAL(_<wchar_t>(),"wchar_t");
  BOOST_CHECK_EQUAL(_<signed char>(),"signed char");
  BOOST_CHECK_EQUAL(_<short int>(),"short int");
  BOOST_CHECK_EQUAL(_<int>(),"int");
  BOOST_CHECK_EQUAL(_<long int>(),"long int");
  BOOST_CHECK_EQUAL(_<long long int>(),"long long int");
  BOOST_CHECK_EQUAL(_<unsigned char>(),"unsigned char");
  BOOST_CHECK_EQUAL(_<unsigned short int>(),"unsigned short int");
  BOOST_CHECK_EQUAL(_<unsigned int>(),"unsigned int");
  BOOST_CHECK_EQUAL(_<unsigned long int>(),"unsigned long int");
  BOOST_CHECK_EQUAL(_<unsigned long long int>(),"unsigned long long int");

  /* floating point types */
  BOOST_CHECK_EQUAL(_<float>(),"float");
  BOOST_CHECK_EQUAL(_<double>(),"double");
}

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()

#endif /* TYPEOUT_TEST_TYPE_FUNDAMENTAL_ENABLED */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
