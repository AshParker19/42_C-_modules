#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int ac, char **av)
{
    std::string input;

    for (int i = 1; i < ac; ++i)
    {
        input += av[i];
        if (i < ac -1)
            input += " ";
    }
    if (!parse(false, input, vt))
        throw (ErrorException());
    if (vt.size() == 1)
        throw (OnlyOneIntegerException());
    parse(true, input, lt);
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    (void) other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    (void) other;
    return (*this);
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isNumber(const std::string &str)
{
    std::string::const_iterator it = str.begin();

    while (it != str.end() && std::isdigit(*it))
        it++;
    return (!str.empty() && it == str.end());
}

bool PmergeMe::noOverflow(std::string token)
{
    const std::string maxInt = "2147483647";

    token.erase(0, token.find_first_not_of('0'));
    if (token.empty())
        return (false);
    if (token.length() > maxInt.size())
        return (false);
    if (token.length() < maxInt.size())
        return (true);
    return (token.compare(maxInt) <= 0);
}

void PmergeMe::generateSequence()
{
    Jacobstahl[0] = 0;
    Jacobstahl[1] = 1;
    for (size_t i = 2; i < 33; ++i)
        Jacobstahl[i] = (Jacobstahl[i - 1] + 2 * Jacobstahl[i - 2]);
}

void PmergeMe::sortHigherValuesRecursivelyVt(size_t index)
{
    int temp;

    if (index == pairsVt.size())
        return ;

    if (pairsVt[index].first > pairsVt[index].second)
    {
        temp = pairsVt[index].first;
        pairsVt[index].first = pairsVt[index].second;
        pairsVt[index].second = temp;
    }

    vt.insert(std::lower_bound(vt.begin(), vt.end(), pairsVt[index].second), pairsVt[index].second);
    sortHigherValuesRecursivelyVt(index + 1);
}

void PmergeMe::insertSmallestVt()
{
    std::vector<std::pair <int, int> >::iterator it;

    for (it = pairsVt.begin(); it != pairsVt.end(); ++it)
    {
        if (it->second == vt[0])
        {
            vt.insert(vt.begin(), it->first);
            break ;
        }
    }
    pairsVt.erase(it);
}

std::vector<int>::iterator PmergeMe::findInPairsVt(int value)
{
    std::vector<std::pair<int, int> >::iterator itP = pairsVt.begin();

    while (itP != pairsVt.end())
    {
        for (std::vector<int>::iterator itV = vt.begin(); itV != vt.end(); ++itV)
        {
            if (value == *itV)
                return (itV);
        }
        ++itP;
    }
    return (vt.end());
}

void PmergeMe::insertInHigherVt(size_t index)
{
    std::vector<int>::iterator end;
    int value = pairsVt[index].first;

    end = findInPairsVt(pairsVt[index].second);
    vt.insert(std::lower_bound(vt.begin(), end, value), value);
}

void PmergeMe::prepareInsertVt(int leftover)
{
    size_t currentIndex;
    int prevIndex;
    bool end = false;

    insertInHigherVt(0);
    for (size_t i = 1; i < 33; i++)
    {
        currentIndex = Jacobstahl[i];
        if (currentIndex > pairsVt.size())
        {
            end = true;
            currentIndex = pairsVt.size() - 1;
        }
        prevIndex = Jacobstahl[i - 1];

        for (int j = currentIndex; j > prevIndex; j--)
            insertInHigherVt(j);
        
        if (end)
            break ;
    }
    if (leftover != -1)
        vt.insert(std::lower_bound(vt.begin(), vt.end(), leftover), leftover);
}

void PmergeMe::handleVector()
{
    int leftover = -1;

    if (vt.size() % 2 != 0)
    {
        leftover = vt.back();
        vt.erase(vt.end() - 1);
    }
    createPairs(pairsVt, vt);
    vt.clear();
    sortHigherValuesRecursivelyVt(0);
    insertSmallestVt();    
    prepareInsertVt(leftover);
    checkIfSorted(vt);
}

void PmergeMe::sortHigherValuesRecursivelyLt(std::list<std::pair <int, int> >::iterator itPair)
{
    int temp;
    std::list<int>::iterator itLt;

    if (itPair == pairsLt.end())
        return ;

    if (itPair->first > itPair->second)
    {
        temp = itPair->first;
        itPair->first = itPair->second;
        itPair->second = temp;
    }

    for (itLt = lt.begin() ; itLt != lt.end(); ++itLt)
    {
        if (*itLt >= itPair->second)
            break ;
    }

    lt.insert(itLt, itPair->second);
    sortHigherValuesRecursivelyLt(++itPair);
}

void PmergeMe::handleList()
{
    // int leftover = -1;

    // if (lt.size() % 2 != 0)
    // {
    //     leftover = lt.back();
    //     lt.pop_back();
    // }
    createPairs(pairsLt, lt);
    lt.clear();
    sortHigherValuesRecursivelyLt(pairsLt.begin());
    for (std::list<int>::const_iterator it = lt.begin(); it != lt.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";
}

const char *PmergeMe::ErrorException::what(void) const throw()
{
    return ("Error");
}

const char *PmergeMe::OnlyOneIntegerException::what(void) const throw()
{
    return ("Input more positive integers!");
}
