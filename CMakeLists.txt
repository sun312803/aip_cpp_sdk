cmake_minimum_required(VERSION 3.4)
project(aip_cpp_sdk)

set(CMAKE_CXX_STANDARD 14)
##   设置编译选项

SET(CMAKE_C_COMPILER /usr/bin/gcc)
SET(CMAKE_CXX_COMPILER /usr/bin/g++)
##指定
include_directories(base)
include_directories(include)

#find_package()


set (LIB_DIR /usr/lib/x86_64-linux-gnu)
add_definitions( -lcurl -lcrypto -ljsoncpp)
##   添加依赖库
##   链接依赖库
##   添加源文件
add_executable(aip_cpp_sdk  src/demo.cpp)

target_link_libraries(aip_cpp_sdk   ${LIB_DIR}/libcrypto.so  ${LIB_DIR}/libjsoncpp.so  ${LIB_DIR}/libcurl.so  )