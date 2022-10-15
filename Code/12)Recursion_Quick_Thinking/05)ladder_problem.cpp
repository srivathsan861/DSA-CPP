#include<iostream>
using namespace std;

/*
QUESTION: find the different no. of ways in which he can reach the top of the ladder(N), he can either take 1 or 2 or 3 jumps

EXAMPLE: N=4 ->top of ladder
         1 1 1 1 -> he can go to the top by taking 4 single steps,similarly below are all the possibilities
         1 2 1  
         1 1 2
         2 1 1
         2 2 
         1 3
         3 1
         so totally in 7 different ways he can reach the top of the ladder

APPROACH:
 ->QUICK-THINKING: either he can get to the top from (N-1) step or (N-2) step or (N-3) step
   =>f(N-1)+f(N-2)+f(N-3)
 ->BASE-CASE: if N = 0 -> return 1, because obviously there is only 1 way to stand in the ground(think like top of the ladder is in the ground)

TIP: try drawing the recursive tree 

NOTE: you may be given a ladder of size 'N' and jump can be max pf 'K'
      *RECURRENCE-RELATION:f(N) = Σ f(N-i) where 'i' ranges from 1 to 'k' 
*/

int possible_ways(int n,int k){

    if(n==0){      //base case
        return 1;
    }

    if(n  < 0){   //dealing with -ve values
        return 0;
    }

    int ans=0;

    for(int i=1;i <= k;++i){
        ans += possible_ways(n-i,k); //you can also do: ans = f(n-1)+f(n-2)+f(n-3)
    }

return ans;
}

int main(){

    int n=4;
    int k=3;

    cout << "Possible ways: " << possible_ways(n,k) << endl;

return 0;
}