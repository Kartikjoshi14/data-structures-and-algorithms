#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
     int data;
     Node* next;

     Node(int val){
        data = val;
        next = nullptr;
     }
};
void InsertionAtBeg(Node* &head,int val){
    Node* new_node = new Node(val);
    Node* temp  = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = head;
    head = new_node;
}

void InsertionAtPos(Node* &head,int val,int pos){
    Node* temp = head;
    int count = 1;
    Node* new_node = new Node(val);
    while(count != pos-1){
        temp = temp->next;
        count++;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}
void InsertionAtEnd(Node* &head,int val){
    Node* new_node = new Node(val);
    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = head;
}

void DeletionAtBeg(Node* &head){
    Node* temp = head;
    Node* curr = head;
    while(curr->next != head){
        curr = curr->next;
    }
    curr->next = head->next;
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
    delete temp;
}

void DeletionAtEnd(Node* &head){
    Node* temp = head;
    Node* curr = head;
    while(temp->next->next != head){
        temp = temp->next;
        curr = curr->next;
    }
    temp = temp->next;
    curr->next = head;
    delete temp;
}
void PrintList(Node* &head){
    Node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next; 
    }while(temp != head);
    cout<<endl;
}
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;
    cout<<"original list:"<<endl;
    PrintList(head);
    cout<<"insertion at beg val:0\n";
    int val = 0;
    InsertionAtBeg(head,val);
    PrintList(head);
    cout<<"insertion at pos =4,val=5\n";
    val = 5;
    int pos = 4;
    InsertionAtPos(head,val,pos);
    PrintList(head);
    cout<<"insertion at end,val=6\n";
    InsertionAtEnd(head,6);
    PrintList(head);
    cout<<"deletion from beg\n";
    DeletionAtBeg(head);
    PrintList(head);
    cout<<"deletion at pos=3\n";
    DeletionAtPos(head,3);
    PrintList(head);
    cout<<"deletion at end\n";
    DeletionAtEnd(head);
    PrintList(head);
    return 0;
}