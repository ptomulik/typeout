typeout - small c++ library to retrieve c++ type names at runtime
=================================================================

INTRODUCTION
------------

This small utility library allows you to register types or template classes in
one place of your program and retrieve their names at runtime in other places.
This is one of several aspects of so-called reflection (or introspection). The
library is thought to be used for simple debugging and writing test-suites in
form of template functions. It supports standard output streams
(``std::basic_ostream``) and standard strings (``std::string``) as targets.

STATUS
------

The project is at very early stage. Few things already work quite well, but
much of work is in front, and much of already developed code might be subject
to changes. The current status is *experimental*.

Things that work:

  - registering fundamental c++ types (actually all fundamental types are
    pre-registered by ``typeout`` and are ready to use),
  - registering custom classes, and structures,
  - registering template classes (with type and non-type parameters, templates
    as parameters are not currently supported by registration machinery),
  - handling cv-qualified types, references, pointers and array extents for each
    registered type without user's intervention,
  - direct output to standard streams, and standard strings,


Things that are missing:

  - preregistered types from most standard library, e.g. std::string,
    std::tuple and so on,
  - good support for integral values, pointers and references as template
    parameters, and other non-type template parameters,
  - registering function types, function pointers, function templates, and so on,
  - support for templates as template parameters in macros used to register types,
  - direct streaming to boost::unit_test::lazy_ostream used by
    ``BOOST_TEST_MESSAGE()``; currently printing-out type names through this
    stream is possible with functions which return type name written to
    ``std::string``

REQUIREMENTS
------------

The ``typeout`` library has following dependencies:

  - `Boost Config`_ is used to configure the internals and features of the library,
    you need it each time you use the ``typeout`` library,
  - `Boost Preprocessor`_ is used by several preprocessor macros, you need it
    each time you use the ``typeout`` library,
  - `Boost Test Library`_ is used by test suite, you'll need it if you plan to
    compile (and run) test suites,
  - `Doxygen`_ used to generate API documentation, you'll need it if you plan
    to compile API documentation,


MOTIVATION
----------

If you ever used `Boost Test Library`_, you may know the test case templates
(for example `BOOST_AUTO_TEST_CASE_TEMPLATE()`_).  Normally you feed the test
case template from a sequence of types and test case template performs series of
checks on each provided type. The problem is, that when something goes wrong at
runtime and you start investigating the issue, the default output from test
runner (``--log_level=test_suite``) may show you just a bunch of mangled type
names that are not human readable. One possible approach to cope with this
problem is to provide user-readable messages with full information about
currently processed types.

The usage example of `BOOST_AUTO_TEST_CASE_TEMPLATE()`_ is::

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
fails (and yes, on most platforms it fails for ``unsigned char``)? Well, you'll
be informed that::

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
debug information.

The ``typeout`` library provides utilities to generate messages containing
previously registered type names, which may be a valuable debug information from
your test suites.

SOLUTION
--------

Consider the test case from previous section. With ``typeout`` you may easily
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
      using typeout::_string::_;

      BOOST_TEST_MESSAGE(__FILE__ "(" __LINE__ "): note: running my_test with T = " << _<T>() << ";");
      BOOST_CHECK_EQUAL( sizeof(T), (unsigned)4 );
    }

Now, the output from test runner with ``--log_level=message`` is like::

    Running 3 test cases...
    a.cpp(13): note: running my_test with T = int;
    a.cpp(13): note: running my_test with T = long int;
    a.cpp(14): error in "my_test<l>": check sizeof(T) == (unsigned)4 failed [8 != 4]
    a.cpp(13): note: running my_test with T = unsigned char;
    a.cpp(14): error in "my_test<h>": check sizeof(T) == (unsigned)4 failed [1 != 4]

    *** 2 failures detected in test suite "example"

Now it's easier to guess, that the test suite failed for ``long int`` and
``unsigned char`` types.

DOCUMENTATION
-------------

API documentation may be generated with::

    scons api-doc

The generated docs may be found under ``build/doc/typeout/html/index.html``.

TESTS
-----

Tests may be compiled with::

    scons check

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

.. _Doxygen: http://doxygen.org
.. _Boost Config: http://boost.org/libs/config
.. _Boost Preprocessor: http://boost.org/libs/preprocessor
.. _Boost Test Library: http://boost.org/libs/test/
.. _BOOST_AUTO_TEST_CASE_TEMPLATE(): http://boost.org/libs/test/doc/html/utf/user-guide/test-organization/auto-test-case-template.html
.. <!--- vim: set expandtab tabstop=2 shiftwidth=2 syntax=rst: -->
