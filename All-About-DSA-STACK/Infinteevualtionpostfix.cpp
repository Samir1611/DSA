#include <iostream>
#include <cstring>
#include<math.h>
using namespace std;
#define max 10

class EvaluatePostfix {
public:
    int op1Stacktop = -1; 
    int op2Stacktop = -1; 
    int valuetop =-1;
    int stacktop = -1;
    int i, j;
	string scan;
    char op1[max];
    char op2[max];
    int val[max];
    int stack[max];


    void push_in_op1(char item) {
        op1Stacktop++;
        op1[op1Stacktop] = item;
    }
    	
    void push_in_op2(char item) {
        op2Stacktop++;
        op2[op2Stacktop] = item;
    }
     void push_in_value(int item) {
        valuetop++;
        val[valuetop] = item;
    }

    void push_in_stack(int item) {
       stacktop++;
        stack[stacktop] = item;
    }
 
	int pop() {
        if (stacktop != -1) {
            return stack[stacktop--];
        } else {
            return 0;
        }
    }
    

  int precedence(int o1, char op, int o2){
    int res;
    switch (op){
        case'+':  res = o1 + o2; break;
		case '-': res = o1- o2; break; 
		case '*': res = o1 *o2; break;
		case '/': res = o1/o2; break; 
		case '$': res = static_cast<int>(pow(o1, o2)); break;
}
return res;
}

    void EvaluatePostfixer() {
    cout << "Enter the infix: ";
    cin >> scan;
    cout << "Scan Char\t\tOp1\t\tOp2\t\tStack\t\tValue ";

    for (j = 0; j < scan.length(); j++) {
        cout << endl << scan[j] << "\t\t\t";
   
   		if (isdigit(scan[j])){
        push_in_stack(scan[j]-'0');

    }
    else if (scan[j] == '+' || scan[j] == '-' || scan[j] == '*' || scan[j] == '/' || scan[j] == '$') {
			   int r2 = pop();
                int r = pop();
                push_in_op1(r);
                push_in_op2(r2);
            
         	int Valuere = precedence(r,scan[j],r2);
         	 	push_in_value(Valuere);
            	push_in_stack(Valuere);
            }
    
    for (i = 0; i <= op1Stacktop; i++) {
            cout << static_cast<int>(op1[i]);
        }
        op1Stacktop=-1;
        cout<<"\t\t";
        
    for (i = 0; i <= op2Stacktop; i++) {
            cout << static_cast<int>(op2[i]);
        }
        op2Stacktop=-1;
         cout<<"\t\t";
         
     for (i = 0; i <= stacktop; i++) {
            cout << stack[i];
        }
         cout<<"\t\t";


    for (i = 0; i <= valuetop; i++) {
            cout << val[i];
        }
        valuetop=-1;
	}
   
    }

};

int main() {
    EvaluatePostfix P;
    P.EvaluatePostfixer();
    return 0;
}

