#include<iostream>
using namespace std;

//Given a list of numbers, every number occurs twice except one, find that number.
//EXAMPLE: 3,2,3,5,6,5,2 -> o/p: 6

int main(){
    
    cout << "Enter no. of elements present: ";
    int n;
    cin >> n;

    int ans = 0;

    cout << "Enter the value: ";
    for(int i=0;i < n;++i){
        int no;
        cin >> no;
        ans ^= no;                //the intuition is xor of same numbers is 0 so we will be left with the unique number   
    }
    
    cout << "The nuber which occurs once is: " << ans;

return 0;
}