#!/usr/bin/env bash

set -o xtrace
set -o errexit
set -o nounset
set -o pipefail

readonly currentScriptDir=`dirname "$(realpath -s "${BASH_SOURCE[0]}")"`
readonly gitRepoRoot="$currentScriptDir/.."
readonly buildDir="$gitRepoRoot/.build_static_Linux_binary"

rm -rf "$buildDir"
mkdir "$buildDir"

cmake \
  -S "$gitRepoRoot" \
  -B "$buildDir" \
  -D CMAKE_BUILD_TYPE=Release \
  -D CMAKE_EXE_LINKER_FLAGS=" \
    -static \
    -static-libgcc \
    -static-libstdc++" \
  -D RE2C_BUILD_RE2D=0 \
  -D RE2C_BUILD_RE2GO=0 \
  -D RE2C_BUILD_RE2HS=0 \
  -D RE2C_BUILD_RE2JAVA=0 \
  -D RE2C_BUILD_RE2JS=0 \
  -D RE2C_BUILD_RE2OCAML=0 \
  -D RE2C_BUILD_RE2PY=0 \
  -D RE2C_BUILD_RE2RUST=0 \
  -D RE2C_BUILD_RE2V=0 \
  -D RE2C_BUILD_RE2ZIG=0 \
  -D RE2C_BUILD_TESTS=0
cmake --build "$buildDir"
