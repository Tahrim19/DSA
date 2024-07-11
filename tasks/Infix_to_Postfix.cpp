#include <iostream>
#include <string>
#include <stack>
using namespace std;

int Precedence(char operation) {
    if (operation == '+' || operation == '-') // If the operation is addition or subtraction, return precedence 1.
        return 1;
    if (operation == '*' || operation == '/') // If the operation is multiplication or division, return precedence 2.
        return 2;
    if (operation == '^') // If the operation is exponentiation, return precedence 3.
        return 3;
    return 0; // For any other characters, return 0 as default precedence.
}

string InfixToPostfixConvert(string infix) {
    int i = 0;
    string postfix;
    stack<char> myStack; // Create a stack to hold operators

    while (i < infix.length()) {
        if (infix[i] >= 'a' && infix[i] <= 'z') {
            postfix = postfix + infix[i]; // Append variables to the postfix expression
            i++;
        } else if (infix[i] == '(') {
            myStack.push(infix[i]); // Push an opening parenthesis onto the stack
            i++;
        } else if (infix[i] == ')') {
            // Pop operators from the stack and append to postfix until an opening parenthesis is encountered
            while (!myStack.empty() && myStack.top() != '(') {
                postfix = postfix + myStack.top();
                myStack.pop();
            }
            if (!myStack.empty() && myStack.top() == '(') {
                myStack.pop(); // Remove the opening parenthesis from the stack
            }
            i++;
        } else {
            // Operator handling: Pop operators with higher precedence from the stack
            while (!myStack.empty() && Precedence(infix[i]) <= Precedence(myStack.top())) {
                postfix = postfix + myStack.top();
                myStack.pop();
            }
            myStack.push(infix[i]); // Push the current operator onto the stack
            i++;
        }
    }
    // Pop any remaining operators from the stack and append to postfix
    while (!myStack.empty()) {
        postfix = postfix + myStack.top();
        myStack.pop();
    }
    return postfix; // Return the postfix expression
}


int main() {
    string infix;
    cout << "Enter the equation: " << endl;  // (a+b)*(c-d) ans: ab+cd-*
    getline(cin, infix);  

    string postfix;
    postfix = InfixToPostfixConvert(infix);
    cout << "Infix Equation: " << infix << endl;
    cout << "Postfix Notation: " << postfix << endl;
    return 0;
}

