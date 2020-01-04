//
// Created by 石成 on 2020/1/3.
//

#ifndef DATASTRUCTURE_QUEUE_H
#define DATASTRUCTURE_QUEUE_H

#include <list>
#include <iostream>

namespace cheng{
    template <typename T>
    class list_queue{
    public:
        list_queue() = default;
        T dequeue();
        void enqueue(T val);
        bool empty();
        void print();
    private:
        std::list<T> lst;
    };

    template <typename T>
    void list_queue<T>::enqueue(T val) {
        lst.push_back(val);
    }

    template <typename T>
    T list_queue<T>::dequeue() {
        T temp = lst.front();
        lst.pop_front();
        return temp;
    }

    template <typename T>
    bool list_queue<T>::empty() {
        return lst.empty();
    }

    template <typename T>
    void list_queue<T>::print() {
        for (auto it = lst.begin(); it != lst.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
    }

    template <typename T>
    class arr_queue{
    public:
        arr_queue();
        T dequeue();
        void enqueue(T val);
        bool empty();
        void print();
    private:
        T* _data;
        unsigned int _first;
        unsigned int _last;
        unsigned int _size;
        unsigned int _capacity;
        void resize(unsigned int capacity);
    };

    template <typename T>
    arr_queue<T>::arr_queue(){
        _data = new T[1];
        _first = 0;
        _last = 0;
        _size = 0;
        _capacity = 1;
    }

    template <typename T>
    void arr_queue<T>::resize(unsigned int capacity){
        assert(capacity > _size);
        T* temp = new T[capacity];
        for (unsigned int i = 0; i < _size; ++i)
            temp[i] = _data[(_first+i)%_capacity];
        _first = 0;
        _last = _size;
        _capacity = capacity;
        delete [] _data;
        _data = temp;
    }

    template <typename T>
    void arr_queue<T>::enqueue(T val){
        if (_size == _capacity)
            resize(2*_capacity);
        _data[_last++] = val;
        if (_last == _capacity)
            _last = 0;
        ++_size;
    }

    template <typename T>
    T arr_queue<T>::dequeue() {
        assert(_size > 0);
        T val = _data[_first++];
        if (_first == _capacity)
            _first = 0;
        --_size;
        if (_size == _capacity / 4)
            resize(_capacity/2);
        return val;
    }

    template <typename T>
    bool arr_queue<T>::empty(){
        return _size == 0;
    }

    template <typename T>
    void arr_queue<T>::print() {
        for (unsigned int i = 0; i < _size; ++i)
            std::cout << _data[(_first+i)%_capacity] << " ";
        std::cout << std::endl;
    }




}

#endif //DATASTRUCTURE_QUEUE_H
