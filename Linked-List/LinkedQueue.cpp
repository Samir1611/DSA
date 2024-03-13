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

    void enqueue(int data) {
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
    void enqueueatEnd(int data){
    Node* new_node = new Node(data);
    Node*temp = front;
    	  if (rear == NULL) {
            front = new_node;
            rear = new_node;
        }
        while(temp->next!=NULL){
        	
        	temp=temp->next;
		}
		temp->next = new_node;
	}
    void dequeue() {
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
    
    void dequeueatEnd() {
    if (front == NULL) {
        cout << "Queue is empty, nothing to delete" << endl;
        return;
    }
    if (front->next == NULL) {
        cout << "Deleted item is " << front->data << endl;
        delete front;
        front = NULL;
        rear = NULL;
        return;
    }
    Node* temp = front;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    Node* to_delete = temp->next;
    cout << "Deleted item is " << to_delete->data << endl;
    delete to_delete;
    temp->next = NULL;
    rear = temp; 
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
        cout << "1. Enqueue at Head\t\t2. Enqueue at Tail\t\t3. Delete at Head\n4.Delete at Tail\t\t5.Peek\t\t\t\t6. Display\t\t 7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter data to enqueue: ";
            cin >> data;
            queue.enqueue(data);
            break;
        case 2:
        	 cout << "Enter data to enqueue: ";
            cin >> data;
            queue.enqueueatEnd(data);
            break;
        case 3:
            queue.dequeue();
            break;
        case 4:
            queue.dequeueatEnd();
            break;
        case 5:
            queue.peek();
            break;
        case 6:
            queue.display();
            break;
        case 7:
            cout << "Exiting...";
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }
}

