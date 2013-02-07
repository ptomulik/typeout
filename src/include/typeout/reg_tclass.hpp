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

// typeout/reg_tclass.hpp

/** // doc: typeout/reg_tclass.hpp {{{ 
 * \file typeout/reg_tclass.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TYPEOUT_REG_TCLASS_HPP_INCLUDED
#define TYPEOUT_REG_TCLASS_HPP_INCLUDED

#include <typeout/config.hpp>
#include <typeout/type.hpp>
#include <typeout/stream.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/seq/elem.hpp>
#include <boost/preprocessor/seq/enum.hpp>
#include <boost/preprocessor/seq/for_each_i.hpp>
#include <boost/preprocessor/control/if.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/stringize.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>

/** \ingroup typeout_reg_type
 * @{ */
#define TYPEOUT_TPARAM_DECL_typename typename
#define TYPEOUT_TPARAM_DECL_class class
#define TYPEOUT_TPARAM_DECL_const(x) x

#define TYPEOUT_TPARAM_DECL(t) TYPEOUT_TPARAM_DECL_##t
#define TYPEOUT_SEQ_TPARAM(r,a,i,x) \
  (TYPEOUT_TPARAM_DECL(x) BOOST_PP_CAT(a,i))
#define TYPEOUT_SEQ_TPARAMS(a,seq) \
  BOOST_PP_SEQ_FOR_EACH_I(TYPEOUT_SEQ_TPARAM,a,seq)
#define TYPEOUT_SEQ_ENUM_TPARAMS(a,seq) \
  BOOST_PP_SEQ_ENUM(TYPEOUT_SEQ_TPARAMS(a,seq))

#define TYPEOUT_SEQ_TARG(r,a,i,x) \
  (BOOST_PP_CAT(a,i))
#define TYPEOUT_SEQ_TARGS(a,seq) \
  BOOST_PP_SEQ_FOR_EACH_I(TYPEOUT_SEQ_TARG,a,seq)
#define TYPEOUT_SEQ_ENUM_TARGS(a,seq) \
  BOOST_PP_SEQ_ENUM(TYPEOUT_SEQ_TARGS(a,seq))

#define TYPEOUT_TPARAM_STREAMOUT_START_typename typeout::_< 
#define TYPEOUT_TPARAM_STREAMOUT_START_class typeout::_< 
#define TYPEOUT_TPARAM_STREAMOUT_START_const(type) typeout::_< type, 

#define TYPEOUT_TPARAM_STREAMOUT_START(x) TYPEOUT_TPARAM_STREAMOUT_START_##x
#define TYPEOUT_SEQ_STREAMOUT_TPARAM(r,a,i,x) \
  BOOST_PP_IF(i,<< ", " <<, <<) TYPEOUT_TPARAM_STREAMOUT_START(x) \
  BOOST_PP_CAT(a,i) >
#define TYPEOUT_SEQ_STREAMOUT_TPARAMS(a,seq) \
  BOOST_PP_SEQ_FOR_EACH_I(TYPEOUT_SEQ_STREAMOUT_TPARAM,a,seq)

