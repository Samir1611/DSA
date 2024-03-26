#include <iostream>//nlogn
using namespace std;

	
	int merge(int arr[], int low, int mid, int high){
		int i = low;
		int j = mid+1;
		int k = low;
		int arr2[high];
		while((i<=mid)&&(j<=high)){
			if(arr[i] <= arr[j] ){
				 arr2[k] = arr[i];
				i++;
			}else{
			 arr2[k] = arr[j];	 
			j++;
		}
			k++;
		}
		if(i>mid){
			while(j<=high){
				arr2[k] = arr[j];
				j++; k++;
			}
		}else if(j>high){
			while(i<= mid){
				arr2[k] = arr[i];
					i++; k++;
				}
		}
		for(k = low; k<=high; k++){
			arr[k] = arr2[k];
		}
	}
		void mergeSort(int arr[], int low, int high){
		if(low<high){
		int	mid = (low+high)/2;
		mergeSort(arr,low,mid);
		mergeSort(arr,mid+1,high);
		merge(arr,low,mid,high);
		}
	}
	


	int main() {
    int n;
    cout << "Enter the size of n: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    } 
    mergeSort(arr,0,n-1);
     cout << "Sorted Array:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
    
