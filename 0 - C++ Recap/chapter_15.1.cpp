// Chapter 15: Inheritance
// Chapter 14.2: Inheritance Basics

#include <iostream>
using namespace std;

// Inheritance is the process by which a new class—known as a derived class—is created from another class, called the base class.
// A derived class automatically has all the member variables and functions that the base class has and can have additional member functions and/or addi-tional member variables.

// Special member functions, such as constructors, destructors, and assignment operators, are not inherited.

// An Object of a Derived Class Has More Than One Type:
// An object of a derived class has two types: the type of the derived class and the type of the base class.

// Constructors in Derived Classes:
// A derived class does not inherit constructors from its base class. However, the constructors of the base class can be invoked from the constructors of the derived class.
// If you do not explicitly invoke a constructor of the base class from a constructor of the derived class, then the default constructor of the base class is invoked automatically.

// Use of Private Member Variables from the Base Class:
// A derived class does not have direct access to the private member variables of its base class.
// However, the derived class can use the public member functions of the base class to access the private member variables of the base class.

// Private Member Functions Are Effectively Not Inherited:
// A derived class does not have direct access to the private member functions of its base class.
// However, the derived class can use the public member functions of the base class to access the private member functions of the base class.

// The protected Qualifier:
// The protected qualifier is similar to the private qualifier, except that a derived class has access to protected member variables and protected member functions of its base class.

// Redefinition of Member Functions:
// A derived class can redefine a member function of its base class. This is called redefinition.
// The redefined member function in the derived class must have the same name and the same parameter list as the member function in the base class.
// The redefined member function in the derived class must have the same return type as the member function in the base class.

// Redefining Versus Overloading:
// Redefinition is different from overloading.
// Redefinition occurs when a derived class has a member function with the same name and the same parameter list as a member function in the base class.
// Overloading occurs when a class has two or more member functions with the same name but different parameter lists.

// Signatures of Functions:
// The signature of a function consists of the name of the function and the number and types of its parameters.
// If a function has the same name in a derived class as in the base class but has a different signature, that is overloading, not redefinition.

// Access to a Redefined Base Function:
// A derived class can access a redefined member function of its base class by using the scope resolution operator (::).
// But, suppose you want to invoke the version of printCheck given in the definition of the base class Employee with the derived class object sallyH as the calling object for printCheck.
// You do that as follows: sallyH.Employee::printCheck();

// Example of a base class:
class Employee
{
public:
    Employee();
    Employee(string theName, string theSSN);
    string getName() const;
    string getSSN() const;
    double getNetPay() const;
    void setName(string newName);
    void setSSN(string newSSN);
    void setNetPay(double newNetPay);
    void printCheck() const;

private:
    string name;
    string ssn;
    double netPay;
};

// * Example 1 of a derived class:
class HourlyEmployee : public Employee // The public keyword indicates that the derived class has public access to the base class.
{
public:
    HourlyEmployee();
    HourlyEmployee(string theName, string theSSN, double theWageRate, double theHours);
    void setRate(double newWageRate);
    double getRate() const;
    void setHours(double hoursWorked);
    double getHours() const;
    void printCheck(); // You only list the declaration of the inherited member function if you want to change the definition.
    // If you do not list the declaration, then the definition of the inherited member function is used.
private:
    double wageRate;
    double hours;
};

// * Example 2 of a derived class:
class SalariedEmployee : public Employee
{
public:
    SalariedEmployee();
    SalariedEmployee(string theName, string theSSN, double theWeeklySalary);
    double getSalary() const;
    void setSalary(double newSalary);
    void printCheck(); // You only list the declaration of the inherited member function if you want to change the definition.
    // If you do not list the declaration, then the definition of the inherited member function is used.
private:
    double salary; // weekly
};

int main()
{
    HourlyEmployee joe;
    joe.setName("Mighty Joe");
    joe.setSSN("123-45-6789");
    joe.setRate(20.50);
    joe.setHours(40);

    cout << "Check for " << joe.getName()
         << " for " << joe.getHours() << " hours.\n";
    joe.printCheck();
    cout << endl;

    SalariedEmployee boss("Mr. Big Shot", "987-65-4321", 10500.50);
    cout << "Check for " << boss.getName() << endl;
    boss.printCheck();

    return 0;
}

// * Implementation for the Base Class Employee:
Employee::Employee() : name("No name yet"), ssn("No number yet"), netPay(0) // Member initializer list
{
    // deliberately empty
}

Employee::Employee(string theName, string theNumber) : name(theName), ssn(theNumber), netPay(0) // Member initializer list
{
    // deliberately empty
}

string Employee::getName() const // const member function (cannot change the value of any member variables)
{
    return name;
}

string Employee::getSSN() const // const member function (cannot change the value of any member variables)
{
    return ssn;
}

double Employee::getNetPay() const
{
    return netPay;
}

void Employee::setName(string newName)
{
    name = newName;
}

void Employee::setSSN(string newSSN)
{
    ssn = newSSN;
}

void Employee::setNetPay(double newNetPay)
{
    netPay = newNetPay;
}

void Employee::printCheck() const
{
    cout << "\nERROR: printCheck FUNCTION CALLED FOR AN \n"
         << "UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n"
         << "Check with the author of the program about this bug.\n";
    exit(1);
}

// * Implementation for the Derived Class HourlyEmployee:
HourlyEmployee::HourlyEmployee() : Employee(), wageRate(0), hours(0) // * The Employee() part of the initialization list calls the default empty constructor for the base class.
{
    // deliberately empty
}

HourlyEmployee::HourlyEmployee(string theName, string theNumber, double theWageRate, double theHours)
    : Employee(theName, theNumber), wageRate(theWageRate), hours(theHours) // * The Employee(theName, theNumber) part of the initialization list calls the constructor for the base class.
{
    // deliberately empty
}

void HourlyEmployee::setRate(double newWageRate)
{
    wageRate = newWageRate;
}

double HourlyEmployee::getRate() const
{
    return wageRate;
}

void HourlyEmployee::setHours(double hoursWorked)
{
    hours = hoursWorked;
}

double HourlyEmployee::getHours() const
{
    return hours;
}

void HourlyEmployee::printCheck()
{
    setNetPay(hours * wageRate);

    cout << "\n_____________________________________________\n";
    cout << "Pay to the order of " << getName() << endl;
    cout << "The sum of " << getNetPay() << " Dollars\n";
    cout << "_____________________________________________\n";
    cout << "Check Stub: NOT NEGOTIABLE\n";
    cout << "Employee Number: " << getSSN() << endl;
    cout << "Hourly Employee. \nHours worked: " << hours
         << " Rate: " << wageRate << " Pay: " << getNetPay() << endl;
    cout << "_____________________________________________\n";
}