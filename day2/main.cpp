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
    char del = ' ';

    while(std::getline(inputFile, line))
    {
        std::vector<int> number;
        size_t pos = line.find(" ");

        while(pos != std::string::npos)
        {
            std::string sub = line.substr(line.find(" "));
            int num = atoi(line.substr(0, pos).c_str());
            number.push_back(num);
        }
        while()
        {
            
        }
    }
}