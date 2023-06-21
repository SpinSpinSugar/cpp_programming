# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/chansons/Repositories/cpp_programming/Semester4/Homework3/build/_deps/googletest-src"
  "/home/chansons/Repositories/cpp_programming/Semester4/Homework3/build/_deps/googletest-build"
  "/home/chansons/Repositories/cpp_programming/Semester4/Homework3/build/_deps/googletest-subbuild/googletest-populate-prefix"
  "/home/chansons/Repositories/cpp_programming/Semester4/Homework3/build/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/home/chansons/Repositories/cpp_programming/Semester4/Homework3/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/home/chansons/Repositories/cpp_programming/Semester4/Homework3/build/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/home/chansons/Repositories/cpp_programming/Semester4/Homework3/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/chansons/Repositories/cpp_programming/Semester4/Homework3/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/chansons/Repositories/cpp_programming/Semester4/Homework3/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