/** // doc: TYPEOUT_REG_TCLASS_AS {{{
 * \brief Register template class using custom name
 * \param tpl Name of the class template in the code. 
 * \param as Name used at runtime to represent class template (string or
 *        expression that yields string at runtime).
 * \param tparams Sequence of template parameter types (see below).
 *
 * \note The macro must be invoked at global scope (not in any namespace).
 * \note Don't put semicolon at the end of macro invocation.
 *
 * The \c tparams is a sequence of template parameter types. The word 
 * \e sequence has same meaning as in boost preprocessor library, i.e. a
 * sequence has form
 * \code
 *  (a1)(a2)...(an)
 * \endcode
 * where \c ai are consecutive elements in sequence. The currently supported
 * elements are
 *
 * - \c class or \c typename, for type template parameters,
 * - \c const (\e type), for non-type template parameters (usually integral
 *   constants); the \e type provides type of the parameter
 *
 * \note The template template parameters, i.e. template parameters in form
 *       <tt>template <...> class</tt> are currently not supported.
 *
 * The \c tparams sequence determines the template declaration of the template
 * class being registered.
 *
 * <b>Example 1</b>:
 * \snippet reg_tclass_as1.cpp Declaration and Registration
 *
 * <b>Example 2</b>:
 * \snippet reg_tclass_as2.cpp Declaration and Registration
 *
 * <b>Example 3</b>:
 * \snippet reg_tclass_as3.cpp Declaration and Registration
 *
 * <b>Example 4</b>:
 * \snippet reg_tclass_as4.cpp Declaration and Registration
 *
 * \see TYPEOUT_REG_TCLASS
 * \see TYPEOUT_REG_TCLASS_WITH_TPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_TPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_NPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_NPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_TNPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_TNPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_NTPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_NTPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_TPARAMS_RANGE
 * \see TYPEOUT_REG_TCLASS_WITH_NPARAMS_RANGE
 *
 * \hideinitializer
 */ // }}}
#define TYPEOUT_REG_TCLASS_AS(tpl,as,tparams) \
namespace typeout { namespace _type { \
  template< TYPEOUT_SEQ_ENUM_TPARAMS(A, tparams)> \
  struct _<tpl < TYPEOUT_SEQ_ENUM_TARGS(A, tparams) > > \
  { \
    template <class Ostream> \
    static void write(Ostream& os) \
    { \
      os << as << " < " \
      TYPEOUT_SEQ_STREAMOUT_TPARAMS(A,tparams) \
      << " >"; \
    } \
  }; \
} }

/** // doc: TYPEOUT_REG_TCLASS {{{
 * \brief Register template class using original name 
 * \param tpl Name of the class template in the code. 
 * \param tparams Sequence of template parameter types (see below).
 *
 * \note The macro must be invoked at global scope (not in any namespace).
 * \note Don't put semicolon at the end of macro invocation.
 *
 * The \c tparams is a sequence of template parameter types. The word 
 * \e sequence has same meaning as in boost preprocessor library, i.e. a
 * sequence has form
 * \code
 *  (a1)(a2)...(an)
 * \endcode
 * where \c ai are consecutive elements in sequence. The currently supported
 * elements are
 *
 * - \c class or \c typename, for type template parameters,
 * - \c const (\e type), for non-type template parameters (usually integral
 *   constants); the \e type provides type of the parameter
 *
 * \note The template template parameters, i.e. template parameters in form
 *       <tt>template <...> class</tt> are currently not supported.
 *
 * The \c tparams sequence determines the template declaration of the template
 * class being registered.
 *
 * <b>Example 1</b>:
 * \snippet reg_tclass1.cpp Declaration and Registration
 *
 * <b>Example 2</b>:
 * \snippet reg_tclass2.cpp Declaration and Registration
 *
 * <b>Example 3</b>:
 * \snippet reg_tclass3.cpp Declaration and Registration
 *
 * <b>Example 4</b>:
 * \snippet reg_tclass4.cpp Declaration and Registration
 *
 * \see TYPEOUT_REG_TCLASS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_TPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_TPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_NPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_NPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_TNPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_TNPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_NTPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_NTPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_TPARAMS_RANGE
 * \see TYPEOUT_REG_TCLASS_WITH_NPARAMS_RANGE
 *
 * \hideinitializer
 */ // }}}
#define TYPEOUT_REG_TCLASS(tpl,tparams) \
  TYPEOUT_REG_TCLASS_AS(tpl,BOOST_PP_STRINGIZE(tpl),tparams)

#define TYPEOUT_ALWAYS_REPETITION(z,i,data) data

