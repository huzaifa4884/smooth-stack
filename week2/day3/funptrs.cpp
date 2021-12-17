
#include <iostream>
#include <cassert>

int (*funpt[3])(int , int);

int add(int x , int y)
{
    return x + y;
}

int substract(int x , int y)
{
    return x - y;
}

int multiply(int x , int y)
{
    return x * y;
}

int compute(int x , int y , char funcmask)
{
    funpt[0] = &add;
    funpt[1] = &substract;
    funpt[2] = &multiply;
    
    unsigned op = (unsigned) funcmask & 7;
    switch(op)
    {
        case 1:
            return (*funpt[0])(x , y);
        case 2:
            return (*funpt[1])(x , y);
        case 4:
            return (*funpt[2])(x , y);
        default:
            std::cout<<"no valid selection made";
            return 0;
    }
}

int main()
{
    std::cout<<"calling add 2 + 3  =" << compute(2 , 3 , '1')<<std::endl; //calling add
    std::cout<<"calling add 2 - 3  ="<< compute(2 , 3 , '2')<<std::endl; //calling substract
    std::cout<<"calling add 2 * 3  ="<< compute(2 , 3 , '4')<<std::endl;  //calling multiply

    return 0;
}

