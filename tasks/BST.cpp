#include<iostream>
using namespace std;
struct BSTNode{
	int data;
	BSTNode* left;
	BSTNode* right;
};
BSTNode* root = NULL;

// Function to insert a node with the given 'value' into the binary search tree.
BSTNode* insertion(BSTNode* node, int value) {
    if (node == NULL) {  // If the current node is null, create a new node and return it.
        BSTNode* temp = new BSTNode();
        temp->data = value;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    if (value > node->data) {  // If 'value' is greater than the current node's data, insert it in the right subtree.
        node->right = insertion(node->right, value);
    } else {  // If 'value' is less than or equal to the current node's data, insert it in the left subtree.
        node->left = insertion(node->left, value);
    }
    return node;  // Return the updated node with the inserted value.
}


// Function to search for a specific 'tosearch' value in the binary search tree.
void searching(BSTNode* node, int tosearch) {
    if (node == NULL) {
        cout << "not found"; // If the current node is null, the value is not found in the tree.
    } else if (node->data == tosearch) {
        cout << "found"; // If the value matches the data in the current node, it's found.
    } else if (tosearch > node->data && node->right != NULL) {
        // If 'tosearch' is greater than the current node's data and the right subtree exists, search in the right subtree.
        searching(node->right, tosearch);
    } else if (tosearch < node->data && node->left != NULL) {
        // If 'tosearch' is less than the current node's data and the left subtree exists, search in the left subtree.
        searching(node->left, tosearch);
    } else {
        cout << "not found"; // If none of the above conditions match, the value is not found in the tree.
    }
}


// Function to delete a node with the specified 'todel' value from the binary search tree.
BSTNode* deletion(BSTNode* node, int todel) {
    if (node == NULL) {
        cout << "empty"; // If the tree is empty, there's nothing to delete.
    }
    if (todel < node->data) {
        node->left = deletion(node->left, todel);
    } else if (todel > node->data) {
        node->right = deletion(node->right, todel);
    } else {  // Node to delete found
        if (node->left == NULL) {
            // If the node has no left child, replace it with its right child.
            BSTNode* temp = node->right;
            delete node; // Delete the current node.
            return temp; // Return the right child to connect to the parent.
        }
        if (node->right == NULL) {
            // If the node has no right child, replace it with its left child.
            BSTNode* temp = node->left;
            delete node; // Delete the current node.
            return temp; // Return the left child to connect to the parent.
        } else {
            // If the node has two children, replace it with the smallest value from the right subtree.
            BSTNode* temp = node->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            int small = temp->data;
            node->data = small; // Replace the current node's data with the smallest value.
            node->right = deletion(node->right, todel); // Delete the node with the smallest value in the right subtree.
        }
    }
    return node; // Return the updated node after deletion.
}


// In order traversal
void InOrder(BSTNode* node){ // root node will be present in the middle
	if(node!= NULL){
		InOrder(node->left);
		cout<<node->data << endl;
		InOrder(node->right);
	}
}

// Pre order traversal
void PreOrder(BSTNode* node){ // root node will be present in the starting 
	if(node!= NULL){
		cout<<node->data << endl;
		PreOrder(node->left);
		PreOrder(node->right);
	}
}

// Post order traversal
void PostOrder(BSTNode* node){ // root node will be present in the end
	if(node!= NULL){
		PostOrder(node->left);
		PostOrder(node->right);
		cout<<node->data << endl;
	}
}

// height of each node in BST
int Height(BSTNode* node){
	if(node == NULL){
		return 0;
	}
	else{
		int LeftHeight = Height(node->left);
		int RightHeight = Height(node->right);
		int var = max(LeftHeight,RightHeight) + 1;
		cout<< node->data << " " << var << endl;
		return var;
	}
}


int main(){
//	root = insertion(root,75);
//	root = insertion(root ,85);
//	root = insertion(root,25);
//	root = insertion(root,5);
//	root = insertion(root,95);
//	PreOrder(root);
//	cout<<endl;
//	int search;
//	cout<<"enter number to be searched.";
//	cin>>search;
//	searching(root,search);
//	cout<<endl;
//	int todel;
//	cout<<"enter number to be delete.";
//	cin>>todel;
//	root = deletion(root,todel);
//	cout<<"the value "<<todel<< "is deleted." << endl;
//	cout<<endl;
//	PreOrder(root);
//	cout<<endl;
//	Height(root);
//	return 0;

	int op;
	char choice = 'y';
	while (choice == 'y'){
		cout<<"1. Insertion" << endl;
		cout<<"2. Searching" << endl;
		cout<<"3. Deletion" << endl;
		cout<<"4. In Order Traversal" << endl;
		cout<<"5. Pre Order Traversal" << endl;
		cout<<"6. Post Order Traversal" << endl;
		cout<<"7. Height of each node in BST" << endl;
		cout<<"Enter the operation you want to perform:"<<endl;
		cin>>op;
		switch (op){
		case 1:
			int value;
			cout<<"Enter the value to be inserted:"<<endl;
			cin>>value;
			root = insertion(root,value);
			break;
		case 2:
			int search_value;
			cout<<"Enter the value to be searched:"<<endl;
			cin>>search_value;
			searching(root,search_value);
			break;
		case 3:
			int delete_value;
			cout<<"Enter the value to be deleted:"<<endl;
			cin>>delete_value;
			root = deletion(root,delete_value);
			break;
		case 4:
			InOrder(root);
			break;
		case 5:
			PreOrder(root);
			break;
		case 6:
			PostOrder(root);
			break;
		case 7:
			Height(root);
			break;
		case 8: 
		break;	
		default:
			cout<<"invalid choice!";
	}
	cout<<"do you want to continue? y/n";
	cin>>choice;
}


}

