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

/** // doc: typeout/type/test_partial_specs_ext1_cv_ptr_cv.cpp {{{
 * \file typeout/type/test_partial_specs_ext1_cv_ptr_cv.cpp
 * \todo Write documentation
 */ // }}}
#include <typeout/test_config.hpp>
#if TYPEOUT_TEST_TYPE_PARTIAL_SPECS_EXT1_CV_PTR_CV_ENABLED

#include <typeout/type/partial_specs_ext.hpp>
#include <typeout/type/partial_specs_cv.hpp>
#include <typeout/type/partial_specs_ptr.hpp>
#include <typeout/reg_type.hpp>
#include <typeout/stream/string.hpp>
#include <boost/test/unit_test.hpp>

// We don't include "type/fundamentals.hpp", so we must register locally
// the types we use.
TYPEOUT_REG_TYPE(char)

BOOST_AUTO_TEST_SUITE(typeout)
BOOST_AUTO_TEST_SUITE(_type)
BOOST_AUTO_TEST_SUITE(extents)

BOOST_AUTO_TEST_CASE(cv_ptr_cv_with_leading_dim)
{
  using _string::_;
  BOOST_CHECK_EQUAL(_<char const* const[1]>(),"char const* const[1]");
  BOOST_CHECK_EQUAL(_<char const* const[1][2]>(),"char const* const[1][2]");
  BOOST_CHECK_EQUAL(_<char const* const[1][2][3]>(),"char const* const[1][2][3]");
  BOOST_CHECK_EQUAL(_<char const* const[1][2][3][4]>(),"char const* const[1][2][3][4]");
  BOOST_CHECK_EQUAL(_<char const* const[1][2][3][4][5]>(),"char const* const[1][2][3][4][5]");

  BOOST_CHECK_EQUAL(_<char const* volatile[1]>(),"char const* volatile[1]");
  BOOST_CHECK_EQUAL(_<char const* volatile[1][2]>(),"char const* volatile[1][2]");
  BOOST_CHECK_EQUAL(_<char const* volatile[1][2][3]>(),"char const* volatile[1][2][3]");
  BOOST_CHECK_EQUAL(_<char const* volatile[1][2][3][4]>(),"char const* volatile[1][2][3][4]");
  BOOST_CHECK_EQUAL(_<char const* volatile[1][2][3][4][5]>(),"char const* volatile[1][2][3][4][5]");

  BOOST_CHECK_EQUAL(_<char const* const volatile[1]>(),"char const* const volatile[1]");
  BOOST_CHECK_EQUAL(_<char const* const volatile[1][2]>(),"char const* const volatile[1][2]");
  BOOST_CHECK_EQUAL(_<char const* const volatile[1][2][3]>(),"char const* const volatile[1][2][3]");
  BOOST_CHECK_EQUAL(_<char const* const volatile[1][2][3][4]>(),"char const* const volatile[1][2][3][4]");
  BOOST_CHECK_EQUAL(_<char const* const volatile[1][2][3][4][5]>(),"char const* const volatile[1][2][3][4][5]");

  BOOST_CHECK_EQUAL(_<char volatile* const[1]>(),"char volatile* const[1]");
  BOOST_CHECK_EQUAL(_<char volatile* const[1][2]>(),"char volatile* const[1][2]");
  BOOST_CHECK_EQUAL(_<char volatile* const[1][2][3]>(),"char volatile* const[1][2][3]");
  BOOST_CHECK_EQUAL(_<char volatile* const[1][2][3][4]>(),"char volatile* const[1][2][3][4]");
  BOOST_CHECK_EQUAL(_<char volatile* const[1][2][3][4][5]>(),"char volatile* const[1][2][3][4][5]");

  BOOST_CHECK_EQUAL(_<char volatile* volatile[1]>(),"char volatile* volatile[1]");
  BOOST_CHECK_EQUAL(_<char volatile* volatile[1][2]>(),"char volatile* volatile[1][2]");
  BOOST_CHECK_EQUAL(_<char volatile* volatile[1][2][3]>(),"char volatile* volatile[1][2][3]");
  BOOST_CHECK_EQUAL(_<char volatile* volatile[1][2][3][4]>(),"char volatile* volatile[1][2][3][4]");
  BOOST_CHECK_EQUAL(_<char volatile* volatile[1][2][3][4][5]>(),"char volatile* volatile[1][2][3][4][5]");

  BOOST_CHECK_EQUAL(_<char volatile* const volatile[1]>(),"char volatile* const volatile[1]");
  BOOST_CHECK_EQUAL(_<char volatile* const volatile[1][2]>(),"char volatile* const volatile[1][2]");
  BOOST_CHECK_EQUAL(_<char volatile* const volatile[1][2][3]>(),"char volatile* const volatile[1][2][3]");
  BOOST_CHECK_EQUAL(_<char volatile* const volatile[1][2][3][4]>(),"char volatile* const volatile[1][2][3][4]");
  BOOST_CHECK_EQUAL(_<char volatile* const volatile[1][2][3][4][5]>(),"char volatile* const volatile[1][2][3][4][5]");

  BOOST_CHECK_EQUAL(_<char const volatile* const[1]>(),"char const volatile* const[1]");
  BOOST_CHECK_EQUAL(_<char const volatile* const[1][2]>(),"char const volatile* const[1][2]");
  BOOST_CHECK_EQUAL(_<char const volatile* const[1][2][3]>(),"char const volatile* const[1][2][3]");
  BOOST_CHECK_EQUAL(_<char const volatile* const[1][2][3][4]>(),"char const volatile* const[1][2][3][4]");
  BOOST_CHECK_EQUAL(_<char const volatile* const[1][2][3][4][5]>(),"char const volatile* const[1][2][3][4][5]");

  BOOST_CHECK_EQUAL(_<char const volatile* volatile[1]>(),"char const volatile* volatile[1]");
  BOOST_CHECK_EQUAL(_<char const volatile* volatile[1][2]>(),"char const volatile* volatile[1][2]");
  BOOST_CHECK_EQUAL(_<char const volatile* volatile[1][2][3]>(),"char const volatile* volatile[1][2][3]");
  BOOST_CHECK_EQUAL(_<char const volatile* volatile[1][2][3][4]>(),"char const volatile* volatile[1][2][3][4]");
  BOOST_CHECK_EQUAL(_<char const volatile* volatile[1][2][3][4][5]>(),"char const volatile* volatile[1][2][3][4][5]");

  BOOST_CHECK_EQUAL(_<char const volatile* const volatile[1]>(),"char const volatile* const volatile[1]");
  BOOST_CHECK_EQUAL(_<char const volatile* const volatile[1][2]>(),"char const volatile* const volatile[1][2]");
  BOOST_CHECK_EQUAL(_<char const volatile* const volatile[1][2][3]>(),"char const volatile* const volatile[1][2][3]");
  BOOST_CHECK_EQUAL(_<char const volatile* const volatile[1][2][3][4]>(),"char const volatile* const volatile[1][2][3][4]");
  BOOST_CHECK_EQUAL(_<char const volatile* const volatile[1][2][3][4][5]>(),"char const volatile* const volatile[1][2][3][4][5]");
}

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()

#endif /* TYPEOUT_TEST_TYPE_PARTIAL_SPECS_EXT1_CV_PTR_CV_ENABLED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
