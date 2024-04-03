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

bool PmergeMe::parse(const std::string &input) // TODO: make this a template so tit works with both containers
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
        if (value == 0 || containsAlready(vt, value))
            return (false);
        vt.push_back(value);
    }
    return (true);
}

void PmergeMe::sortVector()
{
    for (std::vector<int>::const_iterator it = vt.begin(); it != vt.end(); it++)
        std::cout << *it << " ";
}

const char *PmergeMe::ErrorException::what(void) const throw()
{
    return ("Error");
}