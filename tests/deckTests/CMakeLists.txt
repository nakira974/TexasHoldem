cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME deck_tests)
set(TEST_NAME "Deck tests")
project(${PROJECT_NAME} CXX C)

file(GLOB_RECURSE HEADERS_FILES
        src/*.hpp
        src/*.h
        src/*.inl
        ${PROJECT_SOURCE_DIR}/includes/*.hpp
        ${PROJECT_SOURCE_DIR}/includes/*.h
        ${PROJECT_SOURCE_DIR}/includes/*.inl
        )
file(GLOB_RECURSE SOURCES_FILES
        src/*.cpp
        src/*.c
        )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME})
set(CMAKE_COMPILE_PDB_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME}/compiled)
set(CMAKE_PDB_OUTPUT_DIRECTORY  ${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME}/pdb)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY   ${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME}/archive)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY    ${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME}/lib)


# Now simply link against gtest or gtest_main as needed. Eg
add_executable(${PROJECT_NAME} ${SOURCES_FILES} ${HEADERS_FILES})
target_link_libraries(${PROJECT_NAME} gtest_main glfw easy_profiler crossguid)
add_test(NAME ${TEST_NAME} COMMAND ${PROJECT_NAME})