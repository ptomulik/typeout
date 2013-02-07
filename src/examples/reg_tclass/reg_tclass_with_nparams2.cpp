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

/** // doc: reg_tclass/reg_tclass_with_nparams2.cpp {{{
 * \file reg_tclass/reg_tclass_with_nparams2.cpp
 * \example reg_tclass_with_nparams2.cpp
 * Register template class with two non-type parameters using 
 * TYPEOUT_REG_TCLASS_WITH_NPARAMS().
 */ // }}}
// [Program]
#include <typeout/reg_tclass.hpp>
#include <typeout/tvalue/fundamental.hpp>
#include <typeout/stream/ostream.hpp>
#include <iostream>

// [Declaration and Registration]
template <int,int> class foo;
TYPEOUT_REG_TCLASS_WITH_NPARAMS(foo,int,2)
// [Declaration and Registration]

int main(int,char*[])
{
  using typeout::_ostream::_;
  std::cout << _< foo<1,2> > << std::endl;
  return 0;
}
// [Program]

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
