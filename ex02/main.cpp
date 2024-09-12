#include "PmergeMe.hpp"

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

void    generatSequenceJacobsthal(vector<int> &SequenceJacobsthal,int size)
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

void    generatIndexSequencess(vector<int> &generatIndexSequences,vector<int> sequenceJacobsthal,int size)
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

void run(int argc, char** argv)
{
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
                str = argv[i + 1];
                throw std::runtime_error("bad input " + str);
            }
            pair = make_pair(max(a, b), min(a, b));
            vectpair.push_back(pair);
        }
        else
            save = a;
    }    
    sortPair(vectpair);
    for (vector<std::pair<int,int> >::iterator it = vectpair.begin(); it != vectpair.end(); it++)
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
        for (vector<int>::iterator it = util.begin(); it != util.end(); it++)
           insertionSort(res, *it);
    }
    else
    {
        generatSequenceJacobsthal(sequenceJacobsthal,size);
        generatIndexSequencess(generatIndexSequences, sequenceJacobsthal,size);
        for (vector<int>::iterator j = generatIndexSequences.begin() ; j != generatIndexSequences.end();j++)
        {
            if (*(j) - 1 < (int)util.size())
                insertionSort(res,util[*(j) - 1]);
        }
        if (util.size()  &&  util[0])
            insertionSort(res,util[0]);
    }
    (save != -1) && (insertionSort(res, save), 0);
}

// void l()
// {
//     system("leaks PmergeMe");
// }

int main(int argc, char** argv) {
    // atexit(l);
    if (argc <= 1) {
        cout << "Erreur : Pas assez d'arguments." << endl;
        return 1;
    }
    try {

        clock_t timeVectorAv = clock();
        run(argc, argv);
        clock_t timeVectorAp = clock() - timeVectorAv;
        clock_t timeDequeAv = clock();
        deque<int> org;
        run(argc, argv,org);
        clock_t timeDequeAp = clock() - timeDequeAv;

        double final1 = static_cast<double>(timeVectorAp) / CLOCKS_PER_SEC * 1000;
        double final2 = static_cast<double>(timeDequeAp) / CLOCKS_PER_SEC * 1000;
        cout << "Before:\t";
        for (int i = 1;argv[i];i++)
        {
            stringstream ss(argv[i]);
            int tmp;ss >> tmp;cout << tmp;
            if (i + 1 != argc)
                cout << " ";
        }
        cout << "\nAfter:\t";
        for (size_t i = 0;org[i];i++)
        {
            cout << org[i];
            if (i + 1 != org.size())
                cout << " ";
        }
        cout << "\nTime to process a range of " << argc - 1<< " elements with std::vector: " << std::fixed << std::setprecision(6) << final1 << " us\n";
        cout << "Time to process a range of " << argc - 1<< " elements with std::deque : " << std::setprecision(6) << final2 << " us\n";
        
    } catch (const exception& e) {
        cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}