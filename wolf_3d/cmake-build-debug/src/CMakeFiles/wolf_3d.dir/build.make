# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/akolomoi/Desktop/wolf_3d/wolf_3d

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug

# Include any dependencies generated for this target.
include src/CMakeFiles/wolf_3d.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/wolf_3d.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/wolf_3d.dir/flags.make

src/CMakeFiles/wolf_3d.dir/create_window.c.o: src/CMakeFiles/wolf_3d.dir/flags.make
src/CMakeFiles/wolf_3d.dir/create_window.c.o: ../src/create_window.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/wolf_3d.dir/create_window.c.o"
	cd /Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wolf_3d.dir/create_window.c.o   -c /Users/akolomoi/Desktop/wolf_3d/wolf_3d/src/create_window.c

src/CMakeFiles/wolf_3d.dir/create_window.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wolf_3d.dir/create_window.c.i"
	cd /Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/akolomoi/Desktop/wolf_3d/wolf_3d/src/create_window.c > CMakeFiles/wolf_3d.dir/create_window.c.i

src/CMakeFiles/wolf_3d.dir/create_window.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wolf_3d.dir/create_window.c.s"
	cd /Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/akolomoi/Desktop/wolf_3d/wolf_3d/src/create_window.c -o CMakeFiles/wolf_3d.dir/create_window.c.s

src/CMakeFiles/wolf_3d.dir/errors.c.o: src/CMakeFiles/wolf_3d.dir/flags.make
src/CMakeFiles/wolf_3d.dir/errors.c.o: ../src/errors.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/CMakeFiles/wolf_3d.dir/errors.c.o"
	cd /Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wolf_3d.dir/errors.c.o   -c /Users/akolomoi/Desktop/wolf_3d/wolf_3d/src/errors.c

src/CMakeFiles/wolf_3d.dir/errors.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wolf_3d.dir/errors.c.i"
	cd /Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/akolomoi/Desktop/wolf_3d/wolf_3d/src/errors.c > CMakeFiles/wolf_3d.dir/errors.c.i

src/CMakeFiles/wolf_3d.dir/errors.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wolf_3d.dir/errors.c.s"
	cd /Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/akolomoi/Desktop/wolf_3d/wolf_3d/src/errors.c -o CMakeFiles/wolf_3d.dir/errors.c.s

src/CMakeFiles/wolf_3d.dir/events.c.o: src/CMakeFiles/wolf_3d.dir/flags.make
src/CMakeFiles/wolf_3d.dir/events.c.o: ../src/events.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/CMakeFiles/wolf_3d.dir/events.c.o"
	cd /Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wolf_3d.dir/events.c.o   -c /Users/akolomoi/Desktop/wolf_3d/wolf_3d/src/events.c

src/CMakeFiles/wolf_3d.dir/events.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wolf_3d.dir/events.c.i"
	cd /Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/akolomoi/Desktop/wolf_3d/wolf_3d/src/events.c > CMakeFiles/wolf_3d.dir/events.c.i

src/CMakeFiles/wolf_3d.dir/events.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wolf_3d.dir/events.c.s"
	cd /Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/akolomoi/Desktop/wolf_3d/wolf_3d/src/events.c -o CMakeFiles/wolf_3d.dir/events.c.s

src/CMakeFiles/wolf_3d.dir/map.c.o: src/CMakeFiles/wolf_3d.dir/flags.make
src/CMakeFiles/wolf_3d.dir/map.c.o: ../src/map.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/CMakeFiles/wolf_3d.dir/map.c.o"
	cd /Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wolf_3d.dir/map.c.o   -c /Users/akolomoi/Desktop/wolf_3d/wolf_3d/src/map.c

src/CMakeFiles/wolf_3d.dir/map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wolf_3d.dir/map.c.i"
	cd /Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/akolomoi/Desktop/wolf_3d/wolf_3d/src/map.c > CMakeFiles/wolf_3d.dir/map.c.i

src/CMakeFiles/wolf_3d.dir/map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wolf_3d.dir/map.c.s"
	cd /Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/akolomoi/Desktop/wolf_3d/wolf_3d/src/map.c -o CMakeFiles/wolf_3d.dir/map.c.s

src/CMakeFiles/wolf_3d.dir/ray.c.o: src/CMakeFiles/wolf_3d.dir/flags.make
src/CMakeFiles/wolf_3d.dir/ray.c.o: ../src/ray.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/CMakeFiles/wolf_3d.dir/ray.c.o"
	cd /Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wolf_3d.dir/ray.c.o   -c /Users/akolomoi/Desktop/wolf_3d/wolf_3d/src/ray.c

src/CMakeFiles/wolf_3d.dir/ray.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wolf_3d.dir/ray.c.i"
	cd /Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/akolomoi/Desktop/wolf_3d/wolf_3d/src/ray.c > CMakeFiles/wolf_3d.dir/ray.c.i

