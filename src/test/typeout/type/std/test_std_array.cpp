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
#if TYPEOUT_TEST_TYPE_STD_ARRAY_ENABLED

#include <typeout/type/std/array.hpp>
#include <typeout/type/fundamental.hpp>
#include <typeout/value/fundamental.hpp>
#include <typeout/stream/string.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(typeout)
BOOST_AUTO_TEST_SUITE(_type)

BOOST_AUTO_TEST_CASE(std_array)
{
  using _string::_;
  /* Integral types */
  BOOST_CHECK_EQUAL((_<std::array<char,1ul> >()),"std::array < char, 1ul >");
  BOOST_CHECK_EQUAL((_<std::array<char,2ul> >()),"std::array < char, 2ul >");
  BOOST_CHECK_EQUAL((_<std::array<char,3ul> >()),"std::array < char, 3ul >");
  BOOST_CHECK_EQUAL((_<std::array<bool,2ul> >()),"std::array < bool, 2ul >");

#if TYPEOUT_SUPPORT_CHAR16_T
  BOOST_CHECK_EQUAL((_<std::array<char16_t,2ul> >()),"std::array < char16_t, 2ul >");
#endif
#if TYPEOUT_SUPPORT_CHAR32_T
  BOOST_CHECK_EQUAL((_<std::array<char32_t,2ul> >()),"std::array < char32_t, 2ul >");
#endif

  BOOST_CHECK_EQUAL((_<std::array<wchar_t,2ul> >()),"std::array < wchar_t, 2ul >");
  BOOST_CHECK_EQUAL((_<std::array<signed char,2ul> >()),"std::array < signed char, 2ul >");
  BOOST_CHECK_EQUAL((_<std::array<short int,2ul> >()),"std::array < short int, 2ul >");
  BOOST_CHECK_EQUAL((_<std::array<int,2ul> >()),"std::array < int, 2ul >");
  BOOST_CHECK_EQUAL((_<std::array<long int,2ul> >()),"std::array < long int, 2ul >");
  BOOST_CHECK_EQUAL((_<std::array<long long int,2ul> >()),"std::array < long long int, 2ul >");
  BOOST_CHECK_EQUAL((_<std::array<unsigned char,2ul> >()),"std::array < unsigned char, 2ul >");
  BOOST_CHECK_EQUAL((_<std::array<unsigned short int,2ul> >()),"std::array < unsigned short int, 2ul >");
  BOOST_CHECK_EQUAL((_<std::array<unsigned int,2ul> >()),"std::array < unsigned int, 2ul >");
  BOOST_CHECK_EQUAL((_<std::array<unsigned long int,2ul> >()),"std::array < unsigned long int, 2ul >");
  BOOST_CHECK_EQUAL((_<std::array<unsigned long long int,2ul> >()),"std::array < unsigned long long int, 2ul >");

  /* floating point types */
  BOOST_CHECK_EQUAL((_<std::array<float,2ul> >()),"std::array < float, 2ul >");
  BOOST_CHECK_EQUAL((_<std::array<double,2ul> >()),"std::array < double, 2ul >");
}

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()

#endif /* TYPEOUT_TEST_TYPE_STD_ARRAY_ENABLED */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
