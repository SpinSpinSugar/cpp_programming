# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chansonsdamour/Desktop/Repositories/cpp_programming_semester3/Homework3/Task2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chansonsdamour/Desktop/Repositories/cpp_programming_semester3/Homework3/Task2/build

# Include any dependencies generated for this target.
include CMakeFiles/Test_generator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Test_generator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Test_generator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Test_generator.dir/flags.make

CMakeFiles/Test_generator.dir/Test_generator.cpp.o: CMakeFiles/Test_generator.dir/flags.make
CMakeFiles/Test_generator.dir/Test_generator.cpp.o: ../Test_generator.cpp
CMakeFiles/Test_generator.dir/Test_generator.cpp.o: CMakeFiles/Test_generator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chansonsdamour/Desktop/Repositories/cpp_programming_semester3/Homework3/Task2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Test_generator.dir/Test_generator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test_generator.dir/Test_generator.cpp.o -MF CMakeFiles/Test_generator.dir/Test_generator.cpp.o.d -o CMakeFiles/Test_generator.dir/Test_generator.cpp.o -c /home/chansonsdamour/Desktop/Repositories/cpp_programming_semester3/Homework3/Task2/Test_generator.cpp

CMakeFiles/Test_generator.dir/Test_generator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test_generator.dir/Test_generator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chansonsdamour/Desktop/Repositories/cpp_programming_semester3/Homework3/Task2/Test_generator.cpp > CMakeFiles/Test_generator.dir/Test_generator.cpp.i

CMakeFiles/Test_generator.dir/Test_generator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test_generator.dir/Test_generator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chansonsdamour/Desktop/Repositories/cpp_programming_semester3/Homework3/Task2/Test_generator.cpp -o CMakeFiles/Test_generator.dir/Test_generator.cpp.s

# Object files for target Test_generator
Test_generator_OBJECTS = \
"CMakeFiles/Test_generator.dir/Test_generator.cpp.o"

# External object files for target Test_generator
Test_generator_EXTERNAL_OBJECTS =

Test_generator: CMakeFiles/Test_generator.dir/Test_generator.cpp.o
Test_generator: CMakeFiles/Test_generator.dir/build.make
Test_generator: CMakeFiles/Test_generator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chansonsdamour/Desktop/Repositories/cpp_programming_semester3/Homework3/Task2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Test_generator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Test_generator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Test_generator.dir/build: Test_generator
.PHONY : CMakeFiles/Test_generator.dir/build

CMakeFiles/Test_generator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Test_generator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Test_generator.dir/clean

CMakeFiles/Test_generator.dir/depend:
	cd /home/chansonsdamour/Desktop/Repositories/cpp_programming_semester3/Homework3/Task2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chansonsdamour/Desktop/Repositories/cpp_programming_semester3/Homework3/Task2 /home/chansonsdamour/Desktop/Repositories/cpp_programming_semester3/Homework3/Task2 /home/chansonsdamour/Desktop/Repositories/cpp_programming_semester3/Homework3/Task2/build /home/chansonsdamour/Desktop/Repositories/cpp_programming_semester3/Homework3/Task2/build /home/chansonsdamour/Desktop/Repositories/cpp_programming_semester3/Homework3/Task2/build/CMakeFiles/Test_generator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Test_generator.dir/depend

