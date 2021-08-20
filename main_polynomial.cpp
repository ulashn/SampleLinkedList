#include <iostream>

#include "Polynomial.hpp"
using namespace std;

int main() {
    Polynomial p1("(3)x^2 + (-1)x^2 + (4)x^5 + (7)x^3");

    p1.printPolynomial();

    p1.simplifyByExponents();

    p1.printPolynomial();

    Polynomial p2("(3)x^2 + (-1)x^2 + (4)x^2 + (5)x^3 + (2)x^3 + (-6)x^3");

    p2.simplifyByExponents();

    cout << "-----" << endl;

    p2.printPolynomial();

    

    return 0;
}