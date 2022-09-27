#include<iostream>
using namespace std;

/*
QN: find all the prime no. from 0 to (10 POWEER 5)
SIEVE APPROACH:(most optimal)
 ->in this approach we directly generate array containing prime no.s
 ->EXAMPLE: N = 20
   1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 (these are indices and we will be using boolean array)
 ->we will set all even no.s as 0(2 is the only even no. which is prime and we will handle it in speacial case)
 ->we wil set all odd no.s as 1(assuming every odd no. is a prime no.)
 ->from the above array we start from 3 and mark it,that is,set the value to 1 because it is not divisble by any no. before it
   and we also cancel all the multiples of three from that array, that is we will set 0 in the indices: 6,9,12,15,18
 ->like this we traverse to all odd no.s and if it's not cancelled before then it is a prime no. and we will cancell all multiples of that no.
 ->if we hit a prime no. -> we can start cancelling from it's square, WHY?
   EXAMPLE:
    when we arive to 5 in the above example, we should cancel 10,15,20.But if you notice all the 3 no.s are already cancelled by the no.s lesser than 5
    so whe will start cancelling from squareof(5). WHY IT'S WORKING LIKE THIS? 
    PROPERTY: it states that for a given no. N there is always 1 divisor possible < rootof(N) if rootof(N) is a prime no.
 ->TIME COMPLEXITY: N/2 + N/3 + N/5 + N/7 .... = N(1/2 + 1/3 +.....) = O(N log log N) -> aprox. equals O(N)
*/

void prime_sieve(int *p){

    for(long long int i=3;i <= 100000;i+=2){       //assuming all odd no.s as prime
        p[i] = 1;
    }

    for(long long int i = 3;i <= 100000;i+=2){
        if(p[i] == 1){                                  
            for(long long int j =  i*i;j <= 100000;j=i+j){  //marking the multiples as not prime
                p[j] = 0;
            }
        }
    }
    //special cases
    p[0] = 0;             //0 is not prime
    p[1] = 0;             //1 is not prime
    p[2] = 1;             //2 is prime
}

int main(){

    long long int n = 100000;

    int p[100005] = {0};                  //first havinf all as not prime

    prime_sieve(p);                       //all prime indices are set to 1

    for(long long int i=0;i <= n;++i){    //check prime and print
        if(p[i] == 1){
            cout << i << " ";
        }
    }

return 0;
}