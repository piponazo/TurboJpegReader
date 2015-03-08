project(jpegturbo-demo)
cmake_minimum_required(VERSION 2.8)

include(cmake_stuff/options.cmake               REQUIRED)
include(cmake_stuff/findDependencies.cmake      REQUIRED)
include(cmake_stuff/compileroptions.cmake       REQUIRED)
include(cmake_stuff/buildFiles.cmake            REQUIRED)

add_executable(jpeg_dec app_jpeg_api.c)
add_executable(turbo_dec app_jpegturbo_api.c)

target_link_libraries(jpeg_dec ${JPEG_LIB})
target_link_libraries(turbo_dec ${JPEG_TURBO_LIB})

include(cmake_stuff/printInfo.cmake             REQUIRED)
