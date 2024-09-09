#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <utility>
#include <stdexcept>
#include <algorithm>

bool checkNumber(std::string const &token)
{
    for(std::string::const_iterator it = token.begin(); it != token.end(); ++it)
    {
        if (!isdigit(*it))
            return false;
    }
    return true;
}

void merge(std::deque<int>& left, std::deque<int>& right, std::deque<int>& result)
{
    while (!left.empty() && !right.empty())
    {
        if (left.front() <= right.front())
        {
            result.push_back(left.front());
            left.pop_front();
        }
        else
        {
            result.push_back(right.front());
            right.pop_front();
        }
    }

    while (!left.empty())
    {
        result.push_back(left.front());
        left.pop_front();
    }

    while (!right.empty())
    {
        result.push_back(right.front());
        right.pop_front();
    }
    // std::cout << "=========================\n";
    // for(std::deque<int>::iterator it = result.begin(); it != result.end();it++)
    // {
    //     std::cout << *it << std::endl;
    // }
}

void sort(std::deque<int>& data)
{
    if (data.size() < 2)
        return;

    std::deque<int> left, right;
    size_t mid = data.size() / 2;
    for (size_t i = 0; i < mid; ++i)
        left.push_back(data[i]);

    for (size_t i = mid; i < data.size(); ++i)
        right.push_back(data[i]);
    sort(left);
    sort(right);
    std::deque<int> merged;
    merge(left, right, merged);
    data = merged;
}

void sortMergeInsert(int argc, char **argv)
{
    std::pair<int, int> pair;
    std::vector<std::pair<int, int> > vectpair;
    std::deque<int> dr_left;
    std::deque<int> dr_right;
    long save = 2147483648;
    (void)save;
    std::string str;

    for (int i = 1; i < argc; i += 2) {
        int a, b;
        std::stringstream ss1(argv[i]);
        if (!(ss1 >> a) || a <= 0 || !(checkNumber(argv[i])))
        {
            str = argv[i];
            throw std::runtime_error("bad input " + str);
        }
        if (i + 1 < argc) {
            std::stringstream ss2(argv[i + 1]);
            if (!(ss2 >> b) || b <= 0 || !(checkNumber(argv[i + 1])))
            {
                str = argv[i];
                throw std::runtime_error("bad input " + str);
            }
            pair = std::make_pair(std::max(a, b), std::min(a, b));
            vectpair.push_back(pair);
        }
        else
        {
            save = a;
        }
    }
    for (std::vector<std::pair<int, int> >::iterator it = vectpair.begin(); it != vectpair.end(); ++it)
        (1) && (dr_left.push_back(it->first), dr_right.push_back(it->second), 0);
    sort(dr_left);
    sort(dr_right);
    std::deque<int> sorted;
    merge(dr_left, dr_right, sorted);
    for(std::deque<int>::iterator it = sorted.begin(); it != sorted.end();it++)
    {
        std::cout << *it << std::endl;
    }
}

int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        std::cout << "Erreur : Pas assez d'arguments." << std::endl;
        return 1;
    }
    try
    {
        sortMergeInsert(argc, argv);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}

// int main()
// {
// testMerge
//     std::deque<int> dequel;
//     std::deque<int> dequer;
//     std::deque<int> result;
//     dequel.push_back(1);
//     dequel.push_back(-1);
//     dequel.push_back(10);
//     dequer.push_back(2);
//     dequer.push_back(3);
//     dequer.push_back(-100);
//     merge(dequel, dequer,result);
// }