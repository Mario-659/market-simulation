set(BINARY ${CMAKE_PROJECT_NAME}_tst)

include_directories(${PROJECT_SOURCE_DIR}/src)

set(TEST_SOURCES
        main.cpp
        Map-test.cpp
        )

add_executable(${CMAKE_PROJECT_NAME}_tst ${TEST_SOURCES})

add_test(NAME ${CMAKE_PROJECT_NAME}_tst COMMAND ${CMAKE_PROJECT_NAME}_tst)

target_link_libraries(${CMAKE_PROJECT_NAME}_tst PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)

