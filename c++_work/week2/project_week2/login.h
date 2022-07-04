#include<string>
class Login
{
    private:
        std::string userName;
        std::string password;

    public:

        Login()
        {
            userName = "huzaifa";
            password = "root";
        }

        bool authencateUser(std::string enteredUserName , std::string enteredPassword)
        {
            if (userName == enteredUserName && password == enteredPassword)
            {
                return true;
            }
            return false;
        }

        // void encrypt(std::string pass)
        // {
        //     Botan::initializationvector
        // }
                
};