cmake_minimum_required(VERSION 3.24)
project(gen_cpp)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include)
find_package(fmt CONFIG REQUIRED)

#add_library(NumInfo STATIC NumInfo.cpp)

set(MAIN_SRC NumInfo.cpp CodeGenerator.cpp)

add_executable(${PROJECT_NAME} main.cpp ${MAIN_SRC})
#target_link_libraries(${PROJECT_NAME} PUBLIC NumInfo)

target_link_libraries(${PROJECT_NAME}  PRIVATE fmt::fmt)

#add_executable(outhhh ${PROJECT_BINARY_DIR}/hhh.cpp)

#add_dependencies(outhhh ${PROJECT_NAME})


#-------------------------test-------------------------

enable_testing()
find_package(GTest CONFIG REQUIRED)
include(GoogleTest)


aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/test/test_NumInfo TEST_NUMINFO_SRC)
add_executable(${PROJECT_NAME}_NumInfo_test ${TEST_NUMINFO_SRC} NumInfo.cpp)
target_link_libraries(${PROJECT_NAME}_NumInfo_test PRIVATE GTest::gtest GTest::gtest_main)
#target_link_libraries(${PROJECT_NAME}_NumInfo_test PRIVATE NumInfo)
gtest_discover_tests(${PROJECT_NAME}_NumInfo_test)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/test/test_CodeGen TEST_CODEGEN_SRC)
add_executable(${PROJECT_NAME}_CodeGen_test ${TEST_CODEGEN_SRC} ${MAIN_SRC})
target_link_libraries(${PROJECT_NAME}_CodeGen_test PRIVATE GTest::gtest GTest::gtest_main)
target_link_libraries(${PROJECT_NAME}_CodeGen_test PRIVATE fmt::fmt)
gtest_discover_tests(${PROJECT_NAME}_CodeGen_test)
