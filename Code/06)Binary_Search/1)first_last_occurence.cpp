#include<iostream>
using namespace std;

int first_occurence(int arr[],int n,int key){

    int start = 0;          
    int end = n-1;
    int ans = -1;

    while(start <= end){

        int mid = (start + end)/2;

        if(arr[mid] == key){
            ans = mid;             //if mid == key --> storeg mid as ans
            end = mid - 1;        //checking for another occurence before mid as our goal is to find the first occurence
        }
        else if(arr[mid] > key){  //if mid > key bring end to mid-1
            end = mid-1;
        }
        else{                    //if mid < key bring start to mid+1 
            start = mid+1;
        }
    }
 return ans;
}

int last_occurence(int arr[],int n,int key){
    int start = 0;
    int end = n-1;
    int ans = -1;

    while(start <= end){
        int mid = (start + end)/2;
        if(arr[mid] == key){
            ans = mid;               //if mid == key --> storeg mid as ans
            start = mid + 1;        //checking for another occurence after mid as our goal is to find the last occurence
        }
        else if(arr[mid] > key){    //if mid > key bring end to mid-1
            end = mid-1;
        }
        else{                       //if mid < key bring start to mid+1 
            start = mid+1;
        }
    }
 return ans;
}

int main(){

    int arr[] = {1,2,2,2,3,3,3,3,4,4,5,5,5,5,5,6};
    int n = sizeof(arr)/sizeof(int);              //size of array

    cout << "Index: " << first_occurence(arr,n,3) << endl; 
    cout << "Index: " <<last_occurence(arr,n,5) <<endl;

return 0;
}