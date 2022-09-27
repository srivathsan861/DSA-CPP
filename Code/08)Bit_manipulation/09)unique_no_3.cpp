#include<iostream>
using namespace std;

/*
we are given an array containing N numbers. All the no.s are present thrice except for one no. which is present once.Find the number.
EXAMPLE: 3,3,2,1,1,1,3 -> 2
OPTIMAL APPROACH:
->the sum of all can be in the form 3N or 3N+1 because every no. is occuring thrice except one no., so if the unique no. is odd then it will be 3N+1 else 3N.
->now add all the bits,
  EXAMPLE: 101
           111
           001
    TOTAL: 213
->now store this 213 in an 64-bit array (because at the worst case it can be 64 bit)
->after storing it in an array it will be stord in reverse order: 312 as the indexing of binary moves from right to left
->take %3 with the elements in the array because by taking mod we eliminate contribution of bits for no.s which are occuring 3N times
->we will finally left out with the unique no.
->NOTE: we can extend this approach to 5N+1,7N+1....etc. (we should take the mod accordingly)
*/

int main(){

int count[64] = {0};                   //initializing it to 0

cout << "Enter number of elements: ";
int n;
cin >> n;

int no;
cout << "Enter the values: " << endl;

for(int i=0;i < n;++i){

   cin >> no;                        //getting input

   int j = 0;

   while(no > 0){                  

    int last_bit = (no & 1);        //storing last bit
    count[j] += last_bit;           //adding last bit in the array
    j++;                            //incrementing the array index
    no = no >> 1;                   //then we are right shifting 'no' because now we should consider the next bit

   }
}

int p = 1;
int ans = 0;

for(int i=0;i < 64;++i){

    count[i] %= 3;                //removing 3N contribution
    ans += (count[i] * p);        //binary to decimal
    p = p * 2;                    //making it base 2 (we can also write: p = p << 1)

}

cout << "The unique number is: " << ans << endl;

return 0;
}