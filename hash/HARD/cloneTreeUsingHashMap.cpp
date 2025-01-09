#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//this is tree structure...
class Node{
    public:
    int data;
    Node * left;
    Node * right;
    Node * random;

    Node(int x){
        data = x;
        left = right = random = nullptr;
    }
};


void copyLeftRightNode(Node * root,unordered_map<Node * ,Node *> &mp){
    if(root == nullptr){
        return;
    }


}
void copyRandom(Node * root,unordered_map<Node * ,Node *> &mp){
    if(root == nullptr){
        return;
    }
}
Node * treeCopy(Node * root){

    if(root == nullptr){
        return nullptr;
    }
    unordered_map<Node * ,Node *> mp;
    Node * copyNode = new Node();
    copyRandom(root,mp);
    copyLeftRightNode(root,mp);

    return copyNode;
}

int main(){
    // first lets create tree
            // 1
            // /  \        
            // 2   3
            // / \
            // 4  5
    Node * node = new Node(1);
    node->left = new Node(2);
    node->right = new Node(3);
    node->left->left = new Node(4);
    node->left->right = new Node(5);

    // 1 to 5, 5 to 3 and 4 to 1
    // adding random pointers
    node->random = node->left->right;
    node->left->right->random = node->right;
    node->left->left->random = node;

    Node * copy_node = treeCopy(node);

    return 0;
}