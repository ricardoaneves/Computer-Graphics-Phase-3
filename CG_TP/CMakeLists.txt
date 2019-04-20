cmake_minimum_required(VERSION 3.9)

# Project Name
PROJECT(cg_tp)

set(CMAKE_CXX_STANDARD 11)

if (NOT APPLE)
    if (WIN32)
        set(GLEW_ROOT_FOLDER "" CACHE PATH "Path to GLEW folder")
        include_directories(${GLEW_ROOT_FOLDER})
        link_directories(${GLEW_ROOT_FOLDER})
    else(WIN32)
        find_package(GLEW REQUIRED)
        include_directories(${GLEW_INCLUDE_DIRS})
        link_libraries(${GLEW_LIBRARIES})
    endif(WIN32)
endif(NOT APPLE)

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})

if(NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)

find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/headers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/tinyxml2)

add_executable(${PROJECT_NAME} main.cpp parser.cpp extractor.cpp tinyxml2/tinyxml2.cpp)
add_executable(generator generator.cpp)

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
