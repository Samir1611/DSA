#include<iostream>
using namespace std;

int main() {
    int n,search;
    int flag = 0;
    cout << "Enter the size of array: ";
    cin >> n;
    int a[n];
    
    for(int i = 0; i < n; i++) {
        cout << "Enter the array element " << i + 1 << ": ";
        cin >> a[i];
    }
    cout<<"Enter the element you wannt to search";
    cin>>search;
    	
    	 for(int i = 0; i < n; i++) {
    		if(search == a[i]){
    			flag = 1;
    		 
			}else flag = 0;
	}
	if(flag =1){
		cout<<"Item found "<<search;
	}
	else cout<<"Not found";
}
