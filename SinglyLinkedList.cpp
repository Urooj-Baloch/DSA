#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
       this->data=data;
       this->next=NULL;

    }
};
void InsertAtHead(Node* &head,int d){
        Node *temp= new Node(d);
        temp->next=head;
        head=temp;
    }
void InsertAtTail(Node* &tail, int d){
    Node* temp= new Node(d);
    tail->next=temp;
    tail=temp;  
}
void Position(Node* &head,int position,int d){
    Node*temp=head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    Node* nodeToInsert= new Node(d);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
}

void Print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    Print(head);
    InsertAtHead(head,12);
    Print(head);
    InsertAtTail(tail,13);
    Print(head);
    Position(head,2,9);
    Print(head);
    Position(tail,2,15);
}