//
// Created by 石成 on 2020/1/3.
//

#ifndef DATASTRUCTURE_LIST_H
#define DATASTRUCTURE_LIST_H

namespace cheng{
    template <typename T>
    // 单向链表
    class list{
    public:
        class node{
        public:
            explicit node(T val)
            {
                data = val;
                next = nullptr;
            };
            node* next;
            T data;

        };
        list(){
            _head = new node(-1);
            _size = 0;
        };
        // 返回链表中数据元素的个数
        unsigned int size();
        // 若链表为空则返回一个布尔值 true
        bool empty();
        // 返回第 n 个元素的值（从0开始计算）
        T value_at(unsigned int index);
        // 添加元素到链表的首部
        void push_front(T value);
        // 删除首部元素并返回其值
        void pop_front();
        // 添加元素到链表的尾部
        void push_back(T value);
        // 删除尾部元素并返回其值
        void pop_back();
        // 返回首部元素的值
        T front();
        // 返回尾部元素的值
        T back();
        // 插入值到指定的索引，并把当前索引的元素指向到新的元素
        void insert(unsigned int index, T value);
        // 删除指定索引的节点
        void erase(unsigned int index);
        // 返回倒数第 n 个节点的值
        T value_n_from_end(unsigned int n);
        // 逆序链表
        void reverse();
        // 删除链表中指定值的第一个元素
        void remove_value(T value);

    private:
        node* _head;
        unsigned int _size;

    };

    template <typename T>
    unsigned int list<T>::size() {
        return _size;
    }

    template <typename T>
    bool list<T>::empty() {
        return _size == 0;
    }

    template <typename T>
    T list<T>::value_at(unsigned int index){
        assert(index < _size);
        node* cur = _head;
        for (unsigned int i = 0; i < index+1; ++i)
            cur = cur->next;
        return cur->data;
    }

    template <typename T>
    void list<T>::push_front(T value){
        node* next = _head->next;
        _head->next = new node(value);
        _head->next->next = next;
        _size++;
    }

    template <typename T>
    void list<T>::pop_front(){
        node* temp = _head->next;
        _head->next = _head->next->next;
        delete temp;
        _size--;
    }

    template <typename T>
    void list<T>::push_back(T value){
        node* cur = _head;
        while (cur->next)
        {
            cur = cur->next;
        }
        cur->next = new node(value);
        _size++;
    }

    template <typename T>
    void list<T>::pop_back(){
        node* cur = _head;
        while (cur->next && cur->next->next)
        {
            cur = cur->next;
        }
        node* temp = cur->next;
        cur->next = nullptr;
        delete temp;
        _size--;
    }

    template <typename T>
    T list<T>::front(){
        assert(_size >= 1);
        return _head->next->data;
    }

    template <typename T>
    T list<T>::back(){
        assert(_size >= 1);
        node* cur = _head;
        while (cur->next)
        {
            cur = cur->next;
        }
        return cur->data;

    }

    template <typename T>
    void list<T>::insert(unsigned int index, T value){
        node* cur = _head;
        for (unsigned int i = 0; i < index; ++i)
        {
            cur = cur->next;
        }
        node* next = cur->next;
        cur->next = new node(value);
        cur->next->next = next;
        _size++;
    }

    template <typename T>
    void list<T>::erase(unsigned int index){
        assert(index < _size);
        node* cur = _head;
        for (unsigned int i = 0; i < index; ++i)
        {
            cur = cur->next;
        }
        node* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        _size--;
    }

    template <typename T>
    T list<T>::value_n_from_end(unsigned int n){
        assert(n <= _size);
        node* slow = _head;
        node* fast = _head;
        for (int i = 0; i < n; ++i)
            fast = fast->next;
        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow->data;
    }

    template <typename T>
    void list<T>::reverse(){
        node* pre = nullptr;
        node* cur = _head->next;
        while (cur)
        {
            node* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        _head->next = pre;
    }

    template <typename T>
    void list<T>::remove_value(T value){
        node* cur = _head;
        while (cur->next && cur->next->data != value)
        {
            cur = cur->next;
        }
        if (cur->next == nullptr)
            return;
        node* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        _size--;
    }
}


#endif //DATASTRUCTURE_LIST_H
