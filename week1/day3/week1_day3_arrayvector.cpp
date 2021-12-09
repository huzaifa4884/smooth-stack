#include <iostream>
#include <vector>
#include<cassert>

int main()
{
    float arr[3] = {2.5 , 5.4 , 4.7};
    std::vector<float> v;
    
    
    for(int i = 0; i < 3; i++)
    {
        v.push_back(arr[i]);
    }
    
    
    std::cout<<std::endl<< "printing vector"<<std::endl;
    
    for(auto& i : v)
    {
        std::cout<<i << " , ";
    }
    std::cout<<std::endl;
    
    for (unsigned i =0; i < sizeof(arr)/sizeof(arr[0]) ; i++)
    {
        assert(arr[i] == v[i]);      // if even a single element failed to match assert will fail and will promp on console
    }

    return 0;
}
