//
// Created by 石成 on 2020/1/3.
//

#ifndef DATASTRUCTURE_HEAP_H
#define DATASTRUCTURE_HEAP_H

#include <vector>
#include <algorithm>

namespace cheng{
    //大顶堆
    template <typename T>
    class heap{
    public:
        heap(){
            // 第一位留空
            _data = std::vector<T>(1, 0);
        }
        // 构造堆
        explicit heap(std::vector<T> vec);
        void insert(T val);
        void del_max();
        T get_max();
        void print();
        bool empty();
        unsigned int size();
    private:
        std::vector<T> _data;
        void swim(unsigned int k);
        void sink(unsigned int k);
    };

    template <typename T>
    heap<T>::heap(std::vector<T> vec){
        _data = std::vector<T>(vec.size()+1, 0);
        for (unsigned int i = 0; i < vec.size(); ++i)
            _data[i+1] = vec[i];
        for (unsigned int i = vec.size() / 2; i >= 1; --i)
            sink(i);
    }

    template <typename T>
    void heap<T>::swim(unsigned int k){
        while (k != 1)
        {
            if (_data[k] > _data[k/2])
            {
                std::swap(_data[k], _data[k/2]);
                k = k / 2;
            }
            else
            {
                break;
            }
        }
    }

    template <typename T>
    void heap<T>::insert(T val){
        _data.push_back(val);
        swim(_data.size()-1);
    }

    template <typename T>
    void heap<T>::sink(unsigned int k){
        while (k * 2 < _data.size())
        {
            int j = k * 2;
            if (j + 1 < _data.size() && _data[j] < _data[j+1])
                ++j;
            if (_data[k] < _data[j])
            {
                std::swap(_data[j], _data[k]);
                k = j;
            }
            else
                break;
        }

    }

    template <typename T>
    void heap<T>::del_max() {
        int n = _data.size();
        std::swap(_data[1], _data[n-1]);
        _data.pop_back();
        sink(1);
    }

    template <typename T>
    T heap<T>::get_max(){
        return _data[1];
    }

    template <typename T>
    void heap<T>::print() {
        for (int i = 0; i < _data.size(); ++i)
            std::cout << _data[i] << " ";
        std::cout << std::endl;
    }

    template <typename T>
    bool heap<T>::empty(){
        return _data.size() == 1;
    }

    template <typename T>
    unsigned int heap<T>::size(){
        return _data.size() - 1;
    }


}

#endif //DATASTRUCTURE_HEAP_H
