#include<iostream>
using namespace std;

/*
we are given an array containing N numbers. all the no.s are present twice except for 2 no.s which are present only once.
find the unique no.s in linear time without using extra space for frequency array.(NOTE:display the min and max unique no.)

EXAMPLE: 5,1,2,1,2,3,5,7 -> 3,7

BRUTE FORCE: using frequency table

OPTIMAL APPROACH: Intuition

->if we find XOR of all no.s, the final XOR will be the XOR of 2 unique no.s because other identical no.s will get cancelled out
->in the above case final XOR is 3 ^ 7 = 0100 ->here find the position of the first set bit(it can be any set bit), position is 2
->now check all the no.s which has 2nd position set int he given array: 5,5,7
->take XOR of the above: 5 ^ 5 ^ 7 = 7 -> We found our first unique number from the array
->for finding the 2nd unique no. we can follow similar process,that is, find all the no.s from the array where position 2 is not set and take XOR of it.
->or what we can do is we can simply take XOR of unique no. 1 with final XOR of whole array: 3 ^ 7 ^ 7 = 3,We found our second unique number from the array
*/

int main(){
    
    cout << "Enter number of elements present: ";
    int n;
    cin >> n;

    int res = 0;

    int no;
    int arr[1000];
    
    cout << "Enter all the elements: " << endl;
    for(int i=0;i < n;++i){
        cin >> no;           //getting input
        arr[i] = no;         //storing the elements in an array
        res ^= no;           //finding the XOR of all no.s
    }
    
    int temp = res;        //we are storing res in temp because we want to use res afterwards

    int pos = 0;           //this variable is used  to find the first set bit of temp

    while((temp&1)!=1){    //check for set bit
        pos++;             //incrementing position until we hit a set bit
        temp = temp >> 1;  //then we are right shifting 'temp' because now we should consider the next bit 
    }

    int mask = (1 << pos); //left shift till pos, that is,if pos = 2,two 0's will be added at the end 
                           //this mask is later used with AND(&) to find the no.s which has bit set at position

    int x = 0;            //consider x,y as the 2 unique no.s
    int y = 0;

    for(int i=0;i < n;++i){
        if((arr[i] & mask) > 0){
            x = x ^ arr[i];        //if the pos bit is set then take the XOR of it -> we will get the first unique no. (example:5^5^7)
        }
    }

    y = res ^ x;                  //(example:3^7^7)

    cout << "MINIMUM of the 2 unique no.s: " << min(x,y) << endl;
    cout << "MAXIMUM of the 2 unique no.s: " << max(x,y) << endl;

return 0;
}