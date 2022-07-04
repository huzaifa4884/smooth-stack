#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<bits/stdc++.h>

double G = 6.673e-11;
double timeStep = 0.001;
double initialMass = 1.0;
double k = 100;
//int N = 2000;
struct Position
{
    float x;
    float y;
};
struct body
{
    int ind;
    double mass;
    double velocity;
    Position r;
    double *force;
    double totalForce;
    double acceleration;
};



int main()
{
    time_t start , end;
    time(&start);


   // int n = 2000;
    //auto it = [] (int a) { return a > 2 ? true : false;};
    body bodies[N];
    //lambda initializer which generates randome numbers for different fields
    auto randP = [] () { return rand() % 200 + 1;};
    auto randM = [] () { return rand() % 500 + 2000;};
    auto initvelocity = [] () { return rand()  % 100 + 400;};
    

    //expression for distance between two points
    auto rij = [] (Position r1 , Position r2) mutable { return sqrt( pow(r2.x - r1.x , 2) + pow(r2.y - r1.y , 2) * 1.0);  };
    
   //lambda for Fij
   auto Fi = [&bodies , &rij](int i) {
       for (int j =0; j<N; j++)
       {
            if (j == i)
            {
                bodies[i].force[j] = 0;
            }
            else
            {
                double temp = rij(bodies[i].r , bodies[j].r);
                bodies[i].force[j] = (G * bodies[i].mass * bodies[j].mass * temp)/ abs(pow(temp , 3));
            }
       }

   };
   auto tf = [] (double *arr) { 
       int sum = 0; for (int i =0; i<N; i++) { sum += arr[i]; } return sum;   }; 
    
    //updating force array
    //auto frc = [] (body &b) mutable { for (int j = 0; j < n; j++) { b.force[j] == G} }

    //initializtion start here
    auto ac = [] (double tf , double m) { return tf / m; };
    for (int i=0; i<N; i++)
    {
        bodies[i].ind = i;
        bodies[i].mass = randM();
        bodies[i].velocity = initvelocity();
        bodies[i].force = new double[N];
        bodies[i].r.x = randP();
        bodies[i].r.y = randP();
    }

    //finding force acceleration ttlfrfc initaly
    for (int i =0; i<N; i++)
    {
        Fi(i);
        bodies[i].totalForce = tf(bodies[i].force);
        bodies[i].acceleration = ac(bodies[i].totalForce , bodies[i].mass);
    }

    //for (int i =0; i<10; i++)
    //{
    //    std::cout <<"body number   : " <<  bodies[i].ind << std::endl;
    //    std::cout <<"body mass     : " <<  bodies[i].mass << std::endl;
    //    std::cout <<"body Velocity : " <<  bodies[i].velocity << std::endl;
    //    std::cout <<"body position : " <<  bodies[i].r.x <<  " , "  << bodies[i].r.y << std::endl;
    //    for (int j =0; j<n; j++) { std::cout << bodies[i].force[j] << " , "; }
    //    std::cout <<std::endl<<"body totalfrc : " << bodies[i].totalForce << std::endl;
    //    std::cout <<"body accelerat: " << bodies[i].acceleration << std::endl;
    //    std::cout << "***************************************************************" <<std::endl;
    //}

    //updating body state here
    for (int i =0; i<k; i++)
    {
        for (int j =0; j<N; j++)
        {
            bodies[i].velocity += timeStep * bodies[i].acceleration;
            bodies[i].r.x += bodies[i].velocity;
            bodies[i].r.y += bodies[i].velocity;

        }
    }
    time(&end);
    double ti = double(end - start)/double(CLOCKS_PER_SEC);
    std::cout <<"time take "<< std::fixed <<  ti << std::setprecision(12) <<  std::endl;

    return 0;
}
