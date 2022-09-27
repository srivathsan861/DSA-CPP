#include<iostream>
using namespace std;

//NOTE: DRY RUN USING PAPER PEN FOR BETTER UNDERSTANDING

/*
EXAMPLE:
N=1001101
M=0000
i = 3
j = 6
ANS = 0000101 (we are replacing position i to j of N with M)
*/

int clear_i_to_j_bits(int n,int i,int j){
    int ones = (~0);        //(~0) = -1 -> first keeeping all as 1 -> 1111111
    int a = ones << (j+1);  //till j+1 setting it to 0 -> 1110000 (assume j = 3)
    int b = (1 << i) - 1;   //we need to create something like 01111 -> whis is in the form [2 Power(n) -1],suppose we need 4 ones then 'n' should be 4
    int mask = a | b;      //by taking OR on a,b we will get all bit as 1 except the bits from i to j
    int ans = n & mask;    //then we can perform AND with the numbers so that we can clear the bits from i to j
    return ans;
}

int replace_bits(int n,int m,int i,int j){
    int cleared_n = clear_i_to_j_bits(n,i,j); //storing the cleared n
    int ans = cleared_n | (m << i);    //m << i adds i 0's after m and by taking OR we will replace i to j in N by M
    return ans;
}

int main(){

    int n = 77; //1001101
    int m = 0;
    int i = 3;
    int j = 6;

    cout << "After replacing: " << replace_bits(n,m,i,j);  //0000101 -> 101 = 5

return 0;
}