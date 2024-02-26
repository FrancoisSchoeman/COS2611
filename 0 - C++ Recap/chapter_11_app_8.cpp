// Appendix 8
// Overloading Operators as Member Functions

#include <iostream>

using namespace std;

// To overload the + operator as a member function, the class definition must include the following member function:
class Money
{
public:
    Money operator+(const Money &amount2);
    // The operator+ member function has one parameter of type Money.
    // The operator+ member function returns a Money object.
    // The operator+ member function is const.
    // The operator+ member function is a member of the Money class.
    // The operator+ member function is a friend of the Money class.
    // The operator+ member function is a public member of the Money class.
private:
    int all_cents;
};

int main()
{
    return 0;
}

Money Money::operator+(const Money &amount2)
{
    Money temp;

    temp.all_cents = all_cents + amount2.all_cents;

    return temp;
}

//  if you overload + as a member operator, then you cannot reverse the two arguments to +. The following is illegal:
// fullAmount = 25 + baseAmount;
// This is because 25 cannot be a calling object. Conversion of long values to type Money works for arguments but not for calling objects.
// On the other hand, if you overload + as a friend, then the following is perfectly legal:
// fullAmount = 25 + baseAmount;