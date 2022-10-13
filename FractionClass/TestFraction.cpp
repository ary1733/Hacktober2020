
// File: TestFraction.cpp
// Contains: void TestFraction()
/************ C++ Headers ************************************/
#include <iostream>
using namespace std;
/************ PROJECT Headers ********************************/
#include "Fraction.hpp"


void TestFraction() {
cout << "\nTest Fraction Data Type" << endl;
// CONSTRUCTORS
// ------------
Fraction f1(5, 3);
Fraction f2(7.2);
Fraction f3;
cout << "Fraction f1(5, 3) = " << f1 << endl;
cout << "Fraction f2(7.2) = " << f2 << endl;
cout << "Fraction f3 = " << f3 << endl;
// BASIC ASSIGNEMENT OPERATOR
// --------------------------
cout << "Assignment (Before): f3 = " << f3 << ". f1 = " << f1 << endl;
f3 = f1;
cout << "Assignment (After): f3 = " << f3 << ". f1 = " << f1 << endl;
f3 = Fraction::sc_fUnity;
// UNARY ARITHMETIC OPERATORS
// --------------------------
f3 = -f1;
cout << "Unary Minus: f3 = " << f3 << ". f1 = " << f1 << endl;
// Pre-decrement. Dividendo
f3 = Fraction::sc_fUnity;
cout << "Pre-Decrement (Before): f3 = " << f3 << ". f1 = " << f1 << endl;
f3 = --f1;
cout << "Pre-Decrement (After): f3 = " << f3 << ". f1 = " << f1 << endl;
// Post-decrement. Lazy Dividendo
f3 = Fraction::sc_fUnity;
cout << "Post-Decrement (Before): f3 = " << f3 << ". f1 = " << f1 << endl;
f3 = f1--;
cout << "Post-Decrement (After): f3 = " << f3 << ". f1 = " << f1 << endl;
// Pre-increment. Componendo
f3 = Fraction::sc_fUnity;
cout << "Pre-Increment (Before): f3 = " << f3 << ". f1 = " << f1 << endl;
f3 = ++f1;
cout << "Pre-Increment (After): f3 = " << f3 << ". f1 = " << f1 << endl;
// Post-increment. Lazy Componendo
f3 = Fraction::sc_fUnity;
cout << "Post-Increment (Before): f3 = " << f3 << ". f1 = " << f1 << endl;
f3 = f1++;
cout << "Post-Increment (After): f3 = " << f3 << ". f1 = " << f1 << endl;
// BINARY ARITHMETIC OPERATORS USING FRIEND FUNCTIONS
// --------------------------------------------------
f1 = Fraction(5, 12);
f2 = Fraction(7, 18);
f3 = f1 + f2;
cout << "Binary Plus: f3 = " << f3 << ". f1 = " << f1
<< ". f2 = " << f2 << endl;
f1 = Fraction(16, 3);
f2 = Fraction(22, 13);
f3 = f1 - f2;
cout << "Binary Minus: f3 = " << f3 << ". f1 = " << f1
<< ". f2 = " << f2 << endl;
f1 = Fraction(5, 12);
f2 = Fraction(18, 25);
f3 = f1 * f2;
cout << "Multiply: f3 = " << f3 << ". f1 = " << f1
<< ". f2 = " << f2 << endl;
f1 = Fraction(5, 12);
f2 = Fraction(7, 18);
f3 = f1 / f2;
cout << "Divide: f3 = " << f3 << ". f1 = " << f1
<< ". f2 = " << f2 << endl;
f1 = Fraction(5, 12);
f2 = Fraction(7, 18);
f3 = f1 % f2;
cout << "Residue: f3 = " << f3 << ". f1 = " << f1
<< ". f2 = " << f2 << endl;
// BINARY RELATIONAL OPERATORS
// ---------------------------
f1 = Fraction(5, 12);
f2 = Fraction(7, 18);
bool bTest = f1 == f2;
cout << "Equal: Test = " << ((bTest)? "true": "false")
<< ". f1 = " << f1 << ". f2 = " << f2 << endl;
bTest = f1 != f2;
cout << "Not Equal: Test = " << ((bTest)? "true": "false")
<< ". f1 = " << f1 << ". f2 = " << f2 << endl;
bTest = f1 < f2;
cout << "Less: Test = " << ((bTest)? "true": "false")
<< ". f1 = " << f1 << ". f2 = " << f2 << endl;
f1 = Fraction(5, 12);
f2 = Fraction(7, 18);
f3 = Fraction(5, 12);
bTest = f1 <= f2;
cout << "Less Equal: Test = " << ((bTest)? "true": "false")
<< ". f1 = " << f1 << ". f2 = " << f2 << endl;
bTest = f1 <= f3;
cout << "Less Equal: Test = " << ((bTest)? "true": "false")
<< ". f1 = " << f1 << ". f3 = " << f3 << endl;
bTest = f1 > f2;
cout << "Greater: Test = " << ((bTest)? "true": "false")
<< ". f1 = " << f1 << ". f2 = " << f2 << endl;
bTest = f1 >= f2;
cout << "Greater Equal: Test = " << ((bTest)? "true": "false")
<< ". f1 = " << f1 << ". f2 = " << f2 << endl;
bTest = f1 >= f3;
cout << "Greater Equal: Test = " << ((bTest)? "true": "false")
<< ". f1 = " << f1 << ". f3 = " << f3 << endl;
return;
}
// End-of-File: TestFraction.cxx
