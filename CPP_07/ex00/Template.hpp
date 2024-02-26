#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

template <typename T>
void swap(T &agr1, T &arg2)
{
    T temp;

    temp = agr1;
    agr1 = arg2;
    arg2 = temp;
}

template <typename T>
T min(T num1, T num2)
{
    return (num1 == num2) ? num2 : ((num1 < num2) ? num1 : num2);
}

template <typename T>
T max(T num1, T num2)
{
    return (num1 == num2) ? num2 : ((num1 > num2) ? num1 : num2);
}

#endif