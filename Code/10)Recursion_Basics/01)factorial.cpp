#include<iostream>
using namespace std;

/*
NOTE: read about how basic recursive functions work

TIPS: try visualizing the recursive tree call backs,call stack,space complexity graph

QUESTION: find the factorial of N

EXAMPLE: N=5 => factorial of 5 is 5*4*3*2*1 = 120

GENERAL FORMULA: N! = N * (N-1)!

VISUALIZATION:        5! = 5 * 4!          
                          4! = 4 * 3!       
                                   3! = 3 * 2!
                                            2! = 2 *  1! 
                                                      1! = 1 * 0!  <- stop  (0 will return 1)

                        till this part we call it as TOP DOWN -> going towards base case 
                    
                       1! = 1 * 0! => 1 * 1 = 1
                       2! = 2 * 1! => 2 * 1 = 2   (here we got the value of 1! = 1 from the return of 1!)
                       3! = 3 * 2! => 3 * 2 = 6   (here we got the value of 2! = 2 from the return of 2!)
                       4! = 4 * 3! => 4 * 6 = 24  (here we got the value of 3! = 6 from the return of 3!)
                       5! = 5 * 4! => 5 * 24= 120 (here we got the value of 4! = 24 from the return of 1!)
                       
                       this part we call it as BOTTOM UP -> going back from base case
*/

int factorial(int n){

    if(n == 0){                         //base case
        return 1;
    }

    int sub_problem = factorial(n-1);  //recursive case
    int ans = n * sub_problem;
    return ans;

}

int main(){

    cout << "Enter a positive number: ";
    int n;
    cin >> n;

    cout << "Factorial of " << n << ": " << factorial(n) << endl;

return 0;
}