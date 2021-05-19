//
// Created by FYHSSGSS on 2021/4/25.
//

#ifndef TARZ_LZ78_CODE_H
#define TARZ_LZ78_CODE_H

#include <bits/stdc++.h>
#include "lz78_tree.h"

typedef unsigned char UC;
using namespace std;


class lz78_code {
private:

public:
    static bool encode(FILE *fin, FILE *fout, int block) {
        lz78_tree T;
        bool end = false;
        int pos = 0;
        for (int i = 0; i < block; i++) {
            UC temp;
            if (fread(&temp, sizeof(temp), 1, fin) == NULL) {
                end = true;
                if (i == 0)return end;
                break;
            }
            T.insert(pos, temp, i);
            T.push(temp);
        }
        unsigned int cnt = T.getCnt();
        if (T.last[pos] != T.getSize() - 1) {
            cnt++;
            cnt |= 1 << 31;
        }
        fwrite(&cnt, sizeof(cnt), 1, fout);
        T.writeinfo(fout);
        return end;
    }

    static bool decode(FILE *fin, FILE *fout) {
        int read_bits = 0, char_num = 0;
        UC chr;
        while (fread(&read_bits, sizeof(read_bits), 1, fin) != NULL) {
            lz78_tree T;
            bool flag = 0;
            if (read_bits < 0) flag = 1, read_bits = read_bits ^ (1 << 31);
            int up = flag ? read_bits - 1 : read_bits, now = 0;
            for (int i = 0; i < read_bits; i++) {
                int endpoint = 0, temp = 0, len = 0;
                fread(&len, sizeof('t'), 1, fin);
                fread(&endpoint, len, 1, fin);
                if (len == 1)endpoint %= 256;
                else if (len == 2)endpoint %= 65536;
                temp = endpoint;
                fread(&chr, sizeof('t'), 1, fin);
                T.insert(temp, chr, i);
                vector<UC> buf = T.pushup(endpoint);
                if (i != read_bits - 1 || !flag)buf.push_back(chr);
                for (int j = 0; j < buf.size(); j++) fwrite(&buf[j], sizeof(buf[j]), 1, fout);
            }
        }
        return 0;
    }
};


#endif //TARZ_LZ78_CODE_H
