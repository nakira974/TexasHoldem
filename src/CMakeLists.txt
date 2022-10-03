project(${PROJECT_NAME} CXX C)

file(GLOB_RECURSE HEADERS_FILES
        ./*.hpp
        ./*.h
        ./*.inl
        )
file(GLOB_RECURSE SOURCES_FILES
        ./*.cpp
        ./*.c
        )

add_executable(${PROJECT_NAME} ${SOURCES_FILES} ${HEADERS_FILES} ${INCLUDES_FILES})
target_link_libraries(${PROJECT_NAME} glfw easy_profiler crossguid)
