#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = NULL;
    }

    void insertatHead(int data) {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }

    void display() {
        if(head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << "-> ";
            temp = temp->next;
        }
        cout << "Null" << endl;
    }

    void insertatTail(int data) {
        Node* new_node = new Node(data);
        if(head == NULL) {
            head = new_node;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void insertatK(int data, int pos) {
        if(pos == 1) {
            insertatHead(data);
            return;
        }
        Node* new_node = new Node(data);
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

    void deleteathead() {
        if(head == NULL) {
            cout << "List is empty, nothing to delete" << endl;
            return;
        }
        Node* temp = head;
        cout<<"Deleted item is "<<head->data<<endl;
        head = head->next;
        delete temp;
    }

    void deleteatend() {
        if(head == NULL) {
            cout << "List is empty, nothing to delete" << endl;
            return;
        }
        if(head->next == NULL) {
            cout<<"Deleted item is "<<head->data<<endl;
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while(temp->next->next != NULL) {
            temp = temp->next;
            
        }
         Node* to_delete = temp->next;
           cout<<"Deleted item is "<<to_delete->data<<endl;
        delete temp->next;
        temp->next = NULL;
    }

    void deleteatK(int pos) {
        if(head == NULL) {
            cout << "List is empty, nothing to delete" << endl;
            return;
        }
        if(pos == 1) {
            deleteathead();
            
            return;
        }
        Node* temp = head;
        int current_pos = 1;
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
        cout<<"Deleted Item is "<<to_delete->data<<endl;
        delete to_delete;
    }

    void search(int data) {
        Node* temp = head;
        bool found = false;
        while(temp != NULL) {
            if(temp->data == data) {
                cout << "Item " << data << " is present" << endl;
                found = true;
                break;
            }
            temp = temp->next;
        }
        if(!found) {
            cout << "Item not found" << endl;
        }
    }
};

int main() {
    LinkedList list;
    int choice, data, pos;
    while(true) {
        cout << "1. Insert at Head\t\t2. Insert at Tail\t\t3. Insert at K\n4. Delete at Head\t\t5. Delete at Tail\t\t6. Delete at K\n7. Display\t\t\t8. Search\t\t\t9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                list.insertatHead(data);
                break;
            case 2:
                cout << "Enter data to insert: ";
                cin >> data;
                list.insertatTail(data);
                break;
            case 3:
                cout << "Enter position to insert: ";
                cin >> pos;
                 cout << "Enter data to insert: ";
                cin >> data;
                list.insertatK(data, pos);
                break;
            case 4:
                list.deleteathead();
                break;
            case 5:
                list.deleteatend();
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> pos;
                list.deleteatK(pos);
                break;
            case 7:
                list.display();
                break;
            case 8:
                cout << "Enter data to search: ";
                cin >> data;
                list.search(data);
                break;
            case 9:
                cout << "Exiting...";
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}
