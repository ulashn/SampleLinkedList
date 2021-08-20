#include "Polynomial.hpp"
using namespace std;

Polynomial::Polynomial() {
    // Does nothing.
}

Polynomial::Polynomial(std::string expression) {
    // expression = (c_1)x^n_1 + (c_2)x^n_2 + ... + (c_k)x^n_k
    // c's are integer coefficients, n's are non-negative integer exponents.

    std::string delimiter = " + ";

    std::string term;
    std::string coefficient;
    std::string exponent;
    size_t pos = 0;

    while (true) {
        pos = expression.find(delimiter);

        bool breakTheLoop = (pos == std::string::npos);

        term = expression.substr(0, pos);
        expression.erase(0, pos + delimiter.length());

        pos = term.find("x");

        coefficient = term.substr(1, pos - 2);
        exponent = term.substr(pos + 2, term.length() - pos);

        terms.insertAtTheEnd(Term(std::atoi(coefficient.c_str()), std::atoi(exponent.c_str())));

        if (breakTheLoop) break;
    }
}

void Polynomial::printPolynomial() {
    // prints the polynomial in expression format.
    // expression = (c_1)x^n_1 + (c_2)x^n_2 + ... + (c_k)x^n_k

    Node<Term> *node = terms.getFirstNode();

    while (node) {
        std::cout << "(" << node->element.getCoefficient() << ")x^" << node->element.getExponent();
        if (node->next) std::cout << " + ";
        node = node->next;
    }

    std::cout << std::endl;
}

void Polynomial::simplifyByExponents() {
    int i = 0;
    Node<Term> *temp = terms.getFirstNode();
    while(temp->next){
        i = 0;
        Node<Term> *temp2 = temp->next;
        while(temp2){
            cout << i << endl;
            cout << temp2->element.getCoefficient() << endl;
            cout << "-----" << endl;
            i++;
            if(temp2->element.getExponent() == temp->element.getExponent()){
                temp->element.setCoefficient(temp2->element.getCoefficient() + temp->element.getCoefficient());
                terms.removeNode(terms.findNode(temp2->element));
                if(temp2){
                    temp2 = temp2->next;
                }
            }
            else
                temp2 = temp2->next;
        }
        if(temp->next == NULL){
            delete temp2;
            break;
        }
        else
            temp = temp->next;
    }   
}

Polynomial Polynomial::operator+(const Polynomial &rhs) const {
    Node<Term> *temp = this->terms.getFirstNode();
    Node<Term> *temp2 = rhs.terms.getFirstNode();
    Polynomial *temppol = new Polynomial();
    while(temp){
        while(temp2){
            if(temp->element.getExponent() == temp2->element.getExponent()){
                Term tempterm((temp->element.getCoefficient() + temp2->element.getCoefficient()),temp->element.getExponent());
                temppol->terms.insertAtTheEnd(tempterm);
                temp2 = temp2->next;
            }
            else
                temp2 = temp2->next;

        }
        temp = temp->next;
    }
    return *temppol;
}
