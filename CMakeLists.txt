cmake_minimum_required(VERSION 3.22)

set(PROJECT_NAME TexasHoldem)
project(${PROJECT_NAME} CXX C)
option(BUILD_WITH_EASY_PROFILER "Enable EasyProfiler usage" ON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(EASY_PROFILER_NO_GUI ON CACHE BOOL "")
set(EASY_PROFILER_NO_SAMPLES ON CACHE BOOL "")

if(WIN32)
    set(PYTHON_EXECUTABLE "python")
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
else()
    set(PYTHON_EXECUTABLE "python3")
endif()

if(BUILD_WITH_EASY_PROFILER)
    message("-- Enabled EasyProfiler")
    add_definitions(-DBUILD_WITH_EASY_PROFILER=1)
    include_directories(deps/easy_profiler/include)
    #set_property(TARGET easy_profiler PROPERTY FOLDER "ThirdPartyLibraries")
    #set_property(TARGET profiler_converter PROPERTY FOLDER "ThirdPartyLibraries")
endif()

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "")
set(GLFW_INSTALL OFF CACHE BOOL "")

set(ASSIMP_NO_EXPORT ON CACHE BOOL "")
set(ASSIMP_BUILD_DRACO OFF CACHE BOOL "")
set(ASSIMP_BUILD_ASSIMP_TOOLS OFF CACHE BOOL "")
set(ASSIMP_BUILD_TESTS OFF CACHE BOOL "")
set(ASSIMP_INSTALL_PDB OFF CACHE BOOL "")
set(ASSIMP_BUILD_ALL_IMPORTERS_BY_DEFAULT OFF CACHE BOOL "")
set(ASSIMP_BUILD_OBJ_IMPORTER ON CACHE BOOL "")
set(ASSIMP_BUILD_GLTF_IMPORTER ON CACHE BOOL "")

set(MESHOPT_BUILD_DEMO OFF CACHE BOOL "")
set(MESHOPT_BUILD_TOOLS OFF CACHE BOOL "")
set(MESHOPT_BUILD_SHARED_LIBS OFF CACHE BOOL "")

#set(Optick_DIR deps/optick/cmake-build-debug)

add_subdirectory(deps/glfw)
add_subdirectory(deps/easy_sources)
add_subdirectory(deps/crossguid)
add_subdirectory(deps/assimp)
add_subdirectory(deps/meshoptimizer)

include_directories(deps/glm)
include_directories(deps/stb)
include_directories(deps/gli)
include_directories(deps/taskflow)
include_directories(deps/imgui)
include_directories(deps/assimp/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/deps/assimp/include)


file(GLOB_RECURSE HEADERS_FILES
        ${PROJECT_SOURCE_DIR}/includes/*.hpp
        ${PROJECT_SOURCE_DIR}/includes/*.h
        ${PROJECT_SOURCE_DIR}/includes/*.inl

        )
file(GLOB_RECURSE SOURCES_FILES
        ${PROJECT_SOURCE_DIR}/includes/*.cpp
        ${PROJECT_SOURCE_DIR}/includes/*.c
        )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_COMPILE_PDB_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/compiled)
set(CMAKE_PDB_OUTPUT_DIRECTORY  ${CMAKE_SOURCE_DIR}/bin/pdb)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY   ${CMAKE_SOURCE_DIR}/bin/archive)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY    ${CMAKE_SOURCE_DIR}/bin/lib)



add_subdirectory(src)
add_subdirectory(tests)
#Optick::OptickCore
