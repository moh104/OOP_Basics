cmake_minimum_required(VERSION 3.10)

project(Calendar)

set(SOURCES
    main.cpp
    calendar.cpp
    event.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(app ${SOURCES})