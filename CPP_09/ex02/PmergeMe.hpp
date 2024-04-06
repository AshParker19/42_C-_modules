#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <exception>
#include <algorithm>
#include <vector>
#include <list>

class PmergeMe // vector and linked list
{
    private:
        PmergeMe();

        std::vector<int> vt;
        std::vector<std::pair <int,int> > pairs;
        // int vector time;

        std::list<int> lt;

    public:
        PmergeMe(const std::string &input); // parse the input in the constructor
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        // parsing
        bool isNumber(const std::string &str);
        bool containsAlready(const std::vector<int>& vt, int value);
        bool noOverflow(std::string token);
        bool parse(const std::string &input);

        // vector
        void createSortVectorPairs();
        void selectSortHigherValues();
        void searchInsert(int value);
        void handleVector();

        // list
        void handleList();

        class ErrorException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };

        class OnlyOneIntegerException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };
};

#endif
