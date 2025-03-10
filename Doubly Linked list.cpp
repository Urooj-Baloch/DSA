#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Function to print the doubly linked list
void Print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}

// Insert at head
void AtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    
    if (head != NULL) {
        head->prev = temp;
    }

    head = temp;
}

// Insert at tail
void AtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

// Insert at a specific position
void AtPosition(Node* &head, Node* &tail, int position, int data) {
    if (position == 1) {
        AtHead(head, data);
        return;
    }

    Node* temp = head;
    int count = 1;

    while (count < position - 1 && temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    // If inserting at the last position
    if (temp->next == NULL) {
        AtTail(tail, data);
        return;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

int main() {
    // Create initial node
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    Print(head);

    // Insert at head
    AtHead(head, 12);
    Print(head);

    // Insert at tail
    AtTail(tail, 13);
    Print(head);

    // Insert at position
    AtPosition(head, tail, 2, 9);
    Print(head);

    // Insert another at position
    AtPosition(head, tail, 2, 15);
    Print(head);

    return 0;
}