/** // doc: TYPEOUT_REG_TCLASS_WITH_TPARAMS_AS {{{
 * \brief Register template class having only type-parameters. Use custom name
 *        to represent class at runtime.
 * \param tpl The original name of class template.
 * \param as  Name used at runtime to represent class template (string or
 *        expression that yields string at runtime).
 * \param n Number of template parameters used.
 *
 * \note The macro must be invoked at global scope (not in any namespace).
 * \note Don't put semicolon at the end of macro invocation.
 *
 * By "template class having only type-parameters" we mean following templates
 * \code
 * template <typename T1,typename T2,...> class foo;
 * \endcode
 * where you may also use \c class keyword instead of \c typename in the
 * template parameter list. Such class templates may be registered by providing
 * just the name and the number of template parameters in use. This is
 * basically what this macro is provided for. 
 *
 * Note, that there are only \c class/typename parameters in the template
 * parameter list (no non-type parameters).
 *
 * \note This macro does not support template type parameters, i.e. classes
 *       declared as:
 * \code
 * template <template <...> class, template <...> class, ... > class foo;
 * \endcode
 *      are not supported.
 *
 * Variadic templates might be handled by registering them several times with
 * different number of parameters. You have to register as many variants as you
 * need later in your program. This may be easily performed with the macro
 * TYPEOUT_REG_TCLASS_WITH_TPARAMS_RANGE(). 
 *
 * <b>Example 1</b>
 * \snippet reg_tclass_with_tparams_as1.cpp Declaration and Registration
 *
 * <b>Example 2</b>
 * \snippet reg_tclass_with_tparams_as2.cpp Declaration and Registration
 *
 * <b>Example 3</b>
 * \snippet reg_tclass_with_tparams_as3.cpp Declaration and Registration
 *
 * \see TYPEOUT_REG_TCLASS
 * \see TYPEOUT_REG_TCLASS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_TPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_NPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_NPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_TNPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_TNPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_NTPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_NTPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_TPARAMS_RANGE
 * \see TYPEOUT_REG_TCLASS_WITH_NPARAMS_RANGE
 *
 * \hideinitializer
 */ // }}}
#define TYPEOUT_REG_TCLASS_WITH_TPARAMS_AS(tpl,as,n) \
  TYPEOUT_REG_TCLASS_AS(tpl,as, \
  BOOST_PP_REPEAT(n,TYPEOUT_ALWAYS_REPETITION,(typename)))
/** // doc: TYPEOUT_REG_TCLASS_WITH_TPARAMS {{{
 * \brief Register template class having only type-parameters. 
 * \param tpl The name of class template.
 * \param n Number of template parameters used.
 *
 * \note The macro must be invoked at global scope (not in any namespace).
 * \note Don't put semicolon at the end of macro invocation.
 *
 * By "template class having only type-parameters" we mean following templates
 * \code
 * template <typename T1,typename T2,...> class foo;
 * \endcode
 * where you may also use \c class keyword instead of \c typename in the
 * template parameter list. Such class templates may be registered by providing
 * just the name and the number of template parameters in use. This is
 * basically what this macro is provided for. 
 *
 * Note, that there are only \c class/typename parameters in the template
 * parameter list (no non-type parameters).
 *
 * \note This macro does not support template type parameters, i.e. classes
 *       declared as:
 * \code
 * template <template <...> class, template <...> class, ... > class foo;
 * \endcode
 *      are not supported.
 *
 *
 * Variadic templates might be handled by registering them several times with
 * different number of parameters. You have to register as many variants as you
 * need later in your program. This may be easily performed with the macro
 * TYPEOUT_REG_TCLASS_WITH_TPARAMS_RANGE(). 
 *
 * <b>Example 1</b>
 * \snippet reg_tclass_with_tparams1.cpp Declaration and Registration
 *
 * <b>Example 2</b>
 * \snippet reg_tclass_with_tparams2.cpp Declaration and Registration
 *
 * <b>Example 3</b>
 * \snippet reg_tclass_with_tparams3.cpp Declaration and Registration
 *
 * \see TYPEOUT_REG_TCLASS
 * \see TYPEOUT_REG_TCLASS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_TPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_NPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_NPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_TNPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_TNPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_NTPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_NTPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_TPARAMS_RANGE
 * \see TYPEOUT_REG_TCLASS_WITH_NPARAMS_RANGE
 *
 * \hideinitializer
 */ // }}}
