//
// Created by 石成 on 2020/1/3.
//

#ifndef DATASTRUCTURE_UNION_FIND_H
#define DATASTRUCTURE_UNION_FIND_H

#include <vector>

namespace cheng{
    class union_find{
    public:
        explicit union_find(unsigned int N);
        void connect(int p, int q);
        bool connected(int p, int q);
        unsigned int count();

    private:
        unsigned int find(int p);
        std::vector<int> _id;
        unsigned int _size;
    };
}
#endif //DATASTRUCTURE_UNION_FIND_H
