add_library(communication_interface INTERFACE )
target_include_directories(communication_interface INTERFACE include)
target_link_libraries( communication_interface INTERFACE osal)

add_subdirectory(linktime)
add_subdirectory(injection)




#TODO: 
