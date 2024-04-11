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

void PmergeMe::prepareInsert(int leftover, bool container)
{
    size_t currentIndex;
    int prevIndex;

    insertInHigherVt(0);
    for (size_t i = 1; i < 33; i++)
    {
        currentIndex = Jacobstahl[i];
        if (currentIndex > pairsVt.size())
            currentIndex = pairsVt.size() - 1;
        prevIndex = Jacobstahl[i - 1];

        for (int j = currentIndex; j > prevIndex; j--)
        {
            if (container == true)
                insertInHigherVt(j);
            else
                insertInHigherLt(j);
        }
    }
    if (leftover != -1)
    {
        if (container == true)
            vt.insert(std::lower_bound(vt.begin(), vt.end(), leftover), leftover);
        else
        {
            std::list<int>::iterator it = lt.begin();
            while (it != lt.end() && *it < leftover)
                ++it;
            lt.insert(it, leftover);
        }
    }
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
    insertSmallest(pairsVt, vt);    
    prepareInsert(leftover, true);
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

std::list<int>::iterator PmergeMe::findInPairsLt(int value)
{
    std::list<std::pair<int, int> >::iterator itP = pairsLt.begin();

    while (itP != pairsLt.end())
    {
        for (std::list<int>::iterator itL = lt.begin(); itL != lt.end(); ++itL)
        {
            if (value == *itL)
                return (itL);
        }
        ++itP;
    }
    return (lt.end());
}

void PmergeMe::insertInHigherLt(size_t index)
{
    std::list<int>::iterator end;
    std::list<std::pair<int, int> >::iterator itP = pairsLt.begin();
    std::list<int>::iterator itL;
    int value;

    std::advance(itP, index);
    value = itP->first;

    end = findInPairsLt(itP->second);

    for (itL = lt.begin(); itL != end; ++itL)
    {
        if (*itL > value)
            break ;
    }
    lt.insert(itL, value);
}

void PmergeMe::handleList()
{
    int leftover = -1;

    if (lt.size() % 2 != 0)
    {
        leftover = lt.back();
        lt.pop_back();
    }
    createPairs(pairsLt, lt);
    lt.clear();
    sortHigherValuesRecursivelyLt(pairsLt.begin());
    insertSmallest(pairsLt, lt);
    prepareInsert(leftover, false);
    checkIfSorted(lt);
}

const char *PmergeMe::ErrorException::what(void) const throw()
{
    return ("Error");
}

const char *PmergeMe::OnlyOneIntegerException::what(void) const throw()
{
    return ("Input more positive integers!");
}
