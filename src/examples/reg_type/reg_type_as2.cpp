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

/** // doc: reg_type/reg_type_as2.cpp {{{
 * \file reg_type/reg_type_as2.cpp
 * \example reg_type_as2.cpp
 * Register new types with custom names, which may be changed at runtime.
 */ // }}}
// [Program]
#include <typeout/reg_type.hpp>
#include <typeout/stream/ostream.hpp>
#include <iostream>
#include <string>

namespace ns1 { struct foo {}; }
namespace ns2 { struct bar {}; }

std::string fooname("foo");
std::string barname("bar");

// use variables to define runtime names for ns1::foo and ns2::bar.
TYPEOUT_REG_TYPE_AS(ns1::foo,fooname)
TYPEOUT_REG_TYPE_AS(ns2::bar,barname)

int main(int,char*[])
{
  using typeout::_ostream::_;
  std::cout << _<ns1::foo> << std::endl; // output: foo
  std::cout << _<ns2::bar> << std::endl; // output: bar
  fooname = "ns1::foo";
  barname = "ns2::bar";
  std::cout << _<ns1::foo> << std::endl; // output: ns1::foo
  std::cout << _<ns2::bar> << std::endl; // output: ns2::bar
  return 0;
}
// [Program]

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
