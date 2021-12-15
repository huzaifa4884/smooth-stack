#include<iostream>
#include<bits/stdc++.h>

int findIndex(int n)
{
    float fibo = 2.078087 * log(n) + 1.672276;
 
    return round(fibo);
}

int main()
{
	int number;
	std::cout<<"Enter the value for number    :";
	std::cin>>number;
	std::cout<<findIndex(number)<<std::endl;
}
