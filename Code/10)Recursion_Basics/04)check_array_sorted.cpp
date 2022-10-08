#include<iostream>
using namespace std;

/*
QUESTION:write a function to check if array is sorted

APPROACH:
 ->we are first splitting the array into 2 array, we can split it in many ways, but here we are considering 
 the first element as one array and the rest of the elements as another array
 ->RECURSIVE CASE: f(N) = [a[0] < a[1] & f(N-1) is sorted]
   it means if f(N-1) array is sortedd and the a[1] element of the array is greater than the a[0] -> return true

VISUALIZATION:
         a[] = 1 2 3 4 5      N=5
                   ↓          considering it as 2 different arrays 
               1     2 3 4 5  N=4
              a[0]   f(N-1)
        check a[0] < a[1] -> 1 < 2 -> true -> consider the next addres and decrement N
                   ↓
              1 2   3 4 5     N=3
        check a[0] < a[1] -> 2 < 3 -> true -> consider the next addres and decrement N
                   ↓
        continue this until N=1 or N=0   <- base case
        if N does not reach 1 or 0 then the array is not sorted
*/

bool is_sorted(int *a,int n){   //base address,size
    
    if(n == 0 || n == 1){       //base case 
        return true;
    }

    if(a[0] < a[1] && is_sorted(a+1,n-1)){     //recursive case
        return true;
    }

    return false;                //if n does not reach 1 or 0
}

int main(){

    int arr[] = {1,2,9,4,5};
    int n=5;

    if(is_sorted(arr,n)){
        cout << "The array is sorted!";
    }
    else{
        cout << "The array is not sorted!";
    }

return 0;
}