#include<iostream>
using namespace std;

int main(){
     
    int a[5]={0};                 //declaration and initialization

    cout << "Enter the values:" << endl;

    for(int i = 0; i < 5; ++i){
        cin >> a[i];                 //input
    }

    int curr_sum = 0;
    int max_sum = 0;

    for(int i=0;i < 5;++i){

        curr_sum += a[i];      //storing sum of subarray

        if(curr_sum < 0){     //if sum of sub array becomes lesser than 0, then re-initialize it to 0
            curr_sum = 0;
        }
        if(curr_sum > max_sum){     //getting the maximum sub array sum
            max_sum = curr_sum;         
        }

    }

    cout << "The maximum subarray sum is: " << max_sum << endl;

return 0;
}