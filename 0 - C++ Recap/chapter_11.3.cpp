// Chapter 11: Friends, Overloaded Operators and Arrays in Classes
// Chapter 11.3: Arrays and Classes

#include <iostream>

using namespace std;

// Using structs with arrays
struct WindInfo
{
    char direction;
    double velocity;
};

// Using classes with arrays
class Money
{
public:
    friend Money operator+(const Money &amount1, const Money &amount2); // Returns the sum of the values of amount1 and amount2.
    friend Money operator-(const Money &amount1, const Money &amount2); // Returns amount1 minus amount2.
    friend Money operator-(const Money &amount);                        // Returns the negative of the value of amount.
    friend bool operator==(const Money &amount1, const Money &amount2); // Returns true if amount1 and amount2 have the same value; false otherwise.
    friend bool operator<(const Money &amount1, const Money &amount2);  // Returns true if amount1 is less than amount2; false otherwise.

    Money(long dollars, int cents);
    Money(long dollars);
    Money();
    friend istream &operator>>(istream &ins, Money &amount);        // Overloads the >> operator so it can be used to input values of type
    friend ostream &operator<<(ostream &outs, const Money &amount); // Overloads the << operator so it can be used to output values of type //Money. Precedes each output value of type Money with a dollar sign.
private:
    long allCents;
};

int main()
{

    WindInfo dataPoint[10]; // An array of 10 WindInfo structs

    // Initializing the array by looping through it
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter velocity for " << i << " numbered data point: ";
        cin >> dataPoint[i].velocity;
        cout << "Enter direction for that data point"
             << " (N, S, E, or W): ";
        cin >> dataPoint[i].direction;
    }

    // Displaying the array by looping through it
    for (int i = 0; i < 10; i++)
    {
        cout << "Wind data point number " << i << ": \n"
             << dataPoint[i].velocity << " miles per hour\n"
             << "direction " << dataPoint[i].direction << endl;
    }

    Money amount[5], max; // An array of 5 Money objects
    int i;
    cout << "Enter 5 amounts of money:\n";
    cin >> amount[0];
    max = amount[0];
    for (i = 1; i < 5; i++)
    {
        cin >> amount[i];
        if (max < amount[i])
            max = amount[i];
        // max is the largest of amount[0], . . ., amount[i]. }
        Money difference[5];
        for (i = 0; i < 5; i++)
            difference[i] = max - amount[i];
        cout << "The highest amount is " << max << endl;
        cout << "The amounts and their\n"
             << "differences from the largest are:\n";
        for (i = 0; i < 5; i++)
        {
            cout << amount[i] << " off by " << difference[i] << endl;
        }

        return 0;
    }
}

Money::Money(long dollars, int cents)
{
    if (dollars * cents < 0)
    {
        cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }
    allCents = dollars * 100 + cents;
}

Money::Money(long dollars) : allCents(dollars * 100)
{
}

Money::Money() : allCents(0)
{
}

// You can also use arrays as member variables in structs and classes
// If you use it in classes, use accessors and mutators to access and change the array