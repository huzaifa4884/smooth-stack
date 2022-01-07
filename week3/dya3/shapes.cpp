#include<iostream>
#include<cmath>


//lets the floats that i declare represents the line
struct Point
{
    float x;
    float y;
};
class Line
{
    public:
        Point p1 , p2;
        float distance;
        Line(float x1 , float y1 , float x2 , float y2)
        {
            p1.x = x1;
            p2.x = x2;
            p1.y = y1;
            p2.y = y2;
            distance = sqrt((p2.x - p1.x) + (p2.y - p1.y)); 
        }

        float findDistance()
        {
            return sqrt((p2.x - p1.x) + (p2.y - p1.y));          
        }
};

class Polygon
{
    public:
        float *arr; //so this array is lines which at this point we dont know yet we can just Lines *lines;
        Polygon(int dimentions)
        {
            std::cout<<"Plygon -> ";
            arr = new float[dimentions];
        }

        ~Polygon()
        {
            arr = NULL;
            delete arr;
        }
};

//***************************************************Tiangle class************************************************
class Triangle : public Polygon
{
    public:
        // Triangle():Polygon(3)
        // {
        //     std::cout<< "Triangle " << std::endl;
        // }
        Triangle(float side1 , float side2 , float side3):Polygon(3)
        {
            std::cout<<"Triangle" << std::endl;
            arr[0] = side1;
            arr[1] = side2;
            arr[2] = side3;
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
//******************************************************Triangle class ends here *********************************

//**************************************this quadrilateral class starting ****************************************
class Quadrilateral : public Polygon
{
    public:
        Quadrilateral():Polygon(4)
        {
            std::cout<<"Quandrilateral -> ";
        }
};

//******************************************************qudrilateral class ends here******************************

//******************************************************Parallelogram class start here*********************************
class Parallelogram : public Quadrilateral
{
    public:
        float angle;
        Parallelogram(float ang)
        {

            std::cout<< "Parralelogram -> ";
            angle = ang;
        }
        Parallelogram(float side1 , float side2 , float angle = 60)
        {
            std::cout<< "Parrallelogram" << std::endl;
            arr[0] = side1;
            arr[1] = side2;
            arr[2] = side1;
            arr[3] = side2;
            this->angle = angle;
        }
};
//***************************************************Parallelogram class ends here**************************************

//***************************************************Ractangle class start here****************************************
class Ractangle : public Parallelogram
{
    public:
        Ractangle(float side1 , float side2):Parallelogram(90)
        {
            std::cout<< "Ractangle " <<std::endl;
            arr[0] = side1;
            arr[1] = side2;
            arr[2] = side1;
            arr[3] = side2;
        }
        float findArea()
        {
            return arr[0] * arr[1];
        }

        float findParameter()
        {
            return 2*(arr[0] + arr[1]);
        }
};
//**************************************************Ractangle class end here************************************************

//**************************************************Rhombus class start here************************************************
class Rhombus : public Parallelogram
{
    public:
        Rhombus(float side , float ang):Parallelogram(ang)
        {
            std::cout<<"Rhombus -> ";
            for(int i =0; i< 4; i++)
            {
                arr[i] = side;
            }

        }
        float findArea()
        {
            return arr[0]*arr[0];
        }
        float findParameter()
        {
            return 4*(arr[0]);
        }
};
//**************************************************Rhombus class ends here************************************************

//**************************************************Start class start here************************************************
class Square : public Rhombus
{
    public:
        Square(float side):Rhombus(side , 90)
        {
            std::cout<<"Square"<<std::endl;
        }

        float findArea()
        {
            return arr[0]*arr[0];
        }
        float findParameter()
        {
            return 4*arr[0];
        }
};
//**************************************************Rhombus ends start here************************************************

//elipse class
class Elipse
{
    public:
        float r1 , r2;
        Elipse(float s1 , float s2)
        {
            r1 = s1;
            r2 = s2;
        }

        float findArea()
        {
            return 3.14 * r1 * r2;
        }
        float findCircumference()
        {
            return 3.14 * (r1 + r2);
        }
};
//elipse class end

//circle class
class Circle : public Elipse
{
    public:
        Circle(float r):Elipse(r , r)
        {
            std::cout << "Circle " <<std::endl;
        }
        float findArea()
        {
            return 3.14 * r1 * r2;
        }
        float findCircumference()
        {
            return 3.14 * (r1 + r2);
        }

        float findDiameter()
        {
            return 2*r1;
        }


};
//**************************************Main*********************

int main()
{
    Triangle t(2 , 4 ,5);
    std::cout<<t.findParameter()<<std::endl;

    std::cout<< " Ractangle " << std::endl;
    Ractangle rt(2 , 3);
    std::cout<< "Parameter " << rt.findParameter() << "Area " << rt.findArea() << "angle " << rt.angle <<std::endl;

    Square sq(2);
    std::cout<< "Parameter " << sq.findParameter() << "Area " << sq.findArea() << "angle " << sq.angle <<std::endl;
    return 0;
}