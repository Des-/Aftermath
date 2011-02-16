# Tries to find libconfig++
# Defines:
#   libconfig++_FOUND - System has libconfig++
#   libconfig++_INCLUDE_DIR - The libconfig++ include directory
#   libconfig++_LIBRARY - The library required to use libconfig++

FIND_PATH(libconfig++_INCLUDE_DIR libconfig.h++)
FIND_LIBRARY(libconfig++_LIBRARY NAMES config++ libconfig++)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(libconfig++ DEFAULT_MSG
                                  libconfig++_LIBRARY
                                  libconfig++_INCLUDE_DIR)
MARK_AS_ADVANCED(libconfig++_INCLUDE libconfig++_LIBRARY)
