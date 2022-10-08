#include<iostream>
using namespace std;

/*
APPROACH TOWARDS RECURSIVE PROBLEMS:
 *rule is principle of mathematical induction(PMI):
  ->figure out the base case
  ->assume such problems can be solved by recursion
  ->using the sub-problems write the answer for the current problem
*/

/*
QUESTION: find Nth fibonacci using recursion

EXAMPLE: 0,1,1,2,3,5,8,13... i.e take any no. for instance, the value of it is sum of previous 2 numbers

RECURSIVE CASE: F(N) = F(N-1) + F(N-2)

TIP: try drawing the recursive tree and read how the call stack changes and visualize it with a graph
*/

int fibonacci(int n){

    if(n == 0 || n == 1){         //base case
        return n;
    }
    
    //recursive case
    int f1 = fibonacci(n-1);
    int f2 = fibonacci(n-2);

    int fib = f1 + f2;

    return fib;
}

int main(){

    cout << "Enter a positive number: ";
    int n;
    cin >> n;

    cout << n << "th fibonacci is: " << fibonacci(n) << endl;

return 0;
}