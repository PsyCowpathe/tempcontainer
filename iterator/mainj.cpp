#include "random_access_iterator.hpp"
#include <vector>

int     main(void)
{
    std::vector<int>    vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);

    ft::random_access_iterator<int>     test;

    test = vec.begin();
}