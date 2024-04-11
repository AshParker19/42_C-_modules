#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <exception>
#include <algorithm>
#include <vector>
#include <list>

template<typename T>
void checkIfSorted(const T &container)
{
    typename T::const_iterator it = container.begin();
    typename T::const_iterator nextIT = it;
    ++nextIT;

    while (nextIT != container.end())
    {
        if (*it > *nextIT)
        {
            std::cout << "KO" << std::endl;
            return ;
        }
        ++it;
        ++nextIT;
    }
    std::cout << "OK" << std::endl;
}

class PmergeMe // vector and linked list
{
    private:
        PmergeMe();

        int Jacobstahl[33];

        std::vector<int> vt;
        std::vector<std::pair <int,int> > pairs;
        // int vector time;

        std::list<int> lt;

    public:
        PmergeMe(int ac, char **av);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        // parsing
        bool isNumber(const std::string &str);
        bool containsAlready(const std::vector<int> &vt, int value);
        bool noOverflow(std::string token);
        bool parse(const std::string &input);

        // Jacobstahl sequence
        void generateSequence();

        // vector
        void createVectorPairs();
        void sortHigherValuesRecursively(size_t index);
        void insertSmallest();
        void prepareInsert(int leftover);
        void insertInHigher(size_t index);
        std::vector<int>::iterator findInPairs(int value);
        void handleVector();

        // list
        // void handleList();

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
