#include<iostream>
using namespace std;

	int BinarySearch( int a[], int n, int data){
		int l = 0; 
		int r = n-1;
		while (l<=r){
		
		int mid = (l+r)/2;
		
		if(data == a[mid]){
			return mid;
		}else if(data < a[mid]){
			r = mid-1;
		}else l = mid+1;
	}
		return -1;
	}

int main() {
    int n,search,l,r;
    int flag = 0;
    cout << "Enter the size of array: ";
    cin >> n;
    int a[n];
    
    for(int i = 0; i < n; i++) {
        cout << "Enter the array element in sorted array " << i + 1 << ": ";
        cin >> a[i];
    }
    cout<<"Enter the element you wannt to search";
    cin>>search;
    
      int index = BinarySearch(a, n, search);

    if (index != -1)
        cout << "Element "<<a[index]<<" found at index " << index << endl;
    else
        cout << "Element not found\n";

    return 0;
    
    
    
}
