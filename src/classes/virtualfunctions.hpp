#ifndef VIRTUALFUNCTIONS_H_
#define VIRTUALFUNCTIONS_H_

#include <iostream>
#include <ostream>
#include <memory>

using namespace std;

class Shape
{
public:
    Shape() {}
    virtual ~Shape ( ) {}

    virtual void draw(int x, int y)
    {
        cout << "Shape::draw(): " << x << ", " << y << endl;
    }

private:
    Shape (const Shape&);
    Shape& operator=(const Shape&);
};

class Polygon : public Shape
{
public:
    virtual void draw ( int x, int y ) override
    {
        cout << "Polygon::draw(): " << x << ", " << y << endl;
    }
};

class Evilgon : public Shape
{
public:
    // Here we define new function draw (shadowing draw() from Shape), because
    // of different types of function arguments
    virtual void draw ( double x, double y )
    {
        cout << "Evilgon::draw(): " << x << ", " << y << endl;
    }
};

// If we put "final" here, we would declare that class Triangle is final
// derived class and we can't create another class (like BermudaTriangle),
// which will inherit Triangle.
class Triangle /*final*/ : public Polygon
{
public:

    // If we put "final" here (with or without override), we declare that
    // this overriding of function is final and we can't override it again in
    // child class of Triangle (BermudaTriangle in this example)
    virtual void draw ( int x, int y ) /*final*/ override
    {
        cout << "Triangle::draw(): " << x << ", " << y << endl;
    }
};

class BermudaTriangle : public Triangle
{
public:
    virtual void draw ( int x, int y ) override
    {
        cout << "BermudaTriangle::draw(): " << x << ", " << y << endl;
    }
};

class Base
{
public:
    Base ( ) {     }
    virtual ~Base ( ) { }

    // Interface function
    void draw ( int x, int y )
    {
        cout << "Start of interface method Base::draw()" << endl;

        // Function (or functions) that do real work
        do_draw ( x, y );

        cout << "Exit Base::draw()" << endl;
    }

private:
    // abstract virtual function for real functionality of method draw
    virtual void do_draw ( int x, int y ) = 0;

    Base ( const Base& );
    Base& operator=( const Base& );
};

class Derived : public Base
{
public:
    virtual void do_draw (int, int)
    {
        cout << "In Derived::do_draw() doing real work" << endl;
    }
};

void StartVF()
{
    shared_ptr<Shape> shape = make_shared<Polygon>();
    shape->draw(11, 12);

    shape = make_shared<Evilgon>();

    // Error - calling method Shape::draw(), but not Evilgon::draw();
    // To block this error write virtual methods in derived classes like this:
    // virtual void func(...) override {...}
    // Special word override signals to compiler to carefully check this
    // function
    shape->draw (33, 44);

    shared_ptr<Base> base = make_shared<Derived> ( );
    base->draw ( 12, 13 );
}

#endif /* VIRTUALFUNCTIONS_H_ */
