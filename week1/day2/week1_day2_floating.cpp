#include<iostream>

int main()
{
	double a , b;
	a = 3.4567e+38;
	b = 1.175494e-38;
	b = a - b;
	std::cout<<a<<std::endl;
       	return 0;	
}
