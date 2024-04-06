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

void PmergeMe::searchInsert(int value)
{
    int toInsert;

    if (value != -1)
    {
        vt.insert(std::lower_bound(vt.begin(), vt.end(), value), value);
        return ;
    }

    for (size_t i = 0; i < pairs.size(); i++)
    {
        toInsert = pairs[i].first;
        vt.insert(std::lower_bound(vt.begin(), vt.end(), toInsert), toInsert);
    }
}

void PmergeMe::handleVector()
{
    // int leftover = -1;

    if (vt.size() == 1)
        throw (OnlyOneIntegerException());

    // if (vt.size() % 2 != 0)
    // {
    //     leftover = vt.back();
    //     vt.erase(vt.end() - 1);
    // }
    
    createVectorPairs();
    vt.clear();
    sortHigherValuesRecursively(0);
    vt.insert(vt.begin(), pairs[0].first);
    pairs.erase(pairs.begin());
    // searchInsert(-1);
    // if (leftover != -1)
    //     searchInsert(leftover);
    
    for (size_t i = 0; i < vt.size(); i++)
        std::cout << vt[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::handleList()
{
    
}

const char *PmergeMe::ErrorException::what(void) const throw()
{
    return ("Error");
}

const char *PmergeMe::OnlyOneIntegerException::what(void) const throw()
{
    return ("Input more positive integers!");
}