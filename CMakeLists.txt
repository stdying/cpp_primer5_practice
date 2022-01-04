cmake_minimum_required(VERSION 3.0.0)
project(cpp_primer5_practice VERSION 0.1.0)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -fexec-charset=GBK")

include(CTest)
enable_testing()

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")
# set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /W4")

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    MESSAGE("Clang")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    MESSAGE("gun")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
    MESSAGE("Intel")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    MESSAGE("MSVC")
endif()

# 告警设置
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /W4")
endif()

# # 告警设置
# if ( CMAKE_COMPILER_IS_GNUCC )
#     set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")
# endif()
# if ( MSVC )
#     set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /W4")
# endif()


#添加子目录
add_subdirectory(src/chapter2)

#添加子目录
add_subdirectory(src/chapter3)
add_subdirectory(src/chapter6)

# 查找当前目录下的所有源文件并存入DIR_SRCS变量 
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src DIR_SRCS)

# 创建可执行程序
add_executable(cpp_primer5_practice ${DIR_SRCS})

target_link_libraries(cpp_primer5_practice chapter2 chapter3 chapter6)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

message(">>>config : DIR_SRCS=${DIR_SRCS} SOURCE_CPP=${SOURCE_CPP} DIR_INC=${DIR_INC}")