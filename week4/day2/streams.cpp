#include<sstream>
#include<string>
#include<iostream>
#include<cassert>
#include<bitset>
#include<vector>
//convertors
std::string toHex(std::string num)
{
    int temp;
    std::stringstream ss;
    ss << num;
    ss >> temp;
    
    ss.str("");
    ss.clear();
    
    ss << std::hex << temp;
    return ss.str();
}
//overloaded for integer argument
std::string toHex(int num)
{
    std::stringstream ss;
    ss << std::hex << num;
    return ss.str();   
}

int hToInt(std::string hexstr)
{
    int temp;
    std::stringstream ss;
    ss << std::hex << hexstr;
    ss >> temp;
    return temp;
}
int bToInt(std::string binstr)
{
    unsigned int temp;
    temp = std::bitset<32>(binstr , 2).to_ulong();
    return temp;
}

std::string iToBinary(std::string num)
{
    int temp;
    std::stringstream ss;
    ss << num;
    ss >> temp;
    std::bitset<32> bin(temp);
    std::cout << bin << std::endl;
    return "";
}
void iToBinary(int num)
{
    std::stringstream ss;
    std::bitset<32> bin(num);
    std::cout << "0b" << bin <<std::endl;
}

bool checkHexIntegrity(std::string str)
{
    for (unsigned i =2; i< str.length(); i++)
    {
        if ((int)str[i] < 48 || ( (int)str[i] > 57 && (int)str[i] < 65 ) || ( (int)str[i] > 90 && (int)str[i] < 97 ) || (int)str[i] > 122)
        {
            return false;
        } 
    }
    return true;
}

void dashBoard()
{
    std::string cmd ,  temp;
    std::vector<std::string> expr;
    //dashboard
    int sum;
    while (true)
    {
        std::cout << "Prompt > ";
        std::getline(std::cin , cmd); // getting input here
        if (cmd == "quit")
            break;
        std::istringstream is(cmd);
        cmd = ""; 
        //parsing input
        while(!is.eof())
        {
            is >> temp;
            if (temp == "bin" || temp == "hex")
            {
                cmd = temp;
                continue;
                std::cout<< "continue didn't skip" << std::endl;

            }
            //check if number is hex and check wrong patern
            if (temp[1] == 'x')
            {
                if (!checkHexIntegrity(temp))
                {   
                    std::cout << "worng input Patern" <<std::endl;
                    break;
                }

                expr.push_back(temp);
                continue;
            }
            //check if number is binary and check wrong patern
            else if (temp[1] == 'b')
            {
                std::cout<<"wil push_back here:" << std::endl;
                continue;
            }
            expr.push_back(temp);
        }
        
        //**************** calculations****************
        sum = 0;
        for (unsigned i =0; i < expr.size(); i++)
        {
            if (expr[i][1] == 'x')
                sum += hToInt(expr[i]);
            if (expr[i][1] == 'b')
                sum += bToInt(expr[i]);
            if (expr[i] != "+")
                sum += std::stoi(expr[i]);   
        }
        
        if (cmd == "hex")
        {
            std::cout <<"0x" + toHex(sum) << std::endl;
            continue;
        }
        
        if (cmd == "bin")
        {
            iToBinary(sum);
            continue;
        }
        
        expr.clear();
    }
}

int main()
{
    std::string str;
    int num = 20;
    std::stringstream ss;
    ss << num;
    str = ss.str();
    std::cout << str << std::endl;
    
    dashBoard();
    //std::cout << toHex("942") << std::endl;
    //std::cout << hToInt("0x3ae") << std::endl;
    //std::cout << bToInt("0b100") << std::endl;
    //std::cout << iToBinary("4") <<std::endl;
}
