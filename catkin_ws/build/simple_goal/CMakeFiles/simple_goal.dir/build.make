# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/demulab/catkin_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/demulab/catkin_ws/build

# Include any dependencies generated for this target.
include simple_goal/CMakeFiles/simple_goal.dir/depend.make

# Include the progress variables for this target.
include simple_goal/CMakeFiles/simple_goal.dir/progress.make

# Include the compile flags for this target's objects.
include simple_goal/CMakeFiles/simple_goal.dir/flags.make

simple_goal/CMakeFiles/simple_goal.dir/src/simple_goal.cpp.o: simple_goal/CMakeFiles/simple_goal.dir/flags.make
simple_goal/CMakeFiles/simple_goal.dir/src/simple_goal.cpp.o: /home/demulab/catkin_ws/src/simple_goal/src/simple_goal.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/demulab/catkin_ws/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object simple_goal/CMakeFiles/simple_goal.dir/src/simple_goal.cpp.o"
	cd /home/demulab/catkin_ws/build/simple_goal && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/simple_goal.dir/src/simple_goal.cpp.o -c /home/demulab/catkin_ws/src/simple_goal/src/simple_goal.cpp

simple_goal/CMakeFiles/simple_goal.dir/src/simple_goal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simple_goal.dir/src/simple_goal.cpp.i"
	cd /home/demulab/catkin_ws/build/simple_goal && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/demulab/catkin_ws/src/simple_goal/src/simple_goal.cpp > CMakeFiles/simple_goal.dir/src/simple_goal.cpp.i

simple_goal/CMakeFiles/simple_goal.dir/src/simple_goal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simple_goal.dir/src/simple_goal.cpp.s"
	cd /home/demulab/catkin_ws/build/simple_goal && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/demulab/catkin_ws/src/simple_goal/src/simple_goal.cpp -o CMakeFiles/simple_goal.dir/src/simple_goal.cpp.s

simple_goal/CMakeFiles/simple_goal.dir/src/simple_goal.cpp.o.requires:
.PHONY : simple_goal/CMakeFiles/simple_goal.dir/src/simple_goal.cpp.o.requires

simple_goal/CMakeFiles/simple_goal.dir/src/simple_goal.cpp.o.provides: simple_goal/CMakeFiles/simple_goal.dir/src/simple_goal.cpp.o.requires
	$(MAKE) -f simple_goal/CMakeFiles/simple_goal.dir/build.make simple_goal/CMakeFiles/simple_goal.dir/src/simple_goal.cpp.o.provides.build
.PHONY : simple_goal/CMakeFiles/simple_goal.dir/src/simple_goal.cpp.o.provides

simple_goal/CMakeFiles/simple_goal.dir/src/simple_goal.cpp.o.provides.build: simple_goal/CMakeFiles/simple_goal.dir/src/simple_goal.cpp.o

# Object files for target simple_goal
simple_goal_OBJECTS = \
"CMakeFiles/simple_goal.dir/src/simple_goal.cpp.o"

# External object files for target simple_goal
simple_goal_EXTERNAL_OBJECTS =

/home/demulab/catkin_ws/devel/lib/simple_goal/simple_goal: simple_goal/CMakeFiles/simple_goal.dir/src/simple_goal.cpp.o
/home/demulab/catkin_ws/devel/lib/simple_goal/simple_goal: simple_goal/CMakeFiles/simple_goal.dir/build.make
/home/demulab/catkin_ws/devel/lib/simple_goal/simple_goal: /opt/ros/indigo/lib/libactionlib.so
/home/demulab/catkin_ws/devel/lib/simple_goal/simple_goal: /opt/ros/indigo/lib/libroscpp.so
/home/demulab/catkin_ws/devel/lib/simple_goal/simple_goal: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/demulab/catkin_ws/devel/lib/simple_goal/simple_goal: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/demulab/catkin_ws/devel/lib/simple_goal/simple_goal: /opt/ros/indigo/lib/librosconsole.so
/home/demulab/catkin_ws/devel/lib/simple_goal/simple_goal: /opt/ros/indigo/lib/librosconsole_log4cxx.so
/home/demulab/catkin_ws/devel/lib/simple_goal/simple_goal: /opt/ros/indigo/lib/librosconsole_backend_interface.so
/home/demulab/catkin_ws/devel/lib/simple_goal/simple_goal: /usr/lib/liblog4cxx.so
/home/demulab/catkin_ws/devel/lib/simple_goal/simple_goal: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/demulab/catkin_ws/devel/lib/simple_goal/simple_goal: /opt/ros/indigo/lib/libroscpp_serialization.so
/home/demulab/catkin_ws/devel/lib/simple_goal/simple_goal: /opt/ros/indigo/lib/librostime.so
/home/demulab/catkin_ws/devel/lib/simple_goal/simple_goal: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/demulab/catkin_ws/devel/lib/simple_goal/simple_goal: /opt/ros/indigo/lib/libxmlrpcpp.so
/home/demulab/catkin_ws/devel/lib/simple_goal/simple_goal: /opt/ros/indigo/lib/libcpp_common.so
/home/demulab/catkin_ws/devel/lib/simple_goal/simple_goal: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/demulab/catkin_ws/devel/lib/simple_goal/simple_goal: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/demulab/catkin_ws/devel/lib/simple_goal/simple_goal: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/demulab/catkin_ws/devel/lib/simple_goal/simple_goal: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/demulab/catkin_ws/devel/lib/simple_goal/simple_goal: simple_goal/CMakeFiles/simple_goal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/demulab/catkin_ws/devel/lib/simple_goal/simple_goal"
	cd /home/demulab/catkin_ws/build/simple_goal && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simple_goal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
simple_goal/CMakeFiles/simple_goal.dir/build: /home/demulab/catkin_ws/devel/lib/simple_goal/simple_goal
.PHONY : simple_goal/CMakeFiles/simple_goal.dir/build

simple_goal/CMakeFiles/simple_goal.dir/requires: simple_goal/CMakeFiles/simple_goal.dir/src/simple_goal.cpp.o.requires
.PHONY : simple_goal/CMakeFiles/simple_goal.dir/requires

simple_goal/CMakeFiles/simple_goal.dir/clean:
	cd /home/demulab/catkin_ws/build/simple_goal && $(CMAKE_COMMAND) -P CMakeFiles/simple_goal.dir/cmake_clean.cmake
.PHONY : simple_goal/CMakeFiles/simple_goal.dir/clean

simple_goal/CMakeFiles/simple_goal.dir/depend:
	cd /home/demulab/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/demulab/catkin_ws/src /home/demulab/catkin_ws/src/simple_goal /home/demulab/catkin_ws/build /home/demulab/catkin_ws/build/simple_goal /home/demulab/catkin_ws/build/simple_goal/CMakeFiles/simple_goal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : simple_goal/CMakeFiles/simple_goal.dir/depend

