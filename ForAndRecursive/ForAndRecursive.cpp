// for_recursive.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
int multiply_recursive(const int& a, const int& b) {
    if (b == 1)
        return a;
    return multiply_recursive(a, b - 1) + a;
}
int factor_recursive(int n) {
    if (n == 1) return 1;
    return n * factor_recursive(n - 1);
}
int main()
{
    int a = 3;
    int b = 5;
    std::cout << "3 * 5 = " << multiply_recursive(a, b) << std::endl;
    std::cout << "3! = " << factor_recursive(3) << std::endl;
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
