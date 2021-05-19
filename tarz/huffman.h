//
// Created by FYHSSGSS on 2021/4/23.
//

#ifndef TARZ_HUFFMAN_H
#define TARZ_HUFFMAN_H

#include <bits/stdc++.h>
#include "huffman_code.h"

class huffman {
private:

public:
    static int FileCheck(char* target, char* destination) {
        if(strcmp(target, destination) == 0) {
            printf("You can't decompress the file to replace itself.");
            return 0;
        }
        FILE *fin = fopen(target, "rb");
        if (fin == NULL) {
            printf("Can't open the file,Please check your file's directory is correct or not.");
            return 0;
        }
        FILE *fout = fopen(destination, "wb");
        if(fout == NULL) {
            printf("Can't write to this file.");
            return 0;
        }
        fseek(fin, 0, SEEK_END);
        size_t init_size = ftell(fin);
        std::cout << "The file size is "<< init_size << "bytes\n" << std:: endl;
        rewind(fin);
        fclose(fin);
        fclose(fout);
        return 1;
    }
    static void encode(char* target,char* destination, int mode) {
        if(!FileCheck(target, destination)) {
            return;
        }
        FILE *fin = fopen(target, "rb");
        FILE *fout = fopen(destination, "wb");
        if (mode == 1) {
            while (!huffman_code::encode(fin, fout, 1 << 20))puts("```waiting```");
        }
        else huffman_code::decode(fin, fout);
        fseek(fout, 0, SEEK_END);
        size_t final_size = ftell(fout);
        std::cout << "The output file is " << final_size << "bytes" <<std::endl;
        fclose(fin);
        fclose(fout);
    }

};


#endif //TARZ_HUFFMAN_H
