#ifndef ROBUSTFRACTION_H
#define ROBUSTFRACTION_H

#include <iostream>
using namespace std;

class Fraction {   
    private:
    // numerator and denominator store the value of the fraction.
    // Keeping them private prevents outside code from changing them directly.
    int numerator;
    int denominator;

    // helper function that computes the greatest common divisor using recursion
    int greatestCommonDivisor(int a, int b) {
        if (b == 0)
            return abs(a);
        return abs(greatestCommonDivisor(b, a % b));
    }

    // reduce the fraction to lowest terms and keep the sign on the numerator
    void simplify() {
        if (denominator < 0) {              // move any negative sign to the top
            numerator *= -1;
            denominator *= -1;
        }

        int gcd = greatestCommonDivisor(numerator, denominator);
        if (gcd != 0) {
            numerator /= gcd;
            denominator /= gcd;
        }
    }

    public:
    // default constructor (no initialization) – this is what the original assignment asked for
    // since the object is often immediately filled by operator>>, we leave the members alone.
    Fraction() { }

    // constructor that accepts a numerator and denominator
    Fraction(int num, int den) : numerator(num), denominator(den) {
        if (denominator == 0) {
            cerr << "Denominator cannot be zero. Using 1 instead.\n";
            denominator = 1;
        }
        simplify();       // always keep the fraction reduced
    }

    // output operator – prints the fraction in a human friendly format
    friend ostream& operator<<(ostream& out, const Fraction& fraction) {
        // if denominator is 1 just print the whole number
        if (fraction.denominator == 1) {
            out << fraction.numerator;
            return out;
        }

        int num = fraction.numerator;
        int den = fraction.denominator;

        // mixed number when numerator larger than denominator
        if (abs(num) > den) {
            int whole = num / den;              // integer part (truncates toward zero)
            int rem = abs(num % den);           // remainder always positive
            out << whole << " and " << rem << "/" << den;
            return out;
        }

        // proper fraction or negative proper fraction
        out << num << "/" << den;
        return out;
    }
    friend istream& operator>>(istream& in, Fraction& fraction) {
        // ask for input only when reading from cin; stringstreams do not need a prompt
        if (&in == &cin) {
            cout << "Enter a fraction in the form n/d: ";
        }

        int num, den;
        char slash;
        in >> num >> slash >> den;   // read something like 5/6

        fraction.numerator = num;
        fraction.denominator = den;

        if (fraction.denominator == 0) {
            cerr << "Denominator cannot be zero. Using 1 instead.\n";
            fraction.denominator = 1;
        }

        fraction.simplify();
        return in;
    }

    friend Fraction operator+(Fraction op1, Fraction op2) {
        // a/b + c/d = (a*d + c*b) / (b*d)
        int num = op1.numerator * op2.denominator + op2.numerator * op1.denominator;
        int den = op1.denominator * op2.denominator;
        Fraction result(num, den);
        result.simplify();
        return result;
    }

    // subtraction operator
    friend Fraction operator-(Fraction op1, Fraction op2) {
        // a/b - c/d = (a*d - c*b) / (b*d)
        int num = op1.numerator * op2.denominator - op2.numerator * op1.denominator;
        int den = op1.denominator * op2.denominator;
        Fraction result(num, den);
        result.simplify();
        return result;
    }

    friend Fraction operator*(Fraction op1, Fraction op2) {
        // a/b * c/d = (a*c) / (b*d)
        int num = op1.numerator * op2.numerator;
        int den = op1.denominator * op2.denominator;
        Fraction result(num, den);
        result.simplify();
        return result;
    }

    // division operator
    friend Fraction operator/(Fraction op1, Fraction op2) {
        // a/b ÷ c/d = (a*d) / (b*c)
        int num = op1.numerator * op2.denominator;
        int den = op1.denominator * op2.numerator;
        Fraction result(num, den);
        result.simplify();
        return result;
    }
    operator double() {
        return static_cast<double>(numerator) / denominator;
    }

    Fraction& operator+=(Fraction fraction) {
        *this = *this + fraction;
        return *this;
    }

    Fraction& operator-=(Fraction fraction) {
        *this = *this - fraction;
        return *this;
    }

    Fraction& operator*=(Fraction fraction) {
        *this = *this * fraction;
        return *this;
    }

    Fraction& operator/=(Fraction fraction) {
        *this = *this / fraction;
        return *this;
    }

    Fraction& operator++() {
        numerator += denominator;
        simplify(); 
        return *this; 
    }

    Fraction operator++(int) {
        Fraction tmp(*this); 
        ++(*this); 
        return tmp;
    }

    Fraction& operator--() {
        numerator -= denominator;
        simplify(); 
        return *this;
    }

    Fraction operator--(int) {
        Fraction tmp(*this);
        --(*this);
        return tmp;
    }
};
#endif