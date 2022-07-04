#include<iostream>
#include<vector>
#include<thread>
#include<mutex>

//just comment out the comment out the mutex lock and unlock program will give an error double free() but some times it will run this problem arise when we use vectors it doesn't arise with arrays
//mutex solves the problem

std::vector<int> nums;
std::mutex mtx;

int calc(int n) 
{ 
    if (n%2 == 0)
        return n/2; 
    else 
        return n*3 + 1; 
}

void work()
{

    unsigned int size = nums.size();
    while( true )
    {
        if ( nums[size-1] == nums[size-4] && nums[size-2] == nums[size-5] && nums[size-3] == nums[size-6] )
        {
            break;
        }
        mtx.lock();
        nums.push_back(calc(nums.back()));
        mtx.unlock();
        size = nums.size();
    }
}


int main()
{
    nums.push_back(11);
    for (unsigned int i = 0; i<6; i++)
    {    
        nums.push_back(calc(nums.back()));
    }

    std::thread t1(work);
    std::thread t2(work);

    t1.join();
    t2.join();
    for (unsigned int i =0; i<nums.size(); i++)
    {
        std::cout << nums[i] << " , ";
    }
    std::cout << std::endl;
    return 0;
}
