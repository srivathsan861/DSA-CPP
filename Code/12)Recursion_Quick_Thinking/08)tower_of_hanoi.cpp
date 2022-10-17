#include<iostream>
using namespace std;

/*
QUESTION: In the classic problem of the Towers of Hanoi, you have 3 towers(A,B,C) and N disks of different sizes which can slide onto any tower. 
          The puzzle starts with disks sorted in ascending order of size from top to bottom

TASK:
 ->move  disks from A to C
 ->pick one disk at a time
 ->can't place a big disk on small disk

TIP: visualize it by seeing online animations and try to draw recursive tree

RECURSIVE-THINKING:
 *move(N-1,A,B) -> we are moving (N-1) disks from tower A to tower B (so now we are left with onedisk -> Nth disk at tower A)
 *shift Nth disk from tower A to tower C (now tower A is empty,tower B has N-1 disks,tower C has Nth disk)
 *move(N-1,B,C) -> we are moving (N-1) disks from tower B tower C (so tower A and B are empty => we moved everything to tower C)
*/

void move(int n,char src,char helper,char dest){

    if(n == 0){  //base case
        return;
    }

    move(n-1,src,dest,helper); //here helper became destination-> moving (N-1) disks from A to B
    cout << "Shift disk " << n << " from " << src << " to " << dest << endl; //printing
    move(n-1,helper,src,dest); //here helper became src -> moving (N-1) disks from B to C

 }

int main(){

    int n = 3;
 
    move(n,'A','B','C');

return 0;
}
