#include<iostream>
#include<thread>
#include<mutex>
#include<queue>
#include<condition_variable>

template <class T>

class ThreadSafeQueue
{
    private:
        std::mutex mut;
        std::condition_variable data_cond;
        std::queue<T> que;
    public:
        ThreadSafeQueue()
        {}
        ThreadSafeQueue(const ThreadSafeQueue &obj)
        {
            std::lock_guard<std::mutex> lk(mut);
            this->que = obj.que;
        }

        bool try_pop(T &value)
        {
            std::lock_guard<std::mutex> lk(mut);
            if (que.empty())
            {
                return false;
            }
            value = que.front();
            que.pop();
            return true;
        }

        std::shared_ptr<T> try_pop()
        {
            std::lock_guard<std::mutex> lk(mut);
            if (que.empty())
            {
                return std::shared_ptr<T>();
            }
            std::shared_ptr<T> res(std::make_shared<T>(que.front()));
            que.pop();
            return res;
        }
        void push(T val)
        {
            std::lock_guard<std::mutex> lk(mut);
            std::cout << "pushing : " << val << std::endl;
            que.push(val);
            //data_cond.notify_one();
        }

};

//one thread brings in the data
void newEntries(ThreadSafeQueue<int>& que)
{
    for (int i=0; i<5; i++)
    {
        que.push(i);
    }
}

void processor(ThreadSafeQueue<int>& que)
{
   for (int i=0; i<5; i++)
    {
        if (que.try_pop(i))
            std::cout << " processed entry number : " << i << std::endl;
    }

}

void newEntriesptr(std::shared_ptr<ThreadSafeQueue<int>> &que)
{
    for (int i=0; i<5; i++)
    {
        que->push(i);
    }
}

void processorptr(std::shared_ptr<ThreadSafeQueue<int>> &que)
{
    for (int i =0; i<5; i++)
    {
        std::shared_ptr<int> ret = que->try_pop();
        if (ret)
        {
            std::cout << " processing after poping : " << *ret << std::endl;
        }
    }
}

int main()
{
    ThreadSafeQueue<int> que;
    std::thread t1(newEntries ,std::ref(que));
    std::thread t2(processor , std::ref(que));
    t1.join();
    t2.join();

    //now when i need the the value of element poped from que by using shared ptr we have
    std::shared_ptr<ThreadSafeQueue<int>> que2 = std::make_shared<ThreadSafeQueue<int>>();
   
    std::thread t3(newEntriesptr , std::ref(que2));
    std::thread t4(processorptr , std::ref(que2));

    t3.join();
    t4.join();
    return 0;
}
