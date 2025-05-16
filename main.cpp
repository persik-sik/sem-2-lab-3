#include <iostream>
#include <cmath>

using namespace std;

class RealNumber {
protected:
    double real;
public:
    RealNumber(double r) : real(r) {}

    virtual double modulus() const {
        return fabs(real);
    }
    virtual void print() const {
        cout << "Real: " << real << ", |Real|: " << modulus() << endl;
    }

    double staticModulus() const {
        return fabs(real);
    }

    void staticPrint() const {
        cout << "[Static] Real: " << real << ", |Real|: " << staticModulus() << endl;
    }
};

class ComplexNumber : public RealNumber {
private:
    double imag;

public:
    ComplexNumber(double r, double i) : RealNumber(r), imag(i) {}

    double modulus() const override {
        return sqrt(real * real + imag * imag);
    }

    void print() const override {
        cout << "Complex: " << real << " + " << imag << "i"
             << ", |Complex|: " << modulus() << endl;
    }

    double staticModulus() const {
        return sqrt(real * real + imag * imag);
    }

    void staticPrint() const {
        cout << "[Static] Complex: " << real << " + " << imag << "i"
             << ", |Complex|: " << staticModulus() << endl;
    }
};

int main() {
    RealNumber r(-3.5);
    r.print();            // Динамический 
    r.staticPrint();      // Статический 

    ComplexNumber c(3.0, 4.0);
    c.print();            // Динамический 
    c.staticPrint();      // Статический 

    return 0;
}
