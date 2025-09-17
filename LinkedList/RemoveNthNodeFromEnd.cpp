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

void RemoveNthNode(Node* &head,int pos){
    Node* temp = head;
    Node* slow = head;
    Node* fast = head;
    int count = 0;
    while(count != pos){
        fast  = fast->next;
        count++;
    }
    while(fast->next != nullptr){
        fast = fast->next;
        temp = temp->next;
        slow = slow->next;
    }
    slow = slow->next;
    temp->next = slow->next;
    delete slow;
}
void PrintList(Node* &head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    Node* root = new Node(1);
    root->next = new Node(2);
    root->next->next = new Node(3);
    root->next->next->next = new Node(4);
    root->next->next->next->next = new Node(5);
    int n;
    cin>>n;
    RemoveNthNode(root,n);
    PrintList(root);
    return 0;
}