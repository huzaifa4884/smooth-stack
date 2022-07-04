#include<iostream>

int main()
{
	bool t[4];

        t[0] = true || true;
        t[1] = false || true;
        t[2] = true || false;
        t[3] = false || false;
	std::cout<< " ******************************** OR **********************************"<<std::endl;
	std::cout<< " True or True    =    "<<t[0] <<std::endl;
        std::cout<< " True or False   =    "<<t[1] <<std::endl;
	std::cout<< " False or True   =    "<<t[2] <<std::endl;
	std::cout<< " False or False  =    "<<t[3] <<std::endl;


	t[0] = true && true;
        t[1] = false && true;
        t[2] = true && false;
        t[3] = false && false;
	std::cout<< " ******************************** And **********************************"<<std::endl;
        std::cout<< " True And True    =    "<<t[0] <<std::endl;
        std::cout<< " True And False   =    "<<t[1] <<std::endl;
        std::cout<< " False And True   =    "<<t[2] <<std::endl;
        std::cout<< " False And False  =    "<<t[3] <<std::endl;


	t[0] = !true;
	t[1] = !false;
	std::cout<< " ******************************** And **********************************"<<std::endl;
        std::cout<< " Not True         =    "<< t[0] <<std::endl;
        std::cout<< " Not False        =    "<< t[1] <<std::endl;

	return 0;
}

