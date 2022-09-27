#include<iostream>
using namespace std;

//NOTE: DRY RUN USING PAPER PEN FOR BETTER UNDERSTANDING

int decimal_to_binary(int n){

    int ans = 0;
    int p = 1;    

    while(n > 0){
        int last_bit = (n & 1);   //storing the last bit
        ans += (last_bit * p);   //for each iteration p value changes in this fashion: 1,10,100,1000..
        p = p * 10;              //converting to base 10
        n = n >> 1;             //then we are right shifting 'n' because now we should consider the next bit (we can also left shift 1)
    }

return ans;
}

int main(){

    int n = 13;
    cout << "Binary Value of 13: " << decimal_to_binary(n);

return 0;
}