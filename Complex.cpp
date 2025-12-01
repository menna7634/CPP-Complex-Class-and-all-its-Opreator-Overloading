#include "Complex.h"
#include <sstream>
#include <iostream>

double Complex::absVal(double x) {
    return (x < 0 ? -x : x);
}

bool Complex::isZero(double x) {
    return absVal(x) < 0.0000001;
}

bool Complex::equalDouble(double a, double b) {
    return absVal(a - b) < 0.0000001;
}

Complex::Complex() : 
real(0), img(0) {}

Complex::Complex(double r, double i) : 
real(r), img(i) {}

double Complex::getReal() const { 
    return real; 
}

double Complex::getImg() const { 
    return img; 
}

Complex Complex::operator+(const Complex& o) const { 
    return Complex(real + o.real, img + o.img); 
}

Complex Complex::operator-(const Complex& o) const { 
    return Complex(real - o.real, img - o.img); 
}

Complex Complex::operator*(const Complex& o) const {
    return Complex(real * o.real - img * o.img, real * o.img + img * o.real);
}

Complex Complex::operator/(const Complex& o) const {
    double d = o.real * o.real + o.img * o.img;
    if (isZero(d)) {
        cout << "\nERROR: Division by zero complex number!\n";
        return Complex(0, 0);
    }
    return Complex((real * o.real + img * o.img) / d, (img * o.real - real * o.img) / d);
}

Complex& Complex::operator+=(const Complex& o) { 
    *this = *this + o; 
    return *this; 
}

Complex& Complex::operator-=(const Complex& o) { 
    *this = *this - o; 
    return *this; 
}

Complex& Complex::operator*=(const Complex& o) {
     *this = *this * o; 
     return *this; 
    }

Complex& Complex::operator/=(const Complex& o) {
     *this = *this / o;
      return *this;
     }

bool Complex::operator==(const Complex& o) const {
     return equalDouble(real, o.real) && equalDouble(img, o.img); 
    }

bool Complex::operator!=(const Complex& o) const { 
    return !(*this == o); 
}

ostream& operator<<(ostream& out, const Complex& c) {
    if (Complex::isZero(c.img)) out << c.real;
    else if (Complex::isZero(c.real)) out << c.img << "i";
    else out << c.real << (c.img >= 0 ? "+" : "") << c.img << "i";
    return out;
}

istream& operator>>(istream& in, Complex& c) {
    string line;
    bool valid;

    valid = false;
    while (!valid) {
        cout << "Enter real part: ";
        getline(in, line);

        if (line.find_first_not_of(' ') == string::npos) {
            cout << "Invalid input! Please enter a numeric value.\n";
            continue;
        }

        stringstream ss(line);
        if (ss >> c.real) valid = true;
        else cout << "Invalid input! Please enter a numeric value.\n";
    }

    valid = false;
    while (!valid) {
        cout << "Enter imaginary part: ";
        getline(in, line);

        if (line.find_first_not_of(' ') == string::npos) {
            cout << "Invalid input! Please enter a numeric value.\n";
            continue;
        }

        stringstream ss(line);
        if (ss >> c.img) valid = true;
        else cout << "Invalid input! Please enter a numeric value.\n";
    }

    return in;
}