#define TYPEOUT_REG_TCLASS_WITH_TPARAMS(tpl,n) \
  TYPEOUT_REG_TCLASS_WITH_TPARAMS_AS(tpl,BOOST_PP_STRINGIZE(tpl),n)

/** // doc: TYPEOUT_REG_TCLASS_WITH_NPARAMS_AS {{{
 * \brief Register template class having only non-type parameters. Use custom
 *        name to represent class at runtime.
 * \param tpl The original name of class template in the code.
 * \param as  Name used at runtime to represent class template (string or
 *            expression that yields string at runtime).
 * \param type Type of template parameters, e.g. \c int.
 * \param n Number of template parameters used.
 *
 * \note The macro must be invoked at global scope (not in any namespace).
 * \note Don't put semicolon at the end of macro invocation.
 *
 * By "template class having only non-type parameters" we mean following
 * templates
 * \code
 * template <type t1, type t2,...> class foo;
 * \endcode
 * where \c type represents type of non-type template parameter, which may be
 * (according to N3485 draft of c++11 standard, 14.1.4, [temp.param]):
 * 
 * - integral or enumeration type,
 * - pointer to object or pointer to function (functions not supported yet),
 * - lvalue reference object or lvalue reference to function (functions not
 *   supported yet),
 * - pointer to member (not supported yet),
 * - std::nullptr_t (not supported yet).
 *
 * It is assumed that all the parameters have exactly same \c type. Such class
 * templates may be registered by providing just the class name, \c type
 * and the number of template parameters in use. This is basically what this
 * macro is provided for. 
 *
 * Variadic templates might be handled by registering them several times with
 * different number of parameters. You have to register as many variants as you
 * need later in your program. This may be easily performed with the macro
 * TYPEOUT_REG_TCLASS_WITH_NPARAMS_RANGE(). 
 *
 * <b>Example 1</b>
 * \snippet reg_tclass_with_nparams_as1.cpp Declaration and Registration
 *
 * <b>Example 2</b>
 * \snippet reg_tclass_with_nparams_as2.cpp Declaration and Registration
 *
 * <b>Example 3</b>
 * \snippet reg_tclass_with_nparams_as3.cpp Declaration and Registration
 *
 * \see TYPEOUT_REG_TCLASS
 * \see TYPEOUT_REG_TCLASS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_TPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_TPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_NPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_TNPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_TNPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_NTPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_NTPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_TPARAMS_RANGE
 * \see TYPEOUT_REG_TCLASS_WITH_NPARAMS_RANGE
 *
 * \hideinitializer
 */ // }}}
#define TYPEOUT_REG_TCLASS_WITH_NPARAMS_AS(tpl,as,type,n) \
  TYPEOUT_REG_TCLASS_AS(tpl,as, \
  BOOST_PP_REPEAT(n,TYPEOUT_ALWAYS_REPETITION,(const(type))))
