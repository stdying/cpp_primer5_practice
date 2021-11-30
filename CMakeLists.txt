cmake_minimum_required(VERSION 3.0.0)
project(cpp_practice VERSION 0.1.0)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -fexec-charset=GBK")

include(CTest)
enable_testing()

#添加子目录
add_subdirectory(src/chapter2)

#添加子目录
add_subdirectory(src/chapter3)

# 查找当前目录下的所有源文件并存入DIR_SRCS变量 
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src DIR_SRCS)

# 创建可执行程序
add_executable(cpp_practice ${DIR_SRCS})

target_link_libraries(cpp_practice chapter2 chapter3)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

message(">>>config : DIR_SRCS=${DIR_SRCS} SOURCE_CPP=${SOURCE_CPP} DIR_INC=${DIR_INC}")