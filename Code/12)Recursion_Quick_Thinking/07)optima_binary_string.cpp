#include<iostream>
using namespace std;

/*
QUESTION: count binary strings of length N, which has no consecutive ones

EXAMPLE: N=2, all possibilities are:
         00 ->included
         01 ->included
         10 ->included
         11 ->not included
         =>answer is 3

TIP: OR -> +    (add values)
     AND -> *   (multiply values)

QUICK-THINKING:
 ->CASE 1:   _________ _
             N-1       0

            *if the last no. is '0', it means all the strings are valid strings of length (N-1) irrespective of it ending with '0' or '1'
             i.e both (1 0) and (0 0) are valid 
             => f(N) = f(N-1)

 ->CASE 2:   ________ _
             N-1      1

            *in this case if we had only 1 at the end , then we want only string which ends at '0' because '1' cannot be at (N-1) 
            i.e because (1 1) is invalid according to qn.

         => ________ __
            N-2      01

            *now here we are placing '0' at (N-1) because there is '1' at (N),
             after placing '0' at (N-1) -> all the strings are valid strings of length (N-2) irrespective of it ending with '0' or '1'
             i.e both (1 0) and (0 0) are valid
             => f(N) = f(N-2)

 ->TOTAL POSSIBLE WAYS:
   *it can either be CASE 1 (OR) CASE 2 
            =>f(N) = f(N-1)   +  f(N-2)

->BASE-CASE:

*/

int main(){

return 0;
}