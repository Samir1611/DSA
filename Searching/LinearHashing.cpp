#include <iostream>
using namespace std;

int main() {
	
	int n;
	cout<<"Enter the size of array elements";
	cin>>n;

	int values[n];
	bool taken[n];
	int a[n];
	int prob2 = 0;

		for(int i = 0; i<n; i++){
			cout<<"Enter the element for position "<<i+1<<" ";
			cin>>a[i];
		}
		cout << "function h(x) = x MOD "<<n<<" using linear probing" << endl;
        cout << "Position\tValue\t\tProb" << endl;
   
        for (int i = 0; i < n; i++){
        taken[i] = false;
        }
        for (int i = 0; i < n; i++) {
        int position = a[i] % n;
        if (!taken[position]) {				//true not taken
            values[position] = a[i];
            prob2=1;
        } else {
            while (taken[position]) {
                position = (position + 1) % n;
            }
                prob2++;
                values[position] = a[i];
        }
            taken[position] = true;
     cout << "   " << position << "\t\t  " << values[position] << "\t\t" << prob2 << endl;
    }
    return 0;
}
