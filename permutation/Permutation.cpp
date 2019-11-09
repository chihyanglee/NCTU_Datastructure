// NCTU_Datastructure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void perm(char* list,const int& i,const int& n) {
    if (i == n) {
        for (int j = 0; j <= n; j++)
            cout << list[j];
        cout << endl;
    }
    else {
        for (int j = i; j <= n; j++) {
            swap(list[i], list[j]);
            perm(list, i + 1, n);
            swap(list[i], list[j]);
        }
    }
}

int main() {
    char s[]{ 'a', 'b', 'c' };
    perm(s, 0, 2);
    return 0;
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
