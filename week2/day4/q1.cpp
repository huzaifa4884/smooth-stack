#include<iostream>

class Grade {
    private:
        char arr[4] {'D','C','B','A'};
    public:
        char grade(const int&& score) {
            int index = score/10;
            return arr[index-1];  // hardcoded fix this
        }
};
int main()
{

    int score[4] = { 40 , 30 , 20, 20 };
    Grade g;
    for (unsigned i =0; i< sizeof(score)/sizeof(score[0]); i++)
    {
        std::cout<<g.grade(score[i] + 0)<<std::endl;
    }
    
    return 0;
}
