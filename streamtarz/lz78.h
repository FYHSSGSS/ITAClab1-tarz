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
    static void encode(int mode) {

        if (mode == 1) {
            while (!lz78_code::encode((1 << 10) * 36));
        }
        else lz78_code::decode();
        return;
    }

};


#endif //TARZ_LZ78_H
