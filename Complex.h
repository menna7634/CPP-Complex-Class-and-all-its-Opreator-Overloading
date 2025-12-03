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
    // Constructors
    Complex();
    Complex(double r, double i);

    // Accessors
    double getReal() const;
    double getImg() const;

    // Arithmetic operators
    Complex operator+(const Complex& o) const;
    Complex operator-(const Complex& o) const;
    Complex operator*(const Complex& o) const;
    Complex operator/(const Complex& o) const;

    Complex& operator+=(const Complex& o);
    Complex& operator-=(const Complex& o);
    Complex& operator*=(const Complex& o);
    Complex& operator/=(const Complex& o);

    Complex operator+() const;
    Complex operator-() const;

    // Increment / Decrement 
    Complex& operator++();       
    Complex operator++(int);     
    Complex& operator--();       
    Complex operator--(int);    

    // Comparison operators
    bool operator==(const Complex& o) const;
    bool operator!=(const Complex& o) const;
    bool operator<(const Complex& o) const;
    bool operator<=(const Complex& o) const;
    bool operator>(const Complex& o) const;
    bool operator>=(const Complex& o) const;

    // Access by index
    double& operator[](int index);
    double operator[](int index) const;

    // Function call operator
    void operator()(double r, double i);

    // Mathematical operations
    double abs() const;
    Complex conjugate() const;
    Complex pow(int n) const;

    operator double() const;   
    Complex operator~() const; 

    friend ostream& operator<<(ostream& out, const Complex& c);
    friend istream& operator>>(istream& in, Complex& c);
};

#endif
