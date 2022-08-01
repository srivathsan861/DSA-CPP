#include<iostream>
using namespace std;

int main(){
   int a[5]={0};                 //declaration and initialization
   int cs[5]={0};
    cout << "Enter the values:" << endl;

    for(int i = 0; i < 5; ++i){
        cin >> a[i];                 //input
    }
    cs[0] = a[0];
    for(int i=1;i < 5;++i){
       cs[i] = cs[i-1] + a[i];
    //    cout << cs[i] << "=" << cs[i-1] << "+" << a[i] << endl;
    }

   int curr_sum = 0;  
   int max_sum = 0;

   int left = -1;                 // starting of the maximum sum subarray
   int right = -1;                // ending of the maximum sum subarray

   for(int i=0;i < 5;++i){

    for(int j=i;j < 5;++j){

        curr_sum = 0;              //re-initializing every time to calculate the sum of new subarray

       curr_sum = cs[j] - cs[i-1];

        if(curr_sum > max_sum){     //getting the maximum sub array sum
            max_sum = curr_sum;         
            left = i;
            right = j;
        }
    }
   }

   cout << "The maximum subarray sum is: " << max_sum << endl;
   cout <<"The maximum sum subarray is: ";
   for(int i=left;i <= right; ++i){   //printing the maximum sum subarray
    cout << a[i] << " ";
   }

return 0;
}