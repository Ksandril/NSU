# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\prog\c_buff

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\prog\c_buff\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/c_buff.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/c_buff.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/c_buff.dir/flags.make

CMakeFiles/c_buff.dir/main.cpp.obj: CMakeFiles/c_buff.dir/flags.make
CMakeFiles/c_buff.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\prog\c_buff\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/c_buff.dir/main.cpp.obj"
	"D:\CLion 2019.2.1\mingw\mingw32\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\c_buff.dir\main.cpp.obj -c D:\prog\c_buff\main.cpp

CMakeFiles/c_buff.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/c_buff.dir/main.cpp.i"
	"D:\CLion 2019.2.1\mingw\mingw32\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\prog\c_buff\main.cpp > CMakeFiles\c_buff.dir\main.cpp.i

CMakeFiles/c_buff.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/c_buff.dir/main.cpp.s"
	"D:\CLion 2019.2.1\mingw\mingw32\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\prog\c_buff\main.cpp -o CMakeFiles\c_buff.dir\main.cpp.s

CMakeFiles/c_buff.dir/tests/tests.cpp.obj: CMakeFiles/c_buff.dir/flags.make
CMakeFiles/c_buff.dir/tests/tests.cpp.obj: ../tests/tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\prog\c_buff\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/c_buff.dir/tests/tests.cpp.obj"
	"D:\CLion 2019.2.1\mingw\mingw32\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\c_buff.dir\tests\tests.cpp.obj -c D:\prog\c_buff\tests\tests.cpp

CMakeFiles/c_buff.dir/tests/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/c_buff.dir/tests/tests.cpp.i"
	"D:\CLion 2019.2.1\mingw\mingw32\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\prog\c_buff\tests\tests.cpp > CMakeFiles\c_buff.dir\tests\tests.cpp.i

CMakeFiles/c_buff.dir/tests/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/c_buff.dir/tests/tests.cpp.s"
	"D:\CLion 2019.2.1\mingw\mingw32\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\prog\c_buff\tests\tests.cpp -o CMakeFiles\c_buff.dir\tests\tests.cpp.s

# Object files for target c_buff
c_buff_OBJECTS = \
"CMakeFiles/c_buff.dir/main.cpp.obj" \
"CMakeFiles/c_buff.dir/tests/tests.cpp.obj"

# External object files for target c_buff
c_buff_EXTERNAL_OBJECTS =

c_buff.exe: CMakeFiles/c_buff.dir/main.cpp.obj
c_buff.exe: CMakeFiles/c_buff.dir/tests/tests.cpp.obj
c_buff.exe: CMakeFiles/c_buff.dir/build.make
c_buff.exe: CMakeFiles/c_buff.dir/linklibs.rsp
c_buff.exe: CMakeFiles/c_buff.dir/objects1.rsp
c_buff.exe: CMakeFiles/c_buff.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\prog\c_buff\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable c_buff.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\c_buff.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/c_buff.dir/build: c_buff.exe

.PHONY : CMakeFiles/c_buff.dir/build

CMakeFiles/c_buff.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\c_buff.dir\cmake_clean.cmake
.PHONY : CMakeFiles/c_buff.dir/clean

CMakeFiles/c_buff.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\prog\c_buff D:\prog\c_buff D:\prog\c_buff\cmake-build-debug D:\prog\c_buff\cmake-build-debug D:\prog\c_buff\cmake-build-debug\CMakeFiles\c_buff.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/c_buff.dir/depend

