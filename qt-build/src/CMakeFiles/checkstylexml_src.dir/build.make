# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /users/disk9/cfse/Stage_Malo/clion-2017.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /users/disk9/cfse/Stage_Malo/clion-2017.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cfse/Stage_Malo/CPACSCreatorTotal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build

# Utility rule file for checkstylexml_src.

# Include the progress variables for this target.
include src/CMakeFiles/checkstylexml_src.dir/progress.make

src/CMakeFiles/checkstylexml_src: src/src_checkstyle-xml


src/src_checkstyle-xml: /home/cfse/Stage_Malo/CPACSCreatorTotal/src/filefilter.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating src_checkstyle-xml"
	/usr/bin/python /home/cfse/Stage_Malo/CPACSCreatorTotal/thirdparty/nsiqcppstyle/nsiqcppstyle.py --ci -o /users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/src --output=xml /home/cfse/Stage_Malo/CPACSCreatorTotal/src

/home/cfse/Stage_Malo/CPACSCreatorTotal/src/filefilter.txt:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating /home/cfse/Stage_Malo/CPACSCreatorTotal/src/filefilter.txt"
	cd /users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/src && /users/disk9/cfse/Stage_Malo/clion-2017.3.3/bin/cmake/bin/cmake -E copy /home/cfse/Stage_Malo/CPACSCreatorTotal/thirdparty/nsiqcppstyle/filefilter.txt /home/cfse/Stage_Malo/CPACSCreatorTotal/src/

checkstylexml_src: src/CMakeFiles/checkstylexml_src
checkstylexml_src: src/src_checkstyle-xml
checkstylexml_src: /home/cfse/Stage_Malo/CPACSCreatorTotal/src/filefilter.txt
checkstylexml_src: src/CMakeFiles/checkstylexml_src.dir/build.make

.PHONY : checkstylexml_src

# Rule to build all files generated by this target.
src/CMakeFiles/checkstylexml_src.dir/build: checkstylexml_src

.PHONY : src/CMakeFiles/checkstylexml_src.dir/build

src/CMakeFiles/checkstylexml_src.dir/clean:
	cd /users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/src && $(CMAKE_COMMAND) -P CMakeFiles/checkstylexml_src.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/checkstylexml_src.dir/clean

src/CMakeFiles/checkstylexml_src.dir/depend:
	cd /users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cfse/Stage_Malo/CPACSCreatorTotal /home/cfse/Stage_Malo/CPACSCreatorTotal/src /users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build /users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/src /users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/src/CMakeFiles/checkstylexml_src.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/checkstylexml_src.dir/depend
