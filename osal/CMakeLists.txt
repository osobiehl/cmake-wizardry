add_subdirectory(rtos)

add_library(osal INTERFACE )
target_include_directories(osal INTERFACE interfaces)
add_subdirectory(unix_injection)
