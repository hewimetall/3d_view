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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kaleighh/3d_view

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kaleighh/3d_view/build

# Include any dependencies generated for this target.
include CMakeFiles/s21_view3d.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/s21_view3d.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/s21_view3d.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/s21_view3d.dir/flags.make

CMakeFiles/s21_view3d.dir/main.c.o: CMakeFiles/s21_view3d.dir/flags.make
CMakeFiles/s21_view3d.dir/main.c.o: ../main.c
CMakeFiles/s21_view3d.dir/main.c.o: CMakeFiles/s21_view3d.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kaleighh/3d_view/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/s21_view3d.dir/main.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/s21_view3d.dir/main.c.o -MF CMakeFiles/s21_view3d.dir/main.c.o.d -o CMakeFiles/s21_view3d.dir/main.c.o -c /Users/kaleighh/3d_view/main.c

CMakeFiles/s21_view3d.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/s21_view3d.dir/main.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/kaleighh/3d_view/main.c > CMakeFiles/s21_view3d.dir/main.c.i

CMakeFiles/s21_view3d.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/s21_view3d.dir/main.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/kaleighh/3d_view/main.c -o CMakeFiles/s21_view3d.dir/main.c.s

CMakeFiles/s21_view3d.dir/parser.c.o: CMakeFiles/s21_view3d.dir/flags.make
CMakeFiles/s21_view3d.dir/parser.c.o: ../parser.c
CMakeFiles/s21_view3d.dir/parser.c.o: CMakeFiles/s21_view3d.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kaleighh/3d_view/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/s21_view3d.dir/parser.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/s21_view3d.dir/parser.c.o -MF CMakeFiles/s21_view3d.dir/parser.c.o.d -o CMakeFiles/s21_view3d.dir/parser.c.o -c /Users/kaleighh/3d_view/parser.c

CMakeFiles/s21_view3d.dir/parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/s21_view3d.dir/parser.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/kaleighh/3d_view/parser.c > CMakeFiles/s21_view3d.dir/parser.c.i

CMakeFiles/s21_view3d.dir/parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/s21_view3d.dir/parser.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/kaleighh/3d_view/parser.c -o CMakeFiles/s21_view3d.dir/parser.c.s

CMakeFiles/s21_view3d.dir/utils.c.o: CMakeFiles/s21_view3d.dir/flags.make
CMakeFiles/s21_view3d.dir/utils.c.o: ../utils.c
CMakeFiles/s21_view3d.dir/utils.c.o: CMakeFiles/s21_view3d.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kaleighh/3d_view/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/s21_view3d.dir/utils.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/s21_view3d.dir/utils.c.o -MF CMakeFiles/s21_view3d.dir/utils.c.o.d -o CMakeFiles/s21_view3d.dir/utils.c.o -c /Users/kaleighh/3d_view/utils.c

CMakeFiles/s21_view3d.dir/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/s21_view3d.dir/utils.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/kaleighh/3d_view/utils.c > CMakeFiles/s21_view3d.dir/utils.c.i

CMakeFiles/s21_view3d.dir/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/s21_view3d.dir/utils.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/kaleighh/3d_view/utils.c -o CMakeFiles/s21_view3d.dir/utils.c.s

CMakeFiles/s21_view3d.dir/ui.c.o: CMakeFiles/s21_view3d.dir/flags.make
CMakeFiles/s21_view3d.dir/ui.c.o: ../ui.c
CMakeFiles/s21_view3d.dir/ui.c.o: CMakeFiles/s21_view3d.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kaleighh/3d_view/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/s21_view3d.dir/ui.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/s21_view3d.dir/ui.c.o -MF CMakeFiles/s21_view3d.dir/ui.c.o.d -o CMakeFiles/s21_view3d.dir/ui.c.o -c /Users/kaleighh/3d_view/ui.c

CMakeFiles/s21_view3d.dir/ui.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/s21_view3d.dir/ui.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/kaleighh/3d_view/ui.c > CMakeFiles/s21_view3d.dir/ui.c.i

CMakeFiles/s21_view3d.dir/ui.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/s21_view3d.dir/ui.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/kaleighh/3d_view/ui.c -o CMakeFiles/s21_view3d.dir/ui.c.s

CMakeFiles/s21_view3d.dir/3dmath.c.o: CMakeFiles/s21_view3d.dir/flags.make
CMakeFiles/s21_view3d.dir/3dmath.c.o: ../3dmath.c
CMakeFiles/s21_view3d.dir/3dmath.c.o: CMakeFiles/s21_view3d.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kaleighh/3d_view/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/s21_view3d.dir/3dmath.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/s21_view3d.dir/3dmath.c.o -MF CMakeFiles/s21_view3d.dir/3dmath.c.o.d -o CMakeFiles/s21_view3d.dir/3dmath.c.o -c /Users/kaleighh/3d_view/3dmath.c

CMakeFiles/s21_view3d.dir/3dmath.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/s21_view3d.dir/3dmath.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/kaleighh/3d_view/3dmath.c > CMakeFiles/s21_view3d.dir/3dmath.c.i

CMakeFiles/s21_view3d.dir/3dmath.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/s21_view3d.dir/3dmath.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/kaleighh/3d_view/3dmath.c -o CMakeFiles/s21_view3d.dir/3dmath.c.s

# Object files for target s21_view3d
s21_view3d_OBJECTS = \
"CMakeFiles/s21_view3d.dir/main.c.o" \
"CMakeFiles/s21_view3d.dir/parser.c.o" \
"CMakeFiles/s21_view3d.dir/utils.c.o" \
"CMakeFiles/s21_view3d.dir/ui.c.o" \
"CMakeFiles/s21_view3d.dir/3dmath.c.o"

# External object files for target s21_view3d
s21_view3d_EXTERNAL_OBJECTS =

s21_view3d: CMakeFiles/s21_view3d.dir/main.c.o
s21_view3d: CMakeFiles/s21_view3d.dir/parser.c.o
s21_view3d: CMakeFiles/s21_view3d.dir/utils.c.o
s21_view3d: CMakeFiles/s21_view3d.dir/ui.c.o
s21_view3d: CMakeFiles/s21_view3d.dir/3dmath.c.o
s21_view3d: CMakeFiles/s21_view3d.dir/build.make
s21_view3d: _deps/raylib-build/raylib/libraylib.a
s21_view3d: _deps/raylib-build/raylib/external/glfw/src/libglfw3.a
s21_view3d: CMakeFiles/s21_view3d.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kaleighh/3d_view/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable s21_view3d"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/s21_view3d.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/s21_view3d.dir/build: s21_view3d
.PHONY : CMakeFiles/s21_view3d.dir/build

CMakeFiles/s21_view3d.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/s21_view3d.dir/cmake_clean.cmake
.PHONY : CMakeFiles/s21_view3d.dir/clean

CMakeFiles/s21_view3d.dir/depend:
	cd /Users/kaleighh/3d_view/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kaleighh/3d_view /Users/kaleighh/3d_view /Users/kaleighh/3d_view/build /Users/kaleighh/3d_view/build /Users/kaleighh/3d_view/build/CMakeFiles/s21_view3d.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/s21_view3d.dir/depend

