// Chapter 6: I/O Streams
// Chapter 6.2: Tools for Stream I/O

#include <iostream>
#include <fstream>
#include <cstdlib> // For the exit function
#include <iomanip> // For the Manipulators (setw, setprecision, etc.)

using namespace std;

int main()
{
    ifstream inStream;
    ofstream outStream;

    // Examples of Output Formatting (incl. flags)
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    outStream.setf(ios::fixed);     // fixed is a flag that tells the stream to display numbers in fixed-point notation (normal notation instead of scientific notation)
    outStream.setf(ios::showpoint); // showpoint is a flag that tells the stream to display a decimal point and trailing zeros on decimal numbers
    outStream.precision(2);         // precision() is a member function of the ostream class that sets the number of digits to display after the decimal point

    // Other flags:
    cout.setf(ios::showpos);    // Displays a plus sign before positive numbers
    cout.setf(ios::left);       // Left-justifies the output
    cout.setf(ios::right);      // Right-justifies the output
    cout.setf(ios::internal);   // Displays the sign before the number, but after any leading zeros
    cout.setf(ios::scientific); // Displays numbers in scientific notation

    // Unset flags:
    outStream.unsetf(ios::fixed);

    // Formatting Functions
    cout.width(10); // Sets the field width to 10 characters (including the number of characters in the number)(only works with the first next output)

    // Manipulators (functions that can be used to set flags)
    cout << "Start" << setw(4) << 10 << setw(4) << 20 << setw(6) << 30;
    cout << "$" << setprecision(2) << 10.3 << endl
         << "$" << 20.5 << endl;

    // Streams as Arguments to Functions
    // Example 1:
    ifstream inStream;
    inStream.open("infile.dat");

    double next, sum = 0;
    int count = 0;

    while (inStream >> next) // The stream is used to check for the end of the file
    {
        sum += next;
        count++;
    }
    cout << "The average of the numbers in infile.dat is " << sum / count << endl;
    inStream.close();

    return 0;
}

// Streams as Arguments to Functions
// Example 2:

void makeNeat(ifstream &messyFile, ofstream &neatFile, int numberAfterDecimalpoint, int fieldWidth);

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("rawdata.dat");
    if (fin.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    fout.open("neat.dat");
    if (fout.fail())
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }
    makeNeat(fin, fout, 5, 12);
    fin.close();
    fout.close();
    cout << "End of program.\n";
    return 0;
}

// Uses iostream, fstream, and iomanip:
void makeNeat(ifstream &messyFile, ofstream &neatFile, int numberAfterDecimalpoint, int fieldWidth)
{
    neatFile.setf(ios::fixed);
    neatFile.setf(ios::showpoint);
    neatFile.setf(ios::showpos);
    neatFile.precision(numberAfterDecimalpoint);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.setf(ios::showpos);
    cout.precision(numberAfterDecimalpoint);

    double next;

    while (messyFile >> next)
    {
        cout << setw(fieldWidth) << next << endl;
        neatFile << setw(fieldWidth) << next << endl;
    }
}