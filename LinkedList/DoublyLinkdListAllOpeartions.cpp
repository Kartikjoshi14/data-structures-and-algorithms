#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
     int data;
     Node* next;
     Node* prev;

     Node(int val){
        data = val;
        next = prev =nullptr;
     }
};

void InsertionAtBeg(Node* &head,int val){
    Node* new_node = new Node(val);
    new_node->next = head;
    head->prev  = new_node;
    head = new_node;
}

void InsertionAtPos(Node* &head,int val,int pos){
    Node* new_node = new Node(val);
    Node* temp = head;
    int count = 1;
    while(count != pos-1){
        temp = temp->next;
        count++;
    }
    new_node->next = temp->next;
    temp->next->prev = new_node;
    temp->next  = new_node;
    new_node->prev = temp;
}

void InsertionAtEnd(Node* &head,int val){
    Node* new_node = new Node(val);
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

void DeletionAtBeg(Node* &head){
    Node* temp = head;
    head = head->next;
    delete temp;
}
void DeletionAtPos(Node* &head,int pos){
    Node* temp = head;
    Node* curr = head;
    int count = 1;
    while(count != pos-1){
        temp = temp->next;
        curr = curr->next;
        count++;
    }
    temp = temp->next;
    curr->next = temp->next;
    temp->next->prev = curr;
    delete temp;
}

void DeletionAtEnd(Node* &head){
    Node* temp = head;
    Node* curr = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
        curr = curr->next;
    }
    temp = temp->next;
    curr->next = nullptr;
    delete temp;
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
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    cout<<"Original list:"<<endl;
    PrintList(head); 
    cout<<"insertion at beg:val=0\n";
    int val = 0;
    InsertionAtBeg(head,val);
    PrintList(head);
    cout<<"insertion at pos=2,val=6\n";
    int pos = 4;
    val = 6;
    InsertionAtPos(head,val,pos);
    PrintList(head);
    cout<<"insertion at end:val=5\n";
     val = 5;
    InsertionAtEnd(head,val);
    PrintList(head);
    cout<<"Deletion at beg:\n";
    DeletionAtBeg(head);
    PrintList(head);
    cout<<"Deletion at pos:3\n";
    pos = 3;
    DeletionAtPos(head,pos);
    PrintList(head);
    cout<<"deletion at end;"<<endl;
    DeletionAtEnd(head);
    PrintList(head);
    return 0;
}