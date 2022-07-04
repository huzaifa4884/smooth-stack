#include<iostream>
#include<vector>
#include<thread>
#include<numeric>
#include<future>
#include<cassert>


template<typename iterator , typename T>
struct accumulate_block
{
    void operator()(iterator first , iterator last , std::promise<T> &prom)
    {
        T result = std::accumulate(first , last , 0);
        prom.set_value(result);
    }
};

template<typename iterator , typename T>

T parallel_accumulate(iterator first , iterator last , T init)
{
    unsigned long const length = std::distance(first , last);
    if(!length)
    {
        return init;
    }
    unsigned long const min_per_thread = 25;
    unsigned long const max_threads = (length+min_per_thread-1)/min_per_thread;
    unsigned long const hardware_threads = std::thread::hardware_concurrency();
    unsigned long const num_threads = std::min(hardware_threads != 0 ? hardware_threads : 2 , max_threads);\
    std::cout << "num Threads: " << num_threads << std::endl;
    unsigned long const block_size = length/num_threads;
    std::vector<T> results(num_threads);
    std::vector<std::thread> threads(num_threads-1);
    iterator block_start = first;


    //future and promise vectors
    std::vector<std::promise<T>> pr(num_threads);
    //std::vector<std::future<T>> fu(num_threads); 
    //i will try not to use future vector and do pr[i].get_future().get();
    //it worked space size LEN saved and one extra loop saved


    for (unsigned long i =0; i < (num_threads -1); ++i)
    {
        iterator block_end = block_start;
        std::advance(block_end , block_size);
        threads[i] = std::thread(accumulate_block<iterator , T>(),block_start , block_end , std::ref(pr[i]));
        block_start = block_end;
    } 

    accumulate_block<iterator , T>() (block_start , last , pr[num_threads-1]);
    
    for (unsigned long i =0; i<num_threads; i++)
    {
        results[i] = pr[i].get_future().get();
    }
    for (auto &entry:threads)
    {
        entry.join();
    }
    return std::accumulate(results.begin(), results.end(),init);
}

int main()
{
    constexpr long LEN = 20000;
    std::vector<long int> myvec;
    for (long ii =0; ii<LEN; ii++)
    {
        myvec.push_back(ii);
    }
    long int sum = parallel_accumulate(myvec.begin() , myvec.end() , long(0));
    std::cout << "sum : " << sum <<std::endl;
    assert(sum == 199990000);
}
