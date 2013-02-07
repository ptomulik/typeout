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
#if TYPEOUT_TEST_STREAMOUT_ENABLED

#include <typeout/write.hpp>
#include <typeout/reg_type.hpp>

#include <boost/test/unit_test.hpp>

TYPEOUT_REG_TYPE(char)

BOOST_AUTO_TEST_SUITE(test_streamout_unit)

template <typename T>
std::string rtstr_of()
{
  using namespace typeout;
  std::stringstream ss;
  ss << _streamout::_<T>;
  return ss.str();
}

template <typename T, T t>
std::string rtstr_of()
{
  using namespace typeout;
  std::stringstream ss;
  _streamout::_(ss,t);
  return ss.str();
}

BOOST_AUTO_TEST_CASE(types)
{
  BOOST_CHECK_EQUAL(rtstr_of<char>(), "char");
}
#if 0
BOOST_AUTO_TEST_CASE(integrals)
{
  BOOST_CHECK_EQUAL((rtstr_of<int,-1>()), "1");
}
#endif
BOOST_AUTO_TEST_SUITE_END()


#endif /* TYPEOUT_TEST_STREAMOUT_ENABLED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
