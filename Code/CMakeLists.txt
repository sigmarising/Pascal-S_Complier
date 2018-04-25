cmake_minimum_required(VERSION 3.10)
#project name
PROJECT(MyCompiler)
set(CMAKE_CXX_STANDARD 11)
MESSAGE(STATUS "Source dir: " ${PROJECT_SOURCE_DIR})
MESSAGE(STATUS "Binary dir: " ${PROJECT_BINARY_DIR})
#head file directory
INCLUDE_DIRECTORIES(include)
#source file directory
AUX_SOURCE_DIRECTORY(src DIR_SRCS)
#set environment variable
SET(MYCOMPILER ${DIR_SRCS})
#add executable file
ADD_EXECUTABLE(pas2c ${MYCOMPILER})
