# Tries to find XRandR
# Defines:
#   XRandR_FOUND - System has XRandR
#   XRandR_INCLUDE_DIR - The XRandR include directory
#   XRandR_LIBRARY - The library required to use XRandR

FIND_PATH(XRandR_INCLUDE_DIR X11/extensions/Xrandr.h)
FIND_LIBRARY(XRandR_LIBRARY NAMES XRandR libXRandR
                                  Xrandr libXrandr
                                  xrandr libxrandr)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(XRandR DEFAULT_MSG
                                  XRandR_LIBRARY
                                  XRandR_INCLUDE_DIR)
MARK_AS_ADVANCED(XRandR_INCLUDE XRandR_LIBRARY)
