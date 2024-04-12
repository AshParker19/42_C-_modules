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

void PmergeMe::binarySearchVt(size_t index)
{
    std::vector<int>::iterator end;
    int value = pairsVt[index].first;

    end = findInPairs(pairsVt[index].second, pairsVt, vt);
    vt.insert(std::lower_bound(vt.begin(), end, value), value);
}

void PmergeMe::prepareInsert(bool useVector)
{
    size_t currentIndex;
    int prevIndex;
    void (PmergeMe::*searchFunc)(size_t) = useVector ? &PmergeMe::binarySearchVt : &PmergeMe::binarySearchLt;

    (this->*searchFunc)(0);
    for (size_t i = 1; i < 33; i++)
    {
        currentIndex = Jacobstahl[i];
        if (currentIndex > pairsVt.size())
            currentIndex = pairsVt.size() - 1;
        prevIndex = Jacobstahl[i - 1];

        for (int j = currentIndex; j > prevIndex; j--)
            (this->*searchFunc)(j);
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
    insertLeftover(pairsVt, leftover); 
    prepareInsert(true);
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

void PmergeMe::binarySearchLt(size_t index)
{
    std::list<int>::iterator itL = lt.begin();
    std::list<int>::iterator mid;
    std::list<int>::iterator end;
    std::list<std::pair<int, int> >::iterator itP = pairsLt.begin();
    int value;
    int distance;

    std::advance(itP, index);
    value = itP->first;
    end = findInPairs(itP->second, pairsLt, lt);
    distance = std::distance(lt.begin(), end);
    while (distance > 1)
    {
        mid = itL;
        std::advance(mid, distance / 2);
        if (*mid > value)
            end = mid;
        else
            itL = mid;
        distance = std::distance(itL, end);
    }
    if (*itL > value)
        lt.insert(itL, value);
    else
        lt.insert(++itL, value);
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
    insertLeftover(pairsLt, leftover); 
    prepareInsert(false);
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
