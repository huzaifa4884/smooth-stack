#include <iostream>


struct myType
{
    int j;
    int k;
    void print()
    {
        std::cout << j <<"  from only print" <<std::endl;
        std::cout << k <<"  from only print" <<std::endl;
    }
    void print() const
    {
        std::cout << j <<"  from const print" <<std::endl;
        std::cout << k <<"  from const print" <<std::endl;
    }
};

int main()
{
    myType t1;
    const myType t2 = {15,16};
    
    t1.j = 12;
    t1.k = 13;
    
    t1.print();
    t2.print();
    
    

    return 0;
}
