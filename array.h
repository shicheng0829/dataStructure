//
// Created by 石成 on 2020/1/1.
//

#ifndef DATASTRUCTURE_ARRAY_H
#define DATASTRUCTURE_ARRAY_H

namespace cheng{
    template <typename T>
    class array
    {
    public:
        array();
        explicit array(unsigned int n);
        unsigned int size();
        unsigned int capacity();
        bool is_empty();
        T& at(unsigned int index);
        void push(T item);
        void insert(unsigned int index, T item);
        void prepend(T item);
        void pop();
        void my_delete(unsigned int index);
        unsigned int remove(T item);
        unsigned int find(T item);

    private:
        void _resize(unsigned int new_capacity);
        T* _data;
        unsigned int _size;
        unsigned int _capacity;
    };
    template <typename T>
    array<T>::array()
    {
        _data = nullptr;
        _size = 0;
        _capacity = 0;
    }
    template <typename T>
    array<T>::array(unsigned int n)
    {
        _data = new T[n];
        _size = 0;
        _capacity = n;
    }

    template <typename T>
    unsigned int array<T>::size()
    {
        return _size;
    }

    template <typename T>
    unsigned int array<T>::capacity()
    {
        return _capacity;
    }

    template <typename T>
    bool array<T>::is_empty()
    {
        return _size == 0;
    }

    template <typename T>
    void array<T>::_resize(unsigned int new_capacity)
    {
        assert(new_capacity >= _size);
        T* temp = new T[new_capacity];
        _capacity = new_capacity;
        for (unsigned int i = 0; i < _size; ++i)
            temp[i] = _data[i];
        delete [] _data;
        _data = temp;
    }

    template <typename T>
    T& array<T>::at(unsigned int index)
    {
        if (index >= _size)
            throw "index is larger than size of array!";
        return _data[index];
    }

    template <typename T>
    void array<T>::push(T item)
    {
        if (_size == _capacity)
            _resize(2 * _capacity);
        _data[_size++] = item;
    }

    template <typename T>
    void array<T>::insert(unsigned int index, T item)
    {
        if (_size == _capacity)
            _resize(2 * _capacity);
        ++_size;
        for (unsigned int i = _size; i > index; --i)
        {
            _data[i] = _data[i-1];
        }
        _data[index] = item;
    }

    template <typename T>
    void array<T>::prepend(T item)
    {
        insert(0, item);
    }

    template <typename T>
    void array<T>::pop()
    {
        --_size;
        if (_size == _capacity / 4)
            _resize(_capacity/2);
    }

    template <typename T>
    void array<T>::my_delete(unsigned int index)
    {
        for (unsigned int i = index; i < _size-1; ++i)
        {
            _data[i] = _data[i+1];
        }
        --_size;
        if (_size == _capacity / 4)
            _resize(_capacity/2);
    }

    template <typename T>
    unsigned int array<T>::remove(T item)
    {
        for (unsigned int i = 0; i < _size; ++i)
        {
            if (_data[i] == item)
            {
                my_delete(i);
                return i;
            }
        }
        return -1;
    }

    template <typename T>
    unsigned int array<T>::find(T item)
    {
        for (unsigned int i = 0; i < _size; ++i)
        {
            if (_data[i] == item)
            {
                return i;
            }
        }
        return -1;
    }

}


#endif //DATASTRUCTURE_ARRAY_H
