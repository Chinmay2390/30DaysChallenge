#include <iostream>
using namespace std;

// Define the structure of a Node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to perform in-order traversal
void inOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    
    // Traverse left subtree
    inOrderTraversal(root->left);
    
    // Visit the root
    cout << root->data << " ";
    
    // Traverse right subtree
    inOrderTraversal(root->right);
}

int main() {
    // Creating a simple binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    cout << "In-order Traversal: ";
    inOrderTraversal(root);  // Output: 4 2 5 1 3
    
    return 0;
}
