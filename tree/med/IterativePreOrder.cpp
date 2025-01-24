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

vector<int> iterativePreOrder(struct Node * root){
    vector<int> ans;
    if(root == nullptr){
        return ans;
    }

    stack<Node *> stk1,stk2;
    stk1.push(root);
    Node * curr;

    while(!stk1.empty()){
        curr = stk1.top();
        stk1.pop();
        stk2.push(curr);

        if(curr->left != nullptr){
            stk1.push(curr->left);
        }
        if(curr->right != nullptr){
            stk1.push(curr->right);
        }
    }

    while (!stk2.empty()) {
        curr = stk2.top();
        stk2.pop();
        ans.push_back(curr->data);
    }

    return ans;

}

int main(){

    // struct Node* root = new Node(5);
    // root->left = new Node(4);
    // root->right = new Node(6);
    // root->left->left = new Node(3);
    // root->left->right = new Node(4);

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    vector<int> ans = iterativePreOrder(root);
    cout<<"PRE-ORDER TRAVERSAL"<<endl;
    for(auto it : ans){
        cout<<it<<" ";
    }


    return 0;
}