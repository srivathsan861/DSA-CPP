#include<iostream>
using namespace std;

/*
QN: Find exponential
EXAMPLE: 2 POWER 6
NAIVE APPROACH: 2 * 2 * 2 * 2 * 2 * 2 -> O(n)
OPTIMAL APPROACH: 
 ->2 POWER 6 -> 2 POWER 110 (representing 6 in binary), let's consider 2 as A
 ->binary(6): 0 -> A          (2 POWER 1) (don't include)
              1 -> A*A        (2 POWER 2) (include)
              1 -> A*A*A*A    (2 POWER 4) (include)
 ->if bit is set include it in answer else don't,that is, 
   (2 POWER 2) * (2 POWER 4) = 4 * 16 = 64 (we got the answer FOR (2 POWER 6))
   ->TIME COMPLEXITY: O(log N)
*/

int power_optimized(int a,int n){

    int ans = 1;

    while(n > 0){

        int last_bit = (n & 1); //storing last bit
        if(last_bit){           //if last bit is set then we are including it in ans
            ans = ans * a;
        }
        a = a * a;             //squaring a
        n = n >> 1;            //then we are right shifting 'n' because now we should consider the next bit
    }

 return ans;
}

int main(){
    
    int a = 2;
    int n = 6;

    cout << "2 POWER 6 is: "  << power_optimized(a,n) << endl;
    
return 0;
}