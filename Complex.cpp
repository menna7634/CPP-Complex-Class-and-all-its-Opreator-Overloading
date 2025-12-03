#include "Complex.h"
#include <sstream>
#include <iostream>
#include <cmath>
#include <stdexcept>

//Static helpers 
double Complex::absVal(double x) {
    return (x < 0 ? -x : x);
}

bool Complex::isZero(double x) {
    return absVal(x) < 1e-7;
}

bool Complex::equalDouble(double a, double b) {
    return absVal(a - b) < 1e-7;
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
    if (isZero(d)) throw runtime_error("Division by zero complex number!");
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

//  Unary operators 
Complex Complex::operator+() const {
     return *this; 
    }
Complex Complex::operator-() const {
     return Complex(-real, -img); 
    }

Complex Complex::operator~() const {
     return conjugate(); 
    }

Complex& Complex::operator++() { 
    real += 1; 
    return *this;
 }

Complex Complex::operator++(int) {
     Complex temp = *this; 
     real += 1; 
     return temp; 
    }

Complex& Complex::operator--() {
     real -= 1;
      return *this;
     }

Complex Complex::operator--(int) { 
    Complex temp = *this; real -= 1;
     return temp;
     }

bool Complex::operator==(const Complex& o) const { 
    return equalDouble(real, o.real) && equalDouble(img, o.img); 
}

bool Complex::operator!=(const Complex& o) const { 
    return !(*this == o);
 }

bool Complex::operator<(const Complex& o) const { 
    return abs() < o.abs();
 }

bool Complex::operator<=(const Complex& o) const { 
    return abs() <= o.abs(); 
}

bool Complex::operator>(const Complex& o) const { 
    return abs() > o.abs(); 
}

bool Complex::operator>=(const Complex& o) const {
     return abs() >= o.abs();
     }

double& Complex::operator[](int index) {
    if (index == 0)
     return real;
    if (index == 1)
     return img;
    throw out_of_range("Index must be 0 (real) or 1 (imaginary)");
}

double Complex::operator[](int index) const {
    if (index == 0) 
    return real;
    if (index == 1) 
    return img;
    throw out_of_range("Index must be 0 (real) or 1 (imaginary)");
}

void Complex::operator()(double r, double i) {
    real = r;
    img = i;
}

double Complex::abs() const {
     return sqrt(real * real + img * img); 
    }

Complex Complex::conjugate() const { 
    return Complex(real, -img); 
}

Complex Complex::pow(int n) const {
    if (n < 0) throw invalid_argument("Negative powers not supported");
    Complex result(1, 0);
    for (int i = 0; i < n; ++i) result *= *this;
    return result;
}

Complex::operator double() const { 
    return abs();
 }

ostream& operator<<(ostream& out, const Complex& c) {
    if (Complex::isZero(c.img)){
     out << c.real;
     } else if (Complex::isZero(c.real)) {
     out << c.img << "i";
      } else{
     out << c.real << (c.img >= 0 ? "+" : "") << c.img << "i";
      }
    return out;
}

istream& operator>>(istream& in, Complex& c) {
    string line;
    bool valid;

    // Real 
    valid = false;
    while (!valid) {
        cout << "Enter real part: ";
        getline(in, line);
        stringstream ss(line);
        if (ss >> c.real && ss.eof()){
         valid = true;
         } else{
         cout << "Invalid input! Please enter a numeric value.\n";
        }
    }

    valid = false;
    while (!valid) {
        cout << "Enter imaginary part: ";
        getline(in, line);
        stringstream ss(line);
        if (ss >> c.img && ss.eof()) {
        valid = true;
        }else{
         cout << "Invalid input! Please enter a numeric value.\n";
        }
    }

    return in;
}
