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

vector<vector<int>> zigZag(Node * head){

    vector<vector<int>> ans;
    int flag = true;
    queue<Node*> q;
    q.push(head);

    
    while(!q.empty()){
        int size = q.size();
        vector<int> subAns(size);

        for(int i = 0;i<size;i++){

            auto curr = q.front();
            q.pop();
            int index = flag?i:(size-1-i);
            subAns[index] = curr->data;

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
    
        }
        flag = !flag;
        ans.push_back(subAns);
    
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



    vector<vector<int>> ans = zigZag(head);
    
    for(int i = 0;i<ans.size();i++){
        for(int j = 0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
    }

    return 0;
}