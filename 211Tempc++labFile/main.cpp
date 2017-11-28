/* Fraction Class - represent a rational number as a
 *   using in integer numerator and integer denominator
 *
 * data members (also called "instance variables")
 *   num - the integer numerator part of the fraction
 *   den - the integer denominator part of the fraction
 *
 * Restrictions of the class
 * - the denominator should never be a value of 0
 * - the denominator should never be negative
 * - the fraction should be reduced to its lowest terms
 *
 *
 *
 * The class definition for the Fraction class contains only
 *   method prototypes.  The actual code for each method is
 *   writen outside/after the class definition.
 *
 *   This usage requires the scope resolution operator ::
 *
 *   Writing code in this style is preferred because:
 *    1. The methods of the class can be determined quickly
 *         when looking at the class definition
 *    2. This is needed when writting C++ header files
 *         the .h file contains the class definitions (Fraction.h)
 *         the .cpp file contains the code for the methods (Fraction.cpp)
 */

// if breaking into multiple source code files, Fraction.h would start here

#include <cstdio>

class Fraction
{
private:
    int num;
    int den;

    // note the Fraction Class has three private methods
    void normalize();
    void reduce ();
    static int greatestCommonDivisor (int a, int b);

public:
    Fraction ();
    Fraction (int val);
    Fraction (int val1, int val2);

    bool equals (Fraction f2);
    Fraction add (Fraction f2);
    char* toStr (char* buf);
};

// if breaking into multiple source code files, Fraction.cpp would start here
//   you would need into include the line of code: #include "Fraction.h"

// note that normalize is a private method
void Fraction::normalize()
{
    if ( den < 0 )
    {
        num = -num;
        den = -den;
    }
}


// note that reduce is private method
void Fraction::reduce ()
{
    int a = num;
    int b = den;

    // take the absolute value of both a and b (make sure a and b are postive numbers)
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;

    int gcd = greatestCommonDivisor (a, b);

    num = num / gcd;
    den = den /gcd;
}

// note that greatestCommonDivisor is a private method
int Fraction::greatestCommonDivisor (int a, int b)
{
    // computer Greatest Common Divisor recursively via Euclid's algorithm
    if (b == 0)
        return a;
    else
        return greatestCommonDivisor (b, a%b);
}

// default constructor: set fraction to 0/1
Fraction::Fraction ()
{
}

// Single integer Constructor: set fraction to val/1
Fraction::Fraction (int val)
{
}

// Double integer Constructor: set fraction to val1/val2
Fraction::Fraction (int val1, int val2)
{
    if ( val2 == 0 ) // verify that den is not zero
    {                //   if so, set to 0/1
        num = 0;
        den = 1;
    }
    else
    {
        num = val1;
        den = val2;
        normalize();
        reduce();
    }
}

// method equals() of the Fraction class
bool Fraction::equals (Fraction f2)
{
    // true if num1*den2 == num2*den1
    if ( num*f2.den == f2.num*den )
        return true;
    else
        return false;
}

// method add() of the Fraction class
Fraction Fraction::add (Fraction f2)
{

    Fraction result (-2, -4);
    return result;
}

// method toStr() of the Fraction class
// toStr is usafe since size of buffer is not verified
char* Fraction::toStr (char* buf)
{
    sprintf (buf, "%d/%d", num, den);
    return buf;
}

// if breaking into multiple source code files, the code that would use the
//   Fraction class would start here
//   you would need into include the line of code: #include "Fraction.h"

int main (int argc, char** argv)
{
    char buffer[100];    // buffer of size 100 to print the class

    Fraction f1;         // must write default constructor for this to work
    Fraction f2(0);      // must write single integer constructor for this to work
    printf ("\n\nTesting Equality\n");
    printf ("Fraction f1: %s\n", f1.toStr(buffer) );
    printf ("Fraction f2: %s\n", f2.toStr(buffer) );


    // what does the default == give as a result?
    if ( &f1 == &f2 )
        printf (" f1 == f2\n");
    else
        printf (" f1 != f2\n");

    // what does the equals( ) method give as a result?
    if ( f1.equals(f2) == true )
        printf (" f1 equals() f2\n");
    else
        printf (" f1 does not equals() f2\n");

    printf ("\n\nTesting add()");
    Fraction f3(-42, -56);
    Fraction f4(52, -13);
    Fraction f5;

    printf ("Fraction f3: %s\n", f3.toStr(buffer) );
    printf ("Fraction f4: %s\n", f4.toStr(buffer) );

    f5 = f3.add(f4);
    printf ("Fraction f5: %s\n", f5.toStr(buffer) );
    printf ("Fraction f3 should not change: %s\n", f3.toStr(buffer) );
    printf ("Fraction f4 should not change: %s\n", f4.toStr(buffer) );

    return 1;
}
