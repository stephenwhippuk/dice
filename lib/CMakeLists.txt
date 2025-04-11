cmake_minimum_required(VERSION 3.26)
set (CMAKE_CXX_STANDARD 14)

include_directories(include)

set(libSources 
    convert.cpp
    diceDiff.cpp
    diceMax.cpp
    diceSum.cpp
    generatorFactory.cpp
    simulator.cpp
    stats.cpp
)

add_library(dslib ${libSources})

