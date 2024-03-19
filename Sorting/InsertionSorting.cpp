#include<iostream>
using namespace std;

		int main(){
		int n,i,j,hole;
		cout<<"Enter the size of n";
		cin>>n;
		
		int arr[n];
		
			for( i = 0; i<n; i++ ){
				cout<<"Enter the element"<<i+1;
				cin>>arr[i];
			}
			
				for (i = 1; i < n; i++) 
			{
			    hole = arr[i];
			    j = i - 1;
			
			    while (j >= 0 && arr[j] > hole) 
			    {
			        arr[j + 1] = arr[j];
			        j = j - 1;
			    }
			    arr[j + 1] = hole;
			}
			
			
			cout<<"Sorted array are"<<endl;
			for( i = 0; i<n; i++ ){
				cout<<arr[i];
			}
		
	}
