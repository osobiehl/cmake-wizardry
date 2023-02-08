add_library( mac_linktime STATIC linktime_mac.cpp)
target_include_directories(mac_linktime PUBLIC .)
target_link_libraries( mac_linktime PUBLIC communication_interface osal rtos_lib)