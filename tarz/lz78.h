//
// Created by FYHSSGSS on 2021/4/25.
//

#ifndef TARZ_LZ78_H
#define TARZ_LZ78_H
#include <bits/stdc++.h>
#include "huffman.h"
#include "lz78_code.h"

class lz78 {
private:

public:
    static void encode(char* target, char* destination, int mode) {
        if(!huffman::FileCheck(target, destination)) {
            return;
        }
        FILE *fin = fopen(target, "rb");
        FILE *fout = fopen(destination, "wb");
        if (mode == 1) {
            while (!lz78_code::encode(fin, fout, 1 << 20))puts("```waiting```");
        }
        else lz78_code::decode(fin, fout);
        fseek(fout, 0, SEEK_END);
        size_t final_size = ftell(fout);
        std::cout << "The file size is "<< final_size << "bytes\n" << std:: endl;
        fclose(fin);
        fclose(fout);
    }

};


#endif //TARZ_LZ78_H
