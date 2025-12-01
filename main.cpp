#include <iostream>
#include "Complex.h"
using namespace std;

int main() {
    Complex A, B;

    cout << "Enter A:\n";
    cin >> A;

    cout << "\nEnter B:\n";
    cin >> B;

    cout << "\n----------------------\n";
    cout << "      RESULTS\n";
    cout << "----------------------\n";

    cout << "A = " << A << endl;
    cout << "B = " << B << endl << endl;

    cout << "A + B = " << A + B << endl;
    cout << "A - B = " << A - B << endl;
    cout << "A * B = " << A * B << endl;
    cout << "A / B = " << A / B << endl;

    Complex C1 = A; C1 += B;
    cout << "A += B = " << C1 << endl;

    Complex C2 = A; C2 -= B;
    cout << "A -= B = " << C2 << endl;

    Complex C3 = A; C3 *= B;
    cout << "A *= B = " << C3 << endl;

    Complex C4 = A; C4 /= B;
    cout << "A /= B = " << C4 << endl;

    cout << "\nA == B = " << (A == B ? "True" : "False") << endl;
    cout << "A != B = " << (A != B ? "True" : "False") << endl;

    return 0;
}
