#include<iostream>
using namespace std;

/*
BRUTE-FORCE APPROACH:
 ->check from 2 to N-1 whether it's divisible by other no.s or not 
 ->TIME COMPLEXITY: O(n), to find range of prime no.s -> O(n*n)
BETTER WAY: 
 ->check from 2 to rootof(n), why? let's take example as 36
   1 * 36
   2 * 18
   3 * 12
   4 * 9
   6 * 6       we can notice that after (6*6) it's repeating -> 4 * 9 and 9 * 4 are same, because of this we can check till rootof(n)
   9 * 4
   12 * 3
   18 * 2
   36 * 1
*/

bool isPrime(int n){

    if(n == 1){         
        return false;           //1 is neither prime nor composite
    }
    if(n == 2){
        return true;            //2 is prime
    } 

    for(int i=2;i*i < n;++i){   //checking till rootof(n)
        if(n%i == 0){           //if any no. % n is 0, then it means n is divisible by some no. so it's not prime no.
            return false;
        }
    }
 
return true;                    //n is not divisible by any no. except 1 and itself so it's a prime no.
}

int main(){
    
    int n;
    cout << "Enter a number to check prime: ";
    cin >> n;
    
    isPrime(n) ?  cout << n << " is a prime number!" : cout << n << " is not a prime number!";

return 0;
}