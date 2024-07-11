#include <iostream>
#include <cmath>
using namespace std;

// Define a structure for a binary search tree node
struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* root = NULL;  // Initialize the root of the binary search tree to be empty (NULL)

// Function to calculate the height of a binary tree
int Height(BSTNode* node) {
    if (node == NULL) {
        return 0;  // If the node is NULL, the height is 0
    }
    int LeftHeight = Height(node->left);   // Recursively calculate the height of the left subtree
    int RightHeight = Height(node->right);  // Recursively calculate the height of the right subtree
    return max(LeftHeight, RightHeight) + 1;  // Return the maximum height of left or right subtree, plus 1 (for the current node)
}

// Function to perform a right rotation (RR imbalance correction)
BSTNode* RRImbalance(BSTNode* node) {
    BSTNode* Nnode = node->right;   // Nnode is the right child of the current node
    BSTNode* LC = Nnode->left;      // LC is the left child of Nnode
    Nnode->left = node;             // Make the current node the left child of Nnode
    node->right = LC;               // Make LC the right child of the current node
    return Nnode;  // Return the new root of the subtree after the rotation
}

// Function to perform a Left rotation (LL imbalance correction)
BSTNode* LLImbalance(BSTNode* node) {
    BSTNode* Nnode = node->left;  // Nnode is the left child of the current node
    BSTNode* RC = Nnode->right;   // RC is the right child of Nnode
    Nnode->right = node;          // Make the current node the right child of Nnode
    node->left = RC;              // Make RC the left child of the current node
    return Nnode;  // Return the new root of the subtree after the rotation
}


// Function to perform a pre-order traversal of the binary search tree and print the nodes
void PreOrder(BSTNode* node) {
    if (node != NULL) {
        cout << node->data << endl;  // Print the data in the current node
        PreOrder(node->left);       // Recursively traverse the left subtree
        PreOrder(node->right);      // Recursively traverse the right subtree
    }
}

int BalanceFactor(BSTNode* node) {
    if (node == NULL) {
        return 0;  // If the node is NULL, the balance factor is 0.
    }
    return Height(node->left) - Height(node->right);  // Calculate and return the balance factor.
}

BSTNode* insertion(BSTNode* node, int value) {
    if (node == NULL) {
        BSTNode* temp = new BSTNode();  // Create a new node to hold the value.
        temp->data = value;
        temp->left = NULL;
        temp->right = NULL;
        return temp;  // Return the new node as a leaf node in the tree.
    }

    if (value > node->data) {
        node->right = insertion(node->right, value);  // Recursively insert into the right subtree.
    } else {
        node->left = insertion(node->left, value);    // Recursively insert into the left subtree.
    }

    // Calculate the balance factor for the current node.
    int balance = BalanceFactor(node);

    // Check for and correct LL, RR, LR, and RL imbalances.
    if (balance > 1  && value < node->left->data) {
        return LLImbalance(node);  // LL imbalance correction.
    }
    if (balance < -1 && value > node->right->data) {
        return RRImbalance(node);  // RR imbalance correction.
    }
    if (balance > 1 && value > node->left->data) {
        // LR imbalance correction: Right rotation on the left child followed by a left rotation on the current node.
        node->left = RRImbalance(node->left);
        return LLImbalance(node);
    }
    if (balance < -1 && value < node->right->data) {
        // RL imbalance correction: Left rotation on the right child followed by a right rotation on the current node.
        node->right = LLImbalance(node->right);
        return RRImbalance(node);
    }

    return node;  // Return the updated (or unchanged) root of the subtree.
}




int main() {
    root = insertion(root, 23);  
    root = insertion(root, 45);   // satisfies RR Imbalance (shift left)
    root = insertion(root, 70);  

	root = insertion(root, 20);
	root = insertion(root, 10);     // satisfies LL Imbalance (shift right)
	root = insertion(root, 5);
	
	root = insertion(root, 50);
	root = insertion(root, 75);     // satisfies RL Imbalance
	root = insertion(root, 65);

	root = insertion(root, 55);
	root = insertion(root, 80);     // satisfies LR Imbalance
	root = insertion(root, 69);	

//	root = insertion(root, 21);
//	root = insertion(root, 26);
//	root = insertion(root, 30);
//	root = insertion(root, 9);
//	root = insertion(root, 4);
//	root = insertion(root, 14);
//	root = insertion(root, 28);
//	root = insertion(root, 18);
//	root = insertion(root, 15);
//	root = insertion(root, 10);
//	root = insertion(root, 2);
//	root = insertion(root, 3);
//	root = insertion(root, 7);
    PreOrder(root);  // Traverse the tree in pre-order and print the output

    return 0;
}

