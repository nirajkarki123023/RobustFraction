#include <iostream>
#include "RobustFraction.h"
using namespace std;


#ifndef TESTING
int main(){
    Fraction fraction1;
    Fraction fraction2;
    cout << "Tests of console input" << endl;
    cin >> fraction1;
    cin >> fraction2;
    cout << endl;
    cout << "Tests of console output" << endl;
    cout << "Left operand: " << fraction1 << endl;
    cout << "Right operand: " << fraction2 << endl;
    cout << endl;
    cout << "Tests of basic arithmetic and conversion" << endl;
    cout << fraction1 << " + " << fraction2 << " = " << fraction1 +
    fraction2 << " (" << double(fraction1 + fraction2) << ")" << endl;
    cout << fraction1 << " - " << fraction2 << " = " << fraction1 -
    fraction2 << " (" << double(fraction1 - fraction2) << ")" << endl;
    cout << fraction1 << " * " << fraction2 << " = " << fraction1 *
    fraction2 << " (" << double(fraction1 * fraction2) << ")" << endl;
    cout << fraction1 << " / " << fraction2 << " = " << fraction1 /
    fraction2 << " (" << double(fraction1 / fraction2) << ")" << endl;
    cout << endl;
    cout << "Tests of relational expression" << endl;
    if(double(fraction1) < double(fraction2)){
    cout << fraction1 << " is less than " << fraction2 << endl;
    }else if(double(fraction2) < double(fraction1)){
    cout << fraction2 << " is less than " << fraction1 << endl;
    }else{
    cout << fraction1 << " is the same as " << fraction2 << endl;
    }
    cout << endl;
    cout << "Tests of increment/decrement" << endl;
    Fraction tmp = fraction1;
    cout << "Original fraction: " << tmp << endl;
    cout << "++fraction: " << ++tmp << endl;
    cout << "fraction: " << tmp << endl;
    cout << "fraction++: " << tmp++ << endl;
    cout << "fraction: " << tmp << endl;
    cout << "--fraction: " << --tmp << endl;
    cout << "fraction: " << tmp << endl;
    cout << "fraction--: " << tmp-- << endl;
    cout << "fraction: " << tmp << endl;
    cout << endl;
    cout << "Tests of compound assignment" << endl;
    cout << "Original fraction: " << fraction1 << endl;
    //Test +=
    cout << fraction1 << " += " << fraction2 << ": ";
    fraction1 += Fraction(3,4);
    cout << fraction1 << endl;
    //Test -=
    cout << fraction1 << " -= " << fraction2 << ": ";
    fraction1 -= Fraction(3,4);
    cout << fraction1 << endl;
    //Test *=
    cout << fraction1 << " *= " << fraction2 << ": ";
    fraction1 *= Fraction(3,4);
    cout << fraction1 << endl;
    //Test /=
    cout << fraction1 << " /= " << fraction2 << ": ";
    fraction1 /= Fraction(3,4);
    cout << fraction1 << endl;
    return 0;
}
#endif