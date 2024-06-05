file(GLOB TEST_FILES "*.cpp")

include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(GTest REQUIRED)

add_executable(test_exec ${TEST_FILES})

target_link_libraries(test_exec main_lib GTest::GTest GTest::Main)