/** // doc: TYPEOUT_REG_TCLASS_WITH_NPARAMS {{{
 * \brief Register template class having only non-type parameters. 
 * \param tpl The original name of class template in the code.
 * \param type Type of template parameters, e.g. \c int.
 * \param n Number of template parameters used.
 *
 * \note The macro must be invoked at global scope (not in any namespace).
 * \note Don't put semicolon at the end of macro invocation.
 *
 * By "template class having only non-type parameters" we mean following
 * templates
 * \code
 * template <type t1, type t2,...> class foo;
 * \endcode
 * where \c type represents type of non-type template parameter, which may be
 * (according to N3485 draft of c++11 standard, 14.1.4, [temp.param]):
 * 
 * - integral or enumeration type,
 * - pointer to object or pointer to function (functions not supported yet),
 * - lvalue reference object or lvalue reference to function (functions not
 *   supported yet),
 * - pointer to member (not supported yet),
 * - std::nullptr_t (not supported yet).
 *
 * It is assumed that all the parameters have exactly same \c type. Such class
 * templates may be registered by providing just the class name, \c type
 * and the number of template parameters in use. This is basically what this
 * macro is provided for. 
 *
 * Variadic templates might be handled by registering them several times with
 * different number of parameters. You have to register as many variants as you
 * need later in your program. This may be easily performed with the macro
 * TYPEOUT_REG_TCLASS_WITH_NPARAMS_RANGE(). 
 *
 * <b>Example 1</b>
 * \snippet reg_tclass_with_nparams1.cpp Declaration and Registration
 *
 * <b>Example 2</b>
 * \snippet reg_tclass_with_nparams2.cpp Declaration and Registration
 *
 * <b>Example 3</b>
 * \snippet reg_tclass_with_nparams3.cpp Declaration and Registration
 *
 * \see TYPEOUT_REG_TCLASS
 * \see TYPEOUT_REG_TCLASS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_TPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_TPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_NPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_TNPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_TNPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_NTPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_NTPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_TPARAMS_RANGE
 * \see TYPEOUT_REG_TCLASS_WITH_NPARAMS_RANGE
 *
 * \hideinitializer
 */ // }}}
#define TYPEOUT_REG_TCLASS_WITH_NPARAMS(tpl,type,n) \
  TYPEOUT_REG_TCLASS_WITH_NPARAMS_AS(tpl,BOOST_PP_STRINGIZE(tpl), \
  type,n)

/** // doc: TYPEOUT_REG_TCLASS_WITH_TNPARAMS_AS {{{
 * \brief Register template class having only type-parameters followed by
 *        non-type parameters. Use custom name to represent class at runtime.
 * \param tpl The original name of class template.
 * \param as  Name used at runtime to represent class template (string or
 *        expression that yields string at runtime).
 * \param type The type of non-type parameters.
 * \param nt Number of type-parameters used.
 * \param nn Number of non-type parameters that follow the type-parameters.
 *
 * \note The macro must be invoked at global scope (not in any namespace).
 * \note Don't put semicolon at the end of macro invocation.
 *
 * This macro is designed to register template classes with signatures as
 * \code
 * template <class T_1, ..., class T_nt, type t_1, ..., type t_nn> class foo;
 * \endcode
 * First \c nt parameters are type-parameters. These parameters are followed by
 * \c nn non-type parameters of same \c type. The \c type may be (according to
 * N3485 draft of c++11 standard, 14.1.4, [temp.param]):
 * 
 * - integral or enumeration type,
 * - pointer to object or pointer to function (functions not supported yet),
 * - lvalue reference object or lvalue reference to function (functions not
 *   supported yet),
 * - pointer to member (not supported yet),
 * - std::nullptr_t (not supported yet).
 *
 * Variadic templates might be handled by registering them several times with
 * different number of parameters. You have to register as many variants as you
 * need later in your program.
 *
 * <b>Example 1</b>
 * \snippet reg_tclass_with_tnparams_as1.cpp Declaration and Registration
 *
 * <b>Example 2</b>
 * \snippet reg_tclass_with_tnparams_as2.cpp Declaration and Registration
 *
 * <b>Example 3</b>
 * \snippet reg_tclass_with_tnparams_as3.cpp Declaration and Registration
 *
 * <b>Example 4</b>
 * \snippet reg_tclass_with_tnparams_as4.cpp Declaration and Registration
 *
 * \see TYPEOUT_REG_TCLASS
 * \see TYPEOUT_REG_TCLASS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_TPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_TPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_NPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_NPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_TNPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_NTPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_NTPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_TPARAMS_RANGE
 * \see TYPEOUT_REG_TCLASS_WITH_NPARAMS_RANGE
 * \hideinitializer
 */ // }}}
