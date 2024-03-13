#include <iostream>
#include <cstring>
using namespace std;
#define max 10

class Postfix {
public:
    int opStacktop = -1; 
    int postStacktop = -1; 
    int i, j;
	string scan;
    char opStack[max];
    char postStack[max];
    
    int pop_opStack() {
        if (opStacktop != -1) {
            return opStack[opStacktop--];
        } else {
            return 0;
        }
    }

    void push_in_opStack(char item) {
        opStacktop++;
        opStack[opStacktop] = item;
    }

    void push_in_postStack(char item) {
        postStacktop++;
        postStack[postStacktop] = item;
    }

    int precedence(char c) {
    	switch(c){
				case '$': return 3;
				case '/': case '*': return 2;
				case '+': case '-': return 1;
				default: return 0;
			}
		}

    void Postfixer() {
    cout << "Enter the infix: ";
    cin >> scan;
    cout << "Scan Char\tPost Stack\tOp Stack";

    for (j = 0; j < scan.length(); j++) {
        cout << endl << scan[j] << "\t\t";

        if (scan[j] == '(') {
            push_in_opStack(scan[j]);
        } else if (tolower(scan[j]) >= 'a' && tolower(scan[j]) <= 'z') {
            push_in_postStack(scan[j]);
        } else if (scan[j] == '+' || scan[j] == '-' || scan[j] == '*' || scan[j] == '/' || scan[j] == '$') {
            if (opStacktop != -1) {
                while (precedence(opStack[opStacktop]) > precedence(scan[j])) {
                    push_in_postStack(pop_opStack());
                }
                push_in_opStack(scan[j]);
            } else {
                push_in_opStack(scan[j]);
            }
        } else if (scan[j] == ')') {
            while (opStack[opStacktop] != '(') {
                push_in_postStack(pop_opStack());
            }
            if (opStack[opStacktop] == '(') {
                opStacktop--;
            }
        }

        for (i = 0; i <= postStacktop; i++) {
            cout << postStack[i];
        }
        cout << "\t\t";

        for (i = 0; i <= opStacktop; i++) {
            cout << opStack[i];
        }
    }

    while (opStacktop != -1) {
        push_in_postStack(pop_opStack());
    }

    cout << "\n\nThe postfix is: ";
    for (i = 0; i <= postStacktop; i++) {
        cout << postStack[i];
    }
}

};

int main() {
    Postfix P;
    P.Postfixer();
    return 0;
}

