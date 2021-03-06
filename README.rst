typeout - c++ library to retrieve type names at runtime
=======================================================

.. image:: https://travis-ci.org/ptomulik/typeout.png?branch=master
   :target: https://travis-ci.org/ptomulik/typeout

INTRODUCTION
------------

This small utility library allows you to register types at one place of your
program and retrieve their names at runtime at other places. The library is
thought to be used for simple debugging and writing test-suites based on c++
templates. Currently it supports standard output streams
(``std::ostream``) and standard strings (``std::string``) as outputs.

STATUS
------

The project is at very early stage. Few things already work quite well, but
much of the work is in front, and much of the existing code/interfaces might be
subject to changes. The current status is thus *experimental*.

Things that work:

  - fundamental c++ types (fundamental c++ types are pre-registered),
  - function pointers (displayed as hex address) and registered function
    pointers (displayed as function name),
  - registering custom classes and structures,
  - registering template classes (with type and non-type parameters),
  - handling cv-qualified types, references, pointers and array extents for each
    registered type without additional user's effort,
  - direct output to standard streams and standard strings, this also works
    with ``boost::unit_test::lazy_ostream`` used by ``BOOST_TEST_MESSAGE()``;

Things that are missing:

  - preregistered types from most standard library, e.g. std::string, and so on,
  - registering function types, function templates, and so on,
  - support for templates as template parameters in macros used to register types,
    stream is possible with functions which return type name written to
    ``std::string``

REQUIREMENTS
------------

The **typeout** library has following dependencies:

  - `Scons`_, if you need to build unit tests, examples or documentation,
  - ``gcc`` (4.8.2 or later) or ``clang`` (3.3 or later), if you need to build
    unit tests or examples,
  - `Boost Config`_ is used to configure the internals and features of the library,
    you need it each time you use the **typeout** library,
  - `Boost Preprocessor`_ is used by several preprocessor macros, you need it
    each time you use the **typeout** library,
  - `Boost Test Library`_ is used by test suite, you'll need it if you plan to
    compile (and run) test suites,
  - `Doxygen`_ used to generate API documentation, you'll need it if you plan
    to compile API documentation,

Example installation on debian/ubuntu:

  - ``apt-get install g++-4.8`` for ``gcc``, or
  - ``apt-get install clang libstdc++-4.8-dev`` for ``clang``,
  - ``apt-get install libboost-test-dev libboost-dev`` for any compiler,
  - ``apt-get install scons``,
  - ``apt-get install doxygen``, if you need build documenation,

Note: we don't use ``libc++-dev`` (a library provided by LLVM) because boost
testing framework is compiled against ``libstdc++`` and we must use the same.

MOTIVATION
----------

SAMPLE PROBLEM
``````````````

If you ever used `Boost Test Library`_, you may know the test case templates
(for example `BOOST_AUTO_TEST_CASE_TEMPLATE()`_).  Normally you feed the test
case template from a meta-sequence of types and it performs series of checks on
each type from the sequence. The problem is, that when something goes wrong at
runtime and you start investigating the issue, the default output from test
runner may be not informative. The test runner usually shows you just brief
result of failed checks without information about the (type) name of the
element from meta-sequence for which the test failed, or (with
``--log_level=test_suite`` for example) the crucial information is encoded in
mangled type names that are not human readable (at least in some compilers,
e.g. g++). One possible remedy is to provide user-readable messages with full
information about currently processed types.

The usage example of `BOOST_AUTO_TEST_CASE_TEMPLATE()`_ (from its
documentation) is::

    #define BOOST_TEST_MODULE example
    #include <boost/test/included/unit_test.hpp>
    #include <boost/test/test_case_template.hpp>
    #include <boost/mpl/list.hpp>

    typedef boost::mpl::list<int,long,unsigned char> test_types;

    BOOST_AUTO_TEST_CASE_TEMPLATE(my_test, T, test_types)
    {
      BOOST_CHECK_EQUAL( sizeof(T), (unsigned)4 );
    }

The question is, what you'll learn from the output of this test case when it
fails (it is designed to fail on most platforms, consider the result of
``sizeof(unsigned char)==4``)? Well, you'll be informed that::

    Running 3 test cases...
    a.cpp(10): error in "my_test<l>": check sizeof(T) == (unsigned)4 failed [8 != 4]
    a.cpp(10): error in "my_test<h>": check sizeof(T) == (unsigned)4 failed [1 != 4]

    *** 2 failures detected in test suite "example"

