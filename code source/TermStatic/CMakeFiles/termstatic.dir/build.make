# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/akitoshi/Documents/Projet/ExiaScreen/Term/TermStatic

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/akitoshi/Documents/Projet/ExiaScreen/Term/TermStatic

# Include any dependencies generated for this target.
include CMakeFiles/termstatic.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/termstatic.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/termstatic.dir/flags.make

CMakeFiles/termstatic.dir/processus.c.o: CMakeFiles/termstatic.dir/flags.make
CMakeFiles/termstatic.dir/processus.c.o: processus.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akitoshi/Documents/Projet/ExiaScreen/Term/TermStatic/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/termstatic.dir/processus.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/termstatic.dir/processus.c.o   -c /home/akitoshi/Documents/Projet/ExiaScreen/Term/TermStatic/processus.c

CMakeFiles/termstatic.dir/processus.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/termstatic.dir/processus.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/akitoshi/Documents/Projet/ExiaScreen/Term/TermStatic/processus.c > CMakeFiles/termstatic.dir/processus.c.i

CMakeFiles/termstatic.dir/processus.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/termstatic.dir/processus.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/akitoshi/Documents/Projet/ExiaScreen/Term/TermStatic/processus.c -o CMakeFiles/termstatic.dir/processus.c.s

CMakeFiles/termstatic.dir/processus.c.o.requires:

.PHONY : CMakeFiles/termstatic.dir/processus.c.o.requires

CMakeFiles/termstatic.dir/processus.c.o.provides: CMakeFiles/termstatic.dir/processus.c.o.requires
	$(MAKE) -f CMakeFiles/termstatic.dir/build.make CMakeFiles/termstatic.dir/processus.c.o.provides.build
.PHONY : CMakeFiles/termstatic.dir/processus.c.o.provides

CMakeFiles/termstatic.dir/processus.c.o.provides.build: CMakeFiles/termstatic.dir/processus.c.o


CMakeFiles/termstatic.dir/main.c.o: CMakeFiles/termstatic.dir/flags.make
CMakeFiles/termstatic.dir/main.c.o: main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akitoshi/Documents/Projet/ExiaScreen/Term/TermStatic/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/termstatic.dir/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/termstatic.dir/main.c.o   -c /home/akitoshi/Documents/Projet/ExiaScreen/Term/TermStatic/main.c

CMakeFiles/termstatic.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/termstatic.dir/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/akitoshi/Documents/Projet/ExiaScreen/Term/TermStatic/main.c > CMakeFiles/termstatic.dir/main.c.i

CMakeFiles/termstatic.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/termstatic.dir/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/akitoshi/Documents/Projet/ExiaScreen/Term/TermStatic/main.c -o CMakeFiles/termstatic.dir/main.c.s

CMakeFiles/termstatic.dir/main.c.o.requires:

.PHONY : CMakeFiles/termstatic.dir/main.c.o.requires

CMakeFiles/termstatic.dir/main.c.o.provides: CMakeFiles/termstatic.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/termstatic.dir/build.make CMakeFiles/termstatic.dir/main.c.o.provides.build
.PHONY : CMakeFiles/termstatic.dir/main.c.o.provides

CMakeFiles/termstatic.dir/main.c.o.provides.build: CMakeFiles/termstatic.dir/main.c.o


CMakeFiles/termstatic.dir/virtuel.c.o: CMakeFiles/termstatic.dir/flags.make
CMakeFiles/termstatic.dir/virtuel.c.o: virtuel.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akitoshi/Documents/Projet/ExiaScreen/Term/TermStatic/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/termstatic.dir/virtuel.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/termstatic.dir/virtuel.c.o   -c /home/akitoshi/Documents/Projet/ExiaScreen/Term/TermStatic/virtuel.c

CMakeFiles/termstatic.dir/virtuel.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/termstatic.dir/virtuel.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/akitoshi/Documents/Projet/ExiaScreen/Term/TermStatic/virtuel.c > CMakeFiles/termstatic.dir/virtuel.c.i

CMakeFiles/termstatic.dir/virtuel.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/termstatic.dir/virtuel.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/akitoshi/Documents/Projet/ExiaScreen/Term/TermStatic/virtuel.c -o CMakeFiles/termstatic.dir/virtuel.c.s

CMakeFiles/termstatic.dir/virtuel.c.o.requires:

.PHONY : CMakeFiles/termstatic.dir/virtuel.c.o.requires

