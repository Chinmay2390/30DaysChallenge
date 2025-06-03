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

int maxPathSum(Node * head,int& maxi){

    if(head == nullptr){
        return 0;
    }


    int left = max(0,maxPathSum(head->left,maxi));
    int right = max(0,maxPathSum(head->right,maxi));

    maxi = max(maxi,left+right+head->data);

    return head->data + max(left,right);
}



int main(){
    
    Node * head = new Node(5);

    head->left = new Node(4);
    head->right = new Node(6);

    head->left->left = new Node(3);
    head->left->right = new Node(2);

    head->right->left = new Node(11);
    head->right->right = new Node(9);

    int maxi = INT_MIN;

    int ans = maxPathSum(head,maxi);
    cout<<"MAXIMUM PATH SUM IS:"<<maxi;

    return 0;
}