#define TYPEOUT_REG_TCLASS_WITH_TNPARAMS_AS(tpl,as,type,nt,nn) \
  TYPEOUT_REG_TCLASS_AS(tpl,as, \
  BOOST_PP_REPEAT(nt,TYPEOUT_ALWAYS_REPETITION,(typename))\
  BOOST_PP_REPEAT(nn,TYPEOUT_ALWAYS_REPETITION,(const(type))))
/** // doc: TYPEOUT_REG_TCLASS_WITH_TNPARAMS {{{
 * \brief Register template class having only type-parameters followed by
 *        non-type parameters. 
 * \param tpl The original name of class template.
 * \param type The type of non-type parameters.
 * \param nt Number of type-parameters used.
 * \param nn Number of non-type parameters that follow the type-parameters.
 *
 * \note The macro must be invoked at global scope (not in any namespace).
 * \note Don't put semicolon at the end of macro invocation.
 *
 * This macro is designed to register template classes with signatures as
 * \code
 * template <class T_1, ..., class T_nt, type t_1, ..., type t_nn> class foo;
 * \endcode
 * First \c nt parameters are type-parameters. These parameters are followed by
 * \c nn non-type parameters of same \c type. The \c type may be (according to
 * N3485 draft of c++11 standard, 14.1.4, [temp.param]):
 * 
 * - integral or enumeration type,
 * - pointer to object or pointer to function (functions not supported yet),
 * - lvalue reference object or lvalue reference to function (functions not
 *   supported yet),
 * - pointer to member (not supported yet),
 * - std::nullptr_t (not supported yet).
 *
 * Variadic templates might be handled by registering them several times with
 * different number of parameters. You have to register as many variants as you
 * need later in your program.
 *
 * <b>Example 1</b>
 * \snippet reg_tclass_with_tnparams1.cpp Declaration and Registration
 *
 * <b>Example 2</b>
 * \snippet reg_tclass_with_tnparams2.cpp Declaration and Registration
 *
 * <b>Example 3</b>
 * \snippet reg_tclass_with_tnparams3.cpp Declaration and Registration
 *
 * <b>Example 4</b>
 * \snippet reg_tclass_with_tnparams4.cpp Declaration and Registration
 *
 * \see TYPEOUT_REG_TCLASS
 * \see TYPEOUT_REG_TCLASS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_TPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_TPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_NPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_NPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_TNPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_NTPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_NTPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_TPARAMS_RANGE
 * \see TYPEOUT_REG_TCLASS_WITH_NPARAMS_RANGE
 * \hideinitializer
 */ // }}}
#define TYPEOUT_REG_TCLASS_WITH_TNPARAMS(tpl,type,nt,nn) \
  TYPEOUT_REG_TCLASS_WITH_TNPARAMS_AS(tpl, \
  BOOST_PP_STRINGIZE(tpl),type,nt,nn)

