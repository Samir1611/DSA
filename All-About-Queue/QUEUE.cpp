#include <iostream>
using namespace std;
#define maxQueue 3

	class Queue{
		public: 
		int queue[maxQueue];
		int i, j, k;
		int rear = -1;
		int front  = 0;
		
		bool IsEmpty(){
			if(front>rear){
			cout<<"Queue is Empty"<<endl;
			return 1;
			}
			else return 0;
			
		}
		void MakeEmpty(){
			front = 0;
			rear = -1;
		}
		bool Full(){
			if(rear == maxQueue -1)
			{
				cout<<"Queue is full"<<endl;
				return 1;
			}
			else 
			return 0;
		}
		int enqueue(){
			if (Full()){	
			}else{
			int item;
			cout<<"Enter the item you want to enter"<<endl;
			cin>>item;
			rear++;
			queue[rear] = item;
		}
		}
		void dequeue(){
			if(IsEmpty()){
			}else{
				front++;
			}
		}
		void Traverse(){
			if(IsEmpty()){
			}else{
				cout<<"[";
				for(i = front; i<=rear; i++){
					cout<<queue[i];
					if (i < rear) {
               		 cout << ",";
           			 }
           		}
				cout<<"]";
		}
		cout<<endl;
	}
	};
	

	int main(){
		char y ='y';
		Queue P;
		int menu; 
		label:
		cout<<"1.Check if Queue Is Empty\t\t";
		cout<<"2.MakeEmpty\t\t";
		cout<<"3. Check if Queue Is Full"<<endl;
	    cout<<"4.Enqueue Element\t\t\t";
	   	cout<<"5.Dequeue Element"<<endl;
	   	cout<<"6.Traverse\t\t\t\t";
		cout<<"7.Exit"<<endl;
		
		cout<<"Enter the menu";
		
		cin>>menu;
		switch(menu){
			case 1:
			if(	P.IsEmpty()){
			}else{
				cout<<"Queue is not Empty"<<endl;
			}
				goto label;
				break;
			case 2:
				P.MakeEmpty();	
				goto label;
				break;
			case 3:
			    if(P.Full()){
				}else{
					cout<<"Queue is not full"<<endl;
				}
			    goto label;
			    break;
			    
				case 4:
					do{
				P.enqueue();
				cout<<"Do you want to insert again Press y/n"<<endl;
				Label2:
				cin>>y;
				}while(y=='y');
				if(y=='n'){
				goto label;
			}else{
				cout<<"Please enter y/n"<<endl;
				goto Label2;
			}
				break;
				
				case 5:
				P.dequeue();
				goto label;
				break;
				
				case 6:
				P.Traverse();
				goto label;
				break;
			
				case 7:
					cout<<"End of program";
					cout<<endl<<"Thank You";
				break;
					
	 			default:
	 				cout<<"Invalid";
	 				goto label;
		}

	}
