#include<iostream>
#include<string>
#include "login.h"
#include "Account.h"


void showAllAccounts()
{
    
    Account a;
    for(const auto &v : a.getAllAccounts())
    {
        for (const auto &i : v)
        {
            std::cout << i << "   ,    ";
        }
        std::cout<<std::endl;
    }
    a.~Account();
}

void displayAccount()
{
    Account ac;
    std::string accNum;
    std::vector<std::string> account;

    std::cout<<"Enter the Account Number      :  ";
    std::cin>>accNum;

    account = ac.getAccountByAccountNumber(accNum);

    if(account.empty())
    {
        std::cout<<"Account Not Found"<<std::endl;
        return;
    }
    
    for (const auto &i : account)
    {
        std::cout<< i <<" , ";
    }
    std::cout<<std::endl;

    ac.~Account();
}

void searchName()
{
    Account ac;
    std::string name;
    std::cout<<"Enter Name    :  ";
    std::cin>>name;
    
    std::vector<std::string> rrs;
    rrs = ac.getAccountByName(name);

    for(auto &i : rrs)
    {
        std::cout<< i <<" , ";
    }

    std::cout<<endl;

    return;
    
}

void createAccount()
{
    Account ac;
    std::string fName , lName , ssn;
    
    std::cout<<"First Name  :  ";
    std::cin>>fName;
    std::cout<<"Last Name   :  ";
    std::cin>>lName;
    std::cout<<"Social Security Number";
    std::cin>>ssn;

    ac.createAccount(fName , lName , ssn);

}

void deleteAccount()
{
    Account ac;
    std::string accNum;
    std::cout<<"Enter the Account Number      :  ";
    std::cin>>accNum;
    ac.deleteAccount(accNum);
}
void dashBoard()
{
    unsigned choice = 0;

    while(true)
    {
        
        std::cout<<"1. Show Accounts"<<std::endl;
        std::cout<<"2. Display Account"<<std::endl;
        std::cout<<"3. Search Name"<<std::endl;
        std::cout<<"4. New Account"<<std::endl;
        std::cout<<"5. Close Account"<<std::endl;
        std::cout<<"6. Quit"<<std::endl;
        
        std::cin>>choice;
        switch (choice)
        {
        case 1:
            showAllAccounts();
            break;

        case 2:
            displayAccount();
            break;
        
        case 3:
            searchName();
            break;
        
        case 4:
            createAccount();
            break;
        
        case 5:
            deleteAccount();
            break;

        case 6:
            return ;
            
        default:
            std::cout<<"kindly select a valid choice";
            break;
        }
    }
}

int main()
{
    // std::string userName , password;
    // std::cout<<"Enter User Name    :";
    // std::cin>>userName;
    // std::cout<<"Enter Password    :";
    // std::cin>>password;

    // Login l;
    // if (l.authencateUser(userName , password) == 1)
    // {
    //     std::cout<<"Authentication Successfull";
    // }
    

    dashBoard();



    return 0;
}
