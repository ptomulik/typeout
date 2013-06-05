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
#if TYPEOUT_TEST_TYPE_STD_RATIO_ENABLED

#include <typeout/type/std/ratio.hpp>
#include <typeout/type/fundamental.hpp>
#include <boost/test/unit_test.hpp>

#include <sstream>

BOOST_AUTO_TEST_SUITE(test_type_std_ratio_unit)

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
  //BOOST_CHECK_EQUAL((_s<std::ratio<1,2> >()), "std::ratio < 1, 2 >");
  //BOOST_CHECK_EQUAL((_s<std::yocto>()),  "std::yocto");
  //BOOST_CHECK_EQUAL((_s<std::zepto>()),  "std::zepto");
  BOOST_CHECK_EQUAL((_s<std::atto>()),   "std::atto");
  BOOST_CHECK_EQUAL((_s<std::femto>()),  "std::femto");
  BOOST_CHECK_EQUAL((_s<std::pico>()),   "std::pico");
  BOOST_CHECK_EQUAL((_s<std::nano>()),   "std::nano");
  BOOST_CHECK_EQUAL((_s<std::micro>()),  "std::micro");
  BOOST_CHECK_EQUAL((_s<std::milli>()),  "std::milli");
  BOOST_CHECK_EQUAL((_s<std::centi>()),  "std::centi");
  BOOST_CHECK_EQUAL((_s<std::deci>()),   "std::deci");
  BOOST_CHECK_EQUAL((_s<std::deca>()),   "std::deca");
  BOOST_CHECK_EQUAL((_s<std::hecto>()),  "std::hecto");
  BOOST_CHECK_EQUAL((_s<std::kilo>()),   "std::kilo");
  BOOST_CHECK_EQUAL((_s<std::mega>()),   "std::mega");
  BOOST_CHECK_EQUAL((_s<std::giga>()),   "std::giga");
  BOOST_CHECK_EQUAL((_s<std::tera>()),   "std::tera");
  BOOST_CHECK_EQUAL((_s<std::peta>()),   "std::peta");
  BOOST_CHECK_EQUAL((_s<std::exa>()),    "std::exa");
  //BOOST_CHECK_EQUAL((_s<std::zetta>()),  "std::zetta");
  //BOOST_CHECK_EQUAL((_s<std::yotta>()),  "std::yotta");
}

BOOST_AUTO_TEST_SUITE_END()

#endif /* TYPEOUT_TEST_TYPE_STD_RATIO_ENABLED */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
