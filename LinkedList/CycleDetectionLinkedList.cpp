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

bool DetectCycle(Node* &root){
    Node* slow =root;
    Node* fast = root;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast) return true;
    }
    return false;
}
int main(){
    Node* root = new Node(1);
    root->next = new Node(2);
    root->next->next = new Node(3);
    root->next->next->next = new Node(4);
    root->next->next->next->next = root->next->next;
    cout<<DetectCycle(root)<<endl;
    return 0;
}