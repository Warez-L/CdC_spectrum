cmake_minimum_required(VERSION 3.22)
project(LV_Spectrum VERSION 1.0)

set(CMAKE_C_STANDARD 99)

set(LV_CONF_PATH
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/lv_conf.h
        CACHE STRING "" FORCE)

set(KISSFFT_DATATYPE float)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/lib/")

include_directories("${CMAKE_INSTALL_PREFIX}/include")

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/src/")
