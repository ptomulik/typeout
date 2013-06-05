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

// typeout/type/std/memory.hpp

/** // doc: typeout/type/std/memory.hpp {{{ 
 * \file typeout/type/std/memory.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TYPEOUT_TYPE_STD_MEMORY_HPP_INCLUDED
#define TYPEOUT_TYPE_STD_MEMORY_HPP_INCLUDED

#include <typeout/config.hpp>
#include <typeout/reg_tclass.hpp>
#include <typeout/reg_type.hpp>

#include <memory>
#if TYPEOUT_SUPPORT_STD_MEMORY
TYPEOUT_REG_TCLASS(std::allocator,(class))
# if TYPEOUT_SUPPORT_CXX11_ALLOCATOR
TYPEOUT_REG_TCLASS(std::allocator_traits,(class))
TYPEOUT_REG_TYPE(std::allocator_arg_t)
TYPEOUT_REG_TCLASS(std::uses_allocator,(class)(class))
# endif
TYPEOUT_REG_TCLASS(std::auto_ptr,(class))
#  if TYPEOUT_SUPPORT_STD_SMART_PTR
TYPEOUT_REG_TCLASS(std::shared_ptr,(class))
TYPEOUT_REG_TCLASS(std::unique_ptr,(class)(class))
TYPEOUT_REG_TCLASS(std::weak_ptr,(class))
TYPEOUT_REG_TCLASS(std::owner_less,(class))
TYPEOUT_REG_TCLASS(std::enable_shared_from_this,(class))
TYPEOUT_REG_TCLASS(std::default_delete,(class))
TYPEOUT_REG_TYPE(std::bad_weak_ptr)
// FIXME: This is perhaps not the best place for (it's not tightly related to
//        SMART_PTR)
TYPEOUT_REG_TCLASS(std::pointer_traits,(class))
# endif

# endif /* TYPEOUT_SUPPORT_STD_MEMORY */

#endif /* TYPEOUT_TYPE_STD_MEMORY_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
