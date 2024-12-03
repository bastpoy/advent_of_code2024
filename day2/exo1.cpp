#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <cstdlib>

bool check_gap(std::vector<int> &list)
{
    //test if two consecutives numbers are equal
    if(std::adjacent_find(list.begin(), list.end()) != list.end())
        return (false);
    //test for two consecutives numbers with a difference of more than three
    for (size_t i = 1; i < list.size(); ++i)
    {
        if (std::abs(list[i] - list[i - 1]) > 3)
            return (false);
    }
    return(true);
}

bool check_validity(std::vector<int> &list)
{
    if(!check_gap(list))
    {
        return (false);
    }
    //check if it is sort ascending
    else if(is_sorted(list.begin(), list.end()))
    {
        return (true);
    }
    // check if it is sort descending
    else
    {
        std::reverse(list.begin(), list.end());
        if(is_sorted(list.begin(), list.end()))
            return (true);
    }
    return (false);
}

void print_vector(std::vector<int> list)
{
    std::vector<int>::iterator it = list.begin();
    while(it != list.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}

int main(void)
{
    std::ifstream inputFile("input", std::ios::binary);
    std::string line;
    int total = 0;

    while(std::getline(inputFile, line))
    {
        std::vector<int> number = {};
        
        size_t pos = line.find(" ");
        std::string  sub = line;

        while(pos != std::string::npos)
        {

            int num = atoi(sub.substr(0, pos).c_str());
            number.push_back(num);

            // std::cout << num << "-";

            sub = sub.substr(pos + 1);
            pos = sub.find(" ");
            
            // last number
            if (pos == std::string::npos)
            {
                // num = atoi(sub.substr(0, pos).c_str());
                // std::cout << "-" << sub << "-" << std::endl;
                num = atoi(sub.c_str());
                number.push_back(num);
                if(check_validity(number))
                {
                    print_vector(number);
                    total++;
                }
                else
                {

                }
            }
        }
        // std::cout << std::endl;
    }
    std::cout << "total: " << total << std::endl;
}