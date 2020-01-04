#include <iostream>
#include "array.h"
#include "list.h"
#include "heap.h"
#include "queue.h"

void print_arr(cheng::array<int> arr)
{
    for (unsigned int i = 0; i < arr.size(); ++i)
    {
        std::cout << arr.at(i) << " ";
    }
    std::cout << std::endl;
}

void print_lst(cheng::list<int> lst)
{
    for (unsigned int i = 0; i < lst.size(); ++i)
    {
        std::cout << lst.value_at(i) << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // array test
    std::cout << "start array test" << std::endl;
    cheng::array<int> arr;
    // [0, 1, 2, 3, 4] size = 5, capacity = 8
    for (int i = 0; i < 5; ++i)
    {
        arr.push(i);
    }
    print_arr(arr);
    std::cout << "size:" << arr.size() << " " << "capacity:" << arr.capacity() << std::endl;
    // [0, 1, 2, 3, 4, 5, 6, 7, 8] size = 9, capacity = 16
    for (int i = 5; i < 9; ++i)
    {
        arr.push(i);
    }
    print_arr(arr);
    std::cout << "size:" << arr.size() << " " << "capacity:" << arr.capacity() << std::endl;
    // [10, 0, 1, 2, 3, 4, 5, 6, 7, 8] size = 10, capacity = 16
    arr.insert(0, 10);
    print_arr(arr);
    std::cout << "size:" << arr.size() << " " << "capacity:" << arr.capacity() << std::endl;

    // [10, 0, 1, 2, 3, 4, 5, 6, 7] size = 9, capacity = 16
    arr.pop();
    print_arr(arr);
    std::cout << "size:" << arr.size() << " " << "capacity:" << arr.capacity() << std::endl;

    // [10, 0, 2, 3, 4, 5, 6, 7] size = 8, capacity = 16
    arr.my_delete(2);
    print_arr(arr);
    std::cout << "size:" << arr.size() << " " << "capacity:" << arr.capacity() << std::endl;

    // [10, 0] size = 2, capacity = 4;
    for (int i = 0 ; i < 6; ++i)
        arr.pop();
    print_arr(arr);
    std::cout << "size:" << arr.size() << " " << "capacity:" << arr.capacity() << std::endl;

    std::cout << "finish array test"<< std::endl;

    std::cout << "start list test"<< std::endl;
    // list test
    cheng::list<int> lst;

    // head->0->1->2->3->4 size = 5
    for (int i = 0 ; i < 5; ++i)
        lst.push_back(i);
    print_lst(lst);
    std::cout << "size: "<< lst.size() << std::endl;

    // head->1->2->3->4 size = 4
    lst.pop_front();
    print_lst(lst);
    std::cout << "size: "<< lst.size() << std::endl;
    std::cout << "front: "<< lst.front() << " back:" << lst.back() << std::endl;

    // head->10->1->2->3->4 size = 5
    lst.push_front(10);
    print_lst(lst);
    std::cout << "size: "<< lst.size() << std::endl;

    // head->10->1->2->3 size = 4
    lst.pop_back();
    print_lst(lst);
    std::cout << "size: "<< lst.size() << std::endl;

    // head->10->1->5->2->3 size = 5
    lst.insert(2, 5);
    print_lst(lst);
    std::cout << "size: "<< lst.size() << std::endl;

    // head->10->1->2->3 size = 4
    lst.erase(2);
    print_lst(lst);
    std::cout << "size: "<< lst.size() << std::endl;


    // head->3->2->1->10 size = 4
    lst.reverse();
    print_lst(lst);
    std::cout << "size: "<< lst.size() << std::endl;


    lst.remove_value(2);
    print_lst(lst);
    std::cout << "size: "<< lst.size() << std::endl;

    std::cout << lst.value_n_from_end(2) << std::endl;

    std::cout << "start heap test" << std::endl;
    std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cheng::heap<int> hp(vec);
//    for (int i = 0; i < 10; ++i)
//        hp.insert(i);
    std::cout << hp.get_max() << std::endl;
    hp.print();
    hp.del_max();
    std::cout << hp.get_max() << std::endl;
    hp.print();

    std::cout << "start list_queue test" << std::endl;
    cheng::list_queue<int> lst_q;
    for (int i = 0; i < 5; ++i)
        lst_q.enqueue(i);
    lst_q.print();
    std::cout << lst_q.dequeue() << std::endl;
    lst_q.print();

    std::cout << "start arr_queue test" << std::endl;
    cheng::arr_queue<int> arr_q;
    for (int i = 0; i < 5; ++i)
        arr_q.enqueue(i);
    arr_q.print();
    for (int i = 0; i < 5; ++i)
    {
        std::cout << arr_q.dequeue() << std::endl;
        arr_q.print();
    }

    return 0;
}
