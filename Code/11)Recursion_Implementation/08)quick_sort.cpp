#include<iostream>
using namespace std;

/*
QUICK-SORT:
 ->VISUALIZATION:            
                             P
                 2 7 8 6 1 5 4  (here we are choosing last element as pivot element => p = 4)
                     ↓
                     P
                 2 1 4 7 8 6 5  (left of pivot element is no.s which are smaller and right side with the no.s which are larger)4

            a1              a2
        left-part       right-part
        fn(a,s,p-1)     fn(a,p+1,e) 
        ...goes on recursively
  
 ->TIP: try dry running it on your own

 ->STEPS:
   * choose pivot
   *divide/partition-> greater than pivot and lesser than pivot
   *recursively solve a1 and a2

 ->RULES:
   *if p < a[j] -> j=j+1
   *if p > a[j] -> i=i+1,swap(a[i],a[j]),j=j+1
 
 ->TIME COMPLEXITY:
   *O(N LOG N) -> avg case
   *O(N*N) -> worst case -> we can fix it by using randomized quick sort
*/

int partition(int *a,int s,int e){

    int i = s-1;            //one step behind 'j'
    int j = s;
    int pivot = a[e];       //here we are choosing last element as pivot element (you can choose any element as pivot element)

    for( ;j <= e-1; ){        //we can also increment 'j' inside for loop, but we are incrementing it down

        if(a[j] <= pivot){   // if a[j] <= pivot -> first increment 'i' and swap a[i] and a[j] -> so that values lesser than pivot
            i=i+1;           // comes left to pivot element
            swap(a[i],a[j]);
        }
        
        j=j+1;               //incrementing 'j'
    }
  
    swap(a[i+1],a[e]);       //placing pivot in the correct index

return i+1;                  //returning the pivot index -> we need this index to split the array into 2 parts
}

void quick_sort(int *a,int s,int e){

    if(s >= e){      //base case
        return;
    }

    int p = partition(a,s,e);
    
    //recursively divide
    quick_sort(a,s,p-1);   //left part
    quick_sort(a,p+1,e);   //right part

return;
}

int main(){

    int arr[] = {2,7,8,6,1,5,4};
    int n = sizeof(arr)/sizeof(int);

    quick_sort(arr,0,n-1);
    
    cout << "Sorted array: " << endl;

    for(int i=0;i <= n-1;++i){
        cout << arr[i] << " ";
    }

return 0;
}