#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node * right;
    Node * left;
    Node(int temp){
        data = temp;
        left = right = nullptr;
    }
};

vector<int> iterativeInOrder(Node * root){
    vector<int> ans;
    stack<Node*> stk;

    Node* curr = root;
    while (curr != nullptr || !stk.empty()) {
        // Traverse to the leftmost node
        while (curr != nullptr) {
            stk.push(curr);
            curr = curr->left;
        }
        // Process the node at the top of the stack
        curr = stk.top();
        stk.pop();
        ans.push_back(curr->data);

        // Move to the right subtree
        curr = curr->right;
    }

    return ans;
}
int main(){

    struct Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(2);
    
    vector<int> ans = iterativeInOrder(root);
    cout<<"IN-ORDER TRAVERSAL"<<endl;
    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;
}