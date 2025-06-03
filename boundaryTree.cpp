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


bool isLeaf(Node * node){
    if(node->left==nullptr && node->right==nullptr){
        return true;
    }
    return false;
}


void leftNodes(Node * head,vector<int> &res){
    auto curr = head->left;
    while(curr){
        if(!isLeaf(curr)) res.push_back(curr->data);
        if (curr->left) curr=curr->left;
        else curr=curr->right;
        
    }

}

void rightNodes(Node * head,vector<int> &res){

    auto curr = head->right;
    vector<int> rNodes;
    while(curr){
        if(!isLeaf(curr)) rNodes.push_back(curr->data);
        if (curr->left) curr=curr->right;
        else curr=curr->left;
        
    }
    for(int i = 0;i<rNodes.size();i++){
        res.push_back(rNodes[i]);
    }

}

void leafNodes(Node * head,vector<int> &res){

    if(head == nullptr){
        return;
    }
    if(head->left==nullptr && head->right==nullptr){
        res.push_back(head->data);
        return;
       
    }
    leafNodes(head->left,res);
    leafNodes(head->right,res);
}

void boundaryTree(Node * head,vector<int> &res){
    // first go left nodes
    // then take leaf nodes
    // take right nodes

    leftNodes(head,res);
    leafNodes(head,res);
    rightNodes(head,res);

}






int main(){
    
    Node * head = new Node(5);

    head->left = new Node(4);
    head->right = new Node(6);

    head->left->left = new Node(3);
    head->left->right = new Node(2);

    head->right->left = new Node(11);
    head->right->right = new Node(9);


    vector<int> res;

    res.push_back(head->data);

    boundaryTree(head,res);

    for(int i = 0;i<res.size();i++){
        cout<<res[i]<<" ";
    }

    return 0;
}