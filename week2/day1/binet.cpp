#include<iostream>
#include<cmath>

int findIndex(int n)
{
    //double fibo = 2.078087 * log(n) + 1.672276;
    //double fibo = std::sqrt(5) * log(n) + ((1-sqrt(5)/2));
    double fibo = (log(n) + log(std::sqrt(5)))/log(sqrt(5));
 
    return std::round(fibo);
}

int main()
{
	int number;
	std::cout<<"Enter the value for number    :";
	std::cin>>number;
	std::cout<<findIndex(number)+1<<std::endl;
}
