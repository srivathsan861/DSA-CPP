#include<iostream>
using namespace std;

/*
bubble_sort_partial_recursion:
 ->DRY-RUN:
           1st iteration    2nd iteration    3rd iteration
           5 4 1 0  N=4     4 1 0     N=3    1 0       N=2
           4 5 1 0  N=4     1 4 0     N=3    0 1       N=2
           4 1 5 0  N=4     1 0 4     N=3    fn(a,n-1)     -> N=1(base-case) -> return
           4 1 0 5  N=4     fn(a,n-1)    ->
           fn(a,n-1)    ->
*/

void bubble_sort_partial_recursion(int a[],int n){

    if(n == 1){           //base case
        return;
    }

    for(int j=0;j < n-1;++j){      //inner loop
        if(a[j] > a[j+1]){
            swap(a[j],a[j+1]);
        }
    }

    bubble_sort_partial_recursion(a,n-1); //we have converted the outer loop to recursive fn.
}

void bubble_sort_fully_recursive(int a[],int j,int n){

    if(n == 1){     //base case
        return;
    }

    //inner swap is performed (n-1) times 
    if(j == (n-1)){     //if 'j' reaches (n-1) re-initialize 'j' index to 0 and remove last element
        return bubble_sort_fully_recursive(a,0,n-1); //
    }

    if(a[j] > a[j+1]){     //swap 
        swap(a[j],a[j+1]);
    }

    bubble_sort_fully_recursive(a,j+1,n);  //if (j != (n-1)) keep iterating on 'j' and perform swap if necessary
    return;
}

int main(){

    int arr[] = {5,4,1,0};
    int n = sizeof(arr)/sizeof(int);
    
    bubble_sort_fully_recursive(arr,0,n);

    cout << "Sorted array: " << endl;

    for(int i=0;i < n;++i){
        cout << arr[i] << " ";
    }
    
return 0;
}