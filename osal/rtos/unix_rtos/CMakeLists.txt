add_library(rtos_lib INTERFACE )
target_include_directories(rtos_lib INTERFACE .)
target_link_libraries( rtos_lib INTERFACE osal)