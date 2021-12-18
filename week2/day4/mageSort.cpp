#include<iostream>
#include<vector>

struct Student {
    
    std::string studentId; // studentId is unique
    int score; // between [1..100]
    
    bool comparator(Student x, Student y) // returns true if score of x is less than score of y
    {
        return (x.score < y.score) ? true : false;
    }
    
};


class MergeSort {
    private:
        Student call;
    
        //merging here
        void merge(std::vector<Student>& s , int start , int mid , int end)
        {
            std::vector<Student> temp;
            
            int i = start;
            int j = mid + 1;
            
            while (i <= mid && j <= end)
            {

    		    if (call.comparator(s[i] , s[j]))
    		    {
	    		    temp.push_back(s[i]);
		    	    ++i;
		        }
		        else
		        {
			        temp.push_back(s[j]);
			        ++j;
		        }
	        }
	        
	        while (i <= mid) 
	        {
		        temp.push_back(s[i]);
    		    ++i;
	        }

	        while (j <= end) 
	        {
		        temp.push_back(s[j]);
		        ++j;
	        }
	        
	        for (int i = start; i <= end; ++i)
	        {
		        s[i].studentId = temp[i - start].studentId;
		        s[i].score = temp[i-start].score;
	        }
        }
        
        //spliting vectors into halves below
        void mergeSort(std::vector<Student>& s ,  int start , int const end)
        {
            if (start < end)
            {
            
                //recursive part
                int mid = (start + end) / 2;
                mergeSort(s, start, mid);
                mergeSort(s, mid + 1, end);
                merge(s, start , mid, end);
            }
        }
        
    public:
        
        
        
        void sort(std::vector<Student>& students) 
        {
           this->mergeSort(students , 0 , students.size()-1);
            
        };  // don't use recursion directly here!
        
        
        
        
};

int main()
{
    std::vector<Student> s;
    s.push_back(Student{"123" , 50});
    s.push_back(Student{"234" , 70});
    s.push_back(Student{"345" , 10});
    s.push_back(Student{"567" , 100});

    MergeSort ms;
    ms.sort(s);
    
    for (unsigned i =0; i<s.size(); i++)
    {
        std::cout<<s[i].studentId<<"    "<<s[i].score<<std::endl;
    }

    return 0;
}
