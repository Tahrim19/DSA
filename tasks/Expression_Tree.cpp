#include<iostream>
#include<string>
#include<stack>
using namespace std;

struct node {
    char data;      // Data stored in the node (either an operator or an operand)
    node* left;     // Pointer to the left child
    node* right;    // Pointer to the right child
};

int Precedence(char operation) {
    if (operation == '+' || operation == '-') // If the operation is addition or subtraction, return precedence 1.
        return 1;
    if (operation == '*' || operation == '/') // If the operation is multiplication or division, return precedence 2.
        return 2;
    if (operation == '^') // If the operation is exponentiation, return precedence 3.
        return 3;
    return 0; // For any other characters, return 0 as the default precedence.
}

// Function to convert infix expression to postfix
string InfixToPostfixConvert(string infix) {
    int i = 0;
    string postfix;   // Initialize an empty string to store the postfix expression
    stack<char> myStack; // Create a stack to hold operators

    while (i < infix.length()) {
        if (infix[i] >= 'a' && infix[i] <= 'z') {
            postfix = postfix + infix[i]; // If the character is an operand, add it to the postfix expression
            i++;
        } else if (infix[i] == '(') {
            myStack.push(infix[i]); // If the character is an opening parenthesis, push it onto the stack
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

// Function to create an expression tree from a postfix expression
node* ExpressionTree(string postfix) {
    stack<node*> nodeStack; // Create a stack to hold nodes
    for (int i = 0; i < postfix.length(); i++) {
        char symbol = postfix[i];
        if (isalnum(symbol)) { // If the symbol is an operand (alphanumeric character)
            node* temp = new node(); // Create a new node
            temp->data = symbol; // Set the data of the node to the operand
            temp->left = NULL;   // Initialize left and right children as null
            temp->right = NULL;
            nodeStack.push(temp); // Push the node onto the stack
        } else { // If the symbol is an operator
            node* temp = new node(); // Create a new node
            temp->data = symbol; // Set the data of the node to the operator
            temp->right = nodeStack.top(); // Pop the top node as the right child
            nodeStack.pop();
            temp->left = nodeStack.top(); // Pop the next node as the left child
            nodeStack.pop();
            nodeStack.push(temp); // Push the new node onto the stack
        }
    }
    return nodeStack.top(); // The final node on the stack is the root of the expression tree
}

// Function to print the expression tree in postfix notation
void printPostfix(node* root) {
    if (root) {
        printPostfix(root->left);  // Recursively print the left subtree
        printPostfix(root->right); // Recursively print the right subtree
        cout << root->data;        // Print the data (operator or operand)
    }
}

int main() {
    string infix;
    cout << "Enter the infix expression: ";
    cin >> infix; // Input the infix expression

    string postfix = InfixToPostfixConvert(infix); // Convert infix to postfix
    cout << "Postfix Expression: " << postfix << endl;

    node* root = ExpressionTree(postfix); // Create an expression tree from the postfix expression

    cout << "Postfix Expression from Expression Tree: ";
    printPostfix(root); // Print the expression tree in postfix notation
    cout << endl;

    return 0;
}

