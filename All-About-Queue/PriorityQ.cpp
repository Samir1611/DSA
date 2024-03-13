#include<iostream>
#define max 6
using namespace std;

class Queue{
	public:
		int arr[max];
		int front;
		int rear;
		
		void MakeEmpty(){
			rear=-1;
			front=0;
		}
		bool IsEmpty(){
			if(rear<front){
				return true;
			}else{
				return false;
			}
		}
		bool IsFull(){
			if(rear==max-1){
					cout<<"The queue is full"<<endl;
				return true;
			}
				return false;
			
		}
		void Enqueue(int item){
			if(!IsFull()){
				rear++;
				cout<<"Enter the item to be enqueued: ";
				cin>>item;
				arr[rear]=item;
			}
		}
		void Dequeue(){
			if(!IsEmpty()){
				int large=front;
				for(int i= front; i<=rear; i++){
					if(arr[large]<arr[i]){
						large=i;
					}
				}
				for(int i=large; i>=front; i--){
					arr[i]=arr[i-1];
				}
				front++;
			}
		}
		void Traverse(){
			cout<<"The items in the queue are: "<<endl;
			for(int i=front; i<=rear;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
};

int main(){
	int choice=0;
	Queue q;
	char y = 'y';
		q.MakeEmpty();
	do{
	cout << "1.Make Empty\t\t\t";
    cout << "2.Enqueue Element\t\t\t";
    cout << "3.Dequeue Element" << endl;
    cout << "4.Traverse\t\t\t\t";
    cout << "5.Exit" << endl;
     cout << "Enter the choice: ";
		cin>>choice;
		
		switch(choice){
			case 1:
				q.MakeEmpty();
				break;
		
			case 2:
				 do {
             	 int var;
				q.Enqueue(var);
                cout << "Do you want to insert again? Press y/n: ";
                cin >> y;
            } while (y == 'y');
            break;
			case 3:
				q.Dequeue();
				break;
			case 4:
				q.Traverse();
				break;
			default:
				choice=5;
		}
	}while(choice!=5);
	return 0;
}
