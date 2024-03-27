#include<iostream>
#include<cmath>
using namespace std;

		int main(){
		int n,i,gap;
		cout<<"Enter the size of n";
		cin>>n;
		
		
		int arr[n];
		
			for( i = 0; i<n; i++ ){
				cout<<"Enter the element"<<i+1;
				cin>>arr[i];
			}
			for(gap = floor(n/2); gap>0; gap = floor(gap/2)){
			
				for (i = gap; i < n; i++) 
			{
				int temp = arr[i];
				int j;
			   for (j = i; j >= gap && arr[j - gap] > temp; j -= gap){
			   
                arr[j] = arr[j - gap];
                
        }
        arr[j] = temp;
			}
		}
			
			cout<<"Sorted array are"<<endl;
			for( i = 0; i<n; i++ ){
				cout<<arr[i];
			}
		
	}
