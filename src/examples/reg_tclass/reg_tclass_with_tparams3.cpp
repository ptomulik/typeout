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

/** // doc: reg_tclass/reg_tclass_with_tparams3.cpp {{{
 * \file reg_tclass/reg_tclass_with_tparams3.cpp
 * \example reg_tclass_with_tparams3.cpp
 * Register variadic template class with one type and one non-type parameter.
 */ // }}}
// [Program]
#include <typeout/reg_tclass.hpp>
#include <typeout/type/fundamental.hpp>
#include <typeout/stream/ostream.hpp>
#include <iostream>

#if TYPEOUT_SUPPORT_VARIADIC_TEMPLATES
// [Declaration and Registration]
template<class...> class foo;
TYPEOUT_REG_TCLASS_WITH_TPARAMS(foo,1)
TYPEOUT_REG_TCLASS_WITH_TPARAMS(foo,2)
TYPEOUT_REG_TCLASS_WITH_TPARAMS(foo,3)
// [Declaration and Registration]
#endif

int main(int,char*[])
{
#if TYPEOUT_SUPPORT_VARIADIC_TEMPLATES
  using typeout::_ostream::_;
  std::cout << _< foo<float> > << std::endl;
  std::cout << _< foo<int,float> > << std::endl;
  std::cout << _< foo<void,float,char> > << std::endl;
#endif
  return 0;
}
// [Program]

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
