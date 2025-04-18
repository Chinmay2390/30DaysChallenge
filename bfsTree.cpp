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

vector<int> bfs(Node * head){

    vector<int> ans;
    queue<Node*> q;
    q.push(head);
    while(!q.empty()){
        Node * curr = q.front();
        q.pop();

        ans.push_back(curr->data);
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);

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


    vector<int> ans = bfs(head);

    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}