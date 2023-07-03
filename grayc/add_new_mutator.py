#!/usr/bin/env python
#
#===- add_new_check.py - GrayC check generator ---------*- python -*--===#
#
# Taken from the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===-----------------------------------------------------------------------===#

from __future__ import print_function

import argparse
import os
import re
import sys


# Adapts the module's CMakelist file. Returns 'True' if it could add a new
# entry and 'False' if the entry already existed.
def adapt_cmake(module_path, check_name_camel):
  filename = os.path.join(module_path, 'CMakeLists.txt')
  with open(filename, 'r') as f:
    lines = f.readlines()

  cpp_file = check_name_camel + '.cpp'

  # Figure out whether this check already exists.
  for line in lines:
    if line.strip() == cpp_file:
      return False

  print('Updating %s...' % filename)
  with open(filename, 'w') as f:
    cpp_found = False
    file_added = False
    for line in lines:
      cpp_line = line.strip().endswith('.cpp')
      if (not file_added) and (cpp_line or cpp_found):
        cpp_found = True
        if (line.strip() > cpp_file) or (not cpp_line):
          f.write('  ' + cpp_file + '\n')
          file_added = True
      f.write(line)

  return True


# Adds a header for the new check.
def write_header(module_path, module, namespace, check_name, check_name_camel):
  check_name_dashes = module + '-' + check_name
  filename = os.path.join(module_path, check_name_camel) + '.h'
  print('Creating %s...' % filename)
  with open(filename, 'w') as f:
    header_guard = ('LLVM_CLANG_TOOLS_EXTRA_GRAYC_' + module.upper() + '_'
                    + check_name_camel.upper() + '_H')
    f.write('//===--- ')
    f.write(os.path.basename(filename))
    f.write(' - grayc ')
    f.write('-' * max(0, 42 - len(os.path.basename(filename))))
    f.write('*- C++ -*-===//')
    f.write("""
//
// Taken from the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef %(header_guard)s
#define %(header_guard)s

#include "../GrayCCheck.h"

namespace clang {
namespace grayc {
namespace %(namespace)s {

/// FIXME: Write a short description.
///
class %(check_name)s : public GrayCCheck {
public:
  %(check_name)s(StringRef Name, GrayCContext *Context)
      : GrayCCheck(Name, Context) {}
  void registerMatchers(ast_matchers::MatchFinder *Finder) override;
  void check(const ast_matchers::MatchFinder::MatchResult &Result) override;
};

} // namespace %(namespace)s
} // namespace grayc
} // namespace clang

#endif // %(header_guard)s
""" % {'header_guard': header_guard,
       'check_name': check_name_camel,
       'check_name_dashes': check_name_dashes,
       'module': module,
       'namespace': namespace})


# Adds the implementation of the new check.
def write_implementation(module_path, module, namespace, check_name_camel):
  filename = os.path.join(module_path, check_name_camel) + '.cpp'
  print('Creating %s...' % filename)
  with open(filename, 'w') as f:
    f.write('//===--- ')
    f.write(os.path.basename(filename))
    f.write(' - grayc ')
    f.write('-' * max(0, 51 - len(os.path.basename(filename))))
    f.write('-===//')
    f.write("""
//
// Taken from the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "%(check_name)s.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

using namespace clang::ast_matchers;

namespace clang {
namespace grayc {
namespace %(namespace)s {

void %(check_name)s::registerMatchers(MatchFinder *Finder) {
  // FIXME: Add matchers.
  Finder->addMatcher(functionDecl().bind("x"), this);
}

void %(check_name)s::check(const MatchFinder::MatchResult &Result) {
  // FIXME: Add callback implementation.
  const auto *MatchedDecl = Result.Nodes.getNodeAs<FunctionDecl>("x");
  if (MatchedDecl->getName().startswith("awesome_"))
    return;
  diag(MatchedDecl->getLocation(), "function %%0 is insufficiently awesome")
      << MatchedDecl;
  diag(MatchedDecl->getLocation(), "insert 'awesome'", DiagnosticIDs::Note)
      << FixItHint::CreateInsertion(MatchedDecl->getLocation(), "awesome_");
}

} // namespace %(namespace)s
} // namespace grayc
} // namespace clang
""" % {'check_name': check_name_camel,
       'module': module,
       'namespace': namespace})


