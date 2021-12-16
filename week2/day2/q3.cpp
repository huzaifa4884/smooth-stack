#include <iostream>

int main()
{
    int n;
    std::cout<<"give the number"<<std::endl;
    std::cin>>n;

    while( n > 2)
    {
	if (n % 2 != 0)
	{
	   break;
	}
        n = n >> 1;
    }
    
    if (n == 2)
    {
        std::cout<< " is power of 2"<<std::endl;
    }
    else
    {
        std::cout<< " is not power of 2"<<std::endl;
    }
    

    return 0;
}

