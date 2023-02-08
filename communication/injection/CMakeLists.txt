add_subdirectory(locator)
add_library( mac_injection STATIC injection_mac.cpp)
target_include_directories(mac_injection PUBLIC .)
target_link_libraries( mac_injection PUBLIC communication_interface osal)