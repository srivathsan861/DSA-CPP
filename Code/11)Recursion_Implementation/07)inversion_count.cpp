#include<iostream>
using namespace std;

/*
QUESTION: a good inversion pair is such that a[i] > a[j] for (i < j) -> if satisfies include it in inversion count

TIP: dry run your code with your own example

                  i     j
EXAMPLE: a[] = {1,5,2,6,3,0}
         a[i] > a[j] i.e 5 > 3 -> true
               i > j i.e 1 < 4 -> true
         =>(5,3) is a good inversion pair, like this we can make many pairs and return total count of pairs
         i.e (1,0),(5,3),(5,2),(5,0),(2,0),(6,0),(3,0),(6,3) => count = 8

BRUTE-FORCE:
 ->use 2 loops, 1st loop to iterste over all elements 'i'
 ->2nd loop to iterate over all elements infront of 'i'
 ->TIME COMPLEXITY: O(N*N)
 ->PSEUDO-CODE:
               for(i=0 ... n-2)
                  for(j=i+1 ... n-1)
                     if(a[i] > a[j])
                        count++

DIVIDE AND CONQUER:
 ->VISUALIZATION:
                  1 5 2 6 3 0
            1 5 2            6 3 0
        1 5       2       6 3      0
       1   5             6   3
        1 5               3 6 (y=1)
           1 2 5(x=1)         0 3 6 (y=3)
                  0 1 2 3 5 6 (z = 4)

       here, x = possible inversions on the left-array
             y = possible inversions on the right-array
             z = possible cross-inversions i.e 'i' lies in the left-array and 'j' lies in the right-array
        =>   total no. of possible inversions = x + y + z => 1 + 3 + 4 = 8
*/

int merge(int *a,int s,int e){

    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    int k = s;
    int temp[100000];
    int count = 0;             //cross-inversion

    while(i <= mid && j <= e){

        if(a[i] < a[j]){        //if a[i] < a[j] -> insert a[i] in temp[k]
            temp[k] = a[i];
            k++;
            i++;
        }
        else{                   //if a[j] < a[i] -> insert a[j] in temp[k]
            temp[k] = a[j];
            k++;
            j++;
            count += mid-i+1;  //HOW?
            /*
            if a[i] > a[j] then (a[i+1],a[i+2],..a[mid]) > a[j] -> because the array is sorted
            EXAMPLE:
                    X X 5 6 7 8      (assume a[i] > a [j])
                        i      mid
                => count = mid - (i-1)
                => count = mid - i + 1  (it is similar to finding  sum of sub-array using cummulative sum)
            */
        }
    } 

    while(i <= mid){            //if 2nd array i.e 'j' pointer array is exhausted -> insert all remaining a[i] in temp[k] 
        temp[k++] = a[i++];
    }

    while(j <= e){              //if 1st array i.e 'i' pointer array is exhausted -> insert all remaining a[j] in temp[k]
        temp[k++] = a[j++];
    }

    for(int i=s;i <= e;++i){    //copy all sorted elements to original array from temp
        a[i] = temp[i];
    }

return count;                   
}

int inversion_count(int *a,int s,int e){

    if(s >= e){   //base case
        return 0;
    }

    int mid = (s+e)/2;
    
    //recursively divide
    int x = inversion_count(a,s,mid);
    int y = inversion_count(a,mid+1,e);

    int z = merge(a,s,e);   //merge 2 sorted arrays by computing the inversion count

    return x+y+z;
}

int main(){

    int arr[] = {1,5,2,6,3,0};
    int n = sizeof(arr)/sizeof(int);

    cout << "Total inversion counts: " << inversion_count(arr,0,n-1);

return 0;
}