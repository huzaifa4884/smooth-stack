#include<iostream>

struct base{};
struct EUR{};
struct POUND{};
struct RS{};

template <class mytype>

class Account
{
    private:
        mytype amt;
    
    public: 
        Account(mytype amt)
        {
            this->amt = amt;
        }
        
        template <typename Q>
        mytype withdraw(Q q , double amt)
        {
            this->amt -= currencyChange(q , amt);
            return this->amt;
        }
        template <typename Q>
        mytype deposit(Q q ,double amt)
        {
            this->amt += currencyChange(q , amt);
            return this->amt;
        }

        void print()
        {
            std::cout << amt << std::endl;
        }
        
        mytype currencyChange(EUR e , double amt)
        {
            typeid(e).name();
            return amt * 1.14;
        }
        mytype currencyChange(POUND e , double amt)
        {
            std::cout << "pund function called " << std::endl;
            typeid(e).name();
            return amt * 1.37;
        }
        mytype currencyChange(RS e , double amt) 
        {
            typeid(e).name();
            return amt * 0.0057;
        }
        mytype currencyChange(base e , double amt)
        {
            typeid(e).name();
            return amt;
        }
        
        template <typename Q>
        bool operator > (Account &a)
        {
            // i can't think of any senerios when ill be given amoutn in another currency since its the class object we compare
            if (this->amt > a.amt)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        //template <typename Q>
        //i cant compare with other then base for example sent euro as Rvalue and i had to oveload operator for that but i can separate functions for that
        // bool operator >(mytype &&amt , Q q)
       // {
       //     if (this->amt > currencyChange(q , amt))
       //     {
       //         return true;
       //     }
       //     else
       //     {
       //         return false;
       //     }
       // }


};


int main()
{
    POUND e;
    std::cout << typeid(e).name() << std::endl;
    Account <double>a(10000);
    a.withdraw(e , 2000);
    a.deposit(e , 2000);
    a.print();
}
