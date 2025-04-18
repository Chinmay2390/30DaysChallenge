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

    return max(height(head->left),height(head->right))+1;
}
bool balancedTree(Node * head){

    if(head == nullptr){
        return true;
    }

    int lh = height(head->left);
    int rh = height(head->right);

    if(abs(lh-rh)>1){
        return false;
    }

    bool left = balancedTree(head->left);
    bool right = balancedTree(head->right);

    if(left == false || right == false){
        return false;
    }

    return true;
}



int main(){
    
    Node * head = new Node(5);

    head->left = new Node(4);

    head->left->left = new Node(3);
    head->left->right = new Node(2);




    cout<<balancedTree(head);
    
    return 0;
}