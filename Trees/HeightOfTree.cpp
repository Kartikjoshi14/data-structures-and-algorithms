#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
     int data;
     Node* left;
     Node* right;

     Node(int val){
        data= val;
        left = right =nullptr;
     }
};

int HeightOfTree(Node* &root){
    if(root==nullptr) return 0;
    int left = HeightOfTree(root->left);
    int right = HeightOfTree(root->right);
    return 1 + max(left,right);
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<HeightOfTree(root);
    return 0;
}