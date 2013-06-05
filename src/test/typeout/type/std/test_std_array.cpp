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
#include <boost/test/unit_test.hpp>

#include <sstream>

BOOST_AUTO_TEST_SUITE(test_type_std_array_unit)

template <typename T>
std::string _s()
{
  std::stringstream ss;
  typeout::_type::_<T>::write(ss);
  return ss.str();
}

BOOST_AUTO_TEST_CASE(type_names)
{
  /* Integral types */
  BOOST_CHECK_EQUAL((_s<std::array<char,1> >()),"std::array < char, 1 >");
  BOOST_CHECK_EQUAL((_s<std::array<char,2> >()),"std::array < char, 2 >");
  BOOST_CHECK_EQUAL((_s<std::array<char,3> >()),"std::array < char, 3 >");
  BOOST_CHECK_EQUAL((_s<std::array<bool,2> >()),"std::array < bool, 2 >");

#if TYPEOUT_SUPPORT_CHAR16_T
  BOOST_CHECK_EQUAL((_s<std::array<char16_t,2> >()),"std::array < char16_t, 2 >");
#endif
#if TYPEOUT_SUPPORT_CHAR32_T
  BOOST_CHECK_EQUAL((_s<std::array<char32_t,2> >()),"std::array < char32_t, 2 >");
#endif

  BOOST_CHECK_EQUAL((_s<std::array<wchar_t,2> >()),"std::array < wchar_t, 2 >");
  BOOST_CHECK_EQUAL((_s<std::array<signed char,2> >()),"std::array < signed char, 2 >");
  BOOST_CHECK_EQUAL((_s<std::array<short int,2> >()),"std::array < short int, 2 >");
  BOOST_CHECK_EQUAL((_s<std::array<int,2> >()),"std::array < int, 2 >");
  BOOST_CHECK_EQUAL((_s<std::array<long int,2> >()),"std::array < long int, 2 >");
  BOOST_CHECK_EQUAL((_s<std::array<long long int,2> >()),"std::array < long long int, 2 >");
  BOOST_CHECK_EQUAL((_s<std::array<unsigned char,2> >()),"std::array < unsigned char, 2 >");
  BOOST_CHECK_EQUAL((_s<std::array<unsigned short int,2> >()),"std::array < unsigned short int, 2 >");
  BOOST_CHECK_EQUAL((_s<std::array<unsigned int,2> >()),"std::array < unsigned int, 2 >");
  BOOST_CHECK_EQUAL((_s<std::array<unsigned long int,2> >()),"std::array < unsigned long int, 2 >");
  BOOST_CHECK_EQUAL((_s<std::array<unsigned long long int,2> >()),"std::array < unsigned long long int, 2 >");

  /* floating point types */
  BOOST_CHECK_EQUAL((_s<std::array<float,2> >()),"std::array < float, 2 >");
  BOOST_CHECK_EQUAL((_s<std::array<double,2> >()),"std::array < double, 2 >");
}

BOOST_AUTO_TEST_SUITE_END()

#endif /* TYPEOUT_TEST_TYPE_STD_ARRAY_ENABLED */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
