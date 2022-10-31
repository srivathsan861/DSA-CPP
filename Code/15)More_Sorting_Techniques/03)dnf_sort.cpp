#include<iostream>
using namespace std;

/*
QUESTION: You will be given an array of 1s,2s and 3s. Sort them in linear time.

TIP: use dutch national flag algorithm

NOTE: 
*Most asked interview problem
*DNF and counting sort takes O(N) but DNF sorts the array in single iteration

VISUALIZATION:
 ->RANDOM-CASE: 0000 1111 _ _ _ _ _ 2222
                    l    m         h         (m to h is the unsorted part which contains 0s,1s and 2s) 
    where l = low, m = mid i.e current position, h = high

 ->initially there won't be any region of 0s,1s and 2s but while traversing we will put it in correct region       

 PSEUDO-CODE:
      while(m < h)
       if a[m] == 0 -> swap it with l
       if a[m] == 2 -> swap it with h
       if a[m] == 1 -> just increment m
*/

void dnf_sort(int a[],int n){

    int low=0;
    int mid=0;
    int high=n-1;

    while(mid <= high){

        if(a[mid] == 0){
            swap(a[mid],a[low]);
            low++;
            mid++;
        }

        if(a[mid] == 1){
            mid++;
        }

        if(a[mid] == 2){
            swap(a[mid],a[high]);
            high--;
            //don't do mid++ here because we may have 0 at mid, to be more clear dry-run -> 1,2,0,0,1,2,0
        }

    }

return;
}

int main(){
    
    int a[] = {1,2,0,0,1,2,0};
    int n = sizeof(a)/sizeof(int); 

    dnf_sort(a,n);
    
    cout << "Sorted array: " << endl;

    for(int i=0;i<n;++i){
        cout << a[i] << " ";
    }

return 0;
}