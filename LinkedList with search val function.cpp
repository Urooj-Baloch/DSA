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
bool SearchValue(Node* head, int target){
    if(head==NULL){
        return false;
    }
    if(head->data==target){
        return true;
    }
    return SearchValue(head->next, target);
}
void List(Node* &head, int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
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
   List(head, 12);
   List(head, 13);
   List(head, 14);
   List(head, 15);
   List(head, 16);
    int searchNum;
    cout << "Enter a value to search in the linked list: ";
    cin >> searchNum;
    bool found = SearchValue(head, searchNum);
    if (found) {
        cout << "Value " << searchNum << " is found in the linked list." << endl;
    } else {
        cout << "Value " << searchNum << " is not found in the linked list." << endl;
    }
    cout<<"Here is the whole list: "<<endl;
      Print(head);
}