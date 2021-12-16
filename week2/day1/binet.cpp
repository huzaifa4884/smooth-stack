#include <iostream>
#include <cmath>

int fibonacci(int index)
{
    return std::round(pow((1 + sqrt(5)) / 2, index) / sqrt(5));
}

long int fibonacci(double index) 
{
    return std::round(pow((1 + sqrt(5)) / 2, index) / sqrt(5));
}

int main()
{
    int fibnum = 2147483647;
    
    int index = 2.078087 * log(fibnum) + 1.672276;  //if i pass largest integer it will give me the index to nearest fibonacci number;
    
    
    fibnum = fibonacci(index);      //this calculate the largest fibonaaci number in integer range
    
    long int lr = fibonacci(index + 1);
    

    
    std::cout<<index<<" , "<<fibnum<<std::endl;
    
    std::cout<<index + 1 << " , " <<lr << "  and this goes out of iteger range cause funtion returns int value the returned value is errored"<<std::endl;
    
    
    
    double newindex = index + 1;
    
    std::cout<< newindex << " , " << fibonacci(newindex) << "  this fibonacci numberis larger then integer range which is 2147483647"<<std::endl;

    return 0;
}

//first i pass the largest integer to inverse binet equation which return index of nearest fibonacci to highest integer
//then i calculate fibbonacci of that index
//then i do 1 + index to see if the next fibonacii goea out of integer range which does
//then create new function which return "long int" and that is correct fibonacci number but larger then highest integer
