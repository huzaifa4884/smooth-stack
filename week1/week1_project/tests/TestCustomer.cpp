#include "../Customer.h"
#include <string>
#include <iostream>

using namespace std;

void testCreateCutomer(string fname , string lname , string ssn , string expected)
{
    if (expected == Customer::createCutomer(fname , lname , ssn))
    {
        cout<<"test Passed"<<endl;
    }
    else
    {
        cout<<"test Failed"<<endl;
    }
}

void testGetSsn(string name , string expected)
{

    Customer cs;
    if (expected == cs.getSsn(name))
    {
        cout<<"test Passed"<<endl;
    }
    else
    {
        cout<<"test failed"<<endl;
    }
} 
int main()
{
    testCreateCutomer("SomeoneF" , "SomeoneL" , "123456789" , "Customer Successfully Added");
    testCreateCutomer("Huzaifa" , "Afridi" , "123-12-1234" , "Customer Already exist");
    testCreateCutomer("Huzaifa" , "Afridi" , "123-12-1234" , "Customer Already exist");


    cout<<"testing get  (overloaded)   getssn()"<<endl;
    testGetSsn("Huzaifa Afridi" , "123-12-1234");
    testGetSsn("somename some" , "");

    return 0;
}
