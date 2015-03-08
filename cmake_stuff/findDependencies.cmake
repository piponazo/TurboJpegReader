find_library(JPEG_TURBO_LIB turbojpeg
    PATHS /opt/libjpeg-turbo /usr/lib/x86_64-linux-gnu
    PATH_SUFFIXES lib64 lib
)

find_library(JPEG_LIB jpeg
    PATHS /opt/libjpeg-turbo /usr/lib/x86_64-linux-gnu
    PATH_SUFFIXES lib64 lib
)

if (NOT JPEG_TURBO_LIB)
    message(FATAL_ERROR "Jpeg turbo library not found!")
endif()

find_path(JPEG_TURBO_INCLUDE_DIR
  NAMES turbojpeg.h
  PATHS /opt/libjpeg-turbo/include
)
