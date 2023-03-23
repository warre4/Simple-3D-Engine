
cmake_minimum_required (VERSION 3.8)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

project(Simple-3D-Engine VERSION 0.0.1 LANGUAGES C)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED_ON)

#file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
#file(GLOB_RECURSE INCLUDE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

add_subdirectory(extern/freeglut)

add_executable(Simple-3D-Engine
#           ${SRC_FILES}
#           ${INCLUDE_FILES}

            "src/main.c"
            "src/general.c"
            "src/color.c"

            "include/general.h"
            "include/color.h"
            "include/vectors.h"
             )

target_include_directories(Simple-3D-Engine
               PUBLIC
               ${CMAKE_CURRENT_SOURCE_DIR}/include/
               ${CMAKE_CURRENT_SOURCE_DIR}/extern/freeglut/include
               )

target_link_libraries(Simple-3D-Engine freeglut_static)