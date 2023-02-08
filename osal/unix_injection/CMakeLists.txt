add_library(unix_queue INTERFACE )
target_include_directories(unix_queue INTERFACE .)
target_link_libraries( unix_queue INTERFACE osal)