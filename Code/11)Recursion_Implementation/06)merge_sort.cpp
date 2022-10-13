#include<iostream>
using namespace std;

/*
MERGE SORT:
 ->VISUALIZATION:
                 5 6 1 2 4 0
            5 6 1           2 4 0    ->recursively dividing into 2 arrays i.e from (0 to mid),(mid + 1 to end)
        5 6       1      2 4      0  ->recursively dividing into 2 arrays i.e from (0 to mid),(mid + 1 to end)
       5   6            2   4        ->recursively dividing into 2 arrays i.e from (0 to mid),(mid + 1 to end)
        5 6              2 4         ->merging 
            1 5 6             0 2 4  ->merging
                  0 1 2 4 5 6        ->merging
*/

void merge(int *a,int s,int e){

    int mid = (s+e)/2;

    int i = s;
    int j = mid+1;
    int k = s;     

    int temp[100];          //to store sorted values

    while(i <= mid && j <= e){

        if(a[i] < a[j]){      //if a[i] < a[j] -> insert a[i] in temp[k]
            temp[k] = a[i];
            k++;
            i++;
        }
        else{                 //if a[j] < a[i] -> insert a[j] in temp[k]
            temp[k] = a[j];
            k++;
            j++;
        }
    }

    while(i <= mid){         //if 2nd array i.e 'j' pointer array is exhausted -> insert all remaining a[i] in temp[k] 
        temp[k] = a[i];
        k++;
        i++;
    }
    
    while (j <= e)           //if 1st array i.e 'i' pointer array is exhausted -> insert all remaining a[j] in temp[k]
    {
       temp[k] = a[j];
       k++;
       j++;
    }

    for(int i=s;i <= e;++i){   //copy all sorted elements to original array from temp
        a[i] = temp[i];
    }
    
}

void merge_sort(int a[],int s,int e){

    if(s >= e){       //base case
        return;
    }

    int mid = (s+e)/2;
    
    //recursively divide
    merge_sort(a,s,mid);       
    merge_sort(a,mid+1,e);

    merge(a,s,e);    //merge 2 sorted arrays

}

int main(){

    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr)/sizeof(int);

    merge_sort(arr,0,n-1);

    cout << "Sorted array: " << endl;

    for(int i=0;i < n;++i){
        cout << arr[i] << " ";
    }

return 0;
}