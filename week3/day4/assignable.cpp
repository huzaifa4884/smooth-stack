#include <iostream>
#include <type_traits>
#include <cassert>

struct A 
{
    int a;
    float b;

};
struct B 
{ 
    B& operator= (const B&) = delete; 
};
struct C
{
    int a;
    float b;

    C& operator =(C &&obj)
    {
        a = obj.a;
        b = obj.b;
        return *this;
    }
};
struct D
{
    int a;
    float b;

    D& operator = (D obj)
    {
        a = obj.a;
        b = obj.b;
        return *this;
    }
};
int main() 
{
  std::cout << std::boolalpha;
  std::cout << "is_copy_assignable:" << std::endl;
  std::cout << "int: " << std::is_copy_assignable<int>::value << std::endl; //int is copy assignable 
  std::cout << "A: " << std::is_copy_assignable<A>::value << std::endl;     //A is copy assignable we have default copy assignment operator which added by compiler
  std::cout << "B: " << std::is_copy_assignable<B>::value << std::endl;     //B is not copy assignable i deleted its assignment fucntion which is added by compiler
  std::cout << "C: " << std::is_copy_assignable<C>::value << std::endl;     //here i added mov assignment operator i overloaded = once i need to add one for copy assignment as well i this case compiler will not add automatically
  std::cout << "D: " << std::is_copy_assignable<D>::value << std::endl;     //this case copy assignable since i added it
  
  A a;
  a.a = 4;
  a.b = 4.5;
  A a1 = a; 
  assert(a.a == a1.a && a.b == a1.b);
  // B and C classes cannot copy i dont how to assert
  return 0;
}




















