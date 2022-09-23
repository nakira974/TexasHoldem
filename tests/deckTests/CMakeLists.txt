cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME deck_tests)
project(${PROJECT_NAME} CXX C)

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



# Now simply link against gtest or gtest_main as needed. Eg
add_executable(${PROJECT_NAME} ${SOURCES_FILES} ${HEADERS_FILES})
target_link_libraries(${PROJECT_NAME} gtest_main glfw easy_profiler)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})