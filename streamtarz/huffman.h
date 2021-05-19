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
    static void encode(int mode) {
        if (mode == 1) {
            while (!huffman_code::encode((1 << 10) * 36));
        }
        else huffman_code::decode();
    }

};


#endif //TARZ_HUFFMAN_H
