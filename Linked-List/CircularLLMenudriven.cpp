#include<iostream>
#include <cstdlib>
using namespace std;

class Node {
public:
    Node* next;
    int val;
    Node(int data) {
        val = data;
        next = NULL;
    }
};

class CircularLinkedList {
public:
    Node* head;
    CircularLinkedList() {
        head = NULL;
    }

    void display() {
        if(head == NULL) {
            cout << "Circular Linked List is empty" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->val << " -> ";
            temp = temp->next;
        } while(temp != head);
        cout << endl;
    }

    void insertatStart(int val) {
        Node* new_node = new Node(val);
        if(head == NULL) {
            head = new_node;
            new_node->next = head;
            return;
        }

        Node* tail = head;
        while(tail->next !=  head) {
            tail = tail->next;
        }
        tail->next = new_node;
        new_node->next = head;
        head = new_node;
    }

    void insertatK(int val, int pos) {
        if(pos == 1) {
            insertatStart(val);
            return;
        }
        Node* new_node = new Node(val);
        Node* temp = head;
        int current_pos = 1;
        while(current_pos != pos-1 ) {
            temp = temp->next;
            current_pos++;
        }
        if(temp == NULL) {
            cout << "Position out of range" << endl;
            return;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }

    void insertatEnd(int val) {
        Node* new_node = new Node(val);
        if(head == NULL) {
            head = new_node;
            new_node->next = head;
            return;
        }
        Node* tail = head;
        while(tail->next !=  head) {
            tail = tail->next;
        }
        tail->next = new_node;
        new_node->next = head;
    }

    void deleteatStart() {
        if(head == NULL) {
            cout << "Circular Linked List is empty" << endl;
            return;
        }
        Node* temp = head;
        Node* tail = head;
        while(tail->next != head) {
            tail = tail->next;
        }
        head = head->next;
        tail->next = head;
        delete temp;
    }

    void deleteatK(int pos) {
        if(head == NULL) {
            cout << "Circular Linked List is empty" << endl;
            return;
        }
        if(pos == 0) {
            deleteatStart();
            return;
        }
        Node* temp = head;
        int current_pos = 0;
        while( current_pos != pos-1) {
            temp = temp->next;
            current_pos++;
        }
        if(temp == NULL ) {
            cout << "Position out of range" << endl;
            return;
        }
        Node* to_delete = temp->next;
        temp->next = temp->next->next;
        delete to_delete;
    }

    void deleteatEnd() {
        if(head == NULL) {
            cout << "Circular Linked List is empty" << endl;
            return;
        }
        Node* tail = head;
        while(tail->next->next != head) {
            tail = tail->next;
        }
        Node* temp = tail->next;
        tail->next = head;
        delete temp;
    }

    void search(int val) {
        if(head == NULL) {
            cout << "Circular Linked List is empty" << endl;
            return;
        }
        Node* temp = head;
        bool found = false;
        do {
            if(temp->val == val) {
                cout << "Item " << val << " is present" << endl;
                found = true;
                break;
            }
            temp = temp->next;
        } while(temp != head);
        if(!found) {
            cout << "Item not found" << endl;
        }
    }
};

int main() {
    CircularLinkedList C;
    int choice, val, pos;
    while(true) {
        cout << "1. Insert at Start\t2. Insert at End\t3. Insert at K\n";
        cout << "4. Delete at Start\t5. Delete at End\t6. Delete at K\n";
        cout << "7. Search\t\t8. Display\t\t9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter value to insert at start: ";
                cin >> val;
                C.insertatStart(val);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> val;
                C.insertatEnd(val);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Enter position to insert: ";
                cin >> pos;
                C.insertatK(val, pos);
                break;
            case 4:
                C.deleteatStart();
                break;
            case 5:
                C.deleteatEnd();
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> pos;
                C.deleteatK(pos);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> val;
                C.search(val);
                break;
            case 8:
                cout << "Circular Linked List: ";
                C.display();
                break;
            case 9:
                cout << "Exiting...";
                exit(0);
            default:
                cout << "Invalid choice" << endl;
        }
    }
}

