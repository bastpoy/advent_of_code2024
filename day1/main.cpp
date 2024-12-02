#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <cstdlib>

int main(void)
{
    std::ifstream inputFile("input", std::ios::binary);

    std::string line;
    size_t total = 0;
    std::vector<int> column1;
    std::vector<int> column2;

    while(std::getline(inputFile, line))
    {
        column1.push_back(atoi(line.substr(0, line.find(" ")).c_str()));
        column2.push_back(atoi(line.substr(line.find(" ") + 3).c_str()));
    }
    std::sort(column1.begin(), column1.end());
    std::sort(column2.begin(), column2.end());  

    std::vector<int>::iterator it = column1.begin();
    // std::vector<int>::iterator it1 = column2.begin();
    while(it != column1.end())
    {
        int frequency = std::count(column2.begin(), column2.end(), *it);

        size_t res = *it * frequency;
        total += res;
        // std::cout << *it << " " << *it1 << std::endl;
        it++;
    }
    std::cout << total << std::endl;
}