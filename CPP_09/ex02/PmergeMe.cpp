#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const std::string &input)
{
    if (!parse(input))
        throw (ErrorException());
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

bool PmergeMe::containsAlready(const std::vector<int>& vt, int value)
{
    return (std::find(vt.begin(), vt.end(), value) != vt.end());
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

bool PmergeMe::parse(const std::string &input) // TODO: make this a template so it works with both containers
{
    std::istringstream iss(input);
    std::string token;
    int value;

    if (input.empty())
        return (false);
    while (iss >> token)
    {
        if (!isNumber(token) || !noOverflow(token))
            return (false);
        value = std::atoi(token.c_str());
        if (value == 0 || containsAlready(vt, value))
            return (false);
        vt.push_back(value);
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

void PmergeMe::createVectorPairs()
{
    for (size_t i = 0; i < vt.size(); i += 2)
        pairs.push_back(std::make_pair(vt[i], vt[i + 1]));
}

void PmergeMe::sortHigherValuesRecursively(size_t index)
{
    int temp;

    if (pairs.size() == index)
        return ;

    if (pairs[index].first > pairs[index].second)
    {
        temp = pairs[index].first;
        pairs[index].first = pairs[index].second;
        pairs[index].second = temp;
    }

    vt.insert(std::lower_bound(vt.begin(), vt.end(), pairs[index].second), pairs[index].second);
    sortHigherValuesRecursively(index + 1);
}

void PmergeMe::insertSmallest()
{
    std::vector<std::pair <int, int> >::iterator it;

    for (it = pairs.begin(); it != pairs.end(); ++it)
    {
        if (it->second == vt[0])
        {
            vt.insert(vt.begin(), it->first);
            break ;
        }
    }
    pairs.erase(it);
}

std::vector<int>::iterator PmergeMe::findInPairs(int value)
{
    std::vector<std::pair<int, int> >::iterator itP = pairs.begin();

    while (itP != pairs.end())
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

void PmergeMe::insertInHigher(size_t index)
{
    std::vector<int>::iterator end;
    int value = pairs[index].first;

    end = findInPairs(pairs[index].second);
    vt.insert(std::lower_bound(vt.begin(), end, value), value);
}

void PmergeMe::prepareInsert(int leftover)
{
    size_t currentIndex;
    int prevIndex;
    bool end = false;
    int j;

    insertInHigher(0);
    for (size_t i = 1; i < 33; i++)
    {
        currentIndex = Jacobstahl[i];
        if (currentIndex > pairs.size())
        {
            end = true;
            currentIndex = pairs.size() - 1;
        }
        prevIndex = Jacobstahl[i - 1];

        for (j = currentIndex; j > prevIndex; j--)
            insertInHigher(j);

        if (end)
            break ;
    }
    if (leftover != -1)
        insertInHigher(j);
}

void PmergeMe::handleVector()
{
    int leftover = -1;

    if (vt.size() == 1)
        throw (OnlyOneIntegerException());
    if (vt.size() % 2 != 0)
    {
        leftover = vt.back();
        vt.erase(vt.end() - 1);
    }
    
    createVectorPairs();
    vt.clear();
    sortHigherValuesRecursively(0);
    insertSmallest();    
    prepareInsert(leftover);
    for (size_t i = 0; i < vt.size(); i++)
        std::cout << vt[i] << " ";
    std::cout << "\n";
}

// void PmergeMe::handleList()
// {
    
// }

const char *PmergeMe::ErrorException::what(void) const throw()
{
    return ("Error");
}

const char *PmergeMe::OnlyOneIntegerException::what(void) const throw()
{
    return ("Input more positive integers!");
}

// I have an array of integers, they represent a specific sequence. It's a static array, it's fine.
// Also I have a vector of positive integers. Now, taking into account the sequence that I have, I want to split vector into specific subgroups.
// the sequence starts like this 0, 1, 1, 3, 5, 11
// Now I iterate through the sequence and let's say I'm on value 5, I use it as an index to say: go to index 5 at the vector and print indexes in an opposite direction till you reach a previous index of a sequence, 3 in this case.
// so, if my input is 52 56 8 65 39 29 55 2 12, in this iteration I want to print 29 39 