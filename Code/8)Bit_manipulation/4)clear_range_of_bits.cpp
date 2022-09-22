#include<iostream>
using namespace std;

int clear_last_i_bits(int n,int i){
    int mask = (-1 << i); //creating all ones and left shifting 'i' places so that if i=4 , then 4 0's will be added to the last
    return n & mask;     //and by performing AND with the number we will clear all bits strting from i
}

int clear_i_to_j_bits(int n,int i,int j){
    int ones = (~0);        //(~0) = -1 -> first keeeping all as 1 -> 1111111
    int a = ones << (j+1);  //till j+1 setting it to 0 -> 1110000 (assume j = 3)
    int b = (1 << i) - 1;   //we need to create something like 01111 -> whis is in the form [2 Power(n) -1],suppose we need 4 ones then 'n' should be 4
    int mask = a | b;      //by taking OR on a,b we will get all bit as 1 except the bits from i to j
    int ans = n & mask;    //then we can perform AND with the numbers so that we can clear the bits from i to j
    return ans;
}

int main(){
   
   int n = 77; //1001101

   cout << "Clearing last 4 bits from 1001101: " << clear_last_i_bits(n,4) << endl; //1000000 = 64

   cout << "Clearing 3 to 6 bits from 1001101: " << clear_i_to_j_bits(n,3,6) << endl; //0000101 -> 101 = 5

return 0;
}