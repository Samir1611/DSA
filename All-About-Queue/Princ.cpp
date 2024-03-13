#include <iostream>
#define SIZE 10
using namespace std;

class queue {
public:
    int item[SIZE];
    int rear = -1;
    int front = 0;

    bool IsEmpty() {
        if (front > rear) {
            cout << "Queue is Empty" << endl;
            return true;
        }
        return false;
    }

    bool Full() {
        if (rear == SIZE - 1) {
            cout << "Queue is full" << endl;
            return true;
        }
        return false;
    }

    void enqueue() {
        if (!Full()) {
            int element;
            cout << "Enter the item you want to enter: ";
            cin >> element;
            rear++;
            item[rear] = element;
        }
    }

    void dequeue() {
    if (!IsEmpty()) {
        int highestIndex = front;
        for (int i = front + 1; i <= rear; i++) {
            if (item[i] > item[highestIndex]) {
                highestIndex = i;
            }
        }
        
        for (int i = highestIndex; i < rear; i++) {
            item[i] = item[i + 1];
        }
        
        rear--;

      
    }
}


    void display() {
        if (!IsEmpty()) {
            // Find the index of the highest element
            int highestIndex = front;
            for (int i = front; i <= rear; i++) {
                if (item[i] > item[highestIndex]) {
                    highestIndex = i;
                }
            }
            // Display the highest element
            cout << item[highestIndex] << " ";

            // Shift elements to the left until the highest element reaches index 0
            for (int i = highestIndex; i > front; i--) {
                item[i] = item[i - 1];
            }
            // Display the remaining elements in descending order
            for (int i = front + 1; i <= rear; i++) {
                cout << item[i] << " ";
            }
            cout << endl;
        }
    }

    void MakeEmpty() {
        front = 0;
        rear = -1;
    }
};

int main(void) {
    queue P;
    char y = 'y';
    P.MakeEmpty();
    int menu;
label:
	cout << "1.Make Empty\t\t\t";
    cout << "2.Enqueue Element\t\t\t";
    cout << "3.Dequeue Element" << endl;
    cout << "4.Traverse\t\t\t\t";
    cout << "5.Exit" << endl;

    cout << "Enter the menu: ";

    cin >> menu;
    switch (menu) {
        
         case 1:
            P.MakeEmpty();
            goto label;
            break;
        case 2:
            do {
                P.enqueue();
                cout << "Do you want to insert again? Press y/n: ";
                cin >> y;
            } while (y == 'y');
            goto label;
            break;

        case 3:
            P.dequeue();
            goto label;
            break;

        case 4:
            P.display();
            goto label;
            break;

        case 5:
            cout << "End of program" << endl;
            cout << "Thank You" << endl;
            break;

        default:
            cout << "Invalid" << endl;
            goto label;
    }
}

