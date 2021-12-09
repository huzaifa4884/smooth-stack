#include <iostream>
#include <cstring>

int main()
{
    void *ptr[3]; 		//actuall data array
    char *type[3];		//character array to keep track of data types
    
    //below are my inputs
    int i = 12;
    float a = 13.5;
    double b = 14.98374982;
    
    //filling type array with types
    type[0] = (char*) typeid(i).name();
    type[1] = (char*) typeid(a).name();
    type[2] = (char*) typeid(b).name();
    
    
    //filling data into void pointer array to keep multiple types
    memcpy(ptr + 0, &i, sizeof i);
    memcpy(ptr + 1 , &a, sizeof a);
    memcpy(ptr + 2 , &b, sizeof b);
    
    
    
    //And printing
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

//In my solution I will  YES cause i am telling data types on runtime
//i used another character pointer array to do that to keep track of types as well

//but if i want to tell the types of data from void pointer array i can never tell which type of data i am getting to make it simple i will say that there is no way to tell difference between floats and ints
//cause in memory we only 0s and 1s
