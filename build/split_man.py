#!/usr/bin/env python3

"""
Generates language-specific manpages by replacing placeholder tokens in the
input manpage.
"""

import sys

if len(sys.argv) != 4:
    print('usage:', sys.argv[0], '<input> <output> <lang>')
    exit(1)

input = sys.argv[1]
output = sys.argv[2]
lang = sys.argv[3].lower().encode('utf-8')

hdr_ext = None
disclaimer = None
if lang == b'c':
    src_ext = b'c'
    hdr_ext = b'h'
    lang_name = b'C/C++'
    disclaimer = b'Note: examples are in C++ (but can be easily adapted to C).'
elif lang == b'd':
    src_ext = b'd'
    lang_name = b'D'
elif lang == b'go':
    src_ext = b'go'
    lang_name = b'Go'
elif lang == b'haskell':
    src_ext = b'hs'
    lang_name = b'Haskell'
elif lang == b'java':
    src_ext = b'java'
    lang_name = b'Java'
elif lang == b'js':
    src_ext = b'js'
    lang_name = b'JavaScript'
elif lang == b'ocaml':
    src_ext = b'ml'
    lang_name = b'OCaml'
elif lang == b'python':
    src_ext = b'py'
    lang_name = b'Python'
elif lang == b'rust':
    src_ext = b'rs'
    lang_name = b'Rust'
elif lang == b'v':
    src_ext = b'v'
    lang_name = b'V'
elif lang == b'zig':
    src_ext = b'zig'
    lang_name = b'Zig'
else:
    print('***', sys.argv[0], ': unknown lang:', lang)
    exit(1)
if hdr_ext == None:
    hdr_ext = src_ext
if disclaimer == None:
    disclaimer = (b'Note: This manual is for ' + lang_name +
        b', but it refers to re2c as the general program.')

with open(input, 'rb') as input_file:
    file_bytes = input_file.read()

file_bytes = file_bytes.replace(b'RE2C_LANG_NAME', lang_name)
file_bytes = file_bytes.replace(b'RE2C_LANG', lang)
file_bytes = file_bytes.replace(b'RE2C_SOURCE_EXT', src_ext)
file_bytes = file_bytes.replace(b'RE2C_HEADER_EXT', hdr_ext)
file_bytes = file_bytes.replace(b'RE2C_DISCLAIMER', disclaimer)

with open(output, 'wb') as output_file:
    output_file.write(file_bytes)
