# Tries to find GLEW
# Defines:
#   GLEW_FOUND - System has GLEW
#   GLEW_INCLUDE_DIR - The GLEW include directory
#   GLEW_LIBRARY - The library required to use GLEW

FIND_PATH(GLEW_INCLUDE_DIR GL/glew.h)
FIND_LIBRARY(GLEW_LIBRARY NAMES GLEW libGLEW)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GLEW DEFAULT_MSG
                                  GLEW_LIBRARY
                                  GLEW_INCLUDE_DIR)
MARK_AS_ADVANCED(GLEW_INCLUDE GLEW_LIBRARY)