src/CMakeFiles/wolf_3d.dir/ray.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wolf_3d.dir/ray.c.s"
	cd /Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/akolomoi/Desktop/wolf_3d/wolf_3d/src/ray.c -o CMakeFiles/wolf_3d.dir/ray.c.s

src/CMakeFiles/wolf_3d.dir/wolf_3d.c.o: src/CMakeFiles/wolf_3d.dir/flags.make
src/CMakeFiles/wolf_3d.dir/wolf_3d.c.o: ../src/wolf_3d.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object src/CMakeFiles/wolf_3d.dir/wolf_3d.c.o"
	cd /Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wolf_3d.dir/wolf_3d.c.o   -c /Users/akolomoi/Desktop/wolf_3d/wolf_3d/src/wolf_3d.c

src/CMakeFiles/wolf_3d.dir/wolf_3d.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wolf_3d.dir/wolf_3d.c.i"
	cd /Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/akolomoi/Desktop/wolf_3d/wolf_3d/src/wolf_3d.c > CMakeFiles/wolf_3d.dir/wolf_3d.c.i

src/CMakeFiles/wolf_3d.dir/wolf_3d.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wolf_3d.dir/wolf_3d.c.s"
	cd /Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/akolomoi/Desktop/wolf_3d/wolf_3d/src/wolf_3d.c -o CMakeFiles/wolf_3d.dir/wolf_3d.c.s

src/CMakeFiles/wolf_3d.dir/draw_funcs.c.o: src/CMakeFiles/wolf_3d.dir/flags.make
src/CMakeFiles/wolf_3d.dir/draw_funcs.c.o: ../src/draw_funcs.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object src/CMakeFiles/wolf_3d.dir/draw_funcs.c.o"
	cd /Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wolf_3d.dir/draw_funcs.c.o   -c /Users/akolomoi/Desktop/wolf_3d/wolf_3d/src/draw_funcs.c

src/CMakeFiles/wolf_3d.dir/draw_funcs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wolf_3d.dir/draw_funcs.c.i"
	cd /Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/akolomoi/Desktop/wolf_3d/wolf_3d/src/draw_funcs.c > CMakeFiles/wolf_3d.dir/draw_funcs.c.i

src/CMakeFiles/wolf_3d.dir/draw_funcs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wolf_3d.dir/draw_funcs.c.s"
	cd /Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/akolomoi/Desktop/wolf_3d/wolf_3d/src/draw_funcs.c -o CMakeFiles/wolf_3d.dir/draw_funcs.c.s

# Object files for target wolf_3d
wolf_3d_OBJECTS = \
"CMakeFiles/wolf_3d.dir/create_window.c.o" \
"CMakeFiles/wolf_3d.dir/errors.c.o" \
"CMakeFiles/wolf_3d.dir/events.c.o" \
"CMakeFiles/wolf_3d.dir/map.c.o" \
"CMakeFiles/wolf_3d.dir/ray.c.o" \
"CMakeFiles/wolf_3d.dir/wolf_3d.c.o" \
"CMakeFiles/wolf_3d.dir/draw_funcs.c.o"

# External object files for target wolf_3d
wolf_3d_EXTERNAL_OBJECTS =

src/wolf_3d: src/CMakeFiles/wolf_3d.dir/create_window.c.o
src/wolf_3d: src/CMakeFiles/wolf_3d.dir/errors.c.o
src/wolf_3d: src/CMakeFiles/wolf_3d.dir/events.c.o
src/wolf_3d: src/CMakeFiles/wolf_3d.dir/map.c.o
src/wolf_3d: src/CMakeFiles/wolf_3d.dir/ray.c.o
src/wolf_3d: src/CMakeFiles/wolf_3d.dir/wolf_3d.c.o
src/wolf_3d: src/CMakeFiles/wolf_3d.dir/draw_funcs.c.o
src/wolf_3d: src/CMakeFiles/wolf_3d.dir/build.make
src/wolf_3d: src/CMakeFiles/wolf_3d.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable wolf_3d"
	cd /Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wolf_3d.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/wolf_3d.dir/build: src/wolf_3d

.PHONY : src/CMakeFiles/wolf_3d.dir/build

src/CMakeFiles/wolf_3d.dir/clean:
	cd /Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/wolf_3d.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/wolf_3d.dir/clean

src/CMakeFiles/wolf_3d.dir/depend:
	cd /Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/akolomoi/Desktop/wolf_3d/wolf_3d /Users/akolomoi/Desktop/wolf_3d/wolf_3d/src /Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug /Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/src /Users/akolomoi/Desktop/wolf_3d/wolf_3d/cmake-build-debug/src/CMakeFiles/wolf_3d.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/wolf_3d.dir/depend
