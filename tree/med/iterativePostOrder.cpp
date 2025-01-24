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

vector<int> iterativePostOrder(Node * root){
    vector<int> ans;

    if(root == nullptr){
        return ans;
    }
    
    stack<Node *> stk1;

    stk1.push(root);
    while(!stk1.empty()){
        Node * curr = stk1.top();
        stk1.pop();
        ans.push_back(curr->data);

        if(curr->right){
            stk1.push(curr->right);
        }
        if(curr->left){
            stk1.push(curr->left);
        }
    }

    return ans;
}
int main(){
    // Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);

    struct Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(2);
    
    vector<int> ans = iterativePostOrder(root);
    cout<<"PRE-ORDER TRAVERSAL"<<endl;
    for(auto it : ans){
        cout<<it<<" ";
    }

    return 0;
}