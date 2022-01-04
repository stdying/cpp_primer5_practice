#ifndef CHAPTER_6
#define CHAPTER_6
#include <iostream>

void print_chapter6();

class Record
{
};

class Phone
{
};

Record lookup(Phone);
Record lookup(const Phone);

void fun1(int i);
void fun1(int i);

const std::string &shorterString(const std::string &s1, const std::string &s2);
std::string &shorterString(std::string &s1, std::string &s2);

#endif