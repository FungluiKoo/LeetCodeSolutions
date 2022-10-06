#include <cmath>
#include <iostream>

using namespace std;

class Shape {
public:
    virtual int getArea() = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double radius) : radius(radius) {}
    int getArea(){
        return ceil(M_PI*radius*radius);
    }
};

class Rectangle : public Shape {
protected:
    double width, height;
public:
    Rectangle(double width, double height) : 
        width(width), height(height) {}
    int getArea(){
        return ceil(width * height);
    }
};

class Square : public Rectangle {
public:
    Square(double width) : Rectangle(width, width) {}
    int getArea(){
        return ceil(width * width);
    }
};

int main(){
    Circle cir(1);
    Rectangle rec(1,2);
    Square sq(3);
    Shape *s1 = &cir, *s2 = &rec, *s3 = &sq;
    Rectangle *s4 = &sq;
    cout << s1->getArea() << "\n" << s2->getArea() << "\n" \
        << s3->getArea() << "\n" << s4->getArea() << "\n";
    return 0;
}
