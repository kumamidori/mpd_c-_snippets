#include <iostream> 
using namespace std;
 

// http://www.tutorialspoint.com/cplusplus/cpp_quick_guide.htm
// から転載。
// 6.8　仮想関数

class Shape {
   protected:
      int width, height;
   public:
      Shape( int a=0, int b=0)
      {
         width = a;
         height = b;
      }
      // 仮想関数は派生クラスで再定義できる
      virtual int area()
      {
         cout << "Parent class area :" <<endl;
         return 0;
      }
};
class Rectangle: public Shape{
   public:
      Rectangle( int a=0, int b=0)
      {
        Shape(a, b); 
      }
      int area ()
      { 
         cout << "Rectangle class area :" <<endl;
         return (width * height); 
      }
};
class Triangle: public Shape{
   public:
      Triangle( int a=0, int b=0)
      {
        Shape(a, b); 
      }
      int area ()
      { 
         cout << "Triangle class area :" <<endl;
         return (width * height / 2); 
      }
};
// Main function for the program
int main( )
{
   Shape *shape;
   Rectangle rec(10,7);
   Triangle  tri(10,5);
 
   // store the address of Rectangle
   shape = &rec;
   // call rectangle area.
   shape->area();
 
   // store the address of Triangle
   shape = &tri;
   // call triangle area.
   shape->area();
   
   return 0;
}
