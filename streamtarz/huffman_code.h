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
    static bool encode(int block) {
        huffman_tree T;
        bool end = false;
        for (int i = 0; i < block; i++) {
            UC temp;
            if(fread(&temp, sizeof(temp), 1, stdin) == NULL) {
                end = true;
                if (i == 0)return end;
                break;
            }
            T.addfreq(temp);
            T.push(temp);
        }
        T.Build();
        T.GenHead();
        T.writeinfo();
        return end;
    }
    static void decode() {
        int read_bits = 0, char_num = 0;
        UC tmp;
        while(fread(&read_bits, sizeof(read_bits), 1, stdin) != NULL) {
            huffman_tree T;
            fread(&tmp, sizeof(tmp), 1, stdin);
            char_num = (int)tmp;
//            printf("bits %d %d\n",read_bits, char_num);
            for (int i = 0; i <= char_num; i++) {
                UC chr;
                int times;
                fread(&chr, sizeof(chr), 1, stdin);
                fread(&times, sizeof(times), 1, stdin);
//                std::cout << (int)chr << ' ' << times << std::endl;
                T.setfreq(chr, times);
            }
            T.Build();
            int cnt = 0, buf = 0;
            while(fread(&buf, sizeof('t'), 1, stdin) != NULL) {
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
                    T.output();
                    break;
                }
            }
        }
    }
};


#endif //TARZ_HUFFMAN_CODE_H
