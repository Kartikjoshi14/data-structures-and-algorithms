#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
     int data;
     Node* next;

     Node(int val){
        data = val;
        next=nullptr;
     }
};

void ReverseListIterative(Node* &root){
    Node* prev = nullptr;
    Node* next = nullptr;
    Node* curr = root;
    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    root = prev;
}

void ReverseListRecursive(Node* &root){
    if(!root || !root->next) return;
    Node* curr = root->next;
    ReverseListRecursive(root->next);
    curr->next = root;
    root->next = nullptr;
    root = curr;
}

void PrintList(Node* &root){
    Node* curr = root;
    while(curr != nullptr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}
int main(){
    Node* root = new Node(1);
    root->next = new Node(2);
    root->next->next = new Node(3);
    root->next->next->next = new Node(4);
    root->next->next->next->next = new Node(5);
    ReverseListIterative(root);
    cout<<"reverseal using iterative:"<<endl;
    PrintList(root);
    ReverseListRecursive(root);
    cout<<"revese using recursive"<<endl;
    PrintList(root);
    return 0;
}