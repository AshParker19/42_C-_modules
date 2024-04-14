#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <exception>
#include <algorithm>
#include <vector>
#include <list>
#include <ctime>

class PmergeMe
{
    private:

        int Jacobstahl[33];
        std::string parsedInput;

        std::vector<int> vt;
        std::vector<std::pair <int,int> > pairsVt;
        double benchmarkVt;

        std::list<int> lt;
        std::list<std::pair <int,int> > pairsLt;
        double benchmarkLt;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other); //TODO:
        PmergeMe &operator=(const PmergeMe &other); //TODO:
        ~PmergeMe();

        // parsing
        bool isNumber(const std::string &str);
        bool noOverflow(std::string token);
        bool containsAlready(const std::string& value);
        void parse(int ac, char **av);

        // Jacobstahl sequence
        void generateSequence();

        // vector
        void sortHigherValuesRecursivelyVt(size_t index);
        void binarySearchVt(size_t index);
        void handleVector();

        void prepareInsert(bool useVector );

        // list
        void sortHigherValuesRecursivelyLt(std::list<std::pair <int, int> >::iterator itPair);
        void binarySearchLt(size_t index);
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

        template<typename T>
        void readStore(T &container)
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
        }

        template<typename T, typename U>
        void createPairs(T &pairs, const U &container)
        {
            int first, second;
            typename U::const_iterator it = container.begin();

            for ( ; it != container.end(); ++it)
            {
                first = *it;
                ++it;
                second = *it;
                pairs.push_back(std::make_pair(first, second));
            }
        }

        template<typename T, typename U>
        void insertSmallest(T &pairs, U &container)
        {
            typename T::iterator it;

            for (it = pairs.begin(); it != pairs.end(); ++it)
            {
                if (it->second == *container.begin())
                {
                    container.insert(container.begin(), it->first);
                    break ;
                }
            }
            pairs.erase(it);
        }

        template<typename T>
        void insertLeftover(T &pairs, int leftover)
        {
            if (leftover != -1)
                pairs.insert(pairs.end(), std::make_pair(leftover, 0));
        }

        template<typename T, typename U>
        typename U::iterator findInPairs(int value, T &pairs, U &container)
        {
            typename T::iterator itP = pairs.begin();
            typename U::iterator itL;

            while (itP != pairs.end())
            {
                for (itL = container.begin(); itL != container.end(); ++itL)
                {
                    if (value == *itL)
                        return (itL);
                }
                ++itP;
            }
            return (container.end());
        }
};

#endif
