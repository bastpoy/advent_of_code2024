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

bool get_do_dont(std::string input, size_t pos)
{
    std::string sub = input.substr(0, pos);
    size_t posDo = sub.rfind("do()");
    size_t posDont = sub.rfind("don't()");

    // std::cout << pos << " pos do: "<< posDo << " posdont: " << posDont << std::endl;
    if(posDo == std::string::npos && posDont == std::string::npos)
    {
        std::cout << "no pos found " << pos << std::endl;
        return (true);
    }
    if(posDo == std::string::npos)
        return (false);
    if (posDont == std::string::npos)
        return (true);
    if (posDo > posDont)
        return (true);
    return(false);
}

std::string readFile(std::string filePath)
{
    std::ifstream inputFile(filePath.c_str(), std::ios::binary);

    std::stringstream buffer;
    buffer << inputFile.rdbuf(); //gets all content of the file and puts it into buffer;
    return (buffer.str());
}


int main(void)
{
    std::string sub = readFile("input");
    int first = 0;
    int second = 0;
    int total = 0;

    size_t pos = sub.find("mul(");
    size_t posSum = 0;
    std::string input = sub;
    while(pos != std::string::npos)
    {
        //get after the mul(
        sub = sub.substr(pos + 4);
        posSum += pos + 4;
        //get the pos of the coma
        size_t coma = sub.find(",");
        //get the first number
        if (coma != std::string::npos && get_do_dont(input, posSum))
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
    std::cout << "total: " << total << std::endl;
    return(0);
}
