#include<iostream>
#include<string.h>
#include<vector>

class Sentence
{
	private:
		char *sentence;
		std::vector<int> vsentence;
	public:
		Sentence(char *sent)
		{
			sentence = sent;
			int i = 0;
			vsentence.push_back(0);
			while (*(sent + i) != '\0')
			{
				if ( *(sent+i) == ' ')
				{
					vsentence.push_back(i+1);
				}
				i++;
			}
		}
		//copy constructor
		Sentence(Sentence& s)
		{
			char *temp = new char;
			//copying source to dest
			int i = 0;
			while(*(s.sentence+i) != '\0')
			{
				*(temp + i) = *(s.sentence+i);
				i++;
			}
			sentence = temp;
			this->vsentence = s.vsentence;
		}

		void operator = (const Sentence& s)
		{
			std::cout<<"operator called"<<std::endl;
			char *temp = new char;
			int i = 0;
			while(*(s.sentence+i) != '\0')
			{
				*(temp + i) = *(s.sentence + i);
				i++;
			}
			sentence = temp;
			this->vsentence = s.vsentence;
		}

		void print()
		{
			std::cout<<sentence<<std::endl;
		}

		int numWords()
		{
			return vsentence.size();
		}

		std::string getWord(int n)
		{
			std::string temp = "";
			if (n <= numWords())
			{
				for (int i = vsentence[n-1]; i < vsentence[n+1]-1; i++) 	
				{
					temp +=*(sentence + i);
					n++;
				}
			}
			else
			{
				std::cout<<"the nth word you want is greater then total number of words";
			}
			return temp;
		}

		void replace(char *sent)
		{
			sentence = sent;
			vsentence.clear();
                        int i = 0;
                        vsentence.push_back(0);
                        while (*(sent + i) != '\0')
                        {       
                                if ( *(sent+i) == ' ')
                                {
                                        vsentence.push_back(i+1); 
                                }
                                i++;
                        }

		}
		char *data()
		{
			return sentence;
		}
};

int main()
{
	Sentence s( (char *) "a quick brown fox jumps over a lazy dog");
	s.print();
	//std::cout<< s.numWords() <<std::endl;
	std::cout<< s.getWord(2) <<std::endl;
	//s.print();
	//std::cout<< s.numWords() <<std::endl;
        //std::cout<< s.getWord(2) <<std::endl;
	Sentence s2(s);
	s2.print();
	s.replace((char*) "huzaifa afridi");
	s2 = s;
	s2.print();
	std::cout<< s2.numWords() <<std::endl;
	//std::cout<< s2.getWord(1) <<std::endl;
	return 0;
}
