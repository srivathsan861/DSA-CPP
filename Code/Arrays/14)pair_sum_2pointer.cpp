#include<iostream>
using namespace std;

//given a sorted array, find pair of elements that sum to K

int main(){

    int a[1000]={0};                 //declaration and initialization
    int n = 0;                        //size of array
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the values:" << endl;
    for(int i = 0; i < n; ++i){
        cin >> a[i];                 //input
    }
    int k=0;
    cout << "Enter the K value: ";
    cin >> k;

    int i=0;                     // first index
    int j=n-1;                   //last index

    /*NOTE: if sum > k  --> decrement j pointer from last
            if sum < k  --> increment i pointer from first
            if sum == k --> decrement j and increment i
            repeat this process unit i < j
    */
   
    while(i < j){                     
        int curr_sum = a[i] + a[j];  // we are adding first and last element and accordingly we are moving the pointers
        if(curr_sum > k){            
            j--;
        }else if(curr_sum < k){
            i++;
        }else if(curr_sum == k){
            cout << "The indices which sums to  K are: " << i << "and" << j << endl;
            j--;
            i++;
        }
    }

return 0;
}