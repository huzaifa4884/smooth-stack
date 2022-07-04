#include<iostream>
#include<string>


class Person
{
	public:
		static int index;
		std::string name;
		int count;
		static Person *persons[10];


		Person(std::string name , int count = 1)
		{
			this->name = name;
			this->count = count;
			//(persons + sizeof(persons[0])) = (this);	
		}
		static Person *getPerson(std::string name , int size)
		{
			for (int i =0; i< size; i++)
			{
				if (persons[i]->name == name)
				{
					return persons[i];
				}
			}
			return NULL;
		}
		~Person()
		{
			for (int i =0; i<4; i++)
			{
				std::cout<< persons[i]->name << " : " << persons[i]->count << std::endl;
				persons[i] = NULL;
			}
		}
};
Person *Person::persons[10]{};
int Person::index = -1;

int main()
{
	std::string names[10] = {"bob", "james", "janet", "bob", "stella"};
//	Person *p;
	bool chk = true;
	int index = 0;
	
	for (int i = 0; i< 5; i++)
	{
		for (int j = 0; j < index; j++)
		{
			if (Person::persons[j]->name == names[i])
			{	
				Person::persons[j] = new Person(names[i] , 2);
				chk = false;
				break;
			}
		}
		if (chk)
		{
			Person::persons[index] = new Person(names[i]);
			index++;
		}	
		chk = true;
	}
	Person *p = NULL;	
	p = p->getPerson("bob" , index);
	std::cout<<p->name<<"  " <<p->count <<std::endl;
	
	std::cout<<"Printing name and calling distructor"<<std::endl;
	p->~Person();	
	return 0;
}
