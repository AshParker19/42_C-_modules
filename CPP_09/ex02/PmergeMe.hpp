#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <exception>
#include <algorithm>
#include <vector>
#include <list>
#include <ctime>
#include <iomanip>

class PmergeMe
{
    private:
        static const int JACOB_NUM = 33;
        int Jacobstahl[JACOB_NUM];
        std::string parsedInput;

        std::vector<int> vt;
        std::vector<std::pair <int,int> > pairsVt;
        double benchmarkVt;

        std::list<int> lt;
        std::list<std::pair <int,int> > pairsLt;
        double benchmarkLt;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        // parsing
        bool isNumber(const std::string &str);
        bool noOverflow(std::string token);
        bool containsAlready(const std::string& value);
        void parse(int ac, char **av);

        // Jacobstahl sequence
        void generateSequence();

        // vector
        bool isSorted();
        void createPairsVt();
        void sortHigherValuesRecursivelyVt(size_t index);
        void insertSmallestVt();
        void binarySearchVt(size_t index);
        std::vector<int>::iterator findInPairsVt(int value);
        void handleVector();

        void prepareInsert(bool useVector);

        // list
        void createPairsLt();
        void sortHigherValuesRecursivelyLt(std::list<std::pair <int, int> >::iterator itPair);
        void insertSmallestLt();
        void binarySearchLt(size_t index);
        std::list<int>::iterator findInPairsLt(int value);
        void handleList();

        void displayResults();

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

        class AlreadySortedInputException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };

        template<typename T>
        const std::string checkIfSorted(const T &container)
        {
            typename T::const_iterator it = container.begin();
            typename T::const_iterator nextIT = it;
            ++nextIT;

            while (nextIT != container.end())
            {
                if (*it > *nextIT)
                    return ("KO");
                ++it;
                ++nextIT;
            }
            return ("OK");
        }

        template<typename T>
        void readStore(T &container, bool useVector)
        {
            std::istringstream iss(parsedInput);
            std::string token;
            int value;

            while (iss >> token)
            {
                value = std::atoi(token.c_str());
                container.push_back(value);
            }
            if (container.size() == 1)
                throw (OnlyOneIntegerException());
            if (useVector && isSorted())
                throw (AlreadySortedInputException());
        }

        template<typename T>
        void insertLeftover(T &pairs, int leftover)
        {
            if (leftover != -1)
                pairs.insert(pairs.end(), std::make_pair(leftover, 0));
        }
};

#endif
