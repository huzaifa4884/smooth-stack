#include<iostream>
#include<string>
#include <bits/stdc++.h>
#include<vector>
#include<ctime>
#include "Customer.h"

using std::cout;
using std::endl;

std::vector<std::string> dummyAccCust = {"Huzaifa Afridi" , "Bob parsons" , "Boby parson" , "Boby parsons"};
std::vector<std::string> dummyOpenDates = {"1/1/1988" , "2/2/1984", "3/3/2002" , "4/4/2015"};
std::vector<std::string> dummyAccountNumbers = {"1234" , "5678" , "9101" , "1213"};


class Account
{
private:
    std::string customerName;  
    std::string openDate;
    std::string accountNumber;
public:
    
    Account()
    {
        customerName = "";
        openDate = "";
        accountNumber = "";
    }

    std::string getCustomerName()
    {
        return customerName;
    }
    
    std::string getOpenDate()
    {
        return openDate;
    }

    std::string getAccountNumber()
    {
        return accountNumber;
    }

    std::string getSSN()
    {
        //here i will customer class and get the ssn using using customer name
        return "SSN";
    }

    std::vector<std::vector<std::string>> getAllAccounts()
    {
        std::vector<std::vector<std::string>> temp;
        temp.push_back(dummyAccCust);
        temp.push_back(dummyAccountNumbers);
        temp.push_back(dummyOpenDates);
        return temp;
    }

    std::vector<std::string> getAccountByAccountNumber(std::string accNum)
    {
        std::vector<std::string> temp;
        Customer cs;
        
        for(unsigned i =0; i<dummyAccCust.size(); i++)
        {
            
            if (accNum == dummyAccountNumbers[i])
            {   
                temp.push_back(dummyAccCust[i]);
                temp.push_back(dummyAccountNumbers[i]);
                temp.push_back(dummyOpenDates[i]);
                break;
            }
            
        }
        
        if (!temp.empty())
        {
            temp.push_back(cs.getSsn(dummyAccCust[0]));            
        }

        cs.~Customer();
        return temp;
        
    }

    int EditDistDP(std::string str1, std::string str2)
    {
        int len1 = str1.length();
        int len2 = str2.length();
    
    
        int DP[2][len1 + 1];
        std::memset(DP, 0, sizeof DP);

        for (int i = 0; i <= len1; i++)
            DP[0][i] = i;
    

        for (int i = 1; i <= len2; i++) {

            for (int j = 0; j <= len1; j++) {
        
                if (j == 0)
                    DP[i % 2][j] = i;
    
                else if (str1[j - 1] == str2[i - 1]) {
                    DP[i % 2][j] = DP[(i - 1) % 2][j - 1];
                }
    
                else {
                    DP[i % 2][j] = 1 + std::min(DP[(i - 1) % 2][j],
                                        std::min(DP[i % 2][j - 1],
                                            DP[(i - 1) % 2][j - 1]));
                }
            }
        }
  
    return DP[len2 % 2][len1];
}

    int *hamHalf(std::string str1)
    {
        std::vector<int> results;
        int temp =0;
        static int indices[3];
        for (unsigned i =0; i< dummyAccCust.size(); i++)
        {   
            
            temp = EditDistDP(str1 , dummyAccCust[i]);
            results.push_back(temp);
        }
        temp =0;
        for (unsigned i = 0; i< dummyAccCust.size(); i++)
        {
            bool chk = true;
            for (unsigned j =0; j < results.size(); j++)
            {
                if (results[i] > results[j])
                    chk = false;

            }
            if(chk)
            {
                results[i] = 1000;
                indices[temp] = (int) i;
                temp++;
            }
            chk = true;
            if(temp > 2)
                break;
        }

    return indices;
    }

    std::vector<std::string> getAccountByName(std::string name)
    {
        std::vector<std::string> temp;


        int *ind = hamHalf(name);

        for (int i = 0; i < 3; i++)
        {
            cout<<i+1 << ". "<< dummyAccCust[ind[i]]<<endl;
        }
        cout<<endl;

        int choice;
        cout<<"Select Either of them or Enter 4 To back to Homme  : ";
        std::cin>>choice;

        while(true)
        {
            switch (choice)
            {
            case 1:
                temp.push_back(dummyAccCust[ind[choice-1]]);
                temp.push_back(dummyAccountNumbers[ind[choice-1]]);
                temp.push_back(dummyOpenDates[ind[choice-1]]);
                return temp;
            case 2:
                temp.push_back(dummyAccCust[ind[choice-1]]);
                temp.push_back(dummyAccountNumbers[ind[choice-1]]);
                temp.push_back(dummyOpenDates[ind[choice-1]]);
                return temp;
            
            case 3:
                temp.push_back(dummyAccCust[ind[choice-1]]);
                temp.push_back(dummyAccountNumbers[ind[choice-1]]);
                temp.push_back(dummyOpenDates[ind[choice-1]]);
                return temp;
            
            case 4:
                return temp;
            
            default:
                cout<<"Please Enter A Valid Choice"<<endl;
                break;
            }
        }
        return temp;
    }

    bool deleteAccount(std::string accountNumber)
    {
        int i =0;
        while(!dummyAccountNumbers[i].empty())
        {
            if (dummyAccountNumbers[i] == accountNumber)
            {
                break;
            }
            i++;
        }
        int choice;
        cout<<"Press 1 to Confirm 2 to Discard  ";
        std::cin>>choice;
        if (choice == 1)
        {
            dummyAccountNumbers.erase(dummyAccountNumbers.begin() + i);
            dummyAccCust.erase(dummyAccCust.begin() + i);
            dummyOpenDates.erase(dummyOpenDates.begin() + i);
        }
        return true;
    }

    bool createAccount(std::string fName , std::string lName , std::string ssn)
    {
        //getting todays date in string formate
        time_t now = time(0);
        tm *dt = std::localtime(&now);
        std::string date = std::to_string(dt->tm_mon) + "/" + std::to_string(dt->tm_mday) + "/" + std::to_string(dt->tm_year);
        
        //generating account number
        std::string accNum = std::to_string(rand() % 8000 + 1000);
        accNum.pop_back();
        

        dummyOpenDates.push_back(date);
        dummyAccountNumbers.push_back(accNum);
        dummyAccCust.push_back(fName + " " + lName);

        Customer::createCutomer(fName , lName , ssn);

        return true;
    }
};
