cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME TexasHoldem_Tests)
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

include_directories(${CMAKE_SOURCE_DIR}/deps/glm)
include_directories(${CMAKE_SOURCE_DIR}/deps/stb)
include_directories(${CMAKE_SOURCE_DIR}/includes)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_subdirectory(deckTests)





