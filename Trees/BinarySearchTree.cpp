#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
     int data;
     Node* left;
     Node* right;
     Node(int val){
        data = val;
        left=right=nullptr;
     }
};
Node* Insert(Node* &root,int val){
    if(root==nullptr) return new Node(val);
    if(val < root->data){
        root->left = Insert(root->left,val);
    }else if(val > root->data){
        root->right = Insert(root->right,val);
    }
    return root;
}

bool Search(Node* &root,int key){
    if(root==nullptr) return false;
    else if(key==root->data) return true;
    else if(key<root->data) return Search(root->left,key);
    else return Search(root->right,key);
}

Node* minValueNode(Node* &root){
    Node* curr = root;
    while(curr && curr->left){
        curr = curr->left;
    }
    return curr;
}
Node* deletenode(Node* &root,int key){
    if(root==nullptr) return nullptr;
    if(key < root->data){
        root->left = deletenode(root->left,key);
    }else if(key > root->data){
        root->right = deletenode(root->right,key);
    }else{
        //Node with one child
        if(root->left == nullptr){
            Node* temp = root->right;
            delete root;
            return temp;
        }else if(root->right == nullptr){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //Node with two children
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right,temp->data);
    }
    return root;
}

void Inorder(Node* &root){
    if(root==nullptr) return ;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
int main(){
    Node* root = nullptr;
    vector<int> arr={50,70,30,20,40,60,80};
    for(int val:arr){
        root = Insert(root,val);
    }
    int key = 30;
    cout<<Search(root,key)<<endl;
    root = deletenode(root,20);
    root = deletenode(root,30);
    Inorder(root);
    return 0;


}