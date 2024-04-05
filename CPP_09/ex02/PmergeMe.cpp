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

bool PmergeMe::parse(const std::string &input) // TODO: make this a template so it works with both containers
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

void PmergeMe::createSortVectorPairs()
{
    for (size_t i = 0; i < vt.size(); i += 2)
        pairs.push_back(std::make_pair(vt[i], vt[i + 1]));

    for (std::vector<std::pair <int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
    {
        if (it->first > it->second)
        {
            int temp = it->first;
            it->first = it->second;
            it->second = temp;
        }
    }
}

void PmergeMe::selectSortHigherValues()
{
    for (size_t i = 0; i < pairs.size(); i++)
        vt.push_back(pairs[i].second);

    std::sort(vt.begin(), vt.end());
}

void PmergeMe::binarySearchInsert()
{
    int toInsert;
    int low = 0, mid, high = vt.size();

    for (size_t i = 0; i < pairs.size(); i++)
    {
        toInsert = pairs[i].first;

        while (low < high)
        {
            mid = (low + high) / 2;
            if (vt[mid] < toInsert)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    // vt.insert();
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
    (void)leftover;
    createSortVectorPairs();
    vt.clear();
    selectSortHigherValues();
    binarySearchInsert();

}

const char *PmergeMe::ErrorException::what(void) const throw()
{
    return ("Error");
}

const char *PmergeMe::OnlyOneIntegerException::what(void) const throw()
{
    return ("Input more positive integers!");
}