set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCES
        main.cpp
        Map.cpp
        Person.cpp
        Specimens.cpp
        Inventory.cpp
        Inventory.h
        Specimens.h
        Person.h
        Map.h
        Random.cpp
        Random.h
        )

add_executable(${CMAKE_PROJECT_NAME}_run ${SOURCES})

add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES})
