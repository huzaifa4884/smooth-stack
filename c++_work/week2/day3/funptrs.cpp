
#include <iostream>
#include <cassert>

int (*funpt[3])(int , int);

bool getBit(unsigned char byte, int position) // position in range 0-7
{
    return (byte >> position) & 0x1;
}

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

int compute(int x , int y , unsigned char funcmask)
{
    funpt[0] = &add;
    funpt[1] = &substract;
    funpt[2] = &multiply;

    bool b1 = getBit(funcmask , 0);
    bool b2 = getBit(funcmask , 1);
    bool b3 = getBit(funcmask , 2);

    if (b1)
    {
        return (*funpt[0])(x , y);
    }
    else if (b2)
    {
        return (*funpt[1])(x , y);
    }
    else if (b3)
    {
        return (*funpt[2])(x , y);
    }

    return 0;
}

int main()
{
    std::cout<<"calling add 2 + 3  =" << compute(2 , 3 , '1')<<std::endl; //calling add
    std::cout<<"calling add 2 - 3  ="<< compute(2 , 3 , '2')<<std::endl; //calling substract
    std::cout<<"calling add 2 * 3  ="<< compute(2 , 3 , '4')<<std::endl;  //calling multiply

    return 0;
}

