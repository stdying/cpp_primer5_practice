#include "chapter6.h"
#include <iostream>
#include <string>
#include <cctype>

void print_chapter6()
{
    std::cout << "=== chapter6 ===" << std::endl;
}

void fun1(int i)
{
    std::cout << "=== fun1 ===" << std::endl;
}

const std::string &shorterString(const std::string &s1, const std::string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}

std::string &shorterString(std::string &s1, std::string &s2){
    return s1.size() <= s2.size() ? s1 : s2;
}