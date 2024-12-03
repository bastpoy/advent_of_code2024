#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <cstdlib>

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

bool check_gap(std::vector<int> &list)
{
    std::vector<int>::iterator it = std::adjacent_find(list.begin(), list.end());
    if(it != list.end())
    {
            return(false);
    }
    for (size_t i = 1; i < list.size(); ++i)
    {
        if (std::abs(list[i] - list[i - 1]) > 3)
        {
            return(false);
        }
    }
    return(true);
}

bool check_sort_ascending(std::vector<int> list)
{
    for(size_t i = 1; i < list.size(); i++)
    {
        if(list[i] <= list[i - 1])
        {
            return (false);
        }
    }
    return(true);
}

bool check_sort_descending(std::vector<int> list)
{
    for(size_t i = 1; i < list.size(); i++)
    {
        if(list[i] >= list[i - 1])
        {
            return(false);
        }
    }
    return(true);
}

bool check_validity(std::vector<int> list)
{
    std::vector<int> original_list = list;

    if(!check_gap(list) || !check_sort_ascending(list) || !check_sort_descending(list))
    {
        // Try removing each level to see if it becomes valid
        for(size_t i = 0; i < original_list.size(); i++)
        {
            std::vector<int> test_list = original_list;
            test_list.erase(test_list.begin() + i);
            
            if(check_gap(test_list) &&
                (check_sort_ascending(test_list) || 
                check_sort_descending(test_list)))
            {
                return true;
            }
        }
        return false;
    }
    
    return true;
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
                num = atoi(sub.c_str());
                number.push_back(num);
                if(check_validity(number))
                {
                    total++;
                }
            }
        }
    }
    std::cout << "total: " << total << std::endl;
}