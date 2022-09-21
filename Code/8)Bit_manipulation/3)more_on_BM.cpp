#include<iostream>
using namespace std;

//NOTE: DRY RUN USING PAPER PEN FOR BETTER UNDERSTANDING

bool isOdd(int n){
    return (n & 1);                   //last bit set then odd else even
}

int get_ith_Bit(int n,int i){
    int mask = (1 << i);                //making everything 0 except ith bit and using it as mask
    int bit = (n & mask) > 0 ? 1 : 0;  //if the (&) val is greater the 0 then bit is set else not
    return bit;
}

int set_ith_Bit(int n,int i){
    int mask = (1 << i);             //same as get_ith_bit,but here we should perform (OR)  because we should go to the ith bit and set it to 1
    int ans = n | mask;
    return ans;
}

int clear_ith_Bit(int n,int i){  
    int mask = ~(1 << i);        //here we will go to the ith bit and take negate of it because then while performing (&) the opposite will happen
    n = n & mask;                //it is similar to get_ith_bit, but we are taking negate of the mask
    return n;
}

int update_ith_Bit(int n,int i,int v){ //for updating ith bit we first go the the ith bit and clear it
    int mask = ~(i << i);          
    int cleared_n = n & mask;          //storing cleared ith bit 'n' as 'cleared_n'
    n = cleared_n | (v << i);          //we want the ith bit val according to the given value 'v'
    return n;
}

int main(){

    int a = 5;  //binary form: 101, the indexing starts from right to left and start from 0, that is,2<-1<-0

    cout << "Is 5 odd? " << isOdd(a) << endl; //101 -> last bit is 1 so odd

    cout << "Find the 2nd  bit of 5: " << get_ith_Bit(a,2) << endl; //101 -> second bit is 1 
    
    cout << "Set 1st bit of 5: " << set_ith_Bit(a,1) << endl; //101 -> setting 1st bit 1 -> 111 = 7

    cout << "Clear 2nd bit of 5: " << clear_ith_Bit(a,2) << endl; //101 -> clear 2nd bit -> 001 = 1

    cout << "Update 1st bit value to 1: " << update_ith_Bit(a,1,1); //101 -> update 1st bit value to 1 -> 111 = 7

return 0;
}