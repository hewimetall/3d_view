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
CMAKE_SOURCE_DIR = /Users/kaleighh/3d_view/build/_deps/raylib-subbuild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kaleighh/3d_view/build/_deps/raylib-subbuild

# Utility rule file for raylib-populate.

# Include any custom commands dependencies for this target.
include CMakeFiles/raylib-populate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/raylib-populate.dir/progress.make

CMakeFiles/raylib-populate: CMakeFiles/raylib-populate-complete

CMakeFiles/raylib-populate-complete: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-install
CMakeFiles/raylib-populate-complete: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-mkdir
CMakeFiles/raylib-populate-complete: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-download
CMakeFiles/raylib-populate-complete: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-update
CMakeFiles/raylib-populate-complete: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-patch
CMakeFiles/raylib-populate-complete: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-configure
CMakeFiles/raylib-populate-complete: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-build
CMakeFiles/raylib-populate-complete: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-install
CMakeFiles/raylib-populate-complete: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/kaleighh/3d_view/build/_deps/raylib-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'raylib-populate'"
	/usr/local/bin/cmake -E make_directory /Users/kaleighh/3d_view/build/_deps/raylib-subbuild/CMakeFiles
	/usr/local/bin/cmake -E touch /Users/kaleighh/3d_view/build/_deps/raylib-subbuild/CMakeFiles/raylib-populate-complete
	/usr/local/bin/cmake -E touch /Users/kaleighh/3d_view/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-done

raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-build: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/kaleighh/3d_view/build/_deps/raylib-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No build step for 'raylib-populate'"
	cd /Users/kaleighh/3d_view/build/_deps/raylib-build && /usr/local/bin/cmake -E echo_append
	cd /Users/kaleighh/3d_view/build/_deps/raylib-build && /usr/local/bin/cmake -E touch /Users/kaleighh/3d_view/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-build

raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-configure: raylib-populate-prefix/tmp/raylib-populate-cfgcmd.txt
raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-configure: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/kaleighh/3d_view/build/_deps/raylib-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "No configure step for 'raylib-populate'"
	cd /Users/kaleighh/3d_view/build/_deps/raylib-build && /usr/local/bin/cmake -E echo_append
	cd /Users/kaleighh/3d_view/build/_deps/raylib-build && /usr/local/bin/cmake -E touch /Users/kaleighh/3d_view/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-configure

raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-download: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-urlinfo.txt
raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-download: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/kaleighh/3d_view/build/_deps/raylib-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (download, verify and extract) for 'raylib-populate'"
	cd /Users/kaleighh/3d_view/build/_deps && /usr/local/bin/cmake -P /Users/kaleighh/3d_view/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp/download-raylib-populate.cmake
	cd /Users/kaleighh/3d_view/build/_deps && /usr/local/bin/cmake -P /Users/kaleighh/3d_view/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp/verify-raylib-populate.cmake
	cd /Users/kaleighh/3d_view/build/_deps && /usr/local/bin/cmake -P /Users/kaleighh/3d_view/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp/extract-raylib-populate.cmake
	cd /Users/kaleighh/3d_view/build/_deps && /usr/local/bin/cmake -E touch /Users/kaleighh/3d_view/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-download

raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-install: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/kaleighh/3d_view/build/_deps/raylib-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'raylib-populate'"
	cd /Users/kaleighh/3d_view/build/_deps/raylib-build && /usr/local/bin/cmake -E echo_append
	cd /Users/kaleighh/3d_view/build/_deps/raylib-build && /usr/local/bin/cmake -E touch /Users/kaleighh/3d_view/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-install

raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/kaleighh/3d_view/build/_deps/raylib-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'raylib-populate'"
	/usr/local/bin/cmake -E make_directory /Users/kaleighh/3d_view/build/_deps/raylib-src
	/usr/local/bin/cmake -E make_directory /Users/kaleighh/3d_view/build/_deps/raylib-build
	/usr/local/bin/cmake -E make_directory /Users/kaleighh/3d_view/build/_deps/raylib-subbuild/raylib-populate-prefix
	/usr/local/bin/cmake -E make_directory /Users/kaleighh/3d_view/build/_deps/raylib-subbuild/raylib-populate-prefix/tmp
	/usr/local/bin/cmake -E make_directory /Users/kaleighh/3d_view/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp
	/usr/local/bin/cmake -E make_directory /Users/kaleighh/3d_view/build/_deps/raylib-subbuild/raylib-populate-prefix/src
	/usr/local/bin/cmake -E make_directory /Users/kaleighh/3d_view/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp
	/usr/local/bin/cmake -E touch /Users/kaleighh/3d_view/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-mkdir

raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-patch: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-update
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/kaleighh/3d_view/build/_deps/raylib-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'raylib-populate'"
	/usr/local/bin/cmake -E echo_append
	/usr/local/bin/cmake -E touch /Users/kaleighh/3d_view/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-patch

raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-test: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/kaleighh/3d_view/build/_deps/raylib-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No test step for 'raylib-populate'"
	cd /Users/kaleighh/3d_view/build/_deps/raylib-build && /usr/local/bin/cmake -E echo_append
	cd /Users/kaleighh/3d_view/build/_deps/raylib-build && /usr/local/bin/cmake -E touch /Users/kaleighh/3d_view/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-test

raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-update: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/kaleighh/3d_view/build/_deps/raylib-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "No update step for 'raylib-populate'"
	/usr/local/bin/cmake -E echo_append
	/usr/local/bin/cmake -E touch /Users/kaleighh/3d_view/build/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-update

raylib-populate: CMakeFiles/raylib-populate
raylib-populate: CMakeFiles/raylib-populate-complete
raylib-populate: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-build
raylib-populate: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-configure
raylib-populate: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-download
raylib-populate: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-install
raylib-populate: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-mkdir
raylib-populate: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-patch
raylib-populate: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-test
raylib-populate: raylib-populate-prefix/src/raylib-populate-stamp/raylib-populate-update
raylib-populate: CMakeFiles/raylib-populate.dir/build.make
.PHONY : raylib-populate

# Rule to build all files generated by this target.
CMakeFiles/raylib-populate.dir/build: raylib-populate
.PHONY : CMakeFiles/raylib-populate.dir/build

CMakeFiles/raylib-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/raylib-populate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/raylib-populate.dir/clean

CMakeFiles/raylib-populate.dir/depend:
	cd /Users/kaleighh/3d_view/build/_deps/raylib-subbuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kaleighh/3d_view/build/_deps/raylib-subbuild /Users/kaleighh/3d_view/build/_deps/raylib-subbuild /Users/kaleighh/3d_view/build/_deps/raylib-subbuild /Users/kaleighh/3d_view/build/_deps/raylib-subbuild /Users/kaleighh/3d_view/build/_deps/raylib-subbuild/CMakeFiles/raylib-populate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/raylib-populate.dir/depend

