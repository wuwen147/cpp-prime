cmake_minimum_required(VERSION 3.13)

project (stl)
set(CMAKE_CXX_STANDARD 17)

include(VER.mk)

#configure_file(include/version.h.in include/version.h)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pthread -O2 -g -Wl,-rpath=.:bin")

include_directories(src)

file(GLOB SRCS 
	src/*.cpp
	)

add_executable(stl ${SRCS}) 

if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 9.0)
	target_link_libraries(stl stdc++fs)  
endif() 
