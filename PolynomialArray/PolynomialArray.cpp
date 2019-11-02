// PolynomialArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

const int MaxTerms = 20;
class term {
    friend Polynomial;
private:
    // coefficient
    float coef;
    // exponent
    int exp;
};

class Polynomial {
private:
    static term termArray[MaxTerms];
    static int free;
    int Start, Finish;
};

term Polynomial::termArray[MaxTerms];
int Polynomial::free = 0;
void Polynomial::NewTerm(float c, int e) {
    if (free >= MaxTerms) {
        cerr << "Too many terms in polynomials" << endl;
        exit();
    }
    termArray[free].coef = c;
    termArray[free].exp = e;
    free++;
    
}
int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
