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

// typeout/test_config.hpp

/** // doc: typeout/test_config.hpp {{{ 
 * \file typeout/test_config.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TYPEOUT_TEST_CONFIG_HPP_INCLUDED
#define TYPEOUT_TEST_CONFIG_HPP_INCLUDED

#include <typeout/config.hpp>

#define TYPEOUT_TEST_TYPE_FUNDAMENTAL_ENABLED 1
#define TYPEOUT_TEST_TYPE_FPTR_ENABLED 1
#define TYPEOUT_TEST_TYPE_PARTIAL_SPECS_ENABLED 1

#define TYPEOUT_TEST_TYPE_PARTIAL_SPECS_CV_ENABLED 1
#define TYPEOUT_TEST_TYPE_PARTIAL_SPECS_PTR_ENABLED 1
#define TYPEOUT_TEST_TYPE_PARTIAL_SPECS_REF_ENABLED 1
#define TYPEOUT_TEST_TYPE_PARTIAL_SPECS_EXT1_ENABLED 1
#define TYPEOUT_TEST_TYPE_PARTIAL_SPECS_EXT1_CV_ENABLED 1
#define TYPEOUT_TEST_TYPE_PARTIAL_SPECS_EXT1_PTR_ENABLED 1
#define TYPEOUT_TEST_TYPE_PARTIAL_SPECS_EXT1_CV_PTR_ENABLED 1
#define TYPEOUT_TEST_TYPE_PARTIAL_SPECS_EXT1_PTR_CV_ENABLED 1
#define TYPEOUT_TEST_TYPE_PARTIAL_SPECS_EXT1_CV_PTR_CV_ENABLED 1
#define TYPEOUT_TEST_TYPE_PARTIAL_SPECS_EXT2_ENABLED 1
#define TYPEOUT_TEST_TYPE_PARTIAL_SPECS_EXT2_CV_ENABLED 1
#define TYPEOUT_TEST_TYPE_PARTIAL_SPECS_EXT2_PTR_ENABLED 1
#define TYPEOUT_TEST_TYPE_PARTIAL_SPECS_EXT2_CV_PTR_ENABLED 1
#define TYPEOUT_TEST_TYPE_PARTIAL_SPECS_EXT2_PTR_CV_ENABLED 1
#define TYPEOUT_TEST_TYPE_PARTIAL_SPECS_EXT2_CV_PTR_CV_ENABLED 1

//
// std::
//
#define TYPEOUT_TEST_TYPE_STD_ARRAY_ENABLED TYPEOUT_SUPPORT_STD_ARRAY
#define TYPEOUT_TEST_TYPE_STD_ATOMIC_ENABLED TYPEOUT_SUPPORT_STD_ATOMIC
#define TYPEOUT_TEST_TYPE_STD_BITSET_ENABLED TYPEOUT_SUPPORT_STD_BITSET
#define TYPEOUT_TEST_TYPE_STD_CHRONO_ENABLED TYPEOUT_SUPPORT_STD_CHRONO
#define TYPEOUT_TEST_TYPE_STD_CLOCALE_ENABLED TYPEOUT_SUPPORT_STD_CLOCALE
#define TYPEOUT_TEST_TYPE_STD_CMATH_ENABLED TYPEOUT_SUPPORT_STD_CMATH
#define TYPEOUT_TEST_TYPE_STD_COMPLEX_ENABLED TYPEOUT_SUPPORT_STD_COMPLEX
#define TYPEOUT_TEST_TYPE_STD_CONDITION_VARIABLE_ENABLED TYPEOUT_SUPPORT_STD_CONDITION_VARIABLE
#define TYPEOUT_TEST_TYPE_STD_CTIME_ENABLED TYPEOUT_SUPPORT_STD_CTIME
#define TYPEOUT_TEST_TYPE_STD_CWCHAR_ENABLED TYPEOUT_SUPPORT_STD_CWCHAR
#define TYPEOUT_TEST_TYPE_STD_DEQUE_ENABLED TYPEOUT_SUPPORT_STD_DEQUE

#define TYPEOUT_TEST_TYPE_STD_MEMORY_ENABLED TYPEOUT_SUPPORT_STD_MEMORY
#define TYPEOUT_TEST_TYPE_STD_RATIO_ENABLED TYPEOUT_SUPPORT_STD_RATIO
#define TYPEOUT_TEST_TYPE_STD_TUPLE_ENABLED TYPEOUT_SUPPORT_STD_TUPLE

//
// boost::
//
#define TYPEOUT_TEST_TYPE_BOOST_TUPLE_ENABLED TYPEOUT_SUPPORT_BOOST_TUPLE

// 
// other features
//
#define TYPEOUT_TEST_STREAM_OSTREAM_ENABLED 1


#endif /* TYPEOUT_TEST_CONFIG_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
