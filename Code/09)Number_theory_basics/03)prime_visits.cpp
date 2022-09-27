#include<iostream>
using namespace std;

/*
QUESTION: Given a range A,B. Find the no. of prime no.s between the range and you have given T testcases (T <= 1000)
NOTE: the problem most of us face while using sieve method int his problem is TIME LIMIT EXCEDED, WHY?

NORMNAL SIEVE APPROACH:(don't approach like this)
 ->for each testcase we are trying to find prime no. between A and B 
 ->suppose we have 1000 queries(Q)/test cases (that is we are given 1000 differewnt ranges)
   then time complexity is O(N*Q), if N = (10 POWER 6) and queries = 1000 -> O(N POWER 9)
   so we will get time limit exceded

OPTIMAL SIEVE APPROACH: 
 ->we should no find prime no.s for Q-queries,instead we should pre-compute sieve once and use it to solve all queries, HOW?
 ->after pre-computing we should find cummulative sum of all prime no.s
 ->EXAMPLE: find prime no. between 11 & 20
   we can do,cum_sum[20] - cum_sum[10]
 ->TIME COMPLEXITY: O(Q + N) and for computing each Q we will take constant time only.
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

    int p[100005] = {0};
    prime_sieve(p);

    int cum_sum[100005] = {0};

    for(int i=1;i <= 100000;++i){
        cum_sum[i] = cum_sum[i-1] + p[i];  //cumulative array which has no. of prime no.s till its index
    }

    cout << "Enter no. of queries: ";
    int q;
    cin >> q;

    while(q--){
        cout << "Enter the range: " << endl;
        int a,b;
        cin >> a >> b;
        cout << "Number of prime no.s present from " << a << " to " << b << ": ";
        cout << cum_sum[b] - cum_sum[a-1] << endl;
    }

return 0;
}