#include<iostream>
using namespace std;

int find(int arr[],int n,int key){
    
    int start = 0;
    int end = n-1;

    while(start <= end){

        int mid = (start+end)/2;

        if(arr[mid] == key){        //if mid == key --> return mid
            return mid;
        }

        else if(arr[start] <= arr[mid]){                //if start <= mid --> mid will be in the first sorted part
            if(key >= arr[start] && key <= arr[mid]){   //if key lies in range [start to mid] then bring end to first sorted part[end=mid-1]
                end = mid-1;                           
            }
            else{                                      //if key lies in range [mid+1 to end] then bring start to second sorted part[start=mid+1]
                start = mid+1;
            }
        }

        else{                                          //mid will be in the second sorted part
            if(key >= arr[mid] && key <= arr[end]){   //if key lies in range [mid to end] then bring start to second sorted part[start=mid+1]
                start = mid+1;
            }
            else{                                    //if key lies in range [mid-1 to start] then bring end to first sorted part[end=mid-1]
                end = mid-1;
            }
        }

    }
 return -1;
}

int main(){
    /*
    example:
    12345  ->we are rotating on index 3
    45123 ->sorted-rotated array
    */

    int arr[] = {4,5,1,2,3};                     
    //we can think like 4,5 is one sorted part(first sorted part) and 1,2,3 is another sorted part(second sorted part)
    
    int n = sizeof(arr)/sizeof(int);              //size of array

    cout << "Index: " << find(arr,n,1) << endl; 
    cout << "Index: " << find(arr,n,100) << endl; 

return 0;
}