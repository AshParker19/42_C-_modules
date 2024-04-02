#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <exception>
#include <vector>
#include <list>

class PmergeMe // vector and linked list
{
    private:
        PmergeMe();
        std::vector<int> vt;
        std::list<int> lt;

    public:
        PmergeMe(const std::string &input); // parse the input in the constructor
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        bool parse(const std::string &input);
};

#endif
