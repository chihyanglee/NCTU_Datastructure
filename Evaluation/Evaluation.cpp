// Evaluation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
string infix_to_postfix(string&);
template<typename T>
bool is_operator(T&);
int operator_priority(const char&);
int evaluate(string);
int main()
{
    string case1 = "a + b * c";
    string case1_p = infix_to_postfix(case1);
    cout << "\t*** case1 ***\n" 
         << "  infix: " << case1 << "\n"
         << "  postfix: " << case1_p << "\n" << endl;

    string case2 = "a * b + c";
    string case2_p = infix_to_postfix(case2);
    cout << "\t*** case2 ***\n"
         << "  infix: " << case2 << "\n"
         << "  postfix: " << case2_p << "\n" << endl;

    string case3 = "a * ( b + c ) * d";
    string case3_p = infix_to_postfix(case3);
    cout << "\t*** case3 ***\n"
         << "  infix: " << case3 << "\n"
         << "  postfix: " << case3_p << "\n" << endl;
}

string infix_to_postfix(string& infix_expression) {
    string postfix_expression;
    stack<char> operator_stack;
    for (char& current_character : infix_expression) {
        // skip whitespace
        if (current_character == ' ') continue;
        if (is_operator(current_character)) {
            // pop previous operator if its priority is higher than current operator
            if (!operator_stack.empty() &&
                operator_stack.top() != '(' &&
                operator_priority(current_character) <= operator_priority(operator_stack.top())) {
                postfix_expression += operator_stack.top();
                operator_stack.pop();
            }
            operator_stack.push(current_character);
            continue;
        }
        if (current_character == '(') {
            operator_stack.push(current_character);
            continue;
        }
        if (current_character == ')') {
            while (!operator_stack.empty() && operator_stack.top() != '(') {
                postfix_expression += operator_stack.top();
                operator_stack.pop();
            }
            // pop '('
            operator_stack.pop();
            continue;
        }
        postfix_expression += current_character;
    }
    while (!operator_stack.empty()) {
        postfix_expression += operator_stack.top();
        operator_stack.pop();
    }
    return postfix_expression;
}

template<typename T>
bool is_operator(T& t) {
    const vector<char> operators{ '+', '-', '*', '/' };
    auto f = find(begin(operators), end(operators), t);
    return f != end(operators);
}
int operator_priority(const char& c) {
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
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
