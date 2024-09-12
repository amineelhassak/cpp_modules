#include "PmergeMe.hpp"

static void merge(const deque<pair<int,int> >& left, const deque<pair<int, int> >& right, deque<pair<int, int> >& result) {
    deque<pair<int, int> >::const_iterator it_left = left.begin();
    deque<pair<int,int> >::const_iterator it_right = right.begin();

    while (it_left != left.end() && it_right != right.end()) {
        if (it_left->first <= it_right->first) {
            result.push_back(*it_left);
            ++it_left;
        } else {
            result.push_back(*it_right);
            ++it_right;
        }
    }

    while (it_left != left.end()) {
        result.push_back(*it_left);
        ++it_left;
    }

    while (it_right != right.end()) {
        result.push_back(*it_right);
        ++it_right;
    }
}

static void insertionSort(deque<int>& sorted, int value) {
    if (value == -1)
        return ;
    deque<int>::iterator pos = lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(pos, value);
}

static void sortPair(deque<pair<int,int> > &data)
{
    if (data.size() < 2) return;

    deque<pair<int,int> > left, right;
    size_t mid = data.size() / 2;

    for (size_t i = 0; i < mid; ++i) {
        left.push_back(data[i]);
    }

    for (size_t i = mid; i < data.size(); ++i) {
        right.push_back(data[i]);
    }

    sortPair(left);
    sortPair(right);

    deque<pair<int, int> > merged;
    merge(left, right, merged);
    data = merged;
}

int SuitJacobsthal(int n) {
    int return_value = (pow(2, n) - pow(-1, n)) / 3;
    if (return_value > 30000)
        return (-1);
    return (return_value);
}

static void    generatSequenceJacobsthal(deque<int> &SequenceJacobsthal,int size)
{
    int value;
    int check = 0;

    for (int i = 0; i < size; i++)
    {
        value = SuitJacobsthal(i);
        if (value == -1)
            break;
        if (value > size)
            check++;
        if (check == 2)
            break;
        SequenceJacobsthal.push_back(value);
    }
}

void    generatIndexSequencess(deque<int> &generatIndexSequences,deque<int> sequenceJacobsthal,int size)
{
    if ((int)sequenceJacobsthal.size() < 3)
        return ;
    deque<int>::iterator it = sequenceJacobsthal.begin();
    deque<int>::iterator it2;
    it += 2;
    int a , b;
    for (; it != sequenceJacobsthal.end(); it++)
    {
        if (it + 1 != sequenceJacobsthal.end())
        {
            generatIndexSequences.push_back(*(it + 1));
            a = *(it);
            b = *(it + 1) - 1;
            if (a > size || b > size)
                break ;
            for (;a < b; b--) 
            {
                generatIndexSequences.push_back(b);
            }
        }
    }
}

void run(int argc, char** argv,int n) {
    deque<int> sequenceJacobsthal;
    deque<int> generatIndexSequences;
    deque<pair<int,int> > dqpair;
    pair<int,int> pair;
    deque<int> util;
    deque<int> vec;
    deque<int> res;
    string str;
    int save = -1;
    int size;
    int a, b;
    (void)n;
    int iplus = (argc  == 2 ) ? 1 : 2;
    
    for (int i = 1; i < argc; i += iplus)
    {
        if (argv[i])
        {
            stringstream ss1(argv[i]);
            if (!(ss1 >> a) || a <= 0 || !(checkNumber(argv[i])))
            {
                str = argv[i];
                throw std::runtime_error("bad input " + str);
            }
        }
        if (i + 1 < argc) {
            stringstream ss2(argv[i + 1]);
            if (!(ss2 >> b) || b <= 0 || !(checkNumber(argv[i + 1])))
            {
                str = argv[i];
                throw std::runtime_error("bad input " + str);
            }
            pair = make_pair(max(a, b), min(a, b));
            dqpair.push_back(pair);
        }
        else
            save = a;
    }
    sortPair(dqpair);
    for (deque<std::pair<int,int> >::iterator it = dqpair.begin(); it != dqpair.end(); it++)
    {
        res.push_back(it->first);
        util.push_back(it->second);
    }
    if (util.begin() != util.end()){
        res.insert(res.begin(), *util.begin());
        util.erase(util.begin());}
    
    size = util.size();
    if (size <= 3)
    {
        for (deque<int>::iterator it = util.begin(); it != util.end(); it++)
           insertionSort(res, *it);
    }
    else
    {
        generatSequenceJacobsthal(sequenceJacobsthal,argc - 1);
        generatIndexSequencess(generatIndexSequences, sequenceJacobsthal,argc - 1);
        for (deque<int>::iterator j = generatIndexSequences.begin() ; j != generatIndexSequences.end();j++)
        {
            if (*(j) - 1 < (int)util.size())
                insertionSort(res,util[*(j) - 1]);
        }
        if (util.size()  &&  util[0])
            insertionSort(res,util[0]);
    }
    (save != -1) && (insertionSort(res, save), 0);
    std::cout <<"After:   ";
    for(int i = 0; i < (int)(res.size()); i++) cout << res[i] << " ";
        cout << endl;
}
