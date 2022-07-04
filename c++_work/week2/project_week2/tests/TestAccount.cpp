#include "../Account.h"
#include <string>
#include <iostream>

using namespace std;


void TestDelete(string accnum , bool expected)
{
    Account ac;
    if (expected == ac.deleteAccount(accnum))
    {
        cout<<"test passed"<<endl;
    }
    else
    {
        cout<<"test failed"<<endl;
    }
}

void TestCreate(string fname ,string lname , string ssn , bool expected)
{
    Account ac;
    if (expected == ac.createAccount(fname , lname , ssn))
    {
        cout<<"test passed"<<endl;
    }
    else
    {
        cout<<"test failed"<<endl;
    }
}

void testSetBalance(std::string accNum , double amount , bool expected)
{
    Account ac;
    if (ac.setBalance(amount , accNum) == expected)
    {
        cout<<"test passed"<<endl;
    }
    else
    {
        cout<<"test failed"<<endl;
    }
}
int main()
{
    TestDelete("1234" , true);
    TestDelete("123" , false);
    TestDelete("" , false);

    TestCreate("huzaifa" , "afridi" , "" , true);
    TestCreate("huzaifa" , "" , "123-13-1234" , true);
    TestCreate("" , "afridi" , "123-13-1234" , true);
}