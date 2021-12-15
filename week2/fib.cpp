#include<iostream>


int fib(int n)
{
	if(n <= 1)
	{
		return n;
	}
	return fib(n-1) + fib(n-2);
}

int main()
{
	for (int i =0; i<30; i++)
	{
		std::cout<< fib(i+1) <<" , ";
	}
	return 0;
}

//i have explained calculation in the jpg file
// up to some point the somplxity is 2n 
// but after somepoint the complexity changes to 2^n which is tooo much in the recursive case
// then found the golden the golden ratio to compte the time
//
//
// furthure more the computation goes on and gives no error
// first i changed the number to 40 for which calcultion took only 2 secs but after 45 it never calculates
// to detect the problem we need to look the time complexity open the equation and try find what is series is telling us
// that will detect the problem for us which is after a certain number time complexity become 2^n
