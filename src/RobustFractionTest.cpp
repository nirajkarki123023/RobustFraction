#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include "RobustFraction.h"

using namespace std;

// Helper function for checking test results
//template <typename T>
bool checkTest(int testNum, int& correct, string whatItShouldBe, string whatItIs) {
    if (whatItShouldBe == whatItIs) {
        correct++;
        cout << "***TEST " << testNum << " PASSED***" << endl;
        return true;
    } else {
        cout << "***TEST " << testNum << " FAILED*** " << endl;
        cout << "   Output was " << whatItIs << endl;
        cout << "   Output should have been " << whatItShouldBe << endl;
        return false;
    }
}

// Convert Fraction to string
string fractionToString(const Fraction& f) {
    ostringstream oss;
    oss << f;
    return oss.str();
}

// Test functions
void testFractionAddition(int& correctTests) {
    Fraction f2(1, 2);
    Fraction f1(3, 4);
    Fraction f3 = f1 + f2;
    checkTest(1, correctTests, "1 and 1/4", fractionToString(f3));
}

void testFractionSubtraction(int& correctTests) {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f4 = f1 - f2;
    checkTest(2, correctTests, "-1/4", fractionToString(f4));
}

void testFractionMultiplication(int& correctTests) {
    Fraction f2(1, 2);
    Fraction f1(3, 4);
    Fraction f5 = f1 * f2;
    checkTest(3, correctTests, "3/8", fractionToString(f5));
}

void testFractionDivision(int& correctTests) {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f6 = f1 / f2;
    checkTest(4, correctTests, "2/3", fractionToString(f6));
}

void testFractionPreIncrement(int& correctTests) {
    Fraction f1(3, 4);
    Fraction preIncrement = ++f1;
    checkTest(5, correctTests, "1 and 3/4", fractionToString(preIncrement));
}

void testFractionPostIncrement(int& correctTests) {
    Fraction f1(3, 4);
    Fraction postIncrement = f1++;
    checkTest(6, correctTests, "3/4", fractionToString(postIncrement));
}

void testFractionPostIncrementFinal(int& correctTests) {
    Fraction f1(3, 4);
    f1++;
    checkTest(7, correctTests, "1 and 3/4", fractionToString(f1));
}

void testFractionPreDecrement(int& correctTests) {
    Fraction f1(3, 4);
    Fraction preDecrement = --f1;
    checkTest(8, correctTests, "-1/4", fractionToString(preDecrement));
}

void testFractionPostDecrement(int& correctTests) {
    Fraction f1(3, 4);
    Fraction postDecrement = f1--;
    checkTest(9, correctTests, "3/4", fractionToString(postDecrement));
}

void testFractionPostDecrementFinal(int& correctTests) {
    Fraction f1(3, 4);
    f1--;
    checkTest(10, correctTests, "-1/4", fractionToString(f1));
}

void testFractionInputValid(int& correctTests) {
    stringstream input("5/6");
    Fraction f;
    input >> f;
    checkTest(11, correctTests, "5/6", fractionToString(f));
}

void testFractionInputInvalid(int& correctTests) {
    stringstream inputInvalid("5/0");
    Fraction f;
    inputInvalid >> f;
    checkTest(12, correctTests, "5", fractionToString(f));
}

// Run all tests
void runAllTests() {
    int correctTests = 0;
    testFractionAddition(correctTests);
    testFractionSubtraction(correctTests);
    testFractionMultiplication(correctTests);
    testFractionDivision(correctTests);
    testFractionPreIncrement(correctTests);
    testFractionPostIncrement(correctTests);
    testFractionPostIncrementFinal(correctTests);
    testFractionPreDecrement(correctTests);
    testFractionPostDecrement(correctTests);
    testFractionPostDecrementFinal(correctTests);
    testFractionInputValid(correctTests);
    testFractionInputInvalid(correctTests);
    cout << "Total tests passed: " << correctTests << " out of 12" << endl;
}

// Main function to run specific tests
int main(int argc, char* argv[]) {
    if (argc == 1) {
        runAllTests();
    } else if (argc == 2) {
        int correctTests = 0;
        int testNumber = atoi(argv[1]);

        switch (testNumber) {
            case 1:
                testFractionAddition(correctTests);
                break;
            case 2:
                testFractionSubtraction(correctTests);
                break;
            case 3:
                testFractionMultiplication(correctTests);
                break;
            case 4:
                testFractionDivision(correctTests);
                break;
            case 5:
                testFractionPreIncrement(correctTests);
                break;
            case 6:
                testFractionPostIncrement(correctTests);
                break;
            case 7:
                testFractionPostIncrementFinal(correctTests);
                break;
            case 8:
                testFractionPreDecrement(correctTests);
                break;
            case 9:
                testFractionPostDecrement(correctTests);
                break;
            case 10:
                testFractionPostDecrementFinal(correctTests);
                break;
            case 11:
                testFractionInputValid(correctTests);
                break;
            case 12:
                testFractionInputInvalid(correctTests);
                break;
            default:
                cerr << "Invalid test number. Please enter a number between 1 and 12" << endl;
                return 1;
        }

        cout << "Total tests passed: " << correctTests << " out of 12" << endl;
    } else {
        cerr << "Usage: " << argv[0] << " [testNumber]" << endl;
        return 1;
    }

    return 0;
}
