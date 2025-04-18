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

int diameterOfTree(Node * head,int &diameter){
    if(head == nullptr){
        return 0;
    }
    int left = diameterOfTree(head->left,diameter);
   
    int right = diameterOfTree(head->right,diameter);
   

    diameter = max(diameter,left+right);

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

  

    int diameter=0;

    int res = diameterOfTree(head,diameter);

    cout<<"DIAMETER OF TREE IS:"<<diameter<<endl;
    cout<<"HEIGHT OF TREE IS:"<<res;

    return 0;
}