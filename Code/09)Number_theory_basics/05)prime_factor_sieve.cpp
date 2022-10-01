#include<iostream>
#include<vector>
using namespace std;

/*
SIEVE BASED APPROACH for prime_factorization:
 ->this method is used when we have lot of queries and asked to find prime factors
 ->so firstly we will pre-compute all primes - > TIME COMPLEXITY:   O(N log log N) aprox.= O(N)
 ->here we will try dividing only by prime no.s, but in previous approach we used all no.s
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

vector<int> factorize(int m,vector<int> primes){

    vector<int> factors;
    factors.clear();                   //initialize the vector

    int i=0;                          //index

    int p = primes[0];                //storing the 0th prime no. in p

    while(p * p <= m){                //while p < rootof(m)
         
        if(m % p == 0){              //if the given no. is divisible by prime no.

            factors.push_back(p);    //insert that prime no. in factors vector

            while(m % p == 0){       //while it is divisible,keep on dividing it (example: 24%2 == 0 ->so 24/2 = 12; 12%2 == 0 -> so 12/2 ....)
                m = m/p;
            }

        }

        i++;                       //if no. is not divisible, try with next prime no. from the primes vector
        p = primes[i];             //store the next prime no. from primes vector in 'p'
    }

    if(m != 1){                    //catch(this is a corner case because we are only running the loop till rootof(m))
        factors.push_back(m);      //so if m != 1, then it will be definitelty a prime no., so insert it in factors vector
    }

return factors;
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

        vector<int> factors = factorize(no,primes);  //storing the prime factors in factors vector

        cout << "Prime factors of " << no << ": " << endl;

        for( auto f : factors){   //printing the prime vactors
            cout << f << ",";
        }
    }

return 0;
}