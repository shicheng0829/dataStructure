//
// Created by 石成 on 2020/1/4.
//

#include "union_find.h"
namespace cheng{
    union_find::union_find(unsigned int N){
        _id = std::vector<int>(N, 0);
        for (unsigned int i = 0; i < N; ++i)
            _id[i] = i;
        _size = N;
    }
    void union_find::connect(int p, int q) {
        _id[p] = q;
        _size--;
    }

    bool union_find::connected(int p, int q) {
        return find(p) == find(q);
    }

    unsigned int union_find::count() {
        return _size;
    }

    unsigned int union_find::find(int p){
        int root = p;
        while(_id[root] != root)
        {
            root = _id[root];
        }
        // 路径压缩
        while(p != root)
        {
            int next = _id[p];
            _id[p] = root;
            p = next;
        }
        return root;
    }
}