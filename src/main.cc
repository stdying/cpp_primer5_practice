#include <iostream>
#include "chapter2/chapter2.h"
#include "chapter3/chapter3.h"
#include "chapter6/chapter6.h"
#include "chapter7/chapter7.h"

int main()
{
    std::cout << "Hello, world!\n";

    int a = 10;
    int a2 = 20;
    int &b = a;
    b = a2;

    std::cout << a << std::endl;
    
    fun_print();
    // print_chapter3();
    fun1(1);
    
    invoke_chapter7();

}
