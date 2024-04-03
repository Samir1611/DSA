#include <iostream>
using namespace std;

int main() {
	
	int n;
	cout << "Enter the size of array elements: ";
	cin >> n;

	int values[n];
	bool taken[n];
	int a[n];
	int prob2 = 0;

	for(int i = 0; i < n; i++){
		cout << "Enter the element for position " << i+1 << ": ";
		cin >> a[i];
	}
	
	cout << "Function h(x) = x MOD " << n << " using quadratic probing" << endl;
    cout << "Position\tValue\t\tProb" << endl;
   
    for (int i = 0; i < n; i++){
        taken[i] = false;
    }

    for (int i = 0; i < n; i++) {
        int position = a[i] % n;
        prob2 = 1; 
        if (!taken[position]) {	// True if not taken
            values[position] = a[i];
        } else {
            int offset = 1;
            int original_position = position;
            while (taken[position]) {
                position = (original_position + offset * offset) % n; 
                offset++;
                prob2++;
            }
            values[position] = a[i];
        }
        taken[position] = true;
        cout << "   " << position << "\t\t  " << values[position] << "\t\t" << prob2 << endl;
    }
    return 0;
}
