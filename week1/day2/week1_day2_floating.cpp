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

//so the main idea is that even after the subtraction the resulting number wont change at all
//to meassure the precision according to IEEE 754
// if the floating point number is 32 bit
// lets say forexample we have number 3.5 its between 2 and 4
// what we do is (4-2/2^23) in case of 32 bits number
// in simple words range/mentisaa = precssion                                               
