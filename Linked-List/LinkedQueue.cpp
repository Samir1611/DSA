#include <iostream>
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

class Queue {
public:
    Node* front;
    Node* rear;
    Queue() {
        front = NULL;
        rear = NULL;
    }
   void enqueueatEnd(int data) {
        Node* new_node = new Node(data);
        if (rear == NULL) {
            front = new_node;
            rear = new_node;
        }
        else {
            rear->next = new_node;
            rear = new_node;
        }
    }
    void dequeuefromFront() {
        if (front == NULL) {
            cout << "Queue is empty, nothing to dequeue" << endl;
            return;
        }
        Node* temp = front;
        cout << "Dequeued item is " << front->data << endl;
        if (front == rear) {
            front = NULL;
            rear = NULL;
        }
        else {
            front = front->next;
        }
        delete temp;
    }


    void peek() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
        }
        else {
            cout << front->data << " is at the front of the queue" << endl;
        }
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " <- ";
            temp = temp->next;
        }
        cout << "Null" << endl;
    }
};

int main() {

    Queue queue;
    int choice, data;
    while (true) {
        cout << "1.Enqueue at End\t\t2. Delete from  Front\n3.Peek\t\t\t\t\t4. Display\t 5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
    
        case 1:
        	 cout << "Enter data to enqueue: ";
            cin >> data;
            queue.enqueueatEnd(data);
            break;
        case 2:
            queue.dequeuefromFront();
            break;
        case 3:
            queue.peek();
            break;
        case 4:
            queue.display();
            break;
        case 5:
            cout << "Exiting...";
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }
}

