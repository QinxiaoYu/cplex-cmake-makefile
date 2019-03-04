cmake_minimum_required(VERSION 3.13)
project(deterministic)

# folder for cmake files
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# using cplex lib
add_definitions(-DUSE_CPLEX)
find_package(CPLEX REQUIRED)
include_directories(${CPLEX_INCLUDE_DIRS})
set(LIBS ${LIBS} ${CPLEX_LIBRARIES})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -DNDEBUG -DIL_STD -pthread -Wl ${LINUX_CXX_FLAGS}")
set(CMAKE_CXX_STANDARD 14)

# project files
add_executable(<PROJECT_NAME> <CPP_FILENAMES> <HPP_FILENAMES>)

# link compiled cplex library
target_link_libraries(<PROJECT_NAME> ${CPLEX_LIBRARIES})
