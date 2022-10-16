#include<iostream>
using namespace std;

/*
QUESTION: given N friends who want to got to a party on bikes. Each guy can  go as single or as couple
          find the no. of ways in which N friends can go to the party

EXAMPLE: N=3, all possible ways:
         (1)(2)(3)
         (1 2)(3)
         (1 3)(2)
         (2 3)(1)
         =>answer is 4

TIP: OR -> +    (add values)
     AND -> *   (multiply values)

QUICK-THINKING:
 ->CASE 1:   _________ _
             N-1       ☺️ 

            *he can go alone in a bike AND others can go in any ways
            =>f(N) = 1*f(N-1)

 ->CASE 2:   _______ __
             N-2     ☺️☺️

            *he can go as couple in bike AND others can go in any ways
            *but he can select anyone from remaining (N-1) as a bike partner
             i.e N-1 Combination 1
            =>(N-1)C1 * f(N-2)

 ->TOTAL POSSIBLE WAYS:
   *it can either be CASE 1 (OR) CASE 2 
            =>f(N) = f(N-1) + [(N-1)C1 * f(N-2)]

->BASE-CASE:
  *N=0 -> return 1, because if no one is going that is also one way
  *N=1 -> return 1, one is going
  *N=2 -> return 2, two is going
*/

int main(){

return 0;
}