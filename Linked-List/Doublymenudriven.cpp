#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class Doubly {
public:
    Node *head;
    Node *tail;

    Doubly() {
        head = NULL;
        tail = NULL;
    }

    void insertatHead(int data) {
        Node *new_node = new Node(data);
        if (head == NULL) {
            head = new_node;
            tail = new_node;
            return;
        }
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }

    void insertatTail(int data) {
        Node *new_node = new Node(data);
        if (tail == NULL) {
            head = new_node;
            tail = new_node;
            return;
        }
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }

    void insertatK(int data, int pos) {
        if (pos == 1) {
            insertatHead(data);
            return;
        }
        Node *new_node = new Node(data);
        Node *temp = head;
        int current_pos = 1;
        while (current_pos < pos - 1 && temp != NULL) {
            temp = temp->next;
            current_pos++;
        }
        if (temp == NULL) {
            cout << "Position out of range" << endl;
            return;
        }
        new_node->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = new_node;
        temp->next = new_node;
        new_node->prev = temp;
    }

    void deleteathead() {
        if (head == NULL) {
            cout << "List is empty, nothing to delete" << endl;
            return;
        }
        Node *temp = head;
        cout << "Deleted item is " << head->data << endl;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        } else {
            head->prev = NULL;
        }
        delete temp;
    }

    void deleteatend() {
        if (head == NULL) {
            cout << "List is empty, nothing to delete" << endl;
            return;
        }
        if (head->next == NULL) {
            cout << "Deleted item is " << head->data << endl;
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }
        Node *temp = tail->prev;
        cout << "Deleted item is " << tail->data << endl;
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    void deleteatK(int pos) {
        if (head == NULL) {
            cout << "List is empty, nothing to delete" << endl;
            return;
        }
        if (pos == 1) {
            deleteathead();
            return;
        }
        Node *temp = head;
        int currentPos = 1;
        while (currentPos < pos - 1 && temp != NULL) {
            temp = temp->next;
            currentPos++;
        }
        if (temp == NULL || temp->next == NULL) {
            cout << "Position out of range" << endl;
            return;
        }
        Node *toDelete = temp->next;
        temp->next = toDelete->next;
        if (toDelete->next != NULL)
            toDelete->next->prev = temp;
        else
            tail = temp;
        cout << "Deleted item at position " << pos << ": " << toDelete->data << endl;
        delete toDelete;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "Null" << endl;
    }
};

int main() {
    Doubly L;
    int ch, data, pos;
    while (true) {
        cout << "1. Insert at Head\t\t2. Insert at Tail\t\t3. Insert at K\n";
        cout << "4. Delete at Head\t\t5. Delete at Tail\t\t6. Delete at K\n";
        cout << "7. Display\t\t\t8. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Enter data to insert: ";
            cin >> data;
            L.insertatHead(data);
            break;
        case 2:
            cout << "Enter data to insert: ";
            cin >> data;
            L.insertatTail(data);
            break;
        case 3:
            cout << "Enter position to insert: ";
            cin >> pos;
            cout << "Enter data to insert: ";
            cin >> data;
            L.insertatK(data, pos);
            break;
        case 4:
            L.deleteathead();
            break;
        case 5:
            L.deleteatend();
            break;
        case 6:
            cout << "Enter position to delete: ";
            cin >> pos;
            L.deleteatK(pos);
            break;
        case 7:
            L.display();
            break;
        case 8:
            cout << "Exiting...";
            return 0;
        default: 
        cout<<"Invalid Choice";
        break;
    }}}
            

