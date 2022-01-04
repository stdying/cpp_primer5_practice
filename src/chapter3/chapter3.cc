#include "chapter3.h"
#include <iostream>
#include <string>
#include <cctype>

void string_cin()
{
    std::cout << "--- string_cin ---" << std::endl;
    std::string cs;
    std::cin >> cs;
    std::cout << "cs " << cs;
    std::cout << "==";

    auto size = cs.size();
}

void fun_getline()
{
    std::string line;
    while (getline(std::cin, line))
    {
        std::cout << "输入内容: " << line;
    }
}

void fun_str_add()
{
    std::cout << "--- fun_str_add ---" << std::endl;
    std::string s1 = "hello ", s2 = "world\n";
    std::string s3 = s1 + s2;
    std::cout << "s3 :" << s3;
    std::cout << "--";
}

void fun_str_for()
{
    std::cout << "--- fun_str_for ---" << std::endl;
    std::string s1("hello world !!!");
    //
    decltype(s1.size()) punct = 0;
    for (auto c : s1)
    {
        if (ispunct(c))
        {
            ++punct;
        }
    }
    std::cout << "punct:" << punct << std::endl;

    for (auto &c : s1)
    {
        c = toupper(c);
    }
    std::cout << "toupper:" << s1 << std::endl;
}

void fun_str_index()
{
    std::cout << "--- fun_str_index ---" << std::endl;
    std::string s1{"some thing"};
    if (!s1.empty())
    {
        s1[0] = toupper(s1[0]);
    }
    std::cout << "index touper:" << s1 << std::endl;
}

void fun_str_index2()
{
    std::cout << "--- fun_str_index2 ---" << std::endl;
    std::string s1{"some thing"};
    for (decltype(s1.size()) index = 0; index != s1.size() && !isspace(s1[index]); ++index)
    {
        s1[index] = toupper(s1[index]);
    }
    std::cout << "index toupper:" << s1 << std::endl;
}

void fun_str_index3()
{
    std::cout << "--- fun_str_index3 ---" << std::endl;
    const std::string hexdigist = "0123456789ABCDEF";

    std::cout << "enter:" << std::endl;
    std::string result;
    std::string::size_type n;
    while (std::cin >> n)
    {
        if (n < hexdigist.size())
        {
            result = hexdigist[n];
            std::cout << "result: " << result << std::endl;
        }
    }
}

void print_chapter3(void)
{
    std::cout << "=== chapter3 ===" << std::endl;
    fun_str_index3();
    // string_cin();
    // fun_getline();
    // fun_str_add();
    // fun_str_for();
}