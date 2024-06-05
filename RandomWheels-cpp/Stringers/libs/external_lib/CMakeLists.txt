file(GLOB EXTERNAL_LIB_SRC_FILES "src/*.cpp")

include_directories(${PROJECT_SOURCE_DIR}/libs/external_lib/include)

add_library(external_lib STATIC ${EXTERNAL_LIB_SRC_FILES})
