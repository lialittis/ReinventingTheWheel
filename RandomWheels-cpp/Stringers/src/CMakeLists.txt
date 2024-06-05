file(GLOB SRC_FILES "*.cpp")

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(main_lib ${SRC_FILES})

add_executable(main_exec ${SRC_FILES})

target_link_libraries(main_exec main_lib)
