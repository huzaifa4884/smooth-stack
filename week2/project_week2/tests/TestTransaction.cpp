#include "../Transactions.h"
#include <string>
#include <iostream>
#include "../transactions.pb.h"
#include <fstream>
#include <cassert>

using namespace std;

models::Transactions transactions;

bool testRead()
{
    std::string transactionFile = "TestFile";
    std::fstream input(transactionFile, std::ios::in | std::ios::binary);  
    if (!input) 
    {
        std::cout << transactionFile << ": File not found.  Creating a new file." << std::endl;
        return false;
    } 
    else if (!transactions.ParseFromIstream(&input)) 
    {
        std::cerr << "Failed to parse address book." << endl;
        return false;
    }
    return true;
}

bool testWrtitingToFile()
{
    // Write the new address book back to disk.
    std::string transactionFile = "TestFile";
    std::fstream output(transactionFile, std::ios::out | std::ios::trunc | std::ios::binary);
    if (!transactions.SerializeToOstream(&output)) 
    {
      std::cerr << "Failed to write address book." << endl;
      return false;
    }
    return true;
}


int main()
{
    assert(testRead()==true);
    models::Transaction *t = transactions.add_transaction();
    t->set_account("1234");
    t->set_amount(50);
    t->set_type(models::Transaction::TransactionType::Transaction_TransactionType_DEBIT);
    assert(testWrtitingToFile()==true);



}

