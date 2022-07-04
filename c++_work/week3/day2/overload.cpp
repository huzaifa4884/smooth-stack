#include<iostream>
#include<cstring>
#include<cassert>

class MyString
{
    private:
        char* str;

    public:
        MyString(): str {nullptr}
        {
            str = new char[1];
            str[0] = '\0';
        }

        MyString(char* str)
        {
            if (str == nullptr)
            {
                this->str = new char[1];
                this->str[0] = '\0';
            }
            else
            {
                this->str = new char[strlen(str)+1];
                strcpy(this->str , str);
                str[strlen(str)] = '\0';
               // std::cout<<"value constructor is called   " << this->str << std::endl;
            }
         }
        MyString(MyString &obj)
        {
            str = new char[strlen(obj.str)+1];
            strcpy(this->str , obj.str);
            str[strlen(obj.str)] = '\0';
        }

        MyString(MyString &&obj)
        {
            std::cout<<"Rvalue Constructot is called" <<std::endl;
            str = obj.str;
            obj.~MyString();
        }

        ~MyString()
        {
            str = NULL;
            delete str;
        }
        
        //******************************************overloading assignment operator********************************************
        //wasnt what to do here deep copy or shallow i went with deep
        //*********************************************************************************************************************
        void operator = (MyString &obj)
        {
            std::cout<< "Normal Assignment is called" <<std::endl;
            str = new char[strlen(obj.str)+1];
            strcpy(this->str , obj.str);
            str[strlen(obj.str)] = '\0';
        }
        
        //******************************MOV assignment operator*****************************************
        void operator =(MyString&& obj)
        {
            std::cout<< "Since i get rvalue this function is called" <<std::endl;
            this->str = obj.str;
            obj.~MyString();
        }

        
        //***************************************overloading + Operator*******************************************************
        MyString& operator +(MyString &obj)
        {
            if (obj.str[0] == '\0')
            {
                return *this;
            }
            else if (str[0] == '\0')
            {
                return obj;
            }
            else
            {
                int lenCurrent = strlen(str);
                int lenObj = strlen(obj.str);
                
                char *temp = (char*) malloc(lenCurrent + lenObj + 1); 
                strcpy(temp , str);
                strcat(temp , obj.str);

                return  *(new MyString(temp));
            }
        }
        
        MyString& operator *(int n)
        {
            if (str[0] == '\0' || n == 1)
            {
                return *this;
            }
            else if (n < 1)
            {
                MyString *s = new MyString();
                return *s;
            }
            else
            {
                char *temp = (char*) malloc( (strlen(str) * n) + 1);
                strcpy(temp , str);
                
                for(int i = 1; i < n; i++)
                    strcat(temp , str);

                return *(new MyString(temp));
            }
        }

        bool operator ==(const MyString& obj)
        {
            if (strcmp(str , obj.str) == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        
        void print()
        {
            std::cout<< str << std::endl;
        }
};

int main()
{
    char temp[] = "hello";
    MyString a(temp);
    char temp1[] = " world";
    //call to contructor asking for character pointer
    MyString b(temp1);
    std::cout<<"This is Object a ";
    a.print();
    std::cout<<"This is Object b";
    b.print();
    std::cout<<"and this after + operator" <<std::endl;
    MyString c((a + b));
    c.print();
    std::cout<<"and this after * operator"<<std::endl;
    a = (a * 3); //here it should call MyString(MyString &&obj) but it calls MyString(MyString &obj) function ??
    a.print();
    
    std::cout<<std::endl << std::endl << "forcing to call rvalue constructor" <<std::endl;
    //forcing to call rvalue constructor
    MyString st = (MyString(temp)); // so here the object in the paranthesis is temporary i dont why its not calling mov constructor
    st.print();
    
    //call to == operator
    assert(a == a);
    //a.print();
}
