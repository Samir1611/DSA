#include<iostream>
using namespace std;
	int main(){
		int n,i,j;
		cout<<"Enter the size of n";
		cin>>n;
		
		int arr[n];
		
		
			for( i = 0; i<n; i++ ){
				cout<<"Enter the element"<<i+1;
				cin>>arr[i];
			}
			
	
    for (i = 0; i < n - 1; i++)
{

        for (j = 0; j < n - i - 1; j++){
		
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}}
			
			cout<<"Sorted array are"<<endl;
			for( i = 0; i<n; i++ ){
				cout<<arr[i];
			}
		
	}
