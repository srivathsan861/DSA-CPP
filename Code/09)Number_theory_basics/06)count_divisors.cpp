#include<iostream>
#include<vector>
using namespace std;

/*
EXAMPLE: N=60
DIVISORS of 60: 1,2,3,4,5,6,10,12,15,20,30,60 -> total no. of divisors: 12

NAIVE APPROACH:
 ->to iterate over the array and print if it divides the no. -> TIME COMPLEXITY: O(N)

OPTIMAL APPROACH:
 ->find prime factors of 60 -> (2 POWER 2) * (3 POWER 1) * (5 POWER 1) -> consider it as P1,P2,P3 are the powers:2,1,1
 ->INTIUTION: suppose POWER is 2, then we will have 3 options to pic : (N POWER 0),(N POWER 1),(N POWER 2)
 ->in the above example we have 3 different powers: (p1+1) * (P2+1) * (P3+1)
                                                  : (2+1)  * (1+1)  * (1+1) = 3*2*2 = 12 ->total no. of divisors of 60
 ->TIME COMPLEXITY OF PRE-COMPUTATION IS: O(N LOG LOG N) aprox.= O(N)
 ->TIME COMPLEXITY FOR EACH QUERY: O(log N)
*/

vector<int> prime_sieve(int *p,int n){

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
    
    vector<int> primes;             //if it is a prime no. then we will store it in this vector

    for(int i = 2;i <= n;++i){

       if(p[i] == 1){         
         primes.push_back(i);
       }

    }

return primes;
}

int count_divisors(int m,vector<int> primes){

    int i=0;                   //index
    int ans = 1;               
    int p = primes[0];         //storing the 0th prime no. in p

    while(p * p <= m){         //while p < rootof(m)

        if(m % p == 0){        //if the given no. is divisible by prime no.

            int count = 0;     //stores the value of the exponential

            while(m % p == 0){
                count++;         //when a no. is divisible again and again -> we are increasing the exponential of it from 1,2,3..
                m = m/p;
            }

            ans = ans * (count+1); //total sum of divisors = multiplication of no. of contribution of each prime factors
        }

        i++;                      //if no. is not divisible, try with next prime no. from the primes vector
        p = primes[i];            //store the next prime no. from primes vector in 'p'
    }

    if(m != 1){                  //catch(this is a corner case because we are only running the loop till rootof(m))
        ans = ans * 2;           //this means the m is a prime no. which is raised to power 1, so it will have 2 contributions
                                 //m POWER 0 and m POWER 1, so we should multiply 2 the current contributions from other prime factors
    }
    
return ans;
}

int main(){

    long long int n = 100000;
    int p[n+5];

    for(long long int i=0;i < n;++i){
        p[i] = 0;
    }

    vector<int> primes = prime_sieve(p,n);  //finding primes and storing it in primes vector
    
    cout << "Enter no. of test cases: " ;
    int t;
    cin >> t;

    while(t--){

        cout << "Enter the no: ";
        int no;
        cin >> no;

        int divisors_count = count_divisors(no,primes);  

        cout << "Divisor count of " << no << ": " << divisors_count << endl;

    }

return 0;
}