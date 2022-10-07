#include<iostream>
#define ll long long
using namespace std;

/*
PRE-REQUISITE: INCLUSION EXLUSION PRINCIPLE (read about it)

  ->EXAMPLE: how many no.s from 1 to 100 are multiples of 2 or 3 
  ->FORMULA: |a U b| = |a| + |b| - |a I b|    (assume I as intersect)(even in consideration of more than 2 sets observation remains same)
  ->OBSERVATION: a,b,ab are the subsets which we can create using a and b
                 a -> no. of elements in the subset is odd -> so we are adding it in the ans
                 b -> no. of elements in the subset is odd -> so we are adding it in the ans
                 a,b -> no. of elements in the subset is even -> so we are subtracting it from the ans

  ->consider 'a' as multiples of 2 -> floor[100/2] = 50
  ->consider 'b' as multiples of 3 -> floor[100/3] = 33
  ->consider 'a I b' as multiples of 6 i.e 2*3 -> floor[100/(2*3)] => 100/6 = 16 
  ->applying these values in formula -> 50 + 33 - 16 = 67 (so there are 67 no.s which are divisible by 2 or 3 below 100)
  ->NOTE: for finding the intersection of 2 elements we are multiplying them in the denominator
*/

/*
QUESTION: find numbers between 1 to N which are divisible by prime no.s less than 20
   
APPROACH:
 ->firstly we will find all the subsets using bit manipulation
 ->the loop runs from 1 to ((2 POWER 8) - 1) => (1 << 8)-1 (because there are total of 8 prime no.s lesser than 20)
 ->another loop to multiply denominators for corresponding set bits -> DENOM
 ->if the number of elements in the subset is odd -> add the union value to the ans  (union value = N/(DENOM))
 ->if the number of elements in the subset is even -> subtract the union value to the ans
*/

int main(){
    
    cout << "Enter number of test cases: ";
    ll t;          
    cin >> t;

    ll primes[] = {2,3,5,7,11,13,17,19};   //prime no.s below 20

    while(t--){
        
        cout << "Enter the value of N: ";
        ll n;                            
        cin >> n;

        ll subsets = (1 << 8) - 1;      //max no. of subsets possible
        ll ans = 0;

        for(ll i=1;i <= subsets;++i){

            ll denom = 1ll;           

            ll set_bits =  __builtin_popcount(i);   //return no. os set_bits

            for(ll j=0;j <= 7;++j){

                if(i & (1 << j)){                  //for the corresponding set bits we are multiplying denominator
                   denom = denom * primes[j];
                }

            }

            if(set_bits & 1){                      //if the number of elements in the subset is odd -> add the union value to the ans
                ans += n/denom;                    
            }
            else{
                ans -= n/denom;                   //if the number of elements in the subset is even -> subtract the union value to the ans
            }
        }
        
        cout << "Number of elements which are divisible by prime no.s less than 20 below " << n << ": " << ans << endl;
    }

   
return 0;
}