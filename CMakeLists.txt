cmake_minimum_required(VERSION 3.12)

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
#set(Optick_DIR deps/optick/cmake-build-debug)

add_subdirectory(deps/glfw)
add_subdirectory(deps/easy_sources)

include_directories(deps/glm)
include_directories(deps/stb)




file(GLOB_RECURSE HEADERS_FILES
        ${PROJECT_SOURCE_DIR}/src/*.hpp
        ${PROJECT_SOURCE_DIR}/src/*.h
        ${PROJECT_SOURCE_DIR}/src/*.inl
        ${PROJECT_SOURCE_DIR}/includes/*.hpp
        ${PROJECT_SOURCE_DIR}/includes/*.h
        ${PROJECT_SOURCE_DIR}/includes/*.inl
        )
file(GLOB_RECURSE SOURCES_FILES
        ${PROJECT_SOURCE_DIR}/src/*.cpp
        ${PROJECT_SOURCE_DIR}/src/*.c
        )
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME} ${SOURCES_FILES} ${HEADERS_FILES})
target_link_libraries(${PROJECT_NAME} glfw easy_profiler)#Optick::OptickCore
