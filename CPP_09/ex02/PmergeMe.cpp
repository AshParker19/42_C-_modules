#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const std::string &input)
{
    if (!parse(input))
        throw exception
    (void)input;
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
        ++it;
    return (!str.empty() && it == str.end());
}

bool containsAlready(const std::vector<int>& vt, int value)
{
    return (std::find(vt.begin(), vt.end(), value) != vt.end());
}

bool PmergeMe::parse(const std::string &input)
{
    if (input.empty())
        return (false);

    std::istringstream iss(input);
    std::string token;
    int value;

    while (iss >> token)
    {
        if (!isNumber(token))
            return (false);
        value = std::atoi(token.c_str());
        if (containsAlready(vt, value))
            return (false);
        vt.push_back(value);
    }
    return (true);
}

void PmergeMe::sortVector()
{
    vt.push_back(4);
    vt.push_back(1);
    vt.push_back(77);
    vt.push_back(100);
    vt.push_back(19);
    vt.push_back(42);
}
