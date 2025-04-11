cmake_minimum_required(VERSION 3.26)
project(DiceSim)
set (CMAKE_CXX_STANDARD 14)

include_directories(includes)

set (sources 
        dicesim.cpp 
        display.cpp
        setup.cpp
)

add_subdirectory(lib)
add_executable(DiceSim ${sources})
target_link_libraries(DiceSim PRIVATE dslib )
