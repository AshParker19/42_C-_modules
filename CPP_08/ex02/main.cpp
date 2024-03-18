#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
   MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;
    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737); //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it; 
    }
    std::stack<int> s(mstack);
    return 0;
}

// list test
// int main() 
// {
//     std::list<int> mlist;

//     mlist.push_back(5);
//     mlist.push_back(17);

//     std::cout << mlist.back() << std::endl;
//     mlist.pop_back();

//     std::cout << mlist.size() << std::endl;

//     mlist.push_back(3);
//     mlist.push_back(5);
//     mlist.push_back(737);
//     mlist.push_back(0);

//     std::list<int>::iterator it = mlist.begin();
//     std::list<int>::iterator ite = mlist.end();

//     ++it;
//     --it;

//     while (it != ite) 
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }

//     return 0;
// }

// int main() 
// {
//     MutantStack<int> mstack;

//     for (int i = 0; i < 10; ++i) {
//         mstack.push(i);
//     }

//     std::cout << "Stack contents using iterators:" << std::endl;
//     for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
//         std::cout << *it << ' ';
//     std::cout << "\n";

//     std::cout << "Top --> " << mstack.top() << "\n";

//     mstack.pop();

//     std::vector<int> vec;
//     std::copy(mstack.begin(), mstack.end(), std::back_inserter(vec));

//     std::cout << "Copied to vector:" << std::endl;
//     for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
//         std::cout << *it << ' ';
//     std::cout << "\n";

//     std::cout << "Reverse iterator test:" << std::endl;
//     for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); rit++)
//         std::cout << *rit << ' ';
//     std::cout << "\n";
// }