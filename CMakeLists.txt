cmake_minimum_required(VERSION 3.12.4)
get_directory_property(hasParent PARENT_DIRECTORY)
if(NOT hasParent)
	option(unittests "unittests" OFF)
	get_filename_component(_PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
	set_property(GLOBAL PROPERTY GLOBAL_FETCHDEPS_BASE ${_PARENT_DIR}/al2o3 )
	include(FetchContent)
	FetchContent_Declare( al2o3 GIT_REPOSITORY https://github.com/DeanoC/al2o3 GIT_TAG master )
	FetchContent_GetProperties(al2o3)
	if(NOT al2o3_POPULATED)
		FetchContent_Populate(al2o3)
		add_subdirectory(${al2o3_SOURCE_DIR} ${al2o3_BINARY_DIR})
	endif()
	INIT_AL2O3(${CMAKE_CURRENT_SOURCE_DIR})
endif ()
SET_MIN_VERSIONS()
set(LibName utils_nativefiledialogs)
project(${LibName})

set(Interface
		dialogs.h
		)
set(Src
		dialogs.c

		include/nfd.h
		common.h
		nfd_common.c
		nfd_common.h
		)
if(WIN32)
	list(APPEND Src
			nfd_win.cpp
			)
endif()
if(APPLE)
	list(APPEND Src
			nfd_cocoa.m
			)

endif()
if(UNIX AND !APPLE)
	list(APPEND Src
			nfd_gtk.c
			)
endif()

set(Deps
		al2o3_platform
		al2o3_memory
		)
ADD_LIB(${LibName} "${Interface}" "${Src}" "${Deps}")
target_include_directories(${LibName} PRIVATE src/include)
