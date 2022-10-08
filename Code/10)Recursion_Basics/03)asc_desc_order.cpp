#include<iostream>
using namespace std;

/*
QUESTION: write a function to print first N no.s in increasing and decreasing order

TIP: call stack visualization is must for this problem

VISUALIZATION: 
    befor fn.call    | fn. call  | after fn.call

            DESC      F(N)=F(N-1)      ASCE
  BOTTOM(0) PRINT(0)  ▲  N = 0  | return PRINT(0)  BOTTOM(0)
      ▲     PRINT(1)  |  N = 1  | return PRINT(1)     |
      |     PRINT(2)  |  N = 2  | return PRINT(2)     |
      |     PRINT(3)  |  N = 3  | return PRINT(3)     |
      |     PRINT(4)  |  N = 4  | return PRINT(4)     ▼
    TOP(5)  PRINT(5)  |  N = 5  | return PRINT(5)   TOP(5)
                      |  MAIN   ▼
                      ----------- 
                      CALL STACK

CONCLUSION: 
 ->anything you write before the function call is top-down
 ->anything you write after the function call is bottom-up
*/

void asc_des(int n){

    if(n == 0){            //base case
        cout << endl;
        return;
    }

    cout << n << " ";     //befor fn. call => top-down => descending order

    asc_des(n-1);

    cout << n << " ";    //after fn. call => bottom-up => ascending order

}

int main(){

    cout << "Enter a positive number: ";
    int n;
    cin >> n;

    asc_des(n);

return 0;
}