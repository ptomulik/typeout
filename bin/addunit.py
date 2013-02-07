#! /usr/bin/python

# @COPYRIGHT@
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE

# bin/addunit.py: add new unit (header, source and possibly others)

import argparse 

def add_cli_args(argparser):
    from os import path
    # Default values
    prefix = path.join('src', 'include')
    default_namespace = 'typeout'
    hpp_ext = '.hpp'
    cpp_ext = '.cpp'
    # Options
    argparser.add_argument('-q','--quiet', action = "store_false",
        dest = 'verbose', help = "don't print status messages to stdout")
    argparser.add_argument('--no-cpp', action = 'store_false', 
        dest = 'generate_cpp', default = True,
        help = 'do not generate C++ source file')
    argparser.add_argument('--no-hpp', action = 'store_false', 
        dest = 'generate_hpp', default = True,
        help = 'do not generate C++ header file')
    argparser.add_argument('--default-namespace', type = str, metavar = 'ns',
        action = 'store', dest = 'default_namespace',
        help = "default namespace for generated unit (%s)" % default_namespace,
        default = default_namespace)
    argparser.add_argument('--prefix', type = str, metavar = 'dir',
        action = 'store', dest = 'prefix',
        help = "prefix prepended to output directory (%s)" % prefix,
        default = prefix)
    argparser.add_argument('--hpp-ext', type = str, metavar = 'dir',
        action = 'store', dest = 'hpp_ext',
        help = "extension used for header file (%s)" % hpp_ext,
        default = hpp_ext)
    argparser.add_argument('--cpp-ext', type = str, metavar = 'dir',
        action = 'store', dest = 'cpp_ext', 
        help = "extension used for source file (%s)" % cpp_ext,
        default = cpp_ext)
    # Positioal arguments
    argparser.add_argument('unit_name', metavar = 'name', action = 'store',
                            help = "the::unit::name")

def generate_unit(args):
    import re
    import string
    from os import path, makedirs
    from sys import stderr, stdout


    if args.verbose:
        stdout.write("info: preparing to generate unit %r\n" % args.unit_name)

    error = 0

    if args.unit_name.find('::') == -1:
        unit_name_full = args.default_namespace + '::' + args.unit_name
        if args.verbose:
            stdout.write('info: %r not within a namespace, assuming %r\n' 
                        % (args.unit_name, unit_name_full))
    else:
        unit_name_full =  args.unit_name
    unit_name_parts = unit_name_full.split('::')
    re_id = re.compile(r'^[a-zA-Z_][a-zA-Z0-9_]*$')
    unit_name_correct_parts = [ p for p in unit_name_parts if re_id.match(p) ] 
    if len(unit_name_parts) != len(unit_name_correct_parts) \
    or len(unit_name_parts) < 1:
        stderr.write('error: malformed unit name: %r\n' % args.unit_name)
        error = 1

    unit_name = unit_name_parts[-1]
    unit_header_guard = '_'.join([p.upper() for p in unit_name_parts]) + '_HPP_INCLUDED'
    namespaces = unit_name_parts[:-1]

    if namespaces:
        open_namespaces = '\n'.join(
          ['namespace ' + p + ' {' for p in namespaces ]
        )
        close_namespaces = '\n'.join( 
          [ '} /* namespace ' + p + ' */' for p in reversed(namespaces) ] 
        )
    else:
        open_namespaces = ''
        close_namespaces = ''

    hpp_file_rel = path.join(*unit_name_parts).lower() + args.hpp_ext
    hpp_file_full = path.join(args.prefix, hpp_file_rel)
    cpp_file_rel = path.join(*unit_name_parts).lower() + args.cpp_ext
    cpp_file_full = path.join(args.prefix, cpp_file_rel)
    # FIXME: The extension (and possibly location) should not be hard-coded
    
    # Assure the files to be generated do not exist
    if args.generate_hpp:
        if path.exists(hpp_file_full):
            stderr.write("error: %r already exists, won't override\n" 
                         % hpp_file_full)
            error = 1
    if args.generate_cpp:
        if path.exists(cpp_file_full):
            stderr.write("error: %r already exists, won't override\n"
                         % cpp_file_full)
            error = 1

    # Create directories when necessary
    if not error:
        if args.generate_hpp:
            hpp_dir = path.dirname(hpp_file_full)
            if not path.exists(hpp_dir):
                if args.verbose:
                    stdout.write("info: creating directory %r\n" % hpp_dir)
                makedirs(hpp_dir)
            elif not path.isdir(hpp_dir):
                stderr.write("error: %r is not a directory\n" % hpp_dir)        
                error = 1
        if args.generate_cpp:
            cpp_dir = path.dirname(cpp_file_full)
            if not path.exists(cpp_dir):
                if args.verbose:
                    stdout.write("info: creating directory %r\n" % cpp_dir)
                makedirs(cpp_dir)
            elif not path.isdir(cpp_dir):
                stderr.write("error: %r is not a directory\n" % cpp_dir)        
                error = 1

    if not error:
        # FIXME: customize template
        unit_hpp_in = path.join("template", "addunit", "unit.hpp.in")
        unit_cpp_in = path.join("template", "addunit", "unit.cpp.in")

        substs = {  'UNIT'                 : unit_name,
                    'UNIT_NAMESPACES'      : '::'.join(namespaces),
                    'UNIT_HEADER_FILE'     : hpp_file_rel,
                    'UNIT_SOURCE_FILE'     : cpp_file_rel,
                    'UNIT_HEADER_GUARD'    : unit_header_guard,
                    'UNIT_OPEN_NAMESPACES' : open_namespaces,
                    'UNIT_CLOSE_NAMESPACES': close_namespaces,
                    }

        if args.generate_hpp:
            if args.verbose:
                stdout.write("info: reading %r\n" % unit_hpp_in)
            if not path.isfile(unit_hpp_in):
                stderr.write("error: file %r does not exist\n"
                            % unit_hpp_in)
                error = 1
            else:
                hpp_template = string.Template(file(unit_hpp_in).read())
        if args.generate_cpp:
            if args.verbose:
                stdout.write("info: reading %r\n" % unit_cpp_in)
            if not path.isfile(unit_cpp_in):
                stderr.write("error: file %r does not exist\n"
                            % unit_cpp_in)
                error = 1
            else:
                cpp_template = string.Template(file(unit_cpp_in).read())
    if not error:
        if args.generate_hpp:
            if args.verbose:
                stdout.write("info: generating %r\n" % hpp_file_full)
            file(hpp_file_full, "w").write(hpp_template.substitute(substs))
        if args.generate_cpp:
            if args.verbose:
                stdout.write("info: generating %r\n" % cpp_file_full)
            file(cpp_file_full, "w").write(cpp_template.substitute(substs))
    return error

argparser = argparse.ArgumentParser()
add_cli_args(argparser)
args = argparser.parse_args()
exit(generate_unit(args))

# Local Variables:
# # tab-width:4
# # indent-tabs-mode:nil
# # End:
# vim: set syntax=python expandtab tabstop=4 shiftwidth=4:
