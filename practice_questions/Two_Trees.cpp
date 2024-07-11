/* QUESTION: Write a program that takes two binary tree T1 and T2 as input, and perform following tasks:

- Checks whether two trees T1 and T2 are equal. Equal trees are those that have same data on the same nodes.

- Checks whether two trees T1 and T2 have same structure. Trees having same structure has same number 
  of children for each node but the values stored at the nodes can be different.

- Checks whether two trees T1 and T2 are mirror image of each other. a tree is mirror image of th other tree if for each node 
  the value on the left left child of the root is same as the right child value of the other tree and vice versa. */

#include<iostream>
using namespace std;

struct Tree{
	int data;
	Tree* left;
	Tree* right;
};
Tree* root1 = NULL;
Tree* root2 = NULL;

Tree* insert(Tree* node , int value){
	if (node == NULL) {  // If the current node is null, create a new node and return it.
        Tree* temp = new Tree();
        temp->data = value;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    if (value > node->data) {  // If 'value' is greater than the current node's data, insert it in the right subtree.
        node->right = insert(node->right, value);
    } else {  // If 'value' is less than or equal to the current node's data, insert it in the left subtree.
        node->left = insert(node->left, value);
    }
    return node;  // Return the updated node with the inserted value.
}

// Pre order traversal
void PreOrder(Tree* node){ // root node will be present in the starting 
	if(node!= NULL){
		cout<<node->data << "\t";
		PreOrder(node->left);
		PreOrder(node->right);
	}
}


int EqualTrees(Tree* T1 , Tree* T2){
	// if both trees are empty
	if(T1 == NULL && T2 == NULL){
		return 1; 
	}
	
	// both trees are non empty so we will compare
	if( T1 != NULL && T2 != NULL){   
		int match = T1->data == T2->data; // Check if the data at the current nodes is the same
		// Recursively check for left and right subtree.
		int LeftSubtree = EqualTrees(T1->left , T2->left);
		int RightSubtree = EqualTrees(T1->right , T2->right);
		return(match && LeftSubtree && RightSubtree);
	}
	return 0; // one tree is empty other is not
}



int SameStructure(Tree* T1 , Tree* T2){
	// if both trees are empty
	if(T1 == NULL && T2 == NULL){
		return 1; 
	}
	
	// both trees are non empty so we will compare
	if( T1 != NULL && T2 != NULL){   
		// Recursively check for left and right subtree.
		int LeftSubtree = SameStructure(T1->left , T2->left);
		int RightSubtree = SameStructure(T1->right , T2->right);
		return(LeftSubtree && RightSubtree);
	}
	return 0; // one tree is empty other is not
}


int MirrorImage(Tree* T1 , Tree* T2){
	// if both trees are empty
	if(T1 == NULL && T2 == NULL){
		return 1; 
	}
	
	// both trees are non empty so we will compare
	if( T1 != NULL && T2 != NULL){   
		// Recursively check for left and right subtree.
		int match = T1->data == T2->data; // Check if the data at the current nodes is the same
		int LeftSubtree = MirrorImage(T1->left , T2->right);
		int RightSubtree = MirrorImage(T1->right , T2->left);
		return(match && LeftSubtree && RightSubtree);
	}
	return 0; // one tree is empty other is not
}


int main(){
	cout<<"Tree 1: "<<endl;
	root1 = insert(root1 , 2);
	root1 = insert(root1 , 4);
	root1 = insert(root1 , 6);
	root1 = insert(root1 , 8);
	PreOrder(root1);
	cout<<endl;
	
	cout<<"Tree 2: "<<endl;
	root2 = insert(root2 , 20);
	root2 = insert(root2 , 40);
	root2 = insert(root2 , 60);
	root2 = insert(root2 , 80);
	PreOrder(root2);
	cout<<endl;
	
	
	int result = EqualTrees(root1 , root2);
    if (result) {
        cout << "The trees T1 and T2 are equal." << endl;
    } else {
        cout << "The trees T1 and T2 are not equal." << endl;
    }

	
	int res = SameStructure(root1 , root2);
    if (res) {
        cout << "The trees T1 and T2 have same structure." << endl;
    } else {
        cout << "The trees T1 and T2 do not have same structure." << endl;
    }
    
    int ans = MirrorImage(root1 , root2);
    if (ans) {
        cout << "The trees T1 and T2 are mirror image of each other." << endl;
    } else {
        cout << "The trees T1 and T2 are not mirror image of each other" << endl;
    }
	
	return 0;
}
