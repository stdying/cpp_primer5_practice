#include <iostream>
#include "file_1.h"
extern const int bufSIze = 10;

void fun_print()
{
    double dval = 3.3;
    const int &ri = dval;
    dval = 4.4;

    const double pi = 3.14;
    const double pi2 = 3.14;
    const double *const cptr = &pi;

    std::cout << "bufSize: " << bufSIze << " ri:" << ri << " dval:" << dval << std::endl;
    std::cout << "cptr " << *cptr << std::endl;
}