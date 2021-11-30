#include <iostream>
#include "chapter2.h"
extern const int bufSIze = 10;

void fun_decltype()
{
    std::cout << "--- fun_decltype --" << std::endl;
    const int ci = 12, &cj = ci;
    decltype(ci) x = 13;
    decltype(cj) y = x;
    // decltype(cj) z;
    std::cout << "ci: " << ci << " y " << y << std::endl;
}

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

    int i = 0, &r = i;
    auto a = r;
    const int ci = i, &cr = ci;

    auto &g = ci;
    // auto &n = i,*p2 = &ci;
    std::cout << "ci: " << ci << " cr " << cr << std::endl;

    fun_decltype();
}
