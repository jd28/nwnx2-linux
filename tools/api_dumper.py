#!/usr/bin/env python

import subprocess
import re
import os

def get_forward_decls(whence):
  return subprocess.Popen([
    'cpp',
    '-DNWNX_DUMP_STRUCTS',  # Flag for any special casing needs.
    '-D_NWNDEF_CUSTOM_H_',  # Ignore this since it includes c headers.
    '-D_CEXOARRAYLIST_H_',  # Special Cased
    '-D_CEXOLINKEDLIST_H_', # Special Cased
    '-D_CEXOLINKEDLISTINTERNAL_H_', # Special Cased
    whence+'/../api/nwndef.h'],
    stdout=subprocess.PIPE).communicate()[0].decode("utf-8")

def get_struct_defs(whence):
  return subprocess.Popen([
    'cpp',
    '-DNWNX_DUMP_STRUCTS',  # Flag for any special casing needs.
    '-D_NWNDEF_H_',         # Already done.
    '-D_NWNDEF_CUSTOM_H_',  # Ignore this since it includes c headers.
    '-D_CEXOARRAYLIST_H_',  # Special Cased
    '-D_CEXOLINKEDLIST_H_', # Special Cased
    '-D_CEXOLINKEDLISTINTERNAL_H_', # Special Cased
    whence+'/../api/all.h'],
    stdout=subprocess.PIPE).communicate()[0].decode("utf-8")

def astyle(whence):
  # Make it all look a little better and avoid too many whitespace changes
  # later.
  subprocess.Popen([
    'astyle',
    '--suffix=none', # Don't want .orig files.
    whence+'/../api/api_dump.h'],
    stdout=subprocess.PIPE)

DELETE_PATTERNS = [
  # No preprocessor
  re.compile('^#.*?$', flags=re.MULTILINE),
  # Namespaces
  re.compile('namespace.*?}', flags=re.MULTILINE|re.DOTALL),
  # No operators
  re.compile('^.*?operator.*?;', flags=re.MULTILINE),
  # No templates
  re.compile('template.*?[};]', flags=re.MULTILINE|re.DOTALL),
  # No externs
  re.compile('^extern.*?\(.*?\).*?;', flags=re.MULTILINE|re.DOTALL),
  # No funcions
  re.compile('^.*?[a-zA-Z0-9]\(.*?\).*?;', flags=re.MULTILINE),
  # No visibility specifiers
  re.compile('(public|private|protected).*?:')
]

CEXOARRAYLIST = """
struct CExoArrayList_{0}
{{
    {1} *Array;
    unsigned long Length;
    unsigned long ArraySize;
}};"""

CEXOLINKEDLIST = """
struct CExoLinkedList_{0} {{
    /* 0x0/0 */ CExoLinkedListInternal *List;
}};"""

# Format calls pass in sanitized template parameter name
# and the original template parameter.
TEMPLATE_FORMATERS = {
  'CExoArrayList': CEXOARRAYLIST,
  'CExoLinkedList': CEXOLINKEDLIST,
}

HEADER = """
// Auto-Generated DO NOT edit or use as an include.

struct CExoLinkedListInternal;

struct CExoLinkedList {
    /* 0x0/0 */ CExoLinkedListInternal *List;
};
struct CExoString {
    char *Text;
    unsigned long Length;
};

"""

forwards = {}
templates = {}

TEMPLATE_FIELDS = re.compile('^\s*(.*?)<(.*?)>', flags=re.MULTILINE)
def template_field_replace(match):
  klass, tparam = match.groups(0)
  sanitized_tparam = tparam.replace(' ', '_').strip()
  if sanitized_tparam[-1] == "*":
    r = 'ptr' if sanitized_tparam[-2] == "_" else '_ptr'
    sanitized_tparam = sanitized_tparam.replace('*', r)

  sanitized_type = "%s_%s" % (klass, sanitized_tparam)
  # Add our new type to the forward decl list
  forwards[sanitized_type] = True

  if klass in TEMPLATE_FORMATERS:
    if klass not in templates: templates[klass] = {}
    # Add our new structure definition
    templates[klass][tparam] = TEMPLATE_FORMATERS[klass].format(sanitized_tparam, tparam)

  # Return comment with original type name and the new type.
  return """// {0}<{1}>\n{2}""".format(klass, tparam, sanitized_type)

if __name__ == '__main__':
  whence = os.path.dirname(os.path.realpath(__file__))
  forward_decls = get_forward_decls(whence)
  struct_defs = get_struct_defs(whence)

  for d in DELETE_PATTERNS:
    struct_defs = d.sub('', struct_defs)
    forward_decls = d.sub('', forward_decls)

  struct_defs = TEMPLATE_FIELDS.sub(template_field_replace, struct_defs)

  # Not designed for efficiency.
  with open(whence+'/../api/api_dump.h', 'w') as f:
    f.write(HEADER)

    f.write('// Forward Declarations\n\n')
    for line in forward_decls.splitlines():
      if len(line.strip()):
        f.write(line)
        f.write('\n')

    for t in sorted(forwards.keys()):
      f.write('struct %s;\n' % t)

    for t in sorted(templates.keys()):
      for u in sorted(templates[t].keys()):
        f.write(templates[t][u])

    f.write('// Struct Definitions\n\n')
    for line in struct_defs.splitlines():
      if (not len(line.strip())
          or '__extension__' in line):
           continue
      f.write(line)
      f.write('\n')

  astyle(whence)
