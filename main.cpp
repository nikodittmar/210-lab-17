// COMSC-210 | Lab 17 | Niko Dittmar
#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);

Node* deleteNode(Node *, int);

Node* insertNode(Node *, int, int);

void addFront(Node *);

void addTail(Node *);

void deleteList(Node *);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        if (!head) { // if this is the first node, it's the new head
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else { // its a second or subsequent node; place at the head
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
    output(head);

    // deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    head = deleteNode(head, entry - 1);
    output(head);

    // insert a node
    cout << "After which node to insert 10000? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;
    head = insertNode(head, entry - 1, 10000);
    output(head);

    // deleting the linked list
    deleteList(head);
    head = nullptr;
    output(head);

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

Node* deleteNode(Node *head, int index) {
    if (index == 0) {
        Node *newhead = head->next;
        delete head;
        return newhead;
    }

    // traverse that many times and delete that node
    Node *current = head;
    Node *prev = head;

    for (int i = 0; i < index; i++) {
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }

    return head;
}

Node* insertNode(Node *head, int index, int value) {
    Node *current = head;
    Node *prev = nullptr;

    for (int i = 0; i < index; i++) {
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = value;
    newnode->next = current;
    if (prev) {
        prev->next = newnode;
        return head;
    } else {
        return newnode;
    }    
}

void insertFront(Node *head, int value) {

}

void deleteList(Node *head) {
    Node *current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
}