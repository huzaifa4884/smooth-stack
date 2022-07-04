#include<iostream>
#include<string>
#include <fstream>
// #include "login.h"
#include "Account.h"
#include "Transactions.h"
#include "transactions.pb.h"

models::Transactions transactions;

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
void displayTransactions() 
{
    Transactions t;
    t.displayTransactions(transactions);
}

void createTransaction() 
{
    std::string accNum;
    int type;
    int amnt;
    Account a;
    std::string types[] = {"Debit", "Credit"};

    std::cout << "Enter Your account number : ";
    std::cin >> accNum;

    std::cout << "Enter Transaction Type (0 for debit, widrawl of cash) (1 for credit, deposting cash) : ";
    std::cin >> type;

    if(type > 1) {
        std::cout << "[ERROR] Invalid transaction type !! \nAbort !!\n";
        return;
    }

    std::cout << "Enter amount : ";
    std::cin >> amnt;

    double balance = a.getBalance(accNum);
    if( balance == -1 ) 
    {
        std::cout << "Account Number Not Found"<<std::endl;
        return;
    }
    else
    {
        Transactions t;
        transactions = t.addTransaction(amnt , balance , accNum , type , transactions);
       
    }

    // check for balance
    /// doooont know how 
    // TODO : ^


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
        std::cout<<"6. Create Transaction" << std::endl;
        std::cout<<"7. Display Transaction" << std::endl;
        
        std::cout<<"8. Quit"<<std::endl;
        
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
            createTransaction();
            break;
            
        case 7:
            displayTransactions();
            break; 
        case 8:
            return;
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

    std::string transactionFile = "transactions";
    std::fstream input(transactionFile, std::ios::in | std::ios::binary);  
    if (!input) {
      std::cout << transactionFile << ": File not found.  Creating a new file." << std::endl;
    } else if (!transactions.ParseFromIstream(&input)) {
          std::cerr << "Failed to parse address book." << endl;
    //   return -1;
    }
    dashBoard();


    {
    // Write the new address book back to disk.
    std::fstream output(transactionFile, std::ios::out | std::ios::trunc | std::ios::binary);
    if (!transactions.SerializeToOstream(&output)) {
      std::cerr << "Failed to write address book." << endl;
    }
  }
    return 0;
}
