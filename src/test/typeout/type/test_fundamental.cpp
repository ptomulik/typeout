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
#include <boost/test/unit_test.hpp>

#include <sstream>

BOOST_AUTO_TEST_SUITE(test_type_fundamental_unit)

template <typename T>
std::string rtstr_of()
{
  std::stringstream ss;
  typeout::_type::_<T>::write(ss);
  return ss.str();
}

// Check if the registration of fundamental types produced correct
// meta-classes.
BOOST_AUTO_TEST_CASE(type_names)
{
  /* void */
  BOOST_CHECK_EQUAL(rtstr_of<void>(),"void");

  /* Integral types */
  BOOST_CHECK_EQUAL(rtstr_of<bool>(),"bool");
  BOOST_CHECK_EQUAL(rtstr_of<char>(),"char");

#if TYPEOUT_SUPPORT_CHAR16_T
  BOOST_CHECK_EQUAL(rtstr_of<char16_t>(),"char16_t");
#endif
#if TYPEOUT_SUPPORT_CHAR32_T
  BOOST_CHECK_EQUAL(rtstr_of<char32_t>(),"char32_t");
#endif

  BOOST_CHECK_EQUAL(rtstr_of<wchar_t>(),"wchar_t");
  BOOST_CHECK_EQUAL(rtstr_of<signed char>(),"signed char");
  BOOST_CHECK_EQUAL(rtstr_of<short int>(),"short int");
  BOOST_CHECK_EQUAL(rtstr_of<int>(),"int");
  BOOST_CHECK_EQUAL(rtstr_of<long int>(),"long int");
  BOOST_CHECK_EQUAL(rtstr_of<long long int>(),"long long int");
  BOOST_CHECK_EQUAL(rtstr_of<unsigned char>(),"unsigned char");
  BOOST_CHECK_EQUAL(rtstr_of<unsigned short int>(),"unsigned short int");
  BOOST_CHECK_EQUAL(rtstr_of<unsigned int>(),"unsigned int");
  BOOST_CHECK_EQUAL(rtstr_of<unsigned long int>(),"unsigned long int");
  BOOST_CHECK_EQUAL(rtstr_of<unsigned long long int>(),"unsigned long long int");

  /* floating point types */
  BOOST_CHECK_EQUAL(rtstr_of<float>(),"float");
  BOOST_CHECK_EQUAL(rtstr_of<double>(),"double");
}

BOOST_AUTO_TEST_SUITE_END()

#endif /* TYPEOUT_TEST_TYPE_FUNDAMENTAL_ENABLED */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
