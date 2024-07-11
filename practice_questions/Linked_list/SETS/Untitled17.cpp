// Build a Binary Tree by inserting elements in the same manner as nodes are inserted in the heap
// i.e. from left to right. Each node should hold a string value.
// Given a pointer to the root of a binary tree.

// * Find its mirror image ; mirror image of the tree is build such that the left child of the root
//   is now the right child and right is now the left child.
// * Given an element x, find the predecessors and successors of x, if x exists.
// * Find the level of any element x in the tree , if x exists.
// * Find the height of the node of any element x in the tree,if x exists.

#include <iostream>
#include <list>

struct Heap_Node
{
    int data;
    Heap_Node *left;
    Heap_Node *right;
};

struct Heap_Node *start = NULL;

// Function to insert elements left to right in a binary tree
Heap_Node *insertion_left_to_right(Heap_Node *node, int value)
{
    if (node == NULL)
    {
        struct Heap_Node *new_node = new Heap_Node();
        new_node->data = value;
        new_node->left = new_node->right = NULL;
        return new_node;
    }
    else
    {
        // Insert the new value in a left-to-right manner (filling each level from left to right)
        if (node->left == NULL)
        {
            node->left = insertion_left_to_right(node->left, value);
            if (node->left->data > node->data)
            {
                std::swap(node->data, node->left->data);
            }
        }
        else if (node->right == NULL)
        {
            node->right = insertion_left_to_right(node->right, value);
            if (node->right->data > node->data)
            {
                std::swap(node->data, node->right->data);
            }
        }
        else
        {
            // If both children are already present, recursively insert in the left subtree
            node->left = insertion_left_to_right(node->left, value);

            // Adjust the max-heap property in the left subtree
            if (node->left->data > node->data)
            {
                std::swap(node->data, node->left->data);
            }
        }
    }
    return node;
}

// Function to find the mirror image of a binary tree
Heap_Node *mirror_image(Heap_Node *node)
{
    if (node == NULL)
    {
        return node;
    }

    // Swap the left and right subtrees of the current node
    struct Heap_Node *temp = node->left;
    node->left = node->right;
    node->right = temp;

    // Recursively mirror the left and right subtrees
    mirror_image(node->left);
    mirror_image(node->right);

    return node;
}

// Function to find the predecessors and successors of a given element x
void find_Predecessors_And_Successors(Heap_Node *node, int x, std::list<int> &predecessors, std::list<int> &successors)
{
    if (node == NULL)
    {
        return;
    }

    // Recursively search for predecessors and successors
    if (node->data < x)
    {
        predecessors.push_back(node->data); // "predecessor" refers to smaller values that come before the node.
    }
    else if (node->data > x)
    {
        successors.push_back(node->data); // "successor" refers to greater values that come after the node.
    }

    find_Predecessors_And_Successors(node->left, x, predecessors, successors);
    find_Predecessors_And_Successors(node->right, x, predecessors, successors);
}

// Function to find the level of a given element x in the tree
int find_Level(Heap_Node *node, int x, int level)
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
    int leftLevel = find_Level(node->left, x, level + 1);
    int rightLevel = find_Level(node->right, x, level + 1);

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

// Function to find the height of a given element x in the tree
int find_Height(Heap_Node *node, int x)
{
    if (node == NULL)
    {
        return -1; // Element not found
    }

    if (node->data == x)
    {
        return 3; // Element found at the root, height is 0
    }

    int leftHeight = find_Height(node->left, x);
    if (leftHeight != -1)
    {
        return leftHeight - 1; // Element found in the left subtree, add 1 to its height
    }

    int rightHeight = find_Height(node->right, x);
    if (rightHeight != -1)
    {
        return rightHeight - 1; // Element found in the right subtree, add 1 to its height
    }

    return -1; // Element not found
}

// Function to perform a pre-order traversal of the binary tree
void Pre_Order(Heap_Node *node)
{
    if (node != NULL)
    {
        std::cout << node->data << " , ";
        Pre_Order(node->left);
        Pre_Order(node->right);
    }
}

int main()
{
    struct Heap_Node *root = NULL;

    root = insertion_left_to_right(root, 20);
    root = insertion_left_to_right(root, 30);
    root = insertion_left_to_right(root, 80);
    root = insertion_left_to_right(root, 10);
    root = insertion_left_to_right(root, 50);
    root = insertion_left_to_right(root, 25);
    root = insertion_left_to_right(root, 18);
    root = insertion_left_to_right(root, 97);
    root = insertion_left_to_right(root, 40);

    std::cout << "Max-Heap Tree: ";
    Pre_Order(root);

    std::cout << std::endl;

    // Call the mirror_image function to find the mirror image
    root = mirror_image(root);

    std::cout << "Mirror Image of the Max-Heap Tree: ";
    // Print the tree (mirror image) using Pre_Order
    Pre_Order(root);

    // Define the target element for finding predecessors and successors
    int target_element = 30;
    std::list<int> predecessors, successors;

    // Find predecessors and successors of the target element
    find_Predecessors_And_Successors(root, target_element, predecessors, successors);

    std::cout << "\nPredecessors of " << target_element << ": ";
    for (int &predecessor : predecessors)
    {
        std::cout << predecessor << " , ";
    }

    std::cout << "\nSuccessors of " << target_element << ": ";
    for (int &successor : successors)
    {
        std::cout << successor << " , ";
    }

    std::cout << std::endl;

    // Find the level of the target element
    int search_level = 30;
    int level = find_Level(root, search_level, 0);
    if (level == 0)
    {
        std::cout << "Level of element " << search_level << " is: " << level;
    }
    else if (level != 0)
    {
        std::cout << "Level of element " << search_level << " is: " << level;
    }
    else
    {
        std::cout << "Element " << search_level << " not found in the tree.";
    }

    std::cout << std::endl;

    // Find the height of the target element
    int search_height = 30;
    int Height = find_Height(root, search_height);
    if (Height != -1)
    {
        std::cout << "Height of element " << search_height << " is: " << Height;
    }
    else
    {
        std::cout << "Element " << search_height << " not found in the tree.";
    }

    return 0;
}
