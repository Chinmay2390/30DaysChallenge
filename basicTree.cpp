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

void inOrder(Node * head){
    // root is printed in middle 

    if(head == nullptr){
        return;
    }
    inOrder(head->left);
    cout<<head->data<<" ";
    inOrder(head->right);
}

void preOrder(Node * head){
    
    if(head == nullptr){
        return;
    }
    cout<<head->data<<" ";
    preOrder(head->left);
    preOrder(head->right);
}

void postOrder(Node * head){

    if(head == nullptr){
        return;
    }
    postOrder(head->left);
    postOrder(head->right);
    cout<<head->data<<" ";
}

int main(){
    
    Node * head = new Node(5);

    head->left = new Node(4);
    head->right = new Node(6);

    head->left->left = new Node(3);
    head->left->right = new Node(2);

    head->right->left = new Node(11);
    head->right->right = new Node(9);


    preOrder(head);
    cout<<endl;
    inOrder(head);
    cout<<endl;
    postOrder(head);
    cout<<endl;

    return 0;
}