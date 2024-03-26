#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low]; 
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int post = partition(arr, low, high);
        quickSort(arr, low, post - 1);
        quickSort(arr, post+ 1, high);
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
    quickSort(arr, 0, n - 1);
    cout << "Sorted Array:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

