cmake_minimum_required(VERSION 3.15)
project(streamtarz)

set(CMAKE_CXX_STANDARD 14)

set(BOOST_ROOT "/usr/local/include/boost")

include_directories(/usr/local/include)

add_executable(streamtarz main.cpp huffman.cpp huffman.h huffman_code.cpp huffman_code.h huffman_tree.cpp huffman_tree.h lz78.cpp lz78.h lz78_code.cpp lz78_code.h lz78_tree.cpp lz78_tree.h streamCLI.cpp)