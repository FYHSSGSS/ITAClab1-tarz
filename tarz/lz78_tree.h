//
// Created by FYHSSGSS on 2021/4/25.
//

#ifndef TARZ_LZ78_TREE_H
#define TARZ_LZ78_TREE_H

#include <bits/stdc++.h>

using namespace std;
typedef unsigned char UC;
typedef pair<int, int> PII;
#define X first
#define Y second
#define mem(a, b) memset(a, b, sizeof(a))

struct Item {
    int node[256];

    Item() { mem(node, 0); }
};

class lz78_tree {
private:
    int tot, cnt;
    vector<UC> V, w;
    vector<int> pa;
    vector<Item> ch;
public:
    vector<int> last;

    lz78_tree() {
        cnt = tot = 0;
        ch.clear();
        pa.clear();
        V.clear();
        last.clear();
        Item temp;
        ch.push_back(temp);
        w.push_back(0);
        pa.push_back(-1);
        last.push_back(0);
    }

    void insert(int &now, UC val, int i) {
        if (!ch[now].node[val]) {
            ch[now].node[val] = ++tot;
            Item temp;
            ch.push_back(temp);
            w.push_back(val);
            pa.push_back(now);
            last.push_back(i);
            cnt++;
            now = 0;
            return;
        }
        now = ch[now].node[val];
        return;
    }

    int getCnt() {
        return cnt;
    }

    int getSize() {
        return V.size();
    }

    void push(UC val) {
        V.push_back(val);
    }

    static int len(int val) {
        int res = 1;
        val >>= 8;
        while (val) {
            res++;
            val >>= 8;
        }
        return res;
    }

    void dfs(int &now, UC val, int i, FILE *fout) {
        int here = ch[now].node[val];
        if (last[here] == i) {
            int length = len(pa[here]);
            fwrite(&length, sizeof('t'), 1, fout);
            fwrite(&pa[here], sizeof('t') * length, 1, fout);
            fwrite(&val, sizeof(val), 1, fout);
            now = 0;
            return;
        }
        now = ch[now].node[val];
    }

    vector<UC> pushup(int now) {
        if (now == 0) {
            vector<UC> ret;
            ret.clear();
            return ret;
        }
        vector<UC> ret = pushup(pa[now]);
        ret.push_back(w[now]);
        return ret;
    }

    void writeinfo(FILE *fout) {
        int now = 0;
        for (int i = 0; i < V.size(); i++) {
            UC id = V[i];
            dfs(now, V[i], i, fout);
        }
        if (last[now] != V.size() - 1) {
            UC chr = 'l';
            int length = len(now);
            fwrite(&length, sizeof('t'), 1, fout);
            fwrite(&now, sizeof('t') * length, 1, fout);
            fwrite(&chr, sizeof('l'), 1, fout);
        }
        return;
    }
};


#endif //TARZ_LZ78_TREE_H
