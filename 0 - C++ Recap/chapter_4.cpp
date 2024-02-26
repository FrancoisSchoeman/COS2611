// Chapter 4: Overloading Functions Example

#include <iostream>

using namespace std;

static int add(int x, int y)
{
    return x + y;
}

static double add(double x, double y)
{
    return x + y;
}

int main()
{
    int a = 5, b = 6;
    double c = 5.5, d = 6.6;

    cout << "The sum of " << a << " and " << b << " is " << add(a, b) << endl;
    cout << "The sum of " << c << " and " << d << " is " << add(c, d) << endl;

    return 0;
}