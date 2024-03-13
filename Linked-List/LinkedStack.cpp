#include<iostream>
using namespace std;

		class Node{
			public:
		    int data;
		    Node* next;
		    Node(int data) {
		    this->data = data;
		    next = NULL;
		    }
		};
		
		class LinkedList{
			public:
		    Node* head;
		    LinkedList() {
		        head = NULL;
		    }
		    
		int pushatbeg(int data){
			Node* new_node = new Node(data);	
			new_node->next = head;
			head = new_node; 
		}
		 void pushatend(int data) {
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
		
		void deleteatHead() {
        if(head == NULL) {
            cout << "List is empty, nothing to delete" << endl;
            return;
        }
        Node* temp = head;
        cout<<"Deleted item is "<<head->data<<endl;
        head = head->next;
        delete temp;
 	    }
 	    void deleteatTail() {
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
 	    
 	    void peek(){
 	    	if(head == NULL){
 	    		cout<<"Stack is empty"<<endl;
			 }else
			 cout<<head->data<<"is at top of Stack"<<endl;
		 }
		
		void display() {
        if(head == NULL) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << "-> ";
            temp = temp->next;
        }
        cout << "Null" << endl;
 		   }
		};
		
		int main(){
			
			LinkedList list;
    int choice, data;
    while(true) {
        cout << "1. Insert at Head\t\t2. Insert at Tail\t\t3. Delete at Head\n4.Delete at Tail\t\t5.Peek\t\t\t\t6. Display\t\t 7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                list.pushatbeg(data);
                break;
            case 2:
                cout << "Enter data to insert: ";
                cin >> data;
                list.pushatend(data);
                break;
            case 3:
                list.deleteatHead();
                break;
            case 4:
                list.deleteatTail();
                break;
            case 5:
            	list.peek();
            	break;
            case 6:
                list.display();
                break;      
            case 7:
                cout << "Exiting...";
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }	
		}
