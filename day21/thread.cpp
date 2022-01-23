#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<chrono>
#include<thread>
#include<vector>

double G = 6.673e-11;
double timeStep = 0.001;
double initialMass = 1.0;
double k = 100;
//int N = 100;



struct Position
{
    float x;
    float y;
};

auto rij = [] (Position r1 , Position r2) mutable { return sqrt( pow(r2.x - r1.x , 2) + pow(r2.y - r1.y , 2) * 1.0);  };
class Body
{
    public:
        int ind;
        double mass , velocity , *force , *opForce , totalForce , acceleration;
        Position r;
        
        Body()
        {}
        //constructor
        Body(int index)
        {
            ind = index;
            mass = rand() % 500 + 2000;
            velocity = rand() % 100 + 400;
            r.x = rand() % 200 + 1;
            r.y = rand() % 200 + 1;
            force = new double[N];
            opForce = new double[N];
            totalForce = 0;
            acceleration = 0;
        }

        //updating force array
        void Fi(Body *bd)
        {
            for (int i =0; i<N; i++)
            {
                if (bd[i].ind == this->ind)
                {
                    force[i] = 0;
                    opForce[i] = 0;
                }
                else
                {
                    double temp = rij(r , bd[i].r);
                    force[i] =  (G * mass * bd[i].mass * temp)/ abs(pow(temp , 3));
                    opForce[i] = -1 * force[i];
                }
            }
        }
        //calculating total force and acceleration
        void calcTotalFoce(Body *bd)
        {
            for(int i =0; i<N; i++)
            {
                totalForce += force[i];
                totalForce += bd[i].opForce[i];
            }
            acceleration = totalForce / mass;
        }

        static void print(Body *bodies)
        {
            for (int i =0; i<N; i++)
            {
                std::cout <<"body number   : " <<  bodies[i].ind << std::endl;
                std::cout <<"body mass     : " <<  bodies[i].mass << std::endl;
                std::cout <<"body Velocity : " <<  bodies[i].velocity << std::endl;
                std::cout <<"body position : " <<  bodies[i].r.x <<  " , "  << bodies[i].r.y << std::endl;
                for (int j =0; j<N; j++) { std::cout << bodies[i].force[j] << " , "; }
                std::cout <<std::endl<<"body totalfrc : " << bodies[i].totalForce << std::endl;
                std::cout <<"body accelerat: " << bodies[i].acceleration << std::endl;
                std::cout << "***************************************************************" <<std::endl;
            }
        }

        void updateVelocity() 
        { 
            this->velocity += timeStep * this->acceleration; 
        }
        void updatePosition() 
        {
            this->r.x += this->velocity; this->r.y += this->velocity; 
        }



        
        ~Body()
        {
            delete[] force;
            delete[] opForce;
        }
};


int main()
{
    //std::thread t(hello);
    //t.join();
    std::vector<std::thread> thrds;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    Body *bod = new Body[N];
    //intialize
    for (int i = 0; i<N; i++)
    {
        bod[i] = Body(i);
    }
   
    //calculate forces**********************************************
    
    auto fc = [&bod] (int num) { bod[num].Fi(bod); };    
        //stating threads for it
    for (int i = 0; i<N; i++)
    {
        thrds.push_back(std::thread(fc , i));
    }
        //joining threads
    for (int i =0; i<N; i++)
    {
        thrds[i].join();
    }
    thrds.clear();


    
    // calculating total force and acceleration
    auto tf = [&bod] (int num) { bod[num].calcTotalFoce(bod); };
    for (int i = 0; i<N; i++)
    {
        thrds.push_back(std::thread(tf , i));
    }
    
    for (int i =0; i<N; i++)
    {
        thrds[i].join();
    }
    thrds.clear();

    //updating positions starts from here
    auto updatePos = [&bod] () { for (int i =0; i<N; i++) { bod[i].updateVelocity(); bod[i].updatePosition(); } };
    for (int i=0; i<k; i++)
    {
        thrds.push_back(std::thread(updatePos));
    }

    for (int i =0; i<k; i++)
    {
        thrds[i].join();
    } 
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << k * N * N / std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;



    return 0;
}
