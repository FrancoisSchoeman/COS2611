// Chapter 10: Classes
// Chapter 10.2: Classes

#include <iostream>

using namespace std;

// A class is a user-defined data type that can be used to group related data items of different data types (data objects).
// A class is a blueprint for creating objects.
// A class is a collection of data members and member functions.

// Creating a class
class DayOfYear
{
public:            // Access specifier
    void output(); // A member function declaration
    int month;
    int day;

private: // You can use the private access specifier to hide data from the outside world. The data can only be accessed/changed by member functions of the class.
    // Hiding variables and functions inside a class is called Encapsulation.
    int year;

}; // The semicolon is required after the closing curly brace of a class definition.

// Always try to make all member variables private, and use get and set functions to access them.
// Example:
class Bicycle
{
public:
    void set(int newCadence, int newGear, int newSpeed) // You can also define member functions inside the class definition, but this is not recommended.
    {
        cadence = newCadence;
        gear = newGear;
        speed = newSpeed;
    };
    int getCadence()
    {
        return cadence;
    };

private:
    int cadence;
    int gear;
    int speed;
};

// Accessor and Mutator functions
// Accessor functions are used to get the value of a private variable.
// Mutator functions are used to set/change the value of a private variable.

// When to use structures and when to use classes?
// Use a structure when you want to group related variables together, but you don't need any member functions.
// Use a class when you want to group related variables together, and you need member functions to manipulate the data.

// Using constructors to initialize class variables
// A constructor is a special member function that is called automatically when an object is created.
// A constructor has the same name as the class, and it does not have a return type.
// Example 1 Car class:
class Car
{
public:
    Car(int x); // Constructor declaration
private:
    int speed;
};

Car::Car(int x) // Constructor definition
{
    speed = x;
}

// Example 2 Motorcycle class:
class Motorcycle
{
public:
    Motorcycle(int x)
    { // Constructor definition
        speed = x;
    };

    Motorcycle(); // Overloading the constructor (default constructor)
    // Tip: Always use a default constructor when you have a constructor with parameters.

private:
    int speed;
};

Motorcycle::Motorcycle() : speed(0)
{
    // You can still add things here like cout << "Motorcycle created" << endl; and if-else statements.
} // Initializing the speed variable to 0 when the constructor is called without any parameters.

// Member initializers (since C++11)
class Coordinate
{
public:
    Coordinate();
    Coordinate(int x);
    Coordinate(int x, int y);
    int getX();
    int getY();

private:
    int x = 1; // You can initialize member variables in the class definition.
    int y = 2; // This is called a member initializer.
};
Coordinate::Coordinate() {}
Coordinate::Coordinate(int xVal) : x(xVal) {}
Coordinate::Coordinate(int xVal, int yVal) : x(xVal), y(yVal) {}
int Coordinate::getX()
{
    return x;
}
int Coordinate::getY()
{
    return y;
}

int main()
{

    // Creating class variables
    DayOfYear today, birthday;

    // Assigning values to class variables
    today.month = 9;
    today.day = 25;

    // Using class member functions
    today.output();

    // Assigning classes using a constructor with parameters
    Car myCar(60); // The constructor is called automatically when the object is created.

    // Assigning classes using a constructor without parameters (default constructor)
    Motorcycle myMotorcycle; // The constructor is called automatically when the object is created.

    // Re-initializing a class variable
    myMotorcycle = Motorcycle(100); // You can also assign a class using a constructor with parameters.
    // This is not recommended because it will create a new object and delete the old one, rather use a set member function.

    return 0;
}

// Defining member functions
void DayOfYear::output() // The scope resolution operator (::) is used to specify that the output function is a member of the DayOfYear class.
{
    cout << "month = " << month
         << ", day = " << day << endl;
}