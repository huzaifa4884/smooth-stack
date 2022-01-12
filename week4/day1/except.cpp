#include<iostream>
#include<stdexcept>


void checkNums(float a , float b)
{
    if (a - (int) a > 0)
    {
        throw("a cannot be exactly represented as int");
    }
    if (b - (int)b > 0)
    {
        throw("b cannot be exactly represesnted as int");
    }
}

void checkNumst(float a , float b)
{
    if (a - (int) a > 0)
    {
        throw(std::terminate);
    }
    if (b - (int)b > 0)
    {
        std::cout<< "terminating" << std::endl;
        throw(std::terminate);
    }
} 


int main()
{
    try
    {
        checkNums(2.0 , 2.1);
    } catch(const char *s)
    {
        std::cout << s << std::endl;
    }
    try
    {
        checkNumst(2.0 , 2.1);
    }
    catch(...){}
}
