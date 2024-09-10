#include "PmergeMe.hpp"
#include <cmath>
// class PmergeMe
// {
// public:
//     static bool checkNumber(const string& token);
//     static void merge(const vector<int>& left, const vector<int>& right, vector<int>& result);
//     static void insertionSort(vector<int>& sorted, int value);
//     static void mergeInsertionSort(vector<int>& data);
//     static void printVector(const vector<int>& vec);
//     static void run(int argc, char** argv);
// };


bool checkNumber(const string& token) {
    string::const_iterator it = token.begin();
    while (it != token.end()) {
        if (!isdigit(*it)) {
            return false;
        }
        ++it;
    }
    return true;
}

void merge(const vector<pair<int,int> >& left, const vector<pair<int, int> >& right, vector<pair<int, int> >& result) {
    vector<pair<int, int> >::const_iterator it_left = left.begin();
    vector<pair<int,int> >::const_iterator it_right = right.begin();

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

void insertionSort(vector<int>& sorted, int value) {
    if (value == -1)
        return ;
    vector<int>::iterator pos = lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(pos, value);
}

void printVector(const vector<int>& vec) {
    vector<int>::const_iterator it = vec.begin();
    while (it != vec.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}


void sortPair(vector<pair<int,int> > &data)
{
    if (data.size() < 2) return;

    vector<pair<int,int> > left, right;
    size_t mid = data.size() / 2;

    for (size_t i = 0; i < mid; ++i) {
        left.push_back(data[i]);
    }

    for (size_t i = mid; i < data.size(); ++i) {
        right.push_back(data[i]);
    }

    sortPair(left);
    sortPair(right);

    vector<pair<int, int> > merged;
    merge(left, right, merged);
    data = merged;
}

int SuitJacobsthal(int n) {
    return (pow(2, n) - pow(-1, n)) / 3;
}

void    generatSequenceJacobsthal(vector<int> &SequenceJacobsthal,int size)
{
    for (int i = 0; i < size; i++)
    {

            // if (SuitJacobsthal(i) == -1)
            //     break;
            // std::cout << SuitJacobsthal(i) << std::endl;
        SequenceJacobsthal.push_back(SuitJacobsthal(i));   
    }
    (void )SequenceJacobsthal;
}

void    generatIndexSequencess(vector<int> &generatIndexSequences,vector<int> sequenceJacobsthal)
{
    if ((int)sequenceJacobsthal.size() < 3)
        return ;
    vector<int>::iterator it = sequenceJacobsthal.begin();
    vector<int>::iterator it2;
    it += 2;
    int a , b;
    for (; it != sequenceJacobsthal.end(); it++)
    {
        if (it + 1 != sequenceJacobsthal.end())
        {
            std::cout << *((it + 1)) << std::endl;
            generatIndexSequences.push_back(*(it + 1));
            a = *(it);
            b = *(it + 1) - 1;
            for (;a < b; b--) 
            {
                cout << b << endl;
                generatIndexSequences.push_back(b);
            }
        }
    }
}

void run(int argc, char** argv) {
    vector<int> sequenceJacobsthal;
    vector<int> generatIndexSequences;
    vector<pair<int,int> > vectpair;
    pair<int,int> pair;
    vector<int> util;
    vector<int> vec;
    vector<int> res;
    string str;
    int save = -1;
    int size;
    int a, b;

    for (int i = 1; i < argc; i += 2)
    {
        stringstream ss1(argv[i]);
        if (!(ss1 >> a) || a <= 0 || !(checkNumber(argv[i])))
        {
            str = argv[i];
            throw std::runtime_error("bad input " + str);
        }
        if (i + 1 < argc) {
            stringstream ss2(argv[i + 1]);
            if (!(ss2 >> b) || b <= 0 || !(checkNumber(argv[i + 1])))
            {
                str = argv[i];
                throw std::runtime_error("bad input " + str);
            }
            pair = make_pair(max(a, b), min(a, b));
            vectpair.push_back(pair);
        }
        else
        {
            save = a;
        }
        
    }
    sortPair(vectpair);
    for (vector<std::pair<int,int> >::iterator it = vectpair.begin(); it != vectpair.end(); it++)
    {
        res.push_back(it->first);
        util.push_back(it->second);
    }
    res.insert(res.begin(), *util.begin());
    util.erase(util.begin());
    size = util.size();
    generatSequenceJacobsthal(sequenceJacobsthal,size);
    while (sequenceJacobsthal.back() > 300)
    {
        sequenceJacobsthal.pop_back();
    }
    generatIndexSequencess(generatIndexSequences, sequenceJacobsthal);
    for (vector<int>::iterator j = generatIndexSequences.begin() ; j != generatIndexSequences.end();j++)
    {
        if (*(j) - 1 < (int)util.size())
        {
            insertionSort(res,util[*(j) - 1]);
        }
    }
    insertionSort(res,util[0]);
    if (save != -1)
        insertionSort(res, save);
    for(int i = 0; i < (int)(res.size()); i++)
        cout << res[i] << " ";
    cout << endl;
    // for(int i = 0; i < (int)(util.size()); i++)
    //     cout << util[i] << " ";
    
    cout  << std::endl;
    std::cout << "save is :" << save <<std::endl;
    cout << "Sorted data:" << endl;
    // printVector(vect);
    // (void) save;
    // (void)size;
}

int main(int argc, char** argv) {
    if (argc <= 1) {
        cout << "Erreur : Pas assez d'arguments." << endl;
        return 1;
    }
    try {
        run(argc, argv);
    } catch (const exception& e) {
        cerr << e.what() << '\n';
        return 1;
    }
    // vector<int> vec;
    // vector<int>newsec;
    // generatSequenceJacobsthal(vec,100);
    // for(int i = 0;i < (int)vec.size();i++)
    // {
    //     std::cout << vec[i] << '\n';
    // }
    // generatIndexSequencess(newsec,vec);
    (void)argv;
    (void)argc;
    return 0;
}


// int main()
// {    
//     // cout << SuitJacobsthal(0) << endl;
//     // cout << SuitJacobsthal(1) << endl;
//     // cout << SuitJacobsthal(2) << endl;
//     // cout << SuitJacobsthal(3) << endl;
//     // cout << SuitJacobsthal(4) << endl;
//     // cout << SuitJacobsthal(5) << endl;
//     // cout << SuitJacobsthal(6) << endl;
// }