/** // doc: TYPEOUT_REG_TCLASS_WITH_NTPARAMS_AS {{{
 * \brief Register template class having only non-type parameters followed by
 *        type parameters. Use custom name to represent class at runtime.
 * \param tpl The original name of class template.
 * \param as  Name used at runtime to represent class template (string or
 *        expression that yields string at runtime).
 * \param type The type of non-type parameters.
 * \param nn Number of non-type parameters that follow the type-parameters.
 * \param nt Number of type-parameters used.
 *
 * \note The macro must be invoked at global scope (not in any namespace).
 * \note Don't put semicolon at the end of macro invocation.
 *
 * This macro is designed to register template classes with signatures as
 * \code
 * template <type t_1, ..., type t_nn, class T_1, ..., class T_nt> class foo;
 * \endcode
 * First \c nn parameters are non-type parameters of same \c type. These
 * parameters are followed by \c nt type-parameters. The \c type may be
 * (according to N3485 draft of c++11 standard, 14.1.4, [temp.param]):
 * 
 * - integral or enumeration type,
 * - pointer to object or pointer to function (functions not supported yet),
 * - lvalue reference object or lvalue reference to function (functions not
 *   supported yet),
 * - pointer to member (not supported yet),
 * - std::nullptr_t (not supported yet).
 *
 * Variadic templates might be handled by registering them several times with
 * different number of parameters. You have to register as many variants as you
 * need later in your program.
 *
 * <b>Example 1</b>
 * \snippet reg_tclass_with_ntparams_as1.cpp Declaration and Registration
 *
 * <b>Example 2</b>
 * \snippet reg_tclass_with_ntparams_as2.cpp Declaration and Registration
 *
 * <b>Example 3</b>
 * \snippet reg_tclass_with_ntparams_as3.cpp Declaration and Registration
 *
 * <b>Example 4</b>
 * \snippet reg_tclass_with_ntparams_as4.cpp Declaration and Registration
 *
 * \see TYPEOUT_REG_TCLASS
 * \see TYPEOUT_REG_TCLASS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_TPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_TPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_NPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_NPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_TNPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_NTPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_NTPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_TPARAMS_RANGE
 * \see TYPEOUT_REG_TCLASS_WITH_NPARAMS_RANGE
 * \hideinitializer
 */ // }}}
#define TYPEOUT_REG_TCLASS_WITH_NTPARAMS_AS(tpl,as,type,nn,nt) \
  TYPEOUT_REG_TCLASS_AS(tpl,as, \
  BOOST_PP_REPEAT(nn,TYPEOUT_ALWAYS_REPETITION,(const(type))) \
  BOOST_PP_REPEAT(nt,TYPEOUT_ALWAYS_REPETITION,(typename)))
/** // doc: TYPEOUT_REG_TCLASS_WITH_NTPARAMS {{{
 * \brief Register template class having only non-type parameters followed by
 *        type parameters.
 * \param tpl The original name of class template.
 * \param type The type of non-type parameters.
 * \param nn Number of non-type parameters that follow the type-parameters.
 * \param nt Number of type-parameters used.
 *
 * \note The macro must be invoked at global scope (not in any namespace).
 * \note Don't put semicolon at the end of macro invocation.
 *
 * This macro is designed to register template classes with signatures as
 * \code
 * template <type t_1, ..., type t_nn, class T_1, ..., class T_nt> class foo;
 * \endcode
 * First \c nn parameters are non-type parameters of same \c type. These
 * parameters are followed by \c nt type-parameters. The \c type may be
 * (according to N3485 draft of c++11 standard, 14.1.4, [temp.param]):
 * 
 * - integral or enumeration type,
 * - pointer to object or pointer to function (functions not supported yet),
 * - lvalue reference object or lvalue reference to function (functions not
 *   supported yet),
 * - pointer to member (not supported yet),
 * - std::nullptr_t (not supported yet).
 *
 * Variadic templates might be handled by registering them several times with
 * different number of parameters. You have to register as many variants as you
 * need later in your program.
 *
 * <b>Example 1</b>
 * \snippet reg_tclass_with_ntparams1.cpp Declaration and Registration
 *
 * <b>Example 2</b>
 * \snippet reg_tclass_with_ntparams2.cpp Declaration and Registration
 *
 * <b>Example 3</b>
 * \snippet reg_tclass_with_ntparams3.cpp Declaration and Registration
 *
 * <b>Example 4</b>
 * \snippet reg_tclass_with_ntparams4.cpp Declaration and Registration
 *
 * \see TYPEOUT_REG_TCLASS
 * \see TYPEOUT_REG_TCLASS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_TPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_TPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_NPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_NPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_TNPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_NTPARAMS_AS
 * \see TYPEOUT_REG_TCLASS_WITH_NTPARAMS
 * \see TYPEOUT_REG_TCLASS_WITH_TPARAMS_RANGE
 * \see TYPEOUT_REG_TCLASS_WITH_NPARAMS_RANGE
 * \hideinitializer
 */ // }}}
