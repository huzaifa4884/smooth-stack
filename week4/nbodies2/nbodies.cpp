#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<bits/stdc++.h>
#include<chrono>

double G = 6.673e-11;
double timeStep = 0.001;
double initialMass = 1.0;
double k = 100;
int N = 100;
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
    double *opForce;
    double totalForce;
    double acceleration;
};



int main()
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

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
                bodies[i].opForce[j] = 0;
            }
            else
            {
                double temp = rij(bodies[i].r , bodies[j].r);
                bodies[i].force[j] = (G * bodies[i].mass * bodies[j].mass * temp)/ abs(pow(temp , 3));
                bodies[i].opForce[j] = -1 * bodies[i].force[j];
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
        bodies[i].opForce = new double[N];
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
    
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

   
    std::cout << k * N * N / std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
    return 0;
}
