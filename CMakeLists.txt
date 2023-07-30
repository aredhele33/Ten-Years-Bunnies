# file      CMakeLists.txt
# project   TenYearsBunnies

SET(BUN_PROJECT_NAME "TenYearsBunnies")
SET(BUN_PROJECT_VERSION_MAJOR 1)
SET(BUN_PROJECT_VERSION_MINOR 0)
SET(BUN_PROJECT_VERSION_PATCH 0)
SET(BUN_PROJECT_CXX_STANDARD  20)

CMAKE_MINIMUM_REQUIRED(VERSION 3.25)
PROJECT(${BUN_PROJECT_NAME})
SET    (VERSION_MAJOR ${BUN_PROJECT_VERSION_MAJOR})
SET    (VERSION_MINOR ${BUN_PROJECT_VERSION_MINOR})
SET    (VERSION_PATCH ${BUN_PROJECT_VERSION_PATCH})
SET    (CMAKE_CXX_STANDARD ${BUN_PROJECT_CXX_STANDARD})

MESSAGE(STATUS "[Bun][Project] ${BUN_PROJECT_NAME} ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
MESSAGE(STATUS "[Bun][Project] CXX standard : C++${BUN_PROJECT_CXX_STANDARD}")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    SET(BUN_BUILD_TYPE            "Debug")
    SET(BUN_BUILD_TYPE_DIRECTORY  "Debug")
    SET(BUN_BUILD_TYPE_SUFFIX     "_d")
    SET(BUN_SFML_SUFFIX           "-s-d.a")
    MESSAGE(STATUS "[Bun][Project] Detected build type : Debug")

ENDIF()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    SET(BUN_BUILD_TYPE            "Release")
    SET(BUN_BUILD_TYPE_DIRECTORY  "Release")
    SET(BUN_BUILD_TYPE_SUFFIX     "_r")
    SET(BUN_SFML_SUFFIX           "-s.a")
    MESSAGE(STATUS "[Bun][Project] Detected build type : Debug")

ENDIF()

# Setting default output directories, examples :
# Binaries/Debug
# Binaries/Release
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Binaries/${BUN_BUILD_TYPE_DIRECTORY}")
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Binaries/${BUN_BUILD_TYPE_DIRECTORY}")

file(GLOB_RECURSE TenYearsBunniesHeaders "${CMAKE_SOURCE_DIR}/Sources/Headers/*.hpp")
file(GLOB_RECURSE TenYearsBunniesSources "${CMAKE_SOURCE_DIR}/Sources/Sources/*.cpp")

ADD_EXECUTABLE(TenYearsBunnies ${TenYearsBunniesHeaders} ${TenYearsBunniesSources})

# SFML Setup
TARGET_INCLUDE_DIRECTORIES(TenYearsBunnies PUBLIC "${CMAKE_SOURCE_DIR}/Externals/SFML-2.6.0/include/")

TARGET_LINK_LIBRARIES(TenYearsBunnies
        "${CMAKE_SOURCE_DIR}/Externals/SFML-2.6.0/lib/MiNGW/${BUN_BUILD_TYPE_DIRECTORY}/libsfml-graphics${BUN_SFML_SUFFIX}"
        "${CMAKE_SOURCE_DIR}/Externals/SFML-2.6.0/lib/MiNGW/${BUN_BUILD_TYPE_DIRECTORY}/libsfml-window${BUN_SFML_SUFFIX}"
        "${CMAKE_SOURCE_DIR}/Externals/SFML-2.6.0/lib/MiNGW/${BUN_BUILD_TYPE_DIRECTORY}/libsfml-system${BUN_SFML_SUFFIX}"
        "${CMAKE_SOURCE_DIR}/Externals/SFML-2.6.0/lib/MiNGW/libfreetype.a"
        opengl32 winmm gdi32)

TARGET_COMPILE_DEFINITIONS(TenYearsBunnies PUBLIC "SFML_STATIC")

# Project Setup
TARGET_INCLUDE_DIRECTORIES(TenYearsBunnies PUBLIC "${CMAKE_SOURCE_DIR}/Sources/Headers/")
