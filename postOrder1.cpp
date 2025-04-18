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
    stack<Node *> st1;
    Node * curr = head;

    while(curr != nullptr || !st1.empty()){

        if(curr != nullptr){
            st1.push(curr);
            curr=curr->left;
        }

        else{

            Node * temp = st1.top()->right;
            if(temp == nullptr){
                temp = st1.top();
                st1.pop();
                ans.push_back(temp->data);
                while(!st1.empty() && st1.top()->right == temp){
                    temp = st1.top();
                    st1.pop();
                    ans.push_back(temp->data);
                }

            }
            else{
                curr=temp;
            }
        }

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