# Modifies the module to include the new check.
def adapt_module(module_path, module, check_name, check_name_camel):
  modulecpp = list(filter(
      lambda p: p.lower() == module.lower() + 'module.cpp',
      os.listdir(module_path)))[0]
  filename = os.path.join(module_path, modulecpp)
  with open(filename, 'r') as f:
    lines = f.readlines()

  print('Updating %s...' % filename)
  with open(filename, 'w') as f:
    header_added = False
    header_found = False
    check_added = False
    check_fq_name = module + '-' + check_name
    check_decl = ('    CheckFactories.registerCheck<' + check_name_camel +
                  '>(\n        "' + check_fq_name + '");\n')

    lines = iter(lines)
    try:
      while True:
        line = next(lines)
        if not header_added:
          match = re.search('#include "(.*)"', line)
          if match:
            header_found = True
            if match.group(1) > check_name_camel:
              header_added = True
              f.write('#include "' + check_name_camel + '.h"\n')
          elif header_found:
            header_added = True
            f.write('#include "' + check_name_camel + '.h"\n')

        if not check_added:
          if line.strip() == '}':
            check_added = True
            f.write(check_decl)
          else:
            match = re.search('registerCheck<(.*)> *\( *(?:"([^"]*)")?', line)
            prev_line = None
            if match:
              current_check_name = match.group(2)
              if current_check_name is None:
                # If we didn't find the check name on this line, look on the
                # next one.
                prev_line = line
                line = next(lines)
                match = re.search(' *"([^"]*)"', line)
                if match:
                  current_check_name = match.group(1)
              if current_check_name > check_fq_name:
                check_added = True
                f.write(check_decl)
              if prev_line:
                f.write(prev_line)
        f.write(line)
    except StopIteration:
      pass



def get_actual_filename(dirname, filename):
  if not os.path.isdir(dirname): 
    return ""
  name = os.path.join(dirname, filename)
  if (os.path.isfile(name)):
    return name
  caselessname = filename.lower()
  for file in os.listdir(dirname):
    if (file.lower() == caselessname):
      return os.path.join(dirname, file)
  return ""


# Recreates the list of checks in the docs/grayc/checks directory.
def update_checks_list(grayc_path):
  docs_dir = os.path.join(grayc_path, '../docs/grayc/checks')
  filename = os.path.normpath(os.path.join(docs_dir, 'list.rst'))
  # Read the content of the current list.rst file
  with open(filename, 'r') as f:
    lines = f.readlines()
  # Get all existing docs
  doc_files = list(filter(lambda s: s.endswith('.rst') and s != 'list.rst',
                     os.listdir(docs_dir)))
  doc_files.sort()

  def has_auto_fix(check_name):
    dirname, _, check_name = check_name.partition("-")

    checkerCode = get_actual_filename(dirname,
                                      get_camel_name(check_name) + '.cpp')

    if not os.path.isfile(checkerCode):
      return ""

    with open(checkerCode) as f:
      code = f.read()
      if 'FixItHint' in code or "ReplacementText" in code or "fixit" in code:
        # Some simple heuristics to figure out if a checker has an autofix or not.
        return ' "Yes"'
    return ""


def get_camel_name(check_name):
  return ''.join(map(lambda elem: elem.capitalize(),
                     check_name.split('-'))) 


def main():
  language_to_extension = {
      'c': 'c',
      'c++': 'cpp',
      'objc': 'm',
      'objc++': 'mm',
  }
  parser = argparse.ArgumentParser()
  parser.add_argument(
      '--language',
      help='language to use for new check (defaults to c++)',
      choices=language_to_extension.keys(),
      default='c++',
      metavar='LANG')
  parser.add_argument(
      'module',
      nargs='?',
      help='module directory under which to place the new grayc check (e.g., misc)')
  parser.add_argument(
      'check',
      nargs='?',
      help='name of new grayc check to add (e.g. foo-do-the-stuff)')
  args = parser.parse_args()

  if not args.module or not args.check:
    print('Module and check must be specified.')
    parser.print_usage()
    return

  module = args.module
  check_name = args.check
  check_name_camel = get_camel_name(check_name)
  if check_name.startswith(module):
    print('Check name "%s" must not start with the module "%s". Exiting.' % (
        check_name, module))
    return
  grayc_path = os.path.dirname(sys.argv[0])
  module_path = os.path.join(grayc_path, module)

  if not adapt_cmake(module_path, check_name_camel):
    return

  # Map module names to namespace names that don't conflict with widely used top-level namespaces.
  if module == 'llvm':
    namespace = module + '_check'
  else:
    namespace = module

  write_header(module_path, module, namespace, check_name, check_name_camel)
  write_implementation(module_path, module, namespace, check_name_camel)
  adapt_module(module_path, module, check_name, check_name_camel)

  print('Done. Now it\'s your turn!')


if __name__ == '__main__':
  main()
