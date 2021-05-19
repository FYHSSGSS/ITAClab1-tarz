cmake_minimum_required(VERSION 3.15)
project(tarz)

set(CMAKE_CXX_STANDARD 14)

set(BOOST_ROOT "/usr/local/include/boost")

include_directories(/usr/local/include)

link_directories(/usr/local/lib)

#用于将当前目录下的所有源文件的名字保存在变量 DIR_SRCS 中
aux_source_directory(. DIR_SRCS)

add_executable(demo ${DIR_SRCS} CLI.cpp)

#在这里根据名字boost_thread去寻找libboost_thread.a文件
target_link_libraries(demo boost_thread boost_system)

add_executable(tarz main.cpp huffman.cpp huffman.h huffman_code.cpp huffman_code.h huffman_tree.cpp huffman_tree.h lz78.cpp lz78.h lz78_code.cpp lz78_code.h lz78_tree.cpp lz78_tree.h)