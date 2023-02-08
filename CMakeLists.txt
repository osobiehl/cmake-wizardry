# Fix behavior of CMAKE_CXX_STANDARD when targeting macOS.
if (POLICY CMP0025)
cmake_policy(SET CMP0025 NEW)
endif ()


set(CMAKE_CXX_COMPILER g++)
set(CMAKE_C_COMPILER gcc)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



cmake_minimum_required(VERSION 3.23)
project(my_project)

add_subdirectory(osal)
add_subdirectory(communication)
FIND_PACKAGE( Boost 1.80 COMPONENTS thread REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )


add_library(simulation STATIC simulation.cpp)
target_link_libraries(simulation PUBLIC communication_interface)
target_include_directories(simulation PUBLIC .)
add_executable(main_linktime main_linktime.cpp)


# set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # does not produce the json file

TARGET_LINK_LIBRARIES( main_linktime LINK_PUBLIC 
osal 
rtos_lib 
communication_interface 
simulation 
mac_linktime)

add_executable(main_injection main_injection.cpp)
TARGET_LINK_LIBRARIES( main_injection PUBLIC 
osal  
communication_interface 
simulation 
mac_injection
communication_locator_interface
)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./bin")
