add_library(communication_locator_interface INTERFACE)
target_include_directories(communication_locator_interface INTERFACE include)


add_library(rtos_injection_lib STATIC rtos/locator.cpp)
target_link_libraries(rtos_injection_lib PUBLIC communication_locator_interface rtos_lib)
add_library(unix_injection_lib STATIC unix/locator.cpp)
target_link_libraries(unix_injection_lib PUBLIC communication_locator_interface unix_queue)

if(INJECT_SWITCH_BACKEND)
    target_link_libraries(communication_locator_interface INTERFACE osal unix_injection_lib )
else ()
    target_link_libraries(communication_locator_interface INTERFACE osal rtos_injection_lib)

endif(INJECT_SWITCH_BACKEND)




