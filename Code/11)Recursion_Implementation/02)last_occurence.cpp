#include<iostream>
using namespace std;

/*
QUESTION: find the last occurenece of key using recursion

APPROACH 1: we can recursively traverse the array from back (it's similar to performing linear search recursively from backwards)

APPROACH 2: we can traverse the array from left to right recursively

  ->VISUALIZATION: find last occurenece of 7 in the given array

                TOP-DOWN
        N=6        ↓   1 2 7 3 7 6  return i+1 -> 3+1 = 4 -> return 4    ↑  => last occurence of 7 is at index 4
        N=5        ↓     2 7 3 7 6  return i+1 -> 2+1 = 3 -> return 3    ↑
        N=4        ↓       7 3 7 6  return i+1 -> 1+1 = 2 -> return 2    ↑
        N=3        ↓         3 7 6  return i+1 -> 0+1 = 1 -> return 1    ↑
        N=2        ↓           7 6  check a[0] = 7 -> yes -> return o    ↑
        N=1        ↓             6  check a[0] = 7 -> no -> return -1    ↑
        N=0        ↓             [] -> N=0 -> return -1 (base case)      ↑
                                                                     BOTTOM-UP
*/

int last_occurence(int *a,int n,int key){

    if(n == 0){          //base case
        return -1;
    }

    int i = last_occurence(a+1,n-1,key);   //recursive case

    if(i == -1){                   //if first element of sub-problem is key -> return 0
        if(a[0] == key){
            return 0;
        }
        else{
            return -1;            //if first element of sub-problem is key -> return -1
        }
    }

    return i+1;                  //if 'i' returned by sub-problem is 0 ->return i+1
}

int main(){

    int arr[] = {1,2,7,3,7,6};
    int n = sizeof(arr)/sizeof(int);
    int key = 7;

    cout << "Last occurence of 7 is on index: " << last_occurence(arr,n,key);

return 0;
}