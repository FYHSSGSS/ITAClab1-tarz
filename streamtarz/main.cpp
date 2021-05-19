#include <iostream>
#include "huffman.h"
#include "lz78.h"

char target[110], destination[110];
int main(int argc, char const *argv[]) {
    std::cout << "Hello, World!" << std::endl;
    huffman::encode(1);
//    lz78::encode(1);
    return 0;
}
