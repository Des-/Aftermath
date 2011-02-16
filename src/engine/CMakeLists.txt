# LOCATION:    ${SRC_DIR}/src/engine/
# DESTINATION: ${BIN_DIR}/bin/

# Glob source files
FILE(GLOB ENGINE_SRCS *.cpp)
FILE(GLOB ENGINE_HDRS *.hpp)

# Compile engine
ADD_LIBRARY(${ENGINE_LIB} ${ENGINE_SRCS} ${ENGINE_HDRS})
