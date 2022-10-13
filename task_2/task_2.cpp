// task_2.cpp : Копирование умных массивов.

#include "smart_array.h"
#include <iostream>

int main(int argc, char** argv)
{
    SmartArray arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);

    SmartArray new_array(2);
    new_array.add_element(44);
    new_array.add_element(34);

    arr = new_array;

    for (int i = 0; i < arr.getSize(); ++i)
        std::cout << arr.get_element(i) << " ";

    return 0;
}