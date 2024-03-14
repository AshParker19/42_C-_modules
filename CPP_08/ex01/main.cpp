#include "Span.hpp"

int main()
{
    int shortestSpan;
    int longestSpan;

    {
        try 
        {
            Span s(5);

            s.addNumber(1);
            s.addNumber(8);
            s.addNumber(10);
            s.addNumber(4);
            s.addNumber(15);
            shortestSpan = s.shortestSpan();
            longestSpan = s.longestSpan();
            std::cout << "Shortest span --> " << shortestSpan << std::endl;
            std::cout << "Longest span --> " << longestSpan << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            return (1);
        }
    }
    std::cout << "==================================" << std::endl;
    {
        try
        {
            Span s(10000);
            std::vector<int> v(10000);

            std::srand(unsigned(std::time(0)));
            std::generate(v.begin(), v.end(), std::rand);
            s.addNumber(v.begin(), v.end());
            shortestSpan = s.shortestSpan();
            longestSpan = s.longestSpan();

            std::cout << "Min value -- > " << *std::min_element(v.begin(), v.end()) << "\n";
            std::cout << "Max value -- > " << *std::max_element(v.begin(), v.end()) << "\n";
            std::cout << "Shortest span --> " << shortestSpan << std::endl;
            std::cout << "Longest span --> " << longestSpan << std::endl;
        }
        catch(const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            return (1);
        }
    }
}
