set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCES
        main.cpp
        Map.cpp
        Person.cpp
        Inventory.cpp
        Inventory.h
        Person.h
        Map.h
        Shopkeeper.cpp
        Shopkeeper.h
        Customer.cpp
        Customer.h
        Thief.cpp
        Thief.h
        Guard.cpp
        Guard.h
        Random.cpp
        Random.h
        Simulation.cpp
        Simulation.h
        )

add_executable(${CMAKE_PROJECT_NAME}_run ${SOURCES})

add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES})