Now it's time to start guessing, what was the ``T`` type at the time of
failure.  If your test suite is compiled with ``gcc``, then with flag
``--log_level=test_suite`` you'll be see what follows ::

    Running 3 test cases...
    Entering test suite "example"
    Entering test case "my_test<i>"
    Leaving test case "my_test<i>"
    Entering test case "my_test<l>"
    a.cpp(10): error in "my_test<l>": check sizeof(T) == (unsigned)4 failed [8 != 4]
    Leaving test case "my_test<l>"
    Entering test case "my_test<h>"
    a.cpp(10): error in "my_test<h>": check sizeof(T) == (unsigned)4 failed [1 != 4]
    Leaving test case "my_test<h>"
    Leaving test suite "example"

    *** 2 failures detected in test suite "example"

Judge yourself if it is more informative than the output without any additional
debug information and imagine the debugging for types which come from
instantiation of complicated templates.

The **typeout** library provides utilities which basically allow you to
generate meaningful messages containing previously registered type names, and
can be used to resolve above debugging issues.

SOLUTION
````````

Consider the test case from previous section. With **typeout** you may easily
augment the test case output with your own messages containing type names. For
example::

    #define BOOST_TEST_MODULE example
    #include <boost/test/included/unit_test.hpp>
    #include <boost/test/test_case_template.hpp>
    #include <boost/mpl/list.hpp>
    #include <typeout/typeout.hpp>

    typedef boost::mpl::list<int,long,unsigned char> test_types;

    BOOST_AUTO_TEST_CASE_TEMPLATE(my_test, T, test_types)
    {
      using typeout::_ostream::_;
      BOOST_TEST_MESSAGE(__FILE__ << "(" << __LINE__ << "): note: running my_test<T> with T = " << _<T> << ";");
      BOOST_CHECK_MESSAGE( (sizeof(T) == (unsigned)4), "check sizeof(" << _<T> << ") == (unsigned)4 failed [" << sizeof(T) << " != 4]" );
    }

Now, the output from test runner with ``--log_level=message`` is like::

    Running 3 test cases...
    /tmp/a.cpp(12): note: running my_test<T> with T = int;
    /tmp/a.cpp(12): note: running my_test<T> with T = long int;
    /tmp/a.cpp(13): error in "my_test<l>": check sizeof(long int) == (unsigned)4 failed [8 != 4]
    /tmp/a.cpp(12): note: running my_test<T> with T = unsigned char;
    /tmp/a.cpp(13): error in "my_test<h>": check sizeof(unsigned char) == (unsigned)4 failed [1 != 4]


As you see, it's much easier to guess, that the test suite failed for ``long
int`` and ``unsigned char`` types.

DOCUMENTATION
-------------

API documentation may be generated with::

    scons api-doc

The generated docs may be found under ``build/doc/typeout/html/index.html``.

TESTS
-----

Tests may be compiled with::

    scons unit-test

This creates single program which runs all defined unit tests. The program is
``build/test/runtest`` or ``build/test/runtest.exe``. On Linux platforms the
tests may be run by ``bin/runtest``. The tests runner accepts flags defined by
`Boost Test Library`_ documentation.

EXAMPLES
--------

Examples may be compiled with::

    scons

The compiled binaries may be found under ``build/examples/``.

DIRECTORY STRUCTURE
-------------------

Top level source directory contains following subdirs:

  ================= ==============================================================
  Directory         Description
  ================= ==============================================================
  ``bin/``          contains mainainer scripts,
  ----------------- --------------------------------------------------------------
  ``build/``        this is main (default) variant directory, all the results of
                    compilation go there; the directory is created by scons,
  ----------------- --------------------------------------------------------------
  ``HOWTO/``        several HOWTO documents are placed here,
  ----------------- --------------------------------------------------------------
  ``debian/``       debian packaging files (currently empty),
  ----------------- --------------------------------------------------------------
  ``rpm/``          rpm packaging files (currently empty)
  ----------------- --------------------------------------------------------------
  ``site_scons/``   extensions used by scons,
  ----------------- --------------------------------------------------------------
  ``src/``          main source tree with source files to be compiled,
  ----------------- --------------------------------------------------------------
  ``template/``     templates for source files,
  ================= ==============================================================


LICENSE
-------

@COPYRIGHT@

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE

.. _Scons: http://scons.org
.. _Doxygen: http://doxygen.org
.. _Boost Config: http://boost.org/libs/config
.. _Boost Preprocessor: http://boost.org/libs/preprocessor
.. _Boost Test Library: http://boost.org/libs/test/
.. _BOOST_AUTO_TEST_CASE_TEMPLATE(): http://boost.org/libs/test/doc/html/utf/user-guide/test-organization/auto-test-case-template.html
.. <!--- vim: set expandtab tabstop=2 shiftwidth=2 syntax=rst: -->
