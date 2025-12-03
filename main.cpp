#include <iostream>
#include "Complex.h"

using namespace std;

int main() {
    Complex z1;                
    Complex z2(3, 4);          // 3+4i
    Complex z3(1, -2);         // 1-2i

    cout << "Initial complex numbers:\n";
    cout << "z1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;
    cout << "z3 = " << z3 << endl;

    cout << "\nArithmetic operations:\n";
    cout << "z2 + z3 = " << z2 + z3 << endl;
    cout << "z2 - z3 = " << z2 - z3 << endl;
    cout << "z2 * z3 = " << z2 * z3 << endl;
    cout << "z2 / z3 = " << z2 / z3 << endl;

    z2 += z3;
    cout << "After z2 += z3, z2 = " << z2 << endl;

    z2 -= z3;
    cout << "After z2 -= z3, z2 = " << z2 << endl;

    z2 *= z3;
    cout << "After z2 *= z3, z2 = " << z2 << endl;

    z2 /= z3;
    cout << "After z2 /= z3, z2 = " << z2 << endl;

    cout << "\nUnary operators:\n";
    cout << "+z3 = " << +z3 << endl;
    cout << "-z3 = " << -z3 << endl;
    cout << "~z3 (conjugate) = " << ~z3 << endl;

    cout << "\nIncrement / Decrement:\n";
    Complex z4(5, 6);
    cout << "z4 = " << z4 << endl;
    cout << "z4++ = " << z4++ << endl;
    cout << "After z4++, z4 = " << z4 << endl;
    cout << "++z4 = " << ++z4 << endl;
    cout << "z4-- = " << z4-- << endl;
    cout << "--z4 = " << --z4 << endl;

    cout << "\nComparisons:\n";
    Complex a(3, 4), b(6, 8);
    cout << a << " == " << b << " ? " << (a == b) << endl;
    cout << a << " != " << b << " ? " << (a != b) << endl;
    cout << a << " < " << b << " ? " << (a < b) << endl;
    cout << a << " <= " << b << " ? " << (a <= b) << endl;
    cout << a << " > " << b << " ? " << (a > b) << endl;
    cout << a << " >= " << b << " ? " << (a >= b) << endl;

    cout << "\nAccess by index:\n";
    Complex z5(7, -9);
    cout << "z5 = " << z5 << endl;
    cout << "z5[0] (real) = " << z5[0] << endl;
    cout << "z5[1] (imag) = " << z5[1] << endl;

    cout << "\nUsing operator():\n";
    Complex z6;
    z6(10, 20);
    cout << "z6 = " << z6 << endl;

    cout << "\nMagnitude and power:\n";
    Complex z7(1, 1);
    cout << "z7 = " << z7 << endl;
    cout << "|z7| = " << z7.abs() << endl;
    cout << "z7^3 = " << z7.pow(3) << endl;

    cout << "\nEnter a complex number:\n";
    Complex zInput;
    cin >> zInput;
    cout << "You entered: " << zInput << endl;

    cout << "\nMagnitude via type conversion:\n";
    double mag = z7;
    cout << "Magnitude of " << z7 << " = " << mag << endl;

    return 0;
}
