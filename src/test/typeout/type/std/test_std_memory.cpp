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
#if TYPEOUT_TEST_TYPE_STD_MEMORY_ENABLED

#include <typeout/type/std/memory.hpp>
#include <typeout/type/fundamental.hpp>
#include <typeout/stream/string.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(typeout)
BOOST_AUTO_TEST_SUITE(_type)

BOOST_AUTO_TEST_CASE(std_memory)
{
  using _string::_;
  /* Integral types */
  BOOST_CHECK_EQUAL((_<std::allocator < int > >()),"std::allocator < int >");
  BOOST_CHECK_EQUAL((_<std::allocator < double > >()),"std::allocator < double >");
# if TYPEOUT_SUPPORT_CXX11_ALLOCATOR
  BOOST_CHECK_EQUAL((_<std::allocator_traits < std::allocator < int > > >()), 
                       "std::allocator_traits < std::allocator < int > >");
  BOOST_CHECK_EQUAL((_<std::allocator_arg_t>()), "std::allocator_arg_t");
  BOOST_CHECK_EQUAL((_<std::uses_allocator < int*, std::allocator < int > > >()), 
                       "std::uses_allocator < int*, std::allocator < int > >");
# endif
  BOOST_CHECK_EQUAL((_<std::auto_ptr < int > >()),"std::auto_ptr < int >");
#  if TYPEOUT_SUPPORT_STD_SMART_PTR
  BOOST_CHECK_EQUAL((_<std::shared_ptr < int > >()),"std::shared_ptr < int >");
  BOOST_CHECK_EQUAL((_<std::unique_ptr < int, std::default_delete < int > > >()),
                       "std::unique_ptr < int, std::default_delete < int > >");
  BOOST_CHECK_EQUAL((_<std::weak_ptr < int > >()), "std::weak_ptr < int >");
  BOOST_CHECK_EQUAL((_<std::owner_less < std::shared_ptr < int > > >()),
                       "std::owner_less < std::shared_ptr < int > >");
  BOOST_CHECK_EQUAL((_<std::enable_shared_from_this < int > >()),
                       "std::enable_shared_from_this < int >");
  BOOST_CHECK_EQUAL((_<std::default_delete < int > >()),
                       "std::default_delete < int >");
  BOOST_CHECK_EQUAL((_<std::bad_weak_ptr>()), "std::bad_weak_ptr");
  // FIXME: This is perhaps not the best place for pointer_traits (it's not
  // tightly related to SMART_PTR)
  BOOST_CHECK_EQUAL((_<std::pointer_traits < int* > >()),
                       "std::pointer_traits < int* >");
# endif
}

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()

#endif /* TYPEOUT_TEST_TYPE_STD_MEMORY_ENABLED */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
