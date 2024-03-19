#include<iostream>
using namespace std;

	void swap(int &a1, int &a2){
		int temp = a1;
		a1 = a2;
		a2 = temp;
	}


	int main(){
		int n,i,j;
		cout<<"Enter the size of n";
		cin>>n;
		
		int a[n];
		
		
			for( i = 0; i<n; i++ ){
				cout<<"Enter the element"<<i+1;
				cin>>a[i];
			}
			
			for(j =0; j<n-1; j++){
				for(i = j+1; i<n; i++ ){
					if(a[j]>a[i]){
						swap(a[j],a[i]);
					}
				}
			}
			
			cout<<"Sorted array are"<<endl;
			for( i = 0; i<n; i++ ){
				cout<<a[i];
			}
		
	}
