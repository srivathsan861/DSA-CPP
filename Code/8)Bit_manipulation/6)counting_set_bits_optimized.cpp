#include<iostream>
using namespace std;

//NOTE: DRY RUN USING PAPER PEN FOR BETTER UNDERSTANDING

int count_bits(int n){

    int ans = 0;

    while(n > 0){           
        ans += (n & 1);    //so if the last bit is 1 we will increment
        n = n >> 1;        //and then we are right shifting 'n' because now we should consider the next bit (we can also left shift 1)
    } 

return ans;
}

int count_bits_optimized(int n){

    int ans = 0;

    while(n > 0){            //this while loop runs exacty the number os set bits present in 'n',HOW?
        n = n & (n-1);      //because (n & (n-1)) removes the last set bit, so on each iteration last set bit is removed
        ans++;             //incrementing ans
    }

return ans;
}

int main(){

    int n = 5;

    cout << "Number of set bits in 5: " << count_bits(n) << endl;

    cout << "Number of set bits in 5(optimized): " << count_bits_optimized(n) << endl;

    cout << "Number of set bits in 5(using inbuilt method): " << __builtin_popcount(n) << endl;

return 0;
}