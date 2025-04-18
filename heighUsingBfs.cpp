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

        int ans = 0;
        queue<pair<Node*,int>> q;
        q.push({head,1});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            ans = max(ans,curr.second);
            if(curr.first->left) q.push({curr.first->left,curr.second+1});
            if(curr.first->right) q.push({curr.first->right,curr.second+1});

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


        int ans = height(head);

        cout<<"height of tree is :"<<ans;
        
        return 0;
    }