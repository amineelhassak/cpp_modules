#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <deque>

bool check(std::string it)
{
    return (it > "Ajxcine");
}

void vectorFun()
{
    std::vector<int>vect;

    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(3);
    vect.resize(2);
    vect.shrink_to_fit();
    vect.insert(vect.begin(),0);
    vect.insert(vect.end(),4);
    // vect.erase(vect.begin(),vect.end());
    // vect.emplace(vect.begin(),-1);
    // vect.emplace_back(vect.begin(),5);
    vect.pop_back();
    std::cout << "capacity is " << vect.capacity() << std::endl;
    for (size_t i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] << std::endl;
    }
    // std::vector<int>vect(100);
    for (std::vector<int>::iterator it = vect.begin();it != vect.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << "=======================" << std::endl;
    for (std::vector<int>::reverse_iterator it = vect.rbegin();it != vect.rend(); it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << "=======================" << std::endl;
    for (std::vector<int>::const_iterator it = vect.cbegin();it != vect.cend(); it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << "=======================" << std::endl;
    for (/*std::vector<int>::const_reverse_iterator*/ auto it = vect.crbegin();it != vect.crend(); it++)
    {
        std::cout << *it << std::endl;
    }
}

void funTest()
{
    std::vector<std::string> vect;
    vect.push_back("Alice");
    vect.push_back("bob");
    vect.push_back("Charlie");
    vect.push_back("David");
    vect.push_back("Eve");
    for (auto it = vect.begin() ;it != vect.end();it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << "===========================" << std::endl;
    vect.push_back("frank");
    for (auto it = vect.begin() ;it != vect.end();it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << "===========================" << std::endl;
    vect.pop_back();
    vect.erase(vect.end() - 1);
    for (auto it = vect.begin() ;it != vect.end();it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << "=================sort==========" << std::endl;;
    std::sort(vect.begin(), vect.end());
    for (auto it = vect.begin() ;it != vect.end();it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << "=================find==========" << std::endl;;
    auto it = std::find(vect.begin(),vect.end(),"David");
    if (it != vect.end())
        std::cout << "is found " << *it << std::endl;
    
    try
    {
        std::cout << "============ min elment ===============" << std::endl;
        std::cout << "size is " << vect.size()<< std::endl;
        auto minmax_elemt = minmax_element(vect.begin(),vect.end());
        std::cout << "min element is "<< *minmax_elemt.first << std::endl;
        std::cout << "min element is "<< *minmax_elemt.second << std::endl;
        auto min_elemt  = min_element(vect.begin(),vect.end());
        auto max_elemt = max_element(vect.begin(),vect.end());
        auto min = std::min(vect.begin(),vect.end());
        auto max = std::max(vect.begin(),vect.end());
        std::cout << "min element is "<< *min << std::endl;
        std::cout << "max element is "<< *max << std::endl;
        std::cout << "min_elem element is "<< *min_elemt << std::endl;
        std::cout << "max_elem element is "<< *max_elemt << std::endl;
        std::cout << "============ find_if ===============" << std::endl;
        for (auto it = std::find_if(vect.begin(), vect.end(), check);it != vect.end(); it++)
        {
            std::cout << *it << std::endl;
        }
        
        std::cout << "============ vide  ===============" << std::endl;

        vect.resize(0);
        vect.empty();
        vect.shrink_to_fit();
        for (auto it = vect.begin() ;it != vect.end();it++)
        {
            std::cout << *it << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "============ copy  ===============" << std::endl;
    std::vector<int>array = {0,1,2,3,4,5};
    std::vector<int>vect_copy(10);
    std::copy(array.begin(), array.end(),vect_copy.begin());
    for (auto it = vect_copy.begin() ;it != vect_copy.end();it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << "============ display by copy  ===============" << std::endl;
    std::copy(vect_copy.begin(), vect_copy.end(),std::ostream_iterator<int>(std::cout ," "));
}

void funDecK()
{
    std::deque<char> deck;
    deck.push_back('a');
    deck.push_front('b');
    std::deque<char>::iterator it = deck.begin();
    for (; it != deck.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    
}
int main()
{
    // vectorFun();
    // funTest();
    funDecK();
}

//  c++ -std=c++17 testContainer.cpp