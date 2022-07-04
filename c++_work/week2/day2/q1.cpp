#include <iostream>
#include <cmath>
#include<iomanip>
int main()
{
    double num = 0.125;
    
    double j = std::pow(2,55)*0.125;
    
    num = j * std::floor(std::pow(10 , 55) / std::pow(2 , 55));
    
    
    
    std::cout<<"0."<< std::setprecision(57) << num << std::endl;

    return 0;
}
