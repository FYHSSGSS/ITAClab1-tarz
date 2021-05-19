//
// Created by FYHSSGSS on 2021/4/23.
//

#ifndef TARZ_HUFFMAN_CODE_H
#define TARZ_HUFFMAN_CODE_H
#include <bits/stdc++.h>
#include "huffman_tree.h"
typedef unsigned char UC;

class huffman_code {
public:
    static bool encode(FILE* fin, FILE* fout, int block) {
        huffman_tree T;
        bool end = false;
        for (int i = 0; i < block; i++) {
            UC temp;
            if(fread(&temp, sizeof(temp), 1, fin) == NULL) {
                end = true;
                if (i == 0)return end;
                break;
            }
            T.addfreq(temp);
            T.push(temp);
        }
        T.Build();
        T.GenHead(fout);
        T.writeinfo(fout);
        return end;
    }
    static void decode(FILE *fin, FILE *fout) {
        int read_bits = 0, char_num = 0;
        UC tmp;
        while(fread(&read_bits, sizeof(read_bits), 1, fin) != NULL) {
            huffman_tree T;
            fread(&tmp, sizeof(tmp), 1, fin);
            char_num = (int)tmp;
            for (int i = 0; i <= char_num; i++) {
                UC chr;
                int times;
                fread(&chr, sizeof(chr), 1, fin);
                fread(&times, sizeof(times), 1, fin);
                T.setfreq(chr, times);
            }
            T.Build();
            int cnt = 0, buf = 0;
            while(fread(&buf, sizeof('t'), 1, fin) != NULL) {
                bool flag = 0;
                for(int i = 0; i < 8; i++) {
                    int val = buf & 1;
                    buf >>= 1;
                    cnt++;
                    T.bufpush(val);
                    if (cnt >= read_bits) {
                        flag = 1;
                        break;
                    }
                }
                if (flag) {
                    T.output(fout);
                    break;
                }
            }
        }
    }
};


#endif //TARZ_HUFFMAN_CODE_H
