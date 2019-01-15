//
//  main.cpp
//  Lab2 MichaelGallegos
//
//  Created by Michael Gallegos on 9/3/18.
//  Copyright © 2018 Michael Gallegos. All rights reserved.
//

#include <iostream>
using namespace std;


struct Point {
    
    int x;
    int y;
    Point (int _x, int _y){
        //_x and _y
        x = _x;
        y = _y;
    };
    
    Point& operator=(const Point& p){
        x = p.x;
        y = p.y;
        return *this; //assigning the new X value equals the new object's x value
    }
};

class Shape {
protected:
    Point p;
public:
    Shape(Point p) : p(p) {}
    virtual void Print() {
        
    };
    
};

class Circle: public Shape {
    /*
     * Give it a radius member.
     * Give it a public constructor.
     *   in this constructor, make sure to assign the point member
     *   that is defined in the superclass (Shape)
     * Override the virtual func you defined in Shape
     */
protected:
    float m_radius;
public:
    Circle(Point p, float r) : Shape(p),
    m_radius(r) {}
    
    void Print(){
        /*draw circle of radius r*/
        cout << "Circle of radius " << m_radius << " at point " << p.x << "," << p.y << endl;
    };
};

class Square: public Shape {
protected:
    float m_side;
public:
    Square(Point p, float sideLength) : Shape(p), m_side(sideLength) {}
    
    void Print(){
        cout << "Square of side length " << m_side << " at point " << p.x << "," << p.y << endl;
    };
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    
    Circle *ci = new Circle(Point(3, 5), 3.0);
    ci->Print();
    Square *sq = new Square(Point(1, 2), 4.0);
    sq->Print();
    
    Shape *sh = new Shape(Point(1, 5));
    sh->Print();

    
    return 0;
}
