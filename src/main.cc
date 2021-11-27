#include <iostream>
#include "file_1.h"

int main(int, char **)
{
    std::cout << "Hello, world!\n";

    int a = 10;
    int a2 = 20;
    int &b = a;
    b = a2;

    std::cout << a << std::endl;

    fun_print();
}
