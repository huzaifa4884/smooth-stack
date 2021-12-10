#include <iostream>

int main(void)
{
    int x = 1;
    float y = 1.0;
    char c = '1';
    bool t = 1;
    
    std::cout << "int + float" << " = " <<  typeid(x + y).name() << std::endl;
    std::cout << "int + bool" << " = " <<  typeid(x + t).name() << std::endl;
    std::cout << "int + char" << " = " <<  typeid(x + c).name() << std::endl;
    
    std::cout << "float + char" << " = " <<  typeid(y + c).name() << std::endl;
    std::cout << "float + bool" << " = " <<  typeid(y + t).name() << std::endl;
    
    
    std::cout << "char + bool" << " = " <<  typeid(c + t).name() << std::endl;
    
}

