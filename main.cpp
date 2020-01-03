#include <iostream>
#include "array.h"

void print_arr(cheng::array<int> arr)
{
    for (unsigned int i = 0; i < arr.size(); ++i)
    {
        std::cout << arr.at(i) << " ";
    }
    std::cout << std::endl;
}

int main()
{
    cheng::array<int> arr(5);
    for (int i = 0; i < 5; ++i)
    {
        arr.push(i);
    }
    print_arr(arr);
    for (int i = 5; i < 9; ++i)
    {
        arr.push(i);
    }
    print_arr(arr);
    arr.insert(0, 10);
    print_arr(arr);
    arr.pop();
    print_arr(arr);
    arr.my_delete(2);
    print_arr(arr);
    std::cout << arr.capacity() << std::endl;
    for (int i = 0 ; i < 6; ++i)
        arr.pop();
    print_arr(arr);
    std::cout << arr.capacity() << std::endl;
    return 0;
}
