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

int height(Node * head){
    if(head == nullptr){
        return 0;
    }
    int left = height(head->left);
    if(left == -1){
        return false;
    }
    int right = height(head->right);
    if(right == -1){
        return false;
    }

    if(abs(left-right)>1) return false;
    return max(left,right)+1;
}






int main(){
    
    Node * head = new Node(5);

    head->left = new Node(4);
    head->right = new Node(6);

    head->left->left = new Node(3);
    head->left->right = new Node(2);

    head->right->left = new Node(11);
    head->right->right = new Node(9);

  

    cout<<(height(head)?"1":"0");
    return 0;
}