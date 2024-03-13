#include <iostream>
using namespace std;
#define maxStack 3
//lastInFirstOut
	class Stack{
		public: 
		int stack[maxStack];
		int i, j, k;
		int top = -1;
		
		bool IsEmpty(){
			if(top==-1){
			cout<<"Stack is Empty"<<endl;
			return 1;
			}
			else return 0;
			
		}
		void MakeEmpty(){
				top=-1;
		}
		int peak(){
			if (IsEmpty()) {
            return -1; 
        } else {
            cout << "Peak Element: " << stack[top] << endl;
            return stack[top];
        }
    }
		bool Full(){
			if(top == maxStack -1)
			{
				cout<<"Stack is full"<<endl;
				return 1;
			}
			else 
			return 0;
		}
		int push(){
			if (Full()){	
			}else{
			int item;
			cout<<"Enter the item you want to enter"<<endl;
			cin>>item;
			top++;
			stack[top] = item;
		}
		}
		void pop(){
			if(IsEmpty()){
			}else{
			top--;	
			}
		}
		void Traverse(){
			if(IsEmpty()){
			}else{
				cout<<"[";
				for(i = 0; i<=top; i++){
					cout<<stack[i];
					if(i<top){
					cout<<",";
				}
				}
				
					cout<<"]";
			}
		
			
		}
		 
	};
	

	int main(){
		char y ='y';
		Stack P;
		int menu; 
		label:
		cout<<"1.Check if stack Is Empty"<<endl;
		cout<<"2.MakeEmpty"<<endl;
		cout<<"3.Check if stack Is Full"<<endl;
	    cout<<"4.Push element"<<endl;
	   	cout<<"5.POP Element"<<endl;
	   	cout<<"6.Traverse"<<endl;
	   	cout<<"7.Peak Element"<<endl;
		cout<<"8.Exit"<<endl;
		
		cout<<"Enter the menu";
		
		cin>>menu;
		switch(menu){
			case 1:
			if(	P.IsEmpty()){
			}else{
				cout<<"Stack is not Empty"<<endl;
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
					cout<<"Stack is not full"<<endl;
				}
			    goto label;
			    break;
			    
				case 4:
					do{
				P.push();
				cout<<"Do you want to push again Press y/n"<<endl;
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
				P.pop();
				goto label;
				break;
				
				case 6:
				P.Traverse();
				cout<<endl;
				goto label;
				break;
				
				case 7:
				P.peak();
				cout<<endl;
				goto label;
				break;
			
				case 8:
					cout<<"End of program";
					cout<<endl<<"Thank You";
				break;
					
	 			default:
	 				cout<<"Invalid";
	 				goto label;
		}
		
		
		
	}
