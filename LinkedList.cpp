#include "bits/stdc++.h"
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int d){
        this-> data =d;
        this-> next = NULL;
    }

    ~node(){
       int value = this->data;
       if(this->next!=NULL){
        delete next;
        this->next = NULL;        
       } 
       cout<<"Memory is freed for: "<<value<<endl;
    }
};
void print(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<< " ";
        temp = temp->next;
    }
    cout<<endl;
}

void InsertAtTail(node* &tail, int data){
    node* temp = new node(data);
    tail -> next = temp;
    tail  = temp;
}

void InsertAtHead(node* &head, int data){
    node* temp = new node(data);
    temp ->next = head;
    head = temp;
}

void InsertAtPosition(node*& head,node* &tail, int data, int pos){
    node* temp = new node(data);
    node* cur = head;
    if(pos == 1){
        InsertAtHead(head,data);
        return;
    }

    int count = 1;
    while(count<pos-1){
        cur = cur-> next;
        count++;
    }
    temp->next = cur->next;
    cur-> next = temp;
    if(temp->next == NULL){
        tail = temp;
    }

}

void Deletenode(node* &head,node* &tail, int pos){
    if(pos == 1){
        node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        node* cur = head;
        node* prev = NULL;
        int count=1;
        while(count<pos){
            prev = cur;
            cur = cur->next;
            count++;
        }
        prev->next = cur->next;
        cur->next  = NULL;
        delete cur;

    }
}

int main(){

    node* n = new node(10);
    node* head = n;
    node* tail = n;

    print(head);
    InsertAtHead(head,15);
    print(head);
    InsertAtHead(head,22);
    print(head);

    InsertAtTail(tail, 5);
    print(head);

    InsertAtPosition(head,tail, 1, 5);
    print(head);

    Deletenode(head,tail, 3);
    print(head);
    cout<<"The position of head is: "<<head->data<<endl;
    cout<<"The position of tail is: "<<tail->data<<endl;

    return 0;
}