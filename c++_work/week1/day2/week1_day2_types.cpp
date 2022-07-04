#include<iostream>

int main()
{

	int a;
	double b;
	char c;

	std::cin>>a;
	std::cin>>b;
	std::cin>>c;

	std::cout<<"printing sizes below"<<std::endl;
	std::cout<<sizeof(a)<<std::endl;
	std::cout<<sizeof(b)<<std::endl;
	std::cout<<sizeof(c)<<std::endl;

	return 0;

}
