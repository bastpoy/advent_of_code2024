#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <cstdlib>

static inline bool is_not_alnum_space(char c)
{
    return !(isdigit(c));
}

bool string_is_valid(const std::string &str)
{
    return find_if(str.begin(), str.end(), is_not_alnum_space) == str.end();
}


int main(void)
{
    std::ifstream inputFile("input", std::ios::binary);
    std::string line;
    std::string sub;
    int first = 0;
    int second = 0;
    int total = 0;

    while(std::getline(inputFile, line))
    {
        sub = line;
        size_t pos = line.find("mul(");

        while(pos != std::string::npos)
        {
            //get after the mul(
            sub = sub.substr(pos + 4);
            //get the pos of the coma
            size_t coma = sub.find(",");
            //get the first number
            if (coma != std::string::npos)
            {
                std::string number = sub.substr(0, coma);
                // std::cout << number << " ";
                if(string_is_valid(number))
                {
                    first = atoi(number.c_str());
                    //get the second number
                    pos = sub.substr(coma + 1).find(")");
                    if(pos != std::string::npos)
                    {
                        number = sub.substr(coma + 1, pos);
                        if(string_is_valid(number))
                        {
                            second = atoi(number.c_str());
                            std::cout << first << " " << second << std::endl;
                            total += first * second;
                        }
                        // std::cout << number << std::endl;
                    }
                }
            }
            pos = sub.find("mul(");
        }
    }
    std::cout << "total: " << total << std::endl;
    return(0);
}