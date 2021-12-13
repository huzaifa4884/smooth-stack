#include<string>

std::vector<std::string> dummyfirstNames = {"Huzaifa" , "Fname" , "khabib" , "Naruto"};
std::vector<std::string> dummylastNames = {"Afridi" , "Lname" , "gathje" , "Uzumaki"};
std::vector<std::string> ssns = {"123-12-1234" , "123-12-1234" , "123-12-1234" , "123-12-1234"};

class Customer
{
private:
    std::string firstName , LastName;
    std::string ssn;
public:
    Customer()
    {
        firstName = "";
        LastName = "";
        ssn = "";
    }

    std::string getFirstName()
    {
        return firstName;
    }

    std::string getLastName()
    {
        return LastName;
    }

    std::string getSsn()
    {
        
        return ssn;
    }

    std::string getSsn(std::string name)
    {
        std::string fName , lName;
        std::size_t pos = name.find(" ");
        fName = name.substr(0,pos);
        lName = name.substr(pos , std::string::npos);

        unsigned i = 0;
        while(!dummyfirstNames[i].empty())
        {
            if (fName == dummyfirstNames[i])
            {
                return ssns[i];
            }
        }
        return "";
    }

    static std::string createCutomer(std::string fName , std::string lName , std::string ssn)
    {
        if (fName == "" || lName == "" || ssn == "")
        {
            return "Cannot Add Empty Fields";
        }
        for(auto &i : ssns)
        {
            if (i == ssn)
            {
                return "Customer Already exist";
            }
        }

        dummyfirstNames.push_back(fName);
        dummylastNames.push_back(lName);
        ssns.push_back(ssn);

        return "Customer Successfully Added";
    }
};