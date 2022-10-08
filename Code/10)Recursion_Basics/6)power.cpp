#include<iostream>
#define ll long long
using namespace std;

/*
QUESTION: find (a POWER n) using recursion

APPROACH:
 ->try dividing (a POWER n) into sub problem
 ->a POWER N =  a * (a POWER (N-1))   <- recursive case
 ->anything power 0 is 1 => if n == 0 then return 1 <- base case
*/

ll power(int a,int n){

    if(n == 0){         //base case
        return 1;
    }

    ll p1 = a; 
    ll p2 = power(a,n-1); //recursive case

    ll ans = p1 * p2;
    return ans;
}

int main(){

    ll a = 5;
    ll n = 5;
    cout << "ANSWER: " << power(a,n) << endl;

return 0;
}