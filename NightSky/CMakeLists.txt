cmake_minimum_required(VERSION 3.10)

project(NightSky)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/moh104/RaylibRepo.git
    GIT_TAG        master
)
FetchContent_MakeAvailable(raylib)
include_directories("${CMAKE_BINARY_DIR}/_deps/raylib-src/include")
link_directories("${CMAKE_BINARY_DIR}/_deps/raylib-src/lib")

add_executable(app 
    main.cpp 
    sky.cpp 
    star.cpp
)

include_directories("raylib/include")
link_directories("raylib/lib")

target_link_libraries(app raylib opengl32 gdi32 winmm)