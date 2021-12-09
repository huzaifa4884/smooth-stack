#include <iostream>
#include <cstring>

int main()
{
    void *ptr[3]; //always intiate with 2*n size one index for type
    char *type[3];
    
    //below are my inputs
    int i = 12;
    float a = 13.5;
    double b = 14.98374982;
    
    type[0] = (char*) typeid(i).name();
    type[1] = (char*) typeid(a).name();
    type[2] = (char*) typeid(b).name();
    
    
    memcpy(ptr + 0, &i, sizeof i);
    memcpy(ptr + 1 , &a, sizeof a);
    memcpy(ptr + 2 , &b, sizeof b);
    
    
    
    for (int i =0; i<3; i++)
    {
        if (*type[i] == 'i')
        {
            std::cout<< *reinterpret_cast<int*>(ptr + i)<<std::endl;
        }
        
        else if (*type[i] == 'f')
        {
            std::cout << *reinterpret_cast<float*>(ptr + i)<<std::endl;
        }
        
        else if (*type[i] == 'd')
        {
            std::cout << *reinterpret_cast<double*>(ptr + i) <<std::endl;
        }
    }
    return 0;
    
    
}

//yes

