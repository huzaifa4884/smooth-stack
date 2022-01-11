#include<iostream>



class Polygon
{
    public:
        float *arr; //so this array is lines which at this point we dont know yet we can just Lines *lines;
        Polygon(int dimentions)
        {
            arr = new float[dimentions];
            std::cout<<"Plygon -> ";
        }
};

class Triangle : public Polygon
{
    public:
        // Triangle():Polygon(3)
        // {
        //     std::cout<< "Triangle " << std::endl;
        // }
        Triangle(float a , float b , float c):Polygon(3)
        {
            std::cout<<"Triangle" << std::endl;
            arr[0] = a;
            arr[1] =  b;
            arr[2] = c;
        }

        float findParameter()
        {
            float sum = 0;
            for (int i =0; i< 3; i++)
            {
                sum += arr[i];
            }
            return sum;
        }
        //and here traingle area function
};

class Quadrilateral : public Polygon
{
    public:
        Quadrilateral():Polygon(4)
        {
            std::cout<<"Quandrilateral -> ";
        }

        virtual float findArea()
        {
            return arr[0] * arr[1];
        }

        virtual float findParameter()
        {
            return 2*(arr[0] + arr[1]);
        }
};

class Parallelogram : public Quadrilateral
{
    public:
        float angle;
        Parallelogram()
        {
            std::cout<< "parallelogram -> ";
            angle = 90;
        }
        Parallelogram(float side1 , float side2)
        {
            std::cout<< "Parallelogram " <<std::endl;
            arr[0] = side1;
            arr[1] = side2;
            arr[2] = side1;
            arr[3] = side2;
        }
        float findArea() override
        {
            
            std::cout<< "Parallelogram Area Called  : ";
            return arr[0] * arr[1];
        }

        float findParameter() override
        {

            std::cout<< "Parallelogram Perimeter Called  : ";
            return 2*(arr[0] + arr[1]);
        }
};

class Ractangle : public Parallelogram
{
    public:
        Ractangle(float side1 , float side2)
        {
            std::cout<< "Ractangle " <<std::endl;
            arr[0] = side1;
            arr[1] = side2;
            arr[2] = side1;
            arr[3] = side2;
        }
        float findArea() override
        {
            std::cout<< "Ractangle Area Called  : ";
            return arr[0] * arr[1];
        }

        float findParameter() override
        {
            
            std::cout<< "Ractangle Perimeter Called  : ";
            return 2*(arr[0] + arr[1]);
        }
};


float prntA(Quadrilateral *obj)
{
    return obj->findArea();
}

float prntP(Quadrilateral *obj)
{
    return obj->findArea();
}



int main()
{
    Quadrilateral *q = new Quadrilateral();
    std::cout << std::endl;    
    Ractangle r(2 , 2);
    Parallelogram p(2 , 3);
    q = &r;
    std::cout<< prntA(q) << std::endl;
    std::cout<< prntP(q) << std::endl;

    q = &p;

    std::cout<< prntP(q) << std::endl;
    std::cout<< prntP(q) << std::endl;

}








