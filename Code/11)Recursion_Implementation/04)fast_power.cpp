#include<iostream>
using namespace std;

/*
QUESTION: find (a POWER n) using recursion in O(log N)

APPROACH:
 ->sub-problem:
               a POWER n ->  (a POWER n/2) SQ.2  (if n is even)
               a POWER n -> a(a POWER n/2) SQ.2  (if n is odd)

 ->VISUALIZATION: find a⁹
                     TOP-DOWN
                a⁹ -> ↓(a⁴)² -> returns (a⁴)² = a⁸ ↑ -> since 9 is odd -> return a*a⁸ = a⁹
                      ↓(a²)² -> returns (a²)² = a⁴ ↑	
                      ↓(a¹)² -> returns (a¹)² = a² ↑	
                      ↓(a⁰)² -> returns 1 -> a¹    ↑ (base case)
                                    BOTTOM-UP

 ->TIME COMPLEXITY: depth of call stack gors like: n,n/2,n/4...1 => O(log N)
*/

int fast_power(int a,int n){

    if(n == 0){         //base case
        return 1;
    }

    int smaller_ans = fast_power(a,n/2);  //recursive case

    smaller_ans *= smaller_ans;   //squaring smaller_ans

    //NOTE: for squaring don't do like [fast_power(a,n/2) * fast_power(a,n/2)] -> inefficient

    if(n & 1){                   //if 'n' is odd -> return (a*smaller_ans)
        return a * smaller_ans;
    }

    return smaller_ans;          //if 'n' is even -> return smaller_ans
}

int main(){

    int a = 2;
    int n = 8;

    cout << "2 POWER 8: " << fast_power(a,n) << endl;

return 0;
}