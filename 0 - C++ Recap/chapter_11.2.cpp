// Chapter 11: Friends, Overloaded Operators and Arrays in Classes
// Chapter 11.2: Overloaded Operators

#include <iostream>
#include <cctype>

using namespace std;

// Overloaded operators are functions with special names.
// The operator keyword is used to declare an overloaded operator.
// The syntax for overloaded operators is similar to the syntax for overloaded functions.
// The only difference is that the keyword operator is used in the declaration of the function.
// The keyword operator is followed by the symbol for the operator being defined.
// Example:
class Money
{
public:
    friend Money operator+(const Money &amount1, const Money &amount2); // Returns the sum of the values of amount1 and amount2.
    friend bool operator==(const Money &amount1, const Money &amount2); // Returns true if amount1 and amount2 have the same value; //otherwise, returns false.
    friend Money operator-(const Money &amount1, const Money &amount2); // Returns the difference between amount1 and amount2.
    friend Money operator-(const Money &amount);                        // Returns the negative of the value of amount.
    friend ostream &operator<<(ostream &outs, const Money &amount);     // Outputs the value of amount. // Remeber the & in the parameter list.
    Money(long dollars, int cents);
    Money(long dollars);
    Money();
    double getValue() const;
    void input(istream &ins);
    void output(ostream &outs) const;

private:
    long allCents;
};

int main()
{
    Money cost(1, 50), tax(0, 15), total;
    total = cost + tax;
    cout << "cost = ";
    cost.output(cout);
    cout << endl;
    cout << "tax = ";
    tax.output(cout);
    cout << endl;
    cout << "total bill = ";
    total.output(cout);
    cout << endl;

    if (cost == tax)
    {
        cout << "Move to another state." << endl;
    }
    else
    {
        cout << "Things are okay." << endl;
    }

    return 0;
}

Money operator+(const Money &amount1, const Money &amount2)
{
    Money temp;
    temp.allCents = amount1.allCents + amount2.allCents;
    return temp;
}

bool operator==(const Money &amount1, const Money &amount2)
{
    return (amount1.allCents == amount2.allCents);
}

Money operator-(const Money &amount1, const Money &amount2)
{
    Money temp;
    temp.allCents = amount1.allCents - amount2.allCents;
    return temp;
}

Money operator-(const Money &amount)
{
    Money temp;
    temp.allCents = -amount.allCents;
    return temp;
}

ostream &operator<<(ostream &outs, const Money &amount)
{
    long positiveCents, dollars, cents;
    positiveCents = labs(amount.allCents);
    dollars = positiveCents / 100;
    cents = positiveCents % 100;

    if (amount.allCents < 0)
    {
        outs << "-$" << dollars << '.';
    }
    else
    {
        outs << "$" << dollars << '.';
    }

    if (cents < 10)
    {
        outs << '0';
    }

    outs << cents;

    return outs;
}

// Rules on Overloading Operators
// ■ When overloading an operator, at least one argument of the resulting overloaded operator must be of a class type.
// ■ An overloaded operator can be, but does not have to be, a friend of a class;
// the operator function may be a member of the class or an ordinary(nonfriend) function.(Overloading an operator as a class member is discussed in Appendix 8.)
// ■ You cannot create a new operator.All you can do is overload existing operators, such as +, −, *, /, %, and so forth.
// ■ You cannot change the number of arguments that an operator takes.For example, you cannot change % from a binary to a unary operator when you overload %; you cannot change ++ from a unary to a binary operator when you overload it.
// ■ You cannot change the precedence of an operator. An overloaded operator has the same precedence as the ordinary version of the operator. For example, x*y+z always means (x*y)+z, even if x, y, and z are objects and the operators + and * have been overloaded for the appropriate classes.
// ■ The following operators cannot be overloaded: the dot operator (.), the scope resolution operator (::), and the operators .* and ?:, which are not discussed in this book.

// Overloading unary operators
// Overloading operators such as ++x (prefix) is similar to overloading binary operators.
// We can not yet overload the x++ (postfix) operator.

// Overloading the << or >> operators
// When you overload the << or >> operators, you must be careful to return a reference (&) to the stream object.
// This is because the << and >> operators are used in expressions such as cout << x << y << z;.