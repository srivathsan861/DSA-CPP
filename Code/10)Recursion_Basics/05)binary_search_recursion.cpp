#include<iostream>
using namespace std;

int BS_recursion(int arr[],int start,int end,int k){

    int mid = (start+end)/2;
    
    if( end >= start){

    if(k == arr[mid]){                              //base case
        return mid;
    }
    else if(arr[mid] > k){                          //if k value is lesser than mid -> search on first half of the array
        return BS_recursion(arr,start,mid-1,k);
    }
    else{
        return BS_recursion(arr,mid+1,end,k);       //if k value is greater than mid -> search on second half of the array
    }

    }

return -1;                                         //element not found
}

int main(){

    int arr[] = {1,4,6,8,10};
    int k = 8;
    int start = 0;
    int end = (sizeof(arr)/sizeof(int))-1;

    cout << "INDEX: " << BS_recursion(arr,start,end,k);

return 0;
}
