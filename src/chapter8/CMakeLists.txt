project(chapter8)
# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
# aux_source_directory(. DIR_LIB_SRCS)

include_directories(../chapter7)
# 生成链接库
add_library(chapter8  "chapter8.h" "chapter8.cc")

target_link_libraries(chapter8 chapter7)