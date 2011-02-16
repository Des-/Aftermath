# Tries to find libjpeg
# Defines:
#   libjpeg_FOUND - System has libjpeg
#   libjpeg_INCLUDE_DIR - The libjpeg include directory
#   libjpeg_LIBRARY - The library required to use libjpeg

FIND_PATH(libjpeg_INCLUDE_DIR jpeglib.h)
FIND_LIBRARY(libjpeg_LIBRARY NAMES jpeg libjpeg)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(libjpeg DEFAULT_MSG
                                  libjpeg_LIBRARY
                                  libjpeg_INCLUDE_DIR)
MARK_AS_ADVANCED(libjpeg_INCLUDE libjpeg_LIBRARY)
