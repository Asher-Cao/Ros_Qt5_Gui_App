macro(AddTest)
include(TargetNameHelper)
GetTargetName()
# 查找 GTest 库
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
file(GLOB_RECURSE SRC_FILE CONFIGURE_DEPENDS  ${CMAKE_SOURCE_DIR}  *_test.cpp *_test.cc)
# 添加可执行文件
add_executable(${TARGET_NAME} ${SRC_FILE})

# 链接 GTest 库
target_link_libraries(${TARGET_NAME} ${GTEST_BOTH_LIBRARIES})

# 添加测试
enable_testing()
add_test(NAME ${TARGET_NAME} COMMAND ${TARGET_NAME})

endmacro()