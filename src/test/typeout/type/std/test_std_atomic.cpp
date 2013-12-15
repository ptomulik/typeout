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
#if TYPEOUT_TEST_TYPE_STD_ATOMIC_ENABLED

#include <typeout/type/std/atomic.hpp>
#include <typeout/type/fundamental.hpp>
#include <typeout/stream/string.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(typeout)
BOOST_AUTO_TEST_SUITE(_type)

BOOST_AUTO_TEST_CASE(std_atomic)
{
  using _string::_;
  /* Integral types */
  BOOST_CHECK_EQUAL((_<std::atomic<char> >()),"std::atomic < char >");
  BOOST_CHECK_EQUAL((_<std::atomic<bool> >()),"std::atomic < bool >");

#if TYPEOUT_SUPPORT_CHAR16_T
  BOOST_CHECK_EQUAL((_<std::atomic<char16_t> >()),"std::atomic < char16_t >");
#endif
#if TYPEOUT_SUPPORT_CHAR32_T
  BOOST_CHECK_EQUAL((_<std::atomic<char32_t> >()),"std::atomic < char32_t >");
#endif

  BOOST_CHECK_EQUAL((_<std::atomic<wchar_t> >()),"std::atomic < wchar_t >");
  BOOST_CHECK_EQUAL((_<std::atomic<signed char> >()),"std::atomic < signed char >");
  BOOST_CHECK_EQUAL((_<std::atomic<short int> >()),"std::atomic < short int >");
  BOOST_CHECK_EQUAL((_<std::atomic<int> >()),"std::atomic < int >");
  BOOST_CHECK_EQUAL((_<std::atomic<long int> >()),"std::atomic < long int >");
  BOOST_CHECK_EQUAL((_<std::atomic<long long int> >()),"std::atomic < long long int >");
  BOOST_CHECK_EQUAL((_<std::atomic<unsigned char> >()),"std::atomic < unsigned char >");
  BOOST_CHECK_EQUAL((_<std::atomic<unsigned short int> >()),"std::atomic < unsigned short int >");
  BOOST_CHECK_EQUAL((_<std::atomic<unsigned int> >()),"std::atomic < unsigned int >");
  BOOST_CHECK_EQUAL((_<std::atomic<unsigned long int> >()),"std::atomic < unsigned long int >");
  BOOST_CHECK_EQUAL((_<std::atomic<unsigned long long int> >()),"std::atomic < unsigned long long int >");

  /* floating point types */
  BOOST_CHECK_EQUAL((_<std::atomic<float> >()),"std::atomic < float >");
  BOOST_CHECK_EQUAL((_<std::atomic<double> >()),"std::atomic < double >");
}

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()

#endif /* TYPEOUT_TEST_TYPE_STD_ATOMIC_ENABLED */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
