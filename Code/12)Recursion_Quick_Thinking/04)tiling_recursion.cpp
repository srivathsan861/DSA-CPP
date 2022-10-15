#include<iostream>
using namespace std;

/*
QUESTION: given a wall of size of (4*N) and tiles of size (1,4) and (4,1).
          in how many ways you can build the wall? i.e find the total no. of ways to build the wall

TIP: try visualizing it on you own

APPROACH:
 ->if you take (1,4) tile -> vertical tile,in x-axis it takes 1 unit => it will take 'N/1' tiles to fill the wall
   =>sub-problem: f(N-1)
 ->if you take (4,1) tile -> horizontal tile,in x-axis it will take 4 units => it will take 'N/4' tiles to fill the wall
   =>sub-problem: f(N-4)
 ->total no. of ways to build the wall = f(N-1)+f(N-4)
 ->what is the base case?
   *if we select a vertical(1,4) tile first -> until we build 4 tiles of it we should select only vertical tile
    =>no. of options we have from which we have to select is 1
   *similarly,we select a horizontal(4,1) tile first -> until we build 4 tiles of it we should select only horizontal tiles
    =>no. of options we have from which we have to select is 1
   *if we are not into both the above cases -> we can either select a vertical tile first or a horizontal tile first
    =>no. of options we have from which we have to select is 2
   *base-case: if(N <= 3) -> return 1, (because we have only one option)
               if(N == 4) -> return 2, (because we have two options)
*/

int main(){
  
return 0;
}