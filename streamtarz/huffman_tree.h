//
// Created by FYHSSGSS on 2021/4/23.
//

#ifndef TARZ_HUFFMAN_TREE_H
#define TARZ_HUFFMAN_TREE_H

#include <bits/stdc++.h>

using namespace std;
typedef unsigned char UC;
typedef pair<int, int> PII;
#define X first
#define Y second
const int maxn = 512 + 10;
#define mem(a, b) memset(a, b, sizeof(a))

class huffman_tree {

private:
    int freq[maxn], node[maxn], l[maxn], r[maxn], Path[maxn], deep[maxn], tot, cnt;
    UC chr[maxn];
    vector <pair<UC, UC> > codelist;
    vector <UC> V;
    vector <int> pre_code[maxn];
    queue <bool> buffer;
    priority_queue<PII, vector<PII>, greater<PII> > Q;

public:
    huffman_tree() {
        tot = cnt = 0;
        codelist.clear();
        V.clear();
        while(!Q.empty())Q.pop();
        while(!buffer.empty())buffer.pop();
        mem(freq, 0);
        mem(node, 0);
        mem(l, 0);
        mem(r, 0);
        mem(Path, 0);
        mem(deep, 0);
    }
    ~huffman_tree() {
    }
    void print() {
        cout << "tot:" << tot << endl;
        for (int i = 0; i < V.size(); i++) cout << (int)V[i] << endl;
        for (int i = 0; i < 256; i++)
            if (freq[i]) {
                printf("%d %d\n",i, freq[i]);
            }
        for (int i = 0; i < codelist.size(); i++)
            cout<<"code  "<<(int)codelist[i].X << ' ' << (int)codelist[i].Y << endl;
        cout << endl;
    }
    void addfreq(int pos) {
        freq[pos]++;
    };

    void bufpush(bool val) {
        buffer.push(val);
    }
    void push(UC val) {
        V.push_back(val);
    }

    void setfreq(UC pos, int addv) {
        freq[pos] = addv;
    }
    void dfs(int now, int path, int depth) {
        deep[now] = depth;
        if (l[now] != -1)dfs(l[now], path << 1, depth + 1);
        if (r[now] != -1)dfs(r[now], path << 1 | 1, depth + 1);
        if (l[now] == r[now] && l[now] == -1) Path[now] = path;
        return;
    }

    void Build() {
        for (int i = 0; i < 256; i++)
            if (freq[i]) {
                node[i] = tot;
                l[tot] = r[tot] = -1;
                chr[tot] = (UC)i;
                Q.push(make_pair(freq[i], (UC) tot));
                cnt++;tot++;
            }
        while (Q.size() > 1) {
            PII a = Q.top();
            Q.pop();
            PII b = Q.top();
            Q.pop();
            l[tot] = a.second;
            r[tot] = b.second;
            PII c = make_pair(a.first + b.first, tot);
            tot++;
            Q.push(c);
        }
        dfs(tot - 1, 0, 0);
        for (int i = 0; i < 256; i++) {
            if (freq[i]) {
                int id = node[i], temp = Path[id];
                while (temp) {
                    pre_code[id].push_back(temp & 1);
                    temp >>= 1;
                }
                while (pre_code[id].size() < deep[id])pre_code[id].push_back(0);
                reverse(pre_code[id].begin(), pre_code[id].end());
            }
        }
        for (int i = 0; i < 256; i++)
            if (freq[i])
                codelist.push_back(make_pair((UC) i, (UC)Path[node[i]]));
        return;
    }

    void GenHead() {
        while (! buffer.empty()) buffer.pop();
        for (int i = 0; i < V.size(); i++) {
            int id = node[V[i]];
            for (int j = 0; j < pre_code[id].size(); j++)
                buffer.push(pre_code[id][j]);
        }
        int len = buffer.size(), temp = cnt - 1;
        fwrite(&len, sizeof(len), 1, stdout);
        fwrite(&(temp), sizeof('t'), 1, stdout);
        for (int i = 0; i < 256; i++)
            if (freq[i]) {
                UC t = i;
                fwrite(&t, sizeof('t'), 1, stdout);
                fwrite(&freq[i], sizeof(freq[i]), 1, stdout);
            }
        return;
    }

    void writeinfo() {
        int bit = 0, res = 0;
        while (!buffer.empty()) {
            res = res|(buffer.front()<<bit);
            buffer.pop();
            bit++;
            if(bit == 8) {
                bit = 0;
                fwrite(&res, 1, 1, stdout);
                res=0;
            }
        }
        if(bit)
            fwrite(&res, 1, 1, stdout);
        return;
    }

    void output() {
        int now = tot - 1;
        while(!buffer.empty()) {
            bool val = buffer.front();
            buffer.pop();
            if(val) now = r[now];
            else now = l[now];
            if(l[now] == r[now] && l[now] == -1) {
                fwrite(&chr[now], sizeof('t'), 1, stdout);
                now = tot - 1;
            }
        }
    }
};


#endif //TARZ_HUFFMAN_TREE_H
