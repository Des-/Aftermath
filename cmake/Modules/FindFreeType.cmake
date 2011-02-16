# Tries to find FreeType
# Defines:
#   FreeType_FOUND - System has FreeType
#   FreeType_INCLUDE_DIR - The FreeType include directory
#   FreeType_LIBRARY - The library required to use FreeType

FIND_PATH(FreeType_INCLUDE_DIR freetype2/freetype/freetype.h)
FIND_LIBRARY(FreeType_LIBRARY NAMES freetype libfreetype)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(FreeType DEFAULT_MSG
                                  FreeType_LIBRARY
                                  FreeType_INCLUDE_DIR)
MARK_AS_ADVANCED(FreeType_INCLUDE FreeType_LIBRARY)
