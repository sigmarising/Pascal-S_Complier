project(code)
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
file(GLOB code_SRC
        "*.h"
        "*.cpp"
        )

add_executable(code ${code_SRC})
