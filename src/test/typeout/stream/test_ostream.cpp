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

/** // doc: typeout/stream/test_ostream.cpp {{{
 * \file typeout/stream/test_ostream.cpp
 * \todo Write documentation
 */ // }}}
#include <typeout/test_config.hpp>
#if TYPEOUT_TEST_STREAM_OSTREAM_ENABLED

#include <typeout/stream/ostream.hpp>
#include <typeout/reg_type.hpp>
#include <boost/test/unit_test.hpp>
#include <sstream>

TYPEOUT_REG_TYPE(char)
TYPEOUT_REG_TYPE(int)

BOOST_AUTO_TEST_SUITE(typeout)
BOOST_AUTO_TEST_SUITE(_ostream)

BOOST_AUTO_TEST_SUITE(with_std_stringstream)

template<typename... Types>
std::string __ ()
{
  std::stringstream ss;
  ss << _<Types...>;
  return ss.str();
}
/*
template<typename T>
std::string __ (T t)
{
  using _type::_;
  std::stringstream ss;
  ss << _<T>(t);
  return ss.str();
}
*/
BOOST_AUTO_TEST_CASE(types)
{
  BOOST_CHECK_EQUAL(__<>(),"");
  BOOST_CHECK_EQUAL(__<int>(),"int");
  BOOST_CHECK_EQUAL((__<int,char>()),"int, char");
}

BOOST_AUTO_TEST_CASE(values)
{
  //BOOST_CHECK_EQUAL((__<int>(0)),"0");
  //BOOST_CHECK_EQUAL((__<unsigned int>(0)),"0u");
}
BOOST_AUTO_TEST_SUITE_END()


// few simple tests to ensure, that _ostream compiles when used with
// boost::unit_test::lazy_ostream (used by BOST_XXX_MESSAGE, etc.)
BOOST_AUTO_TEST_SUITE(with_boost_test_ostream)
BOOST_AUTO_TEST_CASE(types)
{
  BOOST_TEST_CHECKPOINT("streaming out _<>         : " << _<>);
  BOOST_TEST_CHECKPOINT("streaming out _<int>      : " << _<int>);
  BOOST_TEST_CHECKPOINT("streaming out _<int,char> : " << (_<int, char>));
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()


#endif /* TYPEOUT_TEST_STREAM_OSTREAM_ENABLED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
