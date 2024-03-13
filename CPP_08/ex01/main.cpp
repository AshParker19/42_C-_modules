#include "Span.hpp"

int main()
{
    try 
    {
        Span s(5);
        int shortestSpan;
        int longestSpan;

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