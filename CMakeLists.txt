cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project (Crow-Websites)

# =================================== load Dependencies globally for all subdirs ===================================
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/src/cmake")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/extern/crow/cmake") # add crow lib's cmake

# Find the packages
find_package(BoostLib REQUIRED) # uses FindBoost.cmake in cmake dir
find_package(CLI11 REQUIRED) # using https://cliutils.gitlab.io/CLI11Tutorial/
find_package(JSON REQUIRED) # using https://github.com/nlohmann/json


# Include the package's header files
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/extern/crow/include") # contains header file for crow lib
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src/include") # contains OUR headers
include_directories(${CLI11_INCLUDE_DIR})
include_directories(${JSON_INCLUDE_DIR})



# ===================================== Accept Build Mode for Debug/Release ========================================
# TODO

# ============================================ Build individual subdirs ============================================
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin) # store produce binaries in src/bin/*
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

# add more folders here as needed (i.e. frontend)
# these trigger the CMakeLists.txt file to be called in the listed dirs
add_subdirectory(src/backend)
