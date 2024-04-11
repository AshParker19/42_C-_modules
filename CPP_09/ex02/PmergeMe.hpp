#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <exception>
#include <algorithm>
#include <vector>
#include <list>

class PmergeMe
{
    private:
        PmergeMe();

        int Jacobstahl[33];

        std::vector<int> vt;
        std::vector<std::pair <int,int> > pairsVt;
        // int vector time;

        std::list<int> lt;
        std::list<std::pair <int,int> > pairsLt;

    public:
        PmergeMe(int ac, char **av);
        PmergeMe(const PmergeMe &other); //TODO:
        PmergeMe &operator=(const PmergeMe &other); //TODO:
        ~PmergeMe();

        // parsing
        bool isNumber(const std::string &str);
        bool noOverflow(std::string token);

        // Jacobstahl sequence
        void generateSequence();

        // vector
        void sortHigherValuesRecursivelyVt(size_t index);
        void insertInHigherVt(size_t index);
        std::vector<int>::iterator findInPairsVt(int value);
        void handleVector();

        void prepareInsert(int leftover, bool container);

        // list
        void sortHigherValuesRecursivelyLt(std::list<std::pair <int, int> >::iterator itPair);
        void insertInHigherLt(size_t index);
        std::list<int>::iterator findInPairsLt(int value);
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
        bool containsAlready(T container, int value)
        {
            return (std::find(container.begin(), container.end(), value) != container.end());
        }

        template<typename T>
        bool parse(bool alreadyChecked, const std::string &input, T &container)
        {
            std::istringstream iss(input);
            std::string token;
            int value;

            if (input.empty())
                return (false);
            
            while (iss >> token)
            {
                if (!alreadyChecked && (!isNumber(token) || !noOverflow(token)))
                    return (false);
                value = std::atoi(token.c_str());
                if (!alreadyChecked && (value == 0 || containsAlready(container, value)))
                    return (false);
                container.push_back(value);
            }
            return (true);
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
};

#endif
