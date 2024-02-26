// Chapter 10: Classes
// Chapter 10.4: Introduction to Inheritance

#include <iostream>

using namespace std;

// Inheritance is a mechanism that allows you to create a new class from an existing class. (derived class from base class)
// The new class is called a derived class, and the existing class is called a base class.
// The derived class inherits all the data members and member functions of the base class.
// The derived class can add new data members and member functions of its own.
// The derived class can also override the member functions of the base class.

// Why use inheritance?
// 1. It is a way to reuse code.
// 2. It is a way to establish a hierarchical relationship between classes.

// Types of inheritance
// 1. Single inheritance
// 2. Multiple inheritance
// 3. Multilevel inheritance
// 4. Hierarchical inheritance
// 5. Hybrid inheritance

// Example using an Automobile class as a base class and a Car class as a derived class.
class Automobile
{
public:
    Automobile(int newSpeed, int newGear) : speed(newSpeed), gear(newGear){};
    Automobile() : speed(0), gear(0){};

    void set(int newSpeed, int newGear)
    {
        speed = newSpeed;
        gear = newGear;
    };
    int getSpeed()
    {
        return speed;
    };
    int getGear()
    {
        return gear;
    };

private:
    int speed;
    int gear;
};

class Car : public Automobile // The public keyword is used to specify that the base class is public.
{
public:
    Car(int newSpeed, int newGears, int newDoors) : Automobile(newSpeed, newGears), doors(newDoors){}; // You can use the scope resolution operator to access the base class constructor.

    void set(int newSpeed, int newGear, int newDoors) // The derived class can add new data members and member functions of its own. (Overloading)
    {
        Automobile::set(newSpeed, newGear); // You can use the scope resolution operator to access the base class member functions.
        doors = newDoors;
    };

    int getDoors()
    {
        return doors;
    };

private:
    int doors;
};

int main()
{

    return 0;
}