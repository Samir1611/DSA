#include<iostream>
using namespace std;
	int main(){
		int n;
		
		cout<<"Enter the size of array"<<endl;
		cin>>n;
		int a[n];
		for(int i = 0; i<n; i++){
		
		cout<<"Enter the array element"<<i+1;
		cin>>a[i];
	}
			for(int j = 0; j<n-1; j++){
				int iMin = j;
				for(int i = j+1; i<n; i++){
					if(a[i] < a[iMin]){
						iMin = i;
					}
					if(iMin!=j){
						swap(a[j],a[iMin]);
					}
				}
			}
			  cout << "Sorted array: ";
			for(int i = 0; i<n; i++){
				cout<<a[i]<<" ";
			}
		
	}
