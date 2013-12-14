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

/** // doc: typeout/test_streamout.cpp {{{
 * \file typeout/test_streamout.cpp
 * \todo Write documentation
 */ // }}}
#include <typeout/test_config.hpp>
#if TYPEOUT_TEST_TPACK_ENABLED

#include <typeout/tpack.hpp>
#include <typeout/reg_type.hpp>
#include <boost/test/unit_test.hpp>

TYPEOUT_REG_TYPE(char)
TYPEOUT_REG_TYPE(int)

BOOST_AUTO_TEST_SUITE(test_tpack_unit)

template <class...Args>
std::string _s()
{
  std::stringstream ss;
  typeout::_tpack::_<Args...>::write(ss);
  return ss.str();
}

BOOST_AUTO_TEST_CASE(zero_args)
{
  BOOST_CHECK_EQUAL(_s<>(), "");
}
BOOST_AUTO_TEST_CASE(one_arg)
{
  BOOST_CHECK_EQUAL(_s<char>(), "char");
  BOOST_CHECK_EQUAL(_s<int>(), "int");
}
BOOST_AUTO_TEST_CASE(multiple_args)
{
  BOOST_CHECK_EQUAL((_s<char,int>()), "char, int");
  BOOST_CHECK_EQUAL((_s<int,char>()), "int, char");
  BOOST_CHECK_EQUAL((_s<int,char,char>()), "int, char, char");
}
BOOST_AUTO_TEST_SUITE_END()


#endif /* TYPEOUT_TEST_STREAMOUT_ENABLED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
