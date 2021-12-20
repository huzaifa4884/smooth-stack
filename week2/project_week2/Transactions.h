#include<string>
#include"transactions.pb.h"

// a transaction can only 
// be either credit or debit
enum TransactionType  {debit, credit};

struct transaction {
    // account to which transaction belongs
    int accountNumber;

    // type of transaction
    TransactionType type;

    // ammount of trnsaction
    float amount;
}; 


class Transactions {
    private: 

    public:

        Transactions() {
            // do something ? // ned to make a .proto file now
        }

        void displayTransactions(models::Transactions transactions) 
        {
            // models::Transactions transactions;
            for(int i =0; i < transactions.transaction_size(); i++) 
            {
                std::cout << "TRX : " << i << ", Account: " << transactions.transaction(i).account() << ", Type: " << transactions.transaction(i).type() << ", Ammount: " << transactions.transaction(i).amount() << std::endl;
            }
        }

        models::Transactions addTransaction(int amount , double balance , std::string accountNumber , int type , models::Transactions transactions)
        {
            if (amount > balance)
            {
                std::cout<<"Transaction Not Added reason : Insufficient Funds";
                return transactions;
            }
            // models::Transactions transactions;
            models::Transaction *t = transactions.add_transaction();
            t->set_account(accountNumber);
            t->set_amount(amount);
            if( type == 0 ) 
            {
                t->set_type(models::Transaction::TransactionType::Transaction_TransactionType_DEBIT);
            } 
            else 
            {
               t->set_type(models::Transaction::TransactionType::Transaction_TransactionType_CREDIT);
            }
            return transactions;
        }
};