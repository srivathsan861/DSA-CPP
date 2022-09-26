#include<iostream>
#include<cstring>
using namespace std;

/*
I/O: abc
O/P: "",a,ab,abc,ac,b,bc,c
APPROACH:
 EXAMPLE: abc -> length = 3 (total no. of possibilities: (2 POWER 3)-1 = 7)
 ->BINARY NUMBER SYSTEM:
   0 : 000 -> " "
   1 : 001 -> a
   2 : 010 -> b
   3 : 011 -> bc
   4 : 100 -> c
   5 : 101 -> ac
   6 : 110 -> ab
   7 : 111 -> abc
 ->so what we can do with this binary number system and how to use it to get our subsequence?
 ->now we can divide the problem into 2 parts
    (1)iterate over a set of no.s (till 2 POWER N-1)
    (2)filter/extract the element characters which corresponds to set bit in N.
*/

void filter_chars(int n,char arr[]){

    int j = 0;

    while(n > 0){  

        int last_bit = (n & 1);   //store the last bit

        if(last_bit){
            cout << arr[j];       //if the last bit is set then print the corresponding character
        }

        j++;                      //increment the bit position

        n = n >> 1;               //then we are right shifting 'n' because now we should consider the next bit
    }

    cout << ",";
}

void print_subsets(char arr[]){

    int n = strlen(arr);

    for(int i=0;i < (1 << n);++i){  //loop runs till [(2 POWER N)-1] -> [(1 << N)-1] -> [i < (1 << N)]
        filter_chars(i,arr);        
    }

return;
}

int main(){

    char a[100];
    cin >> a;
    
    cout << "Subset/Subsequence of abc:" << endl;
    print_subsets(a);

return 0;
}