#include<iostream>
#include<thread>
#include<mutex>
#include<string>
#include<vector>

struct Order
{
    std::string from , to;
    bool status;
    int amount;
    std::string currency;
};

std::vector<Order> ledger;

class Country
{
    private:
        std::string name;
        double dollars;
        double pounds;
    public:
        Country(double d , double p , std::string n)
        {
            name = n;
            dollars = d;
            pounds = p;
        }
        
        void checkRequestStatus()
        {
            unsigned temp;
            for (unsigned i =0; i<ledger.size(); i++)
            {
                if (ledger[i].from == this->name && ledger[i].currency == "Dollars")
                {
                    temp = i;
                    if (ledger[i].status == true)
                    {
                        this->dollars += ledger[i].amount;
                    }
                }
                if (ledger[i].from == this->name && ledger[i].currency == "Pounds")
                {
                    std::cout << "we are pounds here to A1" <<std::endl;
                    temp = i;
                    if (ledger[i].status == true)
                    {
                        this->pounds += ledger[i].amount;
                    }
                }
            }
            ledger.erase(ledger.begin() + temp);
        }
        void sendRequest(Order o)
        {
            std::cout << "request sent from " << o.from <<std::endl;
            ledger.push_back(o);
        }

        void entertainOrder(Order &o)
        {
            if (o.currency == "Dollars" && o.amount < this->dollars)
            {
                o.status = true;
                this->dollars -= o.amount;
            }
            if (o.currency == "Pounds" && o.amount < this->pounds)
            {
                o.status = true;
                this->pounds -= o.amount;
            }
        }

        void checkForOrders()
        {
            for (Order &i : ledger)
            {
                if(i.to == this->name)
                {
                    entertainOrder(i);
                    break;
                }
            }
        }

        void print()
        {
            std::cout << name << " $: " << dollars << "  pounds: " << pounds <<std::endl;
        }

};


Order createOrder(int val , std::string cur , std::string fromName , std::string toName)
{
    Order temp;
    temp.amount = val;
    temp.currency = cur;
    temp.from = fromName;
    temp.to = toName;
    temp.status = false;
    return temp;

}

void flow1()
{
    Country A1(2000 , 1000 , "huzaifa");
    std::cout << "A1 is sending request" <<std::endl;
    A1.sendRequest(createOrder(1000 , "pounds" , "huzaifa" , "afridi"));
    A1.checkRequestStatus();
    A1.print();
}
void flow2()
{
    Country A2(5000 , 4000 , "afridi");
    std::cout << "A2 is sending request" << std::endl;
    A2.sendRequest(createOrder(1000 , "Dollars" , "afridi" , "huzaifa"));
    A2.checkForOrders();
    A2.checkRequestStatus();
    A2.print();
}

int main()
{
    std::thread t1(flow1);
    std::thread t2(flow2);
    t1.join();
    t2.join();
}
