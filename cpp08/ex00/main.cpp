#include "easyfind.hpp"
#include <iterator>
#include <list>
#include <forward_list>
#include <vector>
#include <deque>
// void l()
// {
//     system("leaks easyfind");
// }
bool check(int id)
{
    return (id < 0);
}

int main()
{
    std::vector<int> v(5, 20);
    try 
    {
        easyfind(v, 20);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "+++++++++++++++++++++++++++++++++ Sequence container ++++++++++++++++++++++++++++++++++++\n";
    std::cout << "########################## test vector ####################" << std::endl;

    try
    {
        std::vector<int> vect(3, -1); 
        vect.resize(6);
        vect.insert(vect.begin(), 3); 
        vect.push_back(1);            
        vect.insert(vect.begin(), 2); 
        vect.insert(vect.end(), 1000);
        vect.insert(vect.begin(), 1000);

        std::cout << "front is :" << vect.front() << std::endl;
        std::cout << "back is :" << vect.back() << std::endl;
        std::cout << "size vector is : " << vect.size() << std::endl;
        std::cout << "max size vector is : " << vect.max_size() << std::endl;
        std::cout << "empty vector : " << vect.empty() << std::endl;
        
        try {
            std::cout << "at vector is : " << vect.at(4) << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Exception: " << e.what() << '\n';
        }
        
        std::cout << "first param is : " << *vect.begin() << std::endl;
        std::cout << "last param vector is : " << *(vect.end() - 1) << std::endl;
        std::cout << "================= contenu =======================" << std::endl;
        
        std::copy(vect.begin(), vect.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
        std::vector<int>::iterator it = easyfind(vect, 3);
        std::cout << "element found is : " << *it << std::endl;
        
        vect.pop_back();
        std::cout << "---------------------------------------------\n";
        
        vect.insert(vect.begin() + 1, -2000);
        std::copy(vect.begin(), vect.end(), std::ostream_iterator<int>(std::cout, "    "));
        std::cout << std::endl;
        
        std::cout << "========= erase ========= " << std::endl;
        vect.erase(std::find(vect.begin(), vect.end(), -2000));
        std::copy(vect.begin(), vect.end(), std::ostream_iterator<int>(std::cout, "    "));
        std::cout << std::endl;
        
        std::cout << "---------------------------------------------\n";
        vect.erase(vect.end() - 1);
        std::copy(vect.begin(), vect.end(), std::ostream_iterator<int>(std::cout, "    "));
        std::cout << std::endl;
        
        vect.clear();
        std::copy(vect.begin(), vect.end(), std::ostream_iterator<int>(std::cout, "    "));
        std::cout << std::endl;
        
        if (vect.empty())
            std::cout << "================= clear contenu vector =======================" << std::endl;
        
        it = easyfind(vect, 0);
    }
    catch (const EXCEPTIONNOTFOUND &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "...................." << '\n';
    }
    std::cout << "########################## test deque ####################" << std::endl;
        

    try
    {
        std::deque<int> deq(3, -1);
        deq.resize(6);
        deq.push_front(3);         
        deq.push_back(1);          
        deq.push_front(2);         
        deq.insert(deq.end(), 1000); 
        deq.insert(deq.begin(), 1000);
        
        std::cout << "size deque is : " << deq.size() << std::endl;
        std::cout << "max size deque is : " << deq.max_size() << std::endl;
        std::cout << "empty deque : " << deq.empty() << std::endl;
        std::cout << "at deque is : " << deq.at(4) << std::endl;
        std::cout << "first param is : " << *deq.begin() << std::endl;
        std::cout << "last param deque is : " << *(deq.end() - 1) << std::endl;
        std::cout << "================= contenu =======================" << std::endl;
        
        std::copy(deq.begin(), deq.end(), std::ostream_iterator<int>(std::cout, "   "));
        std::cout << std::endl;
        std::deque<int>::iterator it = easyfind(deq, 3);
        std::cout << "element found is : " << *it << std::endl;
        
        deq.pop_back(); 
        deq.pop_front();
        std::cout << "---------------------------------------------\n";
        
        deq.insert(deq.begin() + 1, -2000);
        std::copy(deq.begin(), deq.end(), std::ostream_iterator<int>(std::cout, "   "));
        std::cout << std::endl;
        
        std::cout << "========= erase ========= " << std::endl;
        deq.erase(std::find(deq.begin(), deq.end(), -2000));
        std::copy(deq.begin(), deq.end(), std::ostream_iterator<int>(std::cout, "   "));
        std::cout << std::endl;
        
        std::cout << "---------------------------------------------\n";
        
        if (!deq.empty())
            deq.erase(deq.end() - 1);
        std::copy(deq.begin(), deq.end(), std::ostream_iterator<int>(std::cout, "   "));
        std::cout << std::endl;
        
        deq.clear();
        std::copy(deq.begin(), deq.end(), std::ostream_iterator<int>(std::cout, "   "));
        std::cout << std::endl;
        
        if (deq.empty())
            std::cout << "================= clear contenu deque =======================" << std::endl;
        
        it = easyfind(deq, 0);
    }
    catch (const EXCEPTIONNOTFOUND &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "...................." << '\n';
    }
    std::cout << "########################## test list ####################" << std::endl;
    // double linkdlist

    try
    {
        std::list<int> lst;
        lst.assign(10,-1);
    
        std::list<int> nlst(10,-2);
        std::copy(nlst.begin(), nlst.end(), std::ostream_iterator<int>(std::cout, "   "));
        std::cout << std::endl;
        std::cout << "======================= merge   ============" << std::endl;
        lst.merge(nlst);//splice()
        std::copy(lst.begin(), lst.end(), std::ostream_iterator<int>(std::cout, "   "));
        std::cout << std::endl;
        nlst.clear();
        // lst.resize(6);    
        lst.remove_if(check);
        lst.push_front(3);   
        lst.push_back(1);    
        lst.push_front(2);   
        lst.push_back(1000); 
        lst.push_front(1000);
        std::cout << "((((((((((((((((((()))))))))))))))))))" << std::endl;
        std::copy(lst.crbegin(), lst.crend(), std::ostream_iterator<int>(std::cout, "   "));
        std::cout << std::endl;
        lst.unique();
    
        std::cout << "======================= sort   ============" << std::endl;
        lst.sort();
        std::copy(lst.begin(), lst.end(), std::ostream_iterator<int>(std::cout, "   "));
        std::cout << std::endl;
    
        std::copy(lst.begin(), lst.end(), std::ostream_iterator<int>(std::cout, "   "));
        std::cout << std::endl;
        std::cout << "======================= remove zero   ============" << std::endl;
        lst.remove(0);
        std::copy(lst.begin(), lst.end(), std::ostream_iterator<int>(std::cout, "  "));
        std::cout << std::endl;
    
        std::cout << "size list is : " << lst.size() << std::endl;
        std::cout << "empty list : " << lst.empty() << std::endl;
    
        std::list<int>::iterator it = std::next(lst.begin(), 4);
        std::cout << "element at position 4 is : " << *it << std::endl;
    
        std::cout << "first param is : " << lst.front() << std::endl;
        std::cout << "last param list is : " << lst.back() << std::endl;
        std::cout << "================= contenu =======================" << std::endl;
    
        std::copy(lst.begin(), lst.end(), std::ostream_iterator<int>(std::cout, "   "));
        std::cout << std::endl;
        std::list<int>::iterator found_it = easyfind(lst, 3);
        std::cout << "element found is : " << *found_it << std::endl;
        // std::next(found_it);
        //std::prev(found_it);
        lst.pop_back(); 
        lst.pop_front();
        std::cout << "---------------------------------------------\n";

        lst.insert(std::next(lst.begin(), 1), -2000);
        
        std::copy(lst.begin(), lst.end(), std::ostream_iterator<int>(std::cout, "   "));
        std::cout << std::endl;

        std::cout << "========= erase ========= " << std::endl;
        lst.erase(std::find(lst.begin(), lst.end(), -2000));
        
        std::copy(lst.begin(), lst.end(), std::ostream_iterator<int>(std::cout, "   "));
        std::cout << std::endl;

        std::cout << "---------------------------------------------\n";

        if (!lst.empty())
            lst.erase(--lst.end());
        lst.reverse();
        std::copy(lst.begin(), lst.end(), std::ostream_iterator<int>(std::cout, "   "));
        std::cout << std::endl;

        lst.clear();
        std::copy(lst.begin(), lst.end(), std::ostream_iterator<int>(std::cout, "   "));
        std::cout << std::endl;

        if (lst.empty())
            std::cout << "================= clear contenu list =======================" << std::endl;

        found_it = easyfind(lst, 0);
    }
    catch (const EXCEPTIONNOTFOUND &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "...................." << '\n';
    }
    try
    {
        std::cout << "//////////////////////////////////////////////////////" << std::endl;
        std::list<int> mylist;
        for (int i = 0; i <= 2; i++) mylist.push_back (i*10);
        std::cout << "The last element is " << *std::prev(mylist.end()) << '\n';
        std::cout << "The firt plus one element is " << *std::next(mylist.begin()) << '\n';
        mylist.clear();
    }
    catch(...)
    {
        std::cerr << "Exception " << '\n';
    }
    
    
    std::cout << "########################## test forwad list ####################" << std::endl;
    // simpla linkelist
    try
    {
        std::forward_list<int>fl(10,-2);
        fl.assign(10, -1);
        fl.unique();
        fl.push_front(0);
        fl.push_front(0);
        fl.pop_front();
        fl.insert_after(fl.begin(),20);
        fl.erase_after(fl.begin());
        fl.push_front(1);
        fl.push_front(2);
        std::forward_list<int>::iterator it = fl.begin();
        it = next(it,2);
        fl.erase_after(it);
        // fl.remove_if([](int id){return (id < 0);});// v c++ 17
        // fl.emplace_front(0);
        std::cout << "befor_behin is : " << *fl.before_begin() << std::endl;
        std::copy(fl.begin(), fl.end(), std::ostream_iterator<int>(std::cout, "   "));
        std::cout << std::endl;
    }
    catch(...)
    {
        std::cerr << "..............." << '\n';
    }
    
    return 0;
}