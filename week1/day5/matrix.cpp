#include<iostream>

#define m 5
#define n 4
#define p 2

int main()
{
	int a[m][n];
	int b[n][p];
	int c[m][p];
	
	// filling up first array
	for (int i =0; i<m; i++)
	{
		for (int j =0; j < n; j++)
		{
			a[i][j] = 1;
		}
	}
	

	// filling up 2nd array
	for (int i =0; i<n; i++)
        {
                for (int j =0; j < p; j++)
                {
                        b[i][j] = 1;
                }
        }

	// intializing 3rd array
        for (int i =0; i<m; i++)
        {
                for (int j =0; j < p; j++)
                {
                        c[i][j] = 0;
                }
        }


	if (n == n) // check if the matrices can multiplied or not (question requirement that's why i put this :P  in case we dealing with user input and we dont know sizes of matrices then condition come into play and we will size of to computer sizes and compare them
	{
	
		//Multiplication
		for ( int i =0; i< m; i++)
		{
			for (int j = 0; j < p; j++)
			{
				for (int k =0; k < n; k++)
				{
					c[i][j] = c[i][j] + a[i][k] * b[k][j];
				}
			}
		}
	}
	else
	{
		std::cout<<"cannot be mutitplied the number of culomns in first must equal to number of rows in 2nd to get cross product"<<std::endl;
	}

	// printing
	
	int temp = 0;
	int i =0;
	while(true)
	{

		
		for (int j =0; j < n; j++)
		{
			if (i < m)
				std::cout<<a[i][j]<<" , ";
			else
				std::cout<< "    ";

		}
		
		std::cout<<"     :      ";
		for (int j = 0; j<p; j++)
                {
                        if (temp < n)
                                std::cout<<b[temp][j]<<" , ";
                        else
                                std::cout<< "    ";

                }



		std::cout<<"     :      ";		
		for (int j =0; j < p; j++)
             	{
			if (i < m)
                       		std::cout<<c[i][j]<<" , ";
			else
				std::cout<< "    ";
                }
		
		std::cout<<std::endl;

		i++;
		temp++;

		if (i > m && temp > n)
		{
			break;
		}
        }

}

