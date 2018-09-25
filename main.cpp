#include <iostream>

using namespace std;

class Shape {
   public:
      virtual int getArea() = 0;
      void setWidth(int w) {
         width = w;
      }

      void setHeight(int h) {
         height = h;
      }

      Shape(int w = 0, int h = 0) {
          cout << "Shape constructor" << endl;
          width = w;
          height = h;
      }

      virtual ~Shape() {
          cout << "Shape destructor" << endl;
      }

   protected:
      int width;
      int height;
};

class Rectangle: public Shape {
   public:
      Rectangle(int w = 0, int h = 0):Shape(w, h) { }
      ~Rectangle() {
          cout << "Rectangle destructor" << endl;
      }
      int getArea() {
         return (width * height);
      }
};

class Triangle: public Shape {
   public:
      Triangle(int w = 0, int h = 0):Shape(w, h) { }
      ~Triangle() {
          cout << "Triangle destructor" << endl;
      }
      int getArea() {
         return (width * height)/2;
      }
};

int main(void) {
   Shape *shape;

   shape = new Rectangle(5, 7);

   cout << "Total Rectangle area: " << shape->getArea() << endl;
   delete shape;

   Triangle tri(5, 7);
   shape = &tri;

   cout << "Total Triangle area: " << shape->getArea() << endl;

   return 0;
}