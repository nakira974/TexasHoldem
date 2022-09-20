cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME TexasHoldem)
project(${PROJECT_NAME} CXX C)
option(BUILD_WITH_OPTICK "Enable Optick usage" ON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if(WIN32)
    set(PYTHON_EXECUTABLE "python")
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
else()
    set(PYTHON_EXECUTABLE "python3")
endif()

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "")
set(GLFW_INSTALL OFF CACHE BOOL "")
set(Optick_DIR deps/optick/cmake-build-debug)

add_subdirectory(deps/glfw)

if(BUILD_WITH_OPTICK)
    message("Enabled Optick")
    add_definitions(-DBUILD_WITH_OPTICK=1)
else()
    message("Disabled Optick")
endif()

if(BUILD_WITH_OPTICK)
    add_subdirectory(deps/optick)
    message("Optick has been correctly included")
else()
    message("Optick could not be included into ${PROJECT_NAME}")
endif()
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
target_link_libraries(${PROJECT_NAME} glfw OptickCore)#Optick::OptickCore
