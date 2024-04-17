#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this == &other)
        return (*this);
    
    for (int i = 0; i < 33; i++)
        Jacobstahl[i] = other.Jacobstahl[i];

    parsedInput = other.parsedInput;

    vt = other.vt;
    benchmarkVt = other.benchmarkVt;
    pairsVt = other.pairsVt;

    lt = other.lt;
    pairsLt = other.pairsLt;
    benchmarkLt = other.benchmarkLt;
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

bool PmergeMe::containsAlready(const std::string& value)
{
    std::istringstream iss(parsedInput);
    std::string token;

    while (iss >> token)
    {
        if (token == value)
            return (true);
    }
    return (false);
}

void PmergeMe::parse(int ac, char **av)
{
    for (int i = 1; i < ac; ++i)
    {
        if (!isNumber(av[i]) || !noOverflow(av[i]) || containsAlready(av[i]))
            throw (ErrorException());
        parsedInput += av[i];
        if (i < ac - 1)
            parsedInput += " ";
    }
}

bool PmergeMe::isSorted()
{
    std::vector<int>::const_iterator it = vt.begin();
    std::vector<int>::const_iterator next = it;
    ++next;

    while (next != vt.end())
    {
        if (*it > *next)
            return (false);
        ++it;
        ++next;
    }
    return (true);
}

void PmergeMe::generateSequence()
{
    Jacobstahl[0] = 0;
    Jacobstahl[1] = 1;
    for (size_t i = 2; i < 33; ++i)
        Jacobstahl[i] = (Jacobstahl[i - 1] + 2 * Jacobstahl[i - 2]);
}

void PmergeMe::createPairsVt()
{
    for (size_t i = 0; i < vt.size(); i += 2)
        pairsVt.push_back(std::make_pair(vt[i], vt[i + 1]));
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
    size_t i;

    for (i = 0; i < pairsVt.size(); i++)
    {
        if (pairsVt[i].second == vt[0])
        {
            vt.insert(vt.begin(), pairsVt[i].first);
            pairsVt.erase(pairsVt.begin() + i);
            break ;
        }
    }
}

std::vector<int>::iterator PmergeMe::findInPairsVt(int value)
{
    size_t i = 0, j;

    while (i < pairsVt.size())
    {
        for (j = 0; j < vt.size(); j++)
        {
            if (value == vt[j])
                return (vt.begin() + j);
        }
        i++;
    }
    return (vt.end());
}

void PmergeMe::binarySearchVt(size_t index)
{
    std::vector<int>::iterator end;
    int value = pairsVt[index].first;

    end = findInPairsVt(pairsVt[index].second);
    vt.insert(std::lower_bound(vt.begin(), end, value), value);
}

void PmergeMe::prepareInsert(bool useVector)
{
    size_t currentIndex;
    int prevIndex;
    void (PmergeMe::*searchFunc)(size_t) = useVector ? &PmergeMe::binarySearchVt : &PmergeMe::binarySearchLt;

    (this->*searchFunc)(0);
    for (size_t i = 2; i < 33; i++)
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
    clock_t start, end;

    start = clock();
    readStore(vt, true);
    if (vt.size() % 2 != 0)
    {
        leftover = vt.back();
        vt.erase(vt.end() - 1);
    }
    createPairsVt();
    vt.clear();
    sortHigherValuesRecursivelyVt(0);
    insertSmallestVt();
    insertLeftover(pairsVt, leftover); 
    prepareInsert(true);
    end = clock();
    benchmarkVt = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
}

void PmergeMe::createPairsLt()
{
    int first, second;
    std::list<int>::const_iterator it = lt.begin();

    for ( ; it != lt.end(); ++it)
    {
        first = *it;
        ++it;
        second = *it;
        pairsLt.push_back(std::make_pair(first, second));
    }
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

void PmergeMe::insertSmallestLt()
{
    std::list<std::pair<int, int> >::iterator it;

    for (it = pairsLt.begin(); it != pairsLt.end(); ++it)
    {
        if (it->second == *lt.begin())
        {
            lt.insert(lt.begin(), it->first);
            pairsLt.erase(it);
            break ;
        }
    }
}

std::list<int>::iterator PmergeMe::findInPairsLt(int value)
{
    std::list<std::pair<int, int> >::iterator itP = pairsLt.begin();
    std::list<int>::iterator itL;

    while (itP != pairsLt.end())
    {
        for (itL = lt.begin(); itL != lt.end(); ++itL)
        {
            if (value == *itL)
                return (itL);
        }
        ++itP;
    }
    return (lt.end());
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
    end = findInPairsLt(itP->second);
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
    clock_t start, end;

    start = clock();
    readStore(lt, false);
    if (lt.size() % 2 != 0)
    {
        leftover = lt.back();
        lt.pop_back();
    }
    createPairsLt();
    lt.clear();
    sortHigherValuesRecursivelyLt(pairsLt.begin());
    insertSmallestLt();
    insertLeftover(pairsLt, leftover); 
    prepareInsert(false);
    end = clock();
    benchmarkLt = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
}

void PmergeMe::displayResults()
{
    std::cout << "Before: " << parsedInput << "\n";
    std::cout << "After: ";
    for (size_t i = 0; i < vt.size(); i++)
        std::cout << vt[i] << " ";
    std::cout << "\n";
    std::cout << "std::vector --> " << checkIfSorted(vt) << "\n";
    std::cout << "std::list --> " << checkIfSorted(lt) << "\n";
    std::cout << "Time to process a range of " << vt.size() << " elements with "
              << "std::vector" << " : " << benchmarkVt << "ms\n";
    std::cout << "Time to process a range of " << lt.size() << " elements with "
              << "std::list" << " : " << benchmarkLt << "ms" << std::endl;
}

const char *PmergeMe::ErrorException::what(void) const throw()
{
    return ("Error");
}

const char *PmergeMe::OnlyOneIntegerException::what(void) const throw()
{
    return ("Input more positive integers!");
}

const char *PmergeMe::AlreadySortedInputException::what(void) const throw()
{
    return ("Input is already sorted");
}