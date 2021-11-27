#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

void find(std::vector<std::string> worlds)
{
    int sz = 0;
    std::find_if(worlds.begin(), worlds.end(), [sz](const std::string &a)
                 { return a.size() >= sz; });
}

// int main()
// {
//     int sz = 2;
//     std::vector<std::string> worlds = {"1", "22", "333"};
//     auto wc = std::find_if(worlds.begin(), worlds.end(), [sz](const std::string &a)
//                            { return a.size() >= sz; });
//     auto count = worlds.end() - wc;
//     std::cout << "count:"<<count << std::endl;
// }