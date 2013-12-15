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
 * \todo Some types are currently commented-out, because they're unavailable on
 *  my implementation of std::ratio. It needs investigation and some
 *  preprocessor-based switching of what's going to be tested.
 */ // }}}
#include <typeout/test_config.hpp>
#if TYPEOUT_TEST_TYPE_STD_RATIO_ENABLED

#include <typeout/type/std/ratio.hpp>
#include <typeout/type/fundamental.hpp>
#include <typeout/stream/string.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(typeout)
BOOST_AUTO_TEST_SUITE(_type)

BOOST_AUTO_TEST_CASE(std_ratio)
{
  using _string::_;
  /* Integral types */
  //BOOST_CHECK_EQUAL((_<std::ratio<1,2> >()), "std::ratio < 1, 2 >");
  //BOOST_CHECK_EQUAL((_<std::yocto>()),  "std::yocto");
  //BOOST_CHECK_EQUAL((_<std::zepto>()),  "std::zepto");
  BOOST_CHECK_EQUAL((_<std::atto>()),   "std::atto");
  BOOST_CHECK_EQUAL((_<std::femto>()),  "std::femto");
  BOOST_CHECK_EQUAL((_<std::pico>()),   "std::pico");
  BOOST_CHECK_EQUAL((_<std::nano>()),   "std::nano");
  BOOST_CHECK_EQUAL((_<std::micro>()),  "std::micro");
  BOOST_CHECK_EQUAL((_<std::milli>()),  "std::milli");
  BOOST_CHECK_EQUAL((_<std::centi>()),  "std::centi");
  BOOST_CHECK_EQUAL((_<std::deci>()),   "std::deci");
  BOOST_CHECK_EQUAL((_<std::deca>()),   "std::deca");
  BOOST_CHECK_EQUAL((_<std::hecto>()),  "std::hecto");
  BOOST_CHECK_EQUAL((_<std::kilo>()),   "std::kilo");
  BOOST_CHECK_EQUAL((_<std::mega>()),   "std::mega");
  BOOST_CHECK_EQUAL((_<std::giga>()),   "std::giga");
  BOOST_CHECK_EQUAL((_<std::tera>()),   "std::tera");
  BOOST_CHECK_EQUAL((_<std::peta>()),   "std::peta");
  BOOST_CHECK_EQUAL((_<std::exa>()),    "std::exa");
  //BOOST_CHECK_EQUAL((_<std::zetta>()),  "std::zetta");
  //BOOST_CHECK_EQUAL((_<std::yotta>()),  "std::yotta");
}

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()

#endif /* TYPEOUT_TEST_TYPE_STD_RATIO_ENABLED */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
