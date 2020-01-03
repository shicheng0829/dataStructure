#include <iostream>
#include "array.h"
#include "list.h"

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


    return 0;
}