#define TYPEOUT_REG_TCLASS_WITH_NTPARAMS(tpl,type,nn,nt) \
  TYPEOUT_REG_TCLASS_WITH_NTPARAMS_AS(tpl, \
  BOOST_PP_STRINGIZE(tpl),type,nn,nt)

#define TYPEOUT_REG_TCLASS_WITH_TPARAMS_RANGE_REPETITION(z,n,tpl) \
  TYPEOUT_REG_TCLASS_WITH_TPARAMS(tpl,n)
/** // doc: TYPEOUT_REG_TCLASS_WITH_TPARAMS_RANGE {{{
 * \brief Register template class using variable number of type-parameters.
 * \param tpl The original name of class template.
 * \param nmin Min number of parameters.
 * \param nmax Max number of parameters.
 *
 * \note The macro must be invoked at global scope (not in any namespace).
 * \note Don't put semicolon at the end of macro invocation.
 *
 * This macro is useful when registering variadic class templates. It is
 * designed to register the class templates with signatures such as:
 * \code
 * template <class...> class foo;
 * \endcode
 *
 * If you plan to use (i.e. retrieve the name of) specializations of such
 * templates with different number of arguments, for example with 1 to 3
 * arguments, then just set \c nmin=1 and \c nmax=3.
 *
 * <b>Example 1</b>:
 * \snippet reg_tclass_with_tparams_range1.cpp Declaration and Registration
 *
 * \hideinitializer
 */ // }}}
#define TYPEOUT_REG_TCLASS_WITH_TPARAMS_RANGE(tpl,nmin,nmax) \
  BOOST_PP_REPEAT_FROM_TO(nmin,BOOST_PP_INC(nmax), \
  TYPEOUT_REG_TCLASS_WITH_TPARAMS_RANGE_REPETITION,tpl)

#define TYPEOUT_REG_TCLASS_WITH_NPARAMS_RANGE_REPETITION(z,n,args) \
  TYPEOUT_REG_TCLASS_WITH_NPARAMS(BOOST_PP_SEQ_ELEM(0,args), \
  BOOST_PP_SEQ_ELEM(1,args),n)
/** // doc: TYPEOUT_REG_TCLASS_WITH_NPARAMS_RANGE {{{
 * \brief Register template class using variable number of non-type parameters.
 * \param tpl The original name of class template.
 * \param type The type of non-type parameter.
 * \param nmin Min number of parameters.
 * \param nmax Max number of parameters.
 *
 * \note The macro must be invoked at global scope (not in any namespace).
 * \note Don't put semicolon at the end of macro invocation.
 *
 * This macro is useful when registering variadic class templates. It is
 * designed to register the class templates with signatures such as:
 * \code
 * template <type...> class foo;
 * \endcode
 * The \c type may be (according to N3485 draft of c++11 standard, 14.1.4,
 * [temp.param]):
 * 
 * - integral or enumeration type,
 * - pointer to object or pointer to function (functions not supported yet),
 * - lvalue reference object or lvalue reference to function (functions not
 *   supported yet),
 * - pointer to member (not supported yet),
 * - std::nullptr_t (not supported yet).
 *
 * If you plan to use (i.e. retrieve the name of) specializations of such
 * templates with different number of arguments, for example with 1 to 3
 * arguments, then just set \c nmin=1 and \c nmax=3.
 *
 * <b>Example 1</b>:
 * \snippet reg_tclass_with_nparams_range1.cpp Declaration and Registration
 *
 * \hideinitializer
 */ // }}}
#define TYPEOUT_REG_TCLASS_WITH_NPARAMS_RANGE(tpl,type,nmin,nmax) \
  BOOST_PP_REPEAT_FROM_TO(nmin,BOOST_PP_INC(nmax), \
  TYPEOUT_REG_TCLASS_WITH_NPARAMS_RANGE_REPETITION,(tpl)(type))

/** @} */
#endif /* TYPEOUT_REG_TCLASS_HPP_INCLUDED */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
