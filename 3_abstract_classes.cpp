// Abstract Classes and Pure Virtual Functions

#include <iostream>
using namespace std;

// Abstract classes are classes that cannot be instantiated, and are used to define the structure of derived classes.
// Abstract classes are used to provide a common interface for a set of derived classes.

// A pure virtual function is a function that is declared in the base class, but has no implementation.
// A pure virtual function is a function that must be overridden in a derived class.

// Example of an abstract class:
class Shape
{
public:
    // Pure virtual function
    virtual void draw() = 0;
};

// Derived classes
class Circle : public Shape
{
public:
    void draw()
    {
        cout << "Drawing a circle" << endl;
    }
};

class Square : public Shape
{
public:
    void draw()
    {
        cout << "Drawing a square" << endl;
    }
};

int main()
{
    // Shape shape; // This will cause an error because Shape is an abstract class
    Circle circle;
    Square square;

    circle.draw();
    square.draw();

    // You can also use a pointer to the base class to access the derived classes
    Shape *shapePtr;
    shapePtr = new Circle();
    shapePtr->draw();

    return 0;
}