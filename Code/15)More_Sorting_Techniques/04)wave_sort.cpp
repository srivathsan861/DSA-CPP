#include<iostream>
using namespace std;

/*
QUESTION: Sort the array in such a way that ith inex is greater then the (i+1)th index and (i+2)th index should 
          be lesser then (i+1)th index at every instance.

NOTE: 
*Most asked interview problem

EXAMPLE: 1,3,4,2,7,5
 ->BRUTE-FORCE:
   *first sort the array -> 1,2,3,4,5,7
   *couple swap -> 2,1,4,3,7,5
   *TIME COMPLEXITY: O(N LOG N)
 
 ->OPTIMAL APPROACH: 
   *check if (i+1) pos. is greater than ith pos. -> if yes swap it with ith pos. else don't swap
   *so what we are trying to do here is except for the first and last index, at every 2nd index
   check if it has higher value than its previous and next elemen. if this is true don't swap.
   *TIME COMPLEXITY: O(N)
*/

int main(){

    int a[] = {1,3,4,2,7,8};
    int n = sizeof(a)/sizeof(int);

    for(int i=0;i < n;i+=2){
        
        //check prev. element
        if(i != 0 && a[i] < a[i-1]){  //'i != 0' is included because first element can't have prev element
            swap(a[i],a[i-1]);
        }
        
        //check next element
        if(i != (n-1) && a[i] < a[i+1]){  //'i != (n-1)' is included because last element can't have next element
            swap(a[i],a[i+1]);
        }
    
    }
    
    cout << "Wave sort:" << endl;

    for(int i=0;i < n;++i){    //printing output
        cout << a[i] << " ";
    }

return 0;
}