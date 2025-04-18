#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

vector<int> postOrder(Node * head){

    vector<int> ans;
    stack<Node *> st1,st2;
    Node * curr = head;

    st1.push(curr);


    while(!st1.empty()){
        
        curr = st1.top();
        st1.pop();
        st2.push(curr);

        if(curr->left) st1.push(curr->left);
        if(curr->right) st1.push(curr->right);
    
    }

    while(!st2.empty()){
        curr = st2.top();
        st2.pop();
        ans.push_back(curr->data);
    }

    return ans;
}



int main(){
    
    Node * head = new Node(5);

    head->left = new Node(4);
    head->right = new Node(6);

    head->left->left = new Node(3);
    head->left->right = new Node(2);

    head->right->left = new Node(11);
    head->right->right = new Node(9);


    vector<int> ans = postOrder(head);

    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}