CMakeFiles/termstatic.dir/virtuel.c.o.provides: CMakeFiles/termstatic.dir/virtuel.c.o.requires
	$(MAKE) -f CMakeFiles/termstatic.dir/build.make CMakeFiles/termstatic.dir/virtuel.c.o.provides.build
.PHONY : CMakeFiles/termstatic.dir/virtuel.c.o.provides

CMakeFiles/termstatic.dir/virtuel.c.o.provides.build: CMakeFiles/termstatic.dir/virtuel.c.o


CMakeFiles/termstatic.dir/pbm.c.o: CMakeFiles/termstatic.dir/flags.make
CMakeFiles/termstatic.dir/pbm.c.o: pbm.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akitoshi/Documents/Projet/ExiaScreen/Term/TermStatic/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/termstatic.dir/pbm.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/termstatic.dir/pbm.c.o   -c /home/akitoshi/Documents/Projet/ExiaScreen/Term/TermStatic/pbm.c

CMakeFiles/termstatic.dir/pbm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/termstatic.dir/pbm.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/akitoshi/Documents/Projet/ExiaScreen/Term/TermStatic/pbm.c > CMakeFiles/termstatic.dir/pbm.c.i

CMakeFiles/termstatic.dir/pbm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/termstatic.dir/pbm.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/akitoshi/Documents/Projet/ExiaScreen/Term/TermStatic/pbm.c -o CMakeFiles/termstatic.dir/pbm.c.s

CMakeFiles/termstatic.dir/pbm.c.o.requires:

.PHONY : CMakeFiles/termstatic.dir/pbm.c.o.requires

CMakeFiles/termstatic.dir/pbm.c.o.provides: CMakeFiles/termstatic.dir/pbm.c.o.requires
	$(MAKE) -f CMakeFiles/termstatic.dir/build.make CMakeFiles/termstatic.dir/pbm.c.o.provides.build
.PHONY : CMakeFiles/termstatic.dir/pbm.c.o.provides

CMakeFiles/termstatic.dir/pbm.c.o.provides.build: CMakeFiles/termstatic.dir/pbm.c.o


# Object files for target termstatic
termstatic_OBJECTS = \
"CMakeFiles/termstatic.dir/processus.c.o" \
"CMakeFiles/termstatic.dir/main.c.o" \
"CMakeFiles/termstatic.dir/virtuel.c.o" \
"CMakeFiles/termstatic.dir/pbm.c.o"

# External object files for target termstatic
termstatic_EXTERNAL_OBJECTS =

termstatic: CMakeFiles/termstatic.dir/processus.c.o
termstatic: CMakeFiles/termstatic.dir/main.c.o
termstatic: CMakeFiles/termstatic.dir/virtuel.c.o
termstatic: CMakeFiles/termstatic.dir/pbm.c.o
termstatic: CMakeFiles/termstatic.dir/build.make
termstatic: CMakeFiles/termstatic.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/akitoshi/Documents/Projet/ExiaScreen/Term/TermStatic/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable termstatic"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/termstatic.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/termstatic.dir/build: termstatic

.PHONY : CMakeFiles/termstatic.dir/build

CMakeFiles/termstatic.dir/requires: CMakeFiles/termstatic.dir/processus.c.o.requires
CMakeFiles/termstatic.dir/requires: CMakeFiles/termstatic.dir/main.c.o.requires
CMakeFiles/termstatic.dir/requires: CMakeFiles/termstatic.dir/virtuel.c.o.requires
CMakeFiles/termstatic.dir/requires: CMakeFiles/termstatic.dir/pbm.c.o.requires

.PHONY : CMakeFiles/termstatic.dir/requires

CMakeFiles/termstatic.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/termstatic.dir/cmake_clean.cmake
.PHONY : CMakeFiles/termstatic.dir/clean

CMakeFiles/termstatic.dir/depend:
	cd /home/akitoshi/Documents/Projet/ExiaScreen/Term/TermStatic && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/akitoshi/Documents/Projet/ExiaScreen/Term/TermStatic /home/akitoshi/Documents/Projet/ExiaScreen/Term/TermStatic /home/akitoshi/Documents/Projet/ExiaScreen/Term/TermStatic /home/akitoshi/Documents/Projet/ExiaScreen/Term/TermStatic /home/akitoshi/Documents/Projet/ExiaScreen/Term/TermStatic/CMakeFiles/termstatic.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/termstatic.dir/depend

