// QUESTION:
// Build a Binary Tree by inserting elements in the same manner as nodes are inserted in the heap
// i.e. from left to right. Each node should hold a string value.
// Given a pointer to the root of a binary tree.

// * Find its mirror image ; mirror image of the tree is build such that the left child of the root is now the right child and right is now the left child.

// * Given an element x, find the predecessors and successors of x, if x exists.

// * Find the level of any element x in the tree , if x exists.

// * Find the height of the node of any element x in the tree,if x exists.

#include<iostream>
#include <list>
using namespace std;

struct tree{
	int data;
	tree* left;
	tree* right;
};
tree* root = NULL;
  

// function to insert nodes accoridn to max heap 
tree* insertion(tree* node , int value){
	if(node == NULL){
		tree* temp = new tree();
		temp->data = value;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	else{
		if(node->left == NULL){
			node->left = insertion(node->left,value);
			if(node->left->data > node->data){
				swap(node->data , node->left->data);
			}
		}
		else if(node->right == NULL){
			node->right = insertion(node->right,value);
			if(node->right->data > node->data){
				swap(node->data , node->right->data);
			}
		}
		else{
			node->left = insertion(node->left,value);
			if(node->left->data > node->data){
				swap(node->data , node->left->data);
			}
		}
	}
	return node;
}

// Function to Mirror the tree
void MirrorImage(tree* node){\
	if (node == NULL){
		return;
	}
	if(node->left != NULL){
		MirrorImage(node->left);
	}
	if(node->right != NULL){
		MirrorImage(node->right);
	}
	swap(node->left , node->right);
}


// PREDECESSOR:

// Function to find the values smaller than the given value in a subtree
void findSmallerValues(tree* node, int value) {
    if (node == NULL) {
        return;
    }

    if (node->data < value) {
        cout << node->data << " \t";
    }

    findSmallerValues(node->left, value);
    findSmallerValues(node->right, value);
}

// Function to determine whether the node with the given value is in the left or right subtree
void Predecessor(tree* root, int value) {
    if (root == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }

    tree* node = root;
    tree* parent = NULL;

    // Traverse the tree to find the node and its parent
    while (node != NULL && node->data != value) {
        parent = node;
        if (value < node->data) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    if (node == NULL) {
        cout << "Node not found in the tree." << endl;
    } else {
        if (value > root->data) {
            findSmallerValues(root->left, value);
        } else {
            findSmallerValues(root->right, value);
        }
        cout << endl;
    }
}


// SUCCESSOR:

// Function to find the values larger than the given value in a subtree
void findLargerValues(tree* node, int value) {
    if (node == NULL) {
        return;
    }

    if (node->data > value) {
        cout << node->data << "\t";
    }

    findLargerValues(node->left, value);
    findLargerValues(node->right, value);
}

// Function to determine whether the node with the given value is in the left or right subtree
void Successor(tree* root, int value) {
    if (root == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }

    tree* node = root;
    tree* parent = NULL;

    // Traverse the tree to find the node and its parent
    while (node != NULL && node->data != value) {
        parent = node;
        if (value < node->data) {
            node = node->left;
        } else {
            node = node->right;
        }
    }

    if (node == NULL) {
        cout << "Node not found in the tree." << endl;
    } else {
        findLargerValues(root, value);  
        cout << endl;
    }
}


int Height(tree *node, int x)
{
    if (node == NULL)
    {
        return -1; // Element not found
    }

    if (node->data == x)
    {
        return 3; // Element found at the root, height is 0
    }

    int leftHeight = Height(node->left, x);
    if (leftHeight != -1)
    {
        return leftHeight - 1; // Element found in the left subtree, add 1 to its height
    }

    int rightHeight = Height(node->right, x);
    if (rightHeight != -1)
    {
        return rightHeight - 1; // Element found in the right subtree, add 1 to its height
    }

    return -1; // Element not found
}


// Function to find the level of a given element x in the tree
int Level(tree *node, int x, int level)
{
    if (node == NULL)
    {
        return 0; // Element not found
    }
    if (node->data == x)
    {
        return level; // Element found
    }

    // Recursively search in the left and right subtrees
    int leftLevel = Level(node->left, x, level + 1);
    int rightLevel = Level(node->right, x, level + 1);

    if (leftLevel != 0)
    {
        return leftLevel; // Element found in the left subtree
    }

    if (rightLevel != 0)
    {
        return rightLevel; // Element found in the right subtree
    }

    return 0; // Element not found
}


// Pre order traversal
void PreOrder(tree* node){ // root node will be present in the starting 
	if(node!= NULL){
		cout<<node->data << "\t";
		PreOrder(node->left);
		PreOrder(node->right);
	}
}


int main(){
	cout<<"Heap Tree:"<<endl;

	root = insertion(root, 20);
    root = insertion(root, 30);
    root = insertion(root, 80);
    root = insertion(root, 10);
    root = insertion(root, 50);
    root = insertion(root, 25);
    root = insertion(root, 18);
    root = insertion(root, 97);
    root = insertion(root, 40);
	PreOrder(root);
	cout<<endl;
	
	cout<<endl<<"Mirror Image:"<<endl;
	MirrorImage(root);
	PreOrder(root);
	cout<<endl<<endl;
	
	int x;
	cout<<"enter element:"<<endl;
	cin>>x;
    

    cout << "Predecessors of " << x << ": " <<endl;
    Predecessor(root, x);
    
    
	cout << "Sucessors of " << x << ": "<<endl;
	Successor(root, x);
	cout<<endl;



	int nodeHeight = Height(root, x);
    if (nodeHeight != -1) {
        cout << "Height of node " << x << ": " << nodeHeight << endl;
    } else {
        cout << "Node " << x << " not found in the tree." << endl;
    }
    
    
    int level = Level(root, x, 0);
	if (level != -1) {
	    cout << "Level of node " << x << " is: " << level << endl;
	} else {
	    cout << "Node " << x << " not found in the tree." << endl;
	}
	
	return 0;
}
