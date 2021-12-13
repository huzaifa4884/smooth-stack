#include<iostream>
#include<string>
#include "../login.h"


void testAuthenticate(std::string userName , std::string pass , bool expected)
{
    Login l;
    if (expected == l.authencateUser(userName , pass))
    {
        std::cout<<"test Passed"<<std::endl;
    }
    else
    {
        std::cout<<"Test Failed"<<std::endl;
    }
}

int main()
{

    testAuthenticate("huzaifa" , "root" , true);
    testAuthenticate("lksaj" , "root" , false);
    testAuthenticate("huzaifa" , "lshf" , false);
    testAuthenticate("" , "" , false);

    return 0;
}