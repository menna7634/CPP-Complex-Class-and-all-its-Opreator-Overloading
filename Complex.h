#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double img;

    static double absVal(double x);
    static bool isZero(double x);
    static bool equalDouble(double a, double b);

public:
    Complex();
    Complex(double r, double i);

    double getReal() const;
    double getImg() const;

    Complex operator+(const Complex& o) const;
    Complex operator-(const Complex& o) const;
    Complex operator*(const Complex& o) const;
    Complex operator/(const Complex& o) const;

    Complex& operator+=(const Complex& o);
    Complex& operator-=(const Complex& o);
    Complex& operator*=(const Complex& o);
    Complex& operator/=(const Complex& o);

    bool operator==(const Complex& o) const;
    bool operator!=(const Complex& o) const;

    friend ostream& operator<<(ostream& out, const Complex& c);
    friend istream& operator>>(istream& in, Complex& c);
};

#endif
