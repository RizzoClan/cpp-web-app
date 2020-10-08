# FindJSON.cmake - Try to find the CLI library
# Once done this will define
#
# JSON_FOUND       - Found the json lib path
# JSON_INCLUDE_DIR - Location of the json lib header

# set statically, because these are pinned by git and not version controlled
SET(JSON_FOUND True)
SET(JSON_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/extern/json/) # give relative path to include dir
