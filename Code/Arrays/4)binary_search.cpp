#include<iostream>
using namespace std;

//NOTE: for binary search array must be in a sorted order!

int binary_search(int a[],int n,int key){  

    int start = 0;                           //start of array
    int end = n-1;                           //end of array

    while(start <= end){                   // if element is present the start will be lesser or equal to end

        int mid = (start + end)/2;         //finding middle of array

        if(a[mid] == key){                 // checking middle of array = key value
            return mid;
        }
        else if(a[mid] > key){            //if a[mid] > key , then we are bringing the END TO MID-1
            end = mid - 1;
        }else{
            start = mid + 1;             //if a[mid] < key , then we are bringing the START TO MID+1
        }
    }

return -1;                              //if element not found => start > end , return -1
}

int main(){

    int a[5]={0};                 //declaration and initialization
    
    cout << "Enter the values:" << endl;

    for(int i = 0; i < 5; ++i){
        cin >> a[i];                 //input
    }

    cout << binary_search(a,5,10);   

return 0;
}