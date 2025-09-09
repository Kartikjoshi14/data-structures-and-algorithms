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

Node* MergeLists(Node* &head1,Node* &head2){
    Node* dummy = new Node(0);
    Node* temp = dummy;
    while(head1 && head2){
        if(head1->data < head2->data){
            temp->next = head1;
            head1 = head1->next;
        }else{
            temp->next = head2;
            head2 = head2->next;
        }
        temp  = temp->next;
    }
    while(head1){
        temp->next = head1;
        head1 = head1->next;
    }
    while(head2){
        temp->next = head2;
        head2 = head2->next;
    }
    Node* head = dummy->next;
    delete dummy;
    return head;
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
    Node* head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);

    Node* head2= new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    
    Node* head = MergeLists(head1,head2);
    PrintList(head);
    return 0;
}