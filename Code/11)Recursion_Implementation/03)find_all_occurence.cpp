#include<iostream>
using namespace std;

/*
QUESTION:find all occurrences of key in the given array
*/

void all_occurrences(int *a,int i,int n,int key){  //similar to recursive linear search approach

    if(i == n){        //base case
        return;
    }

    if(a[i] == key){         //if the ith position is equal to key then print the position
        cout << i << " ";
    }

    all_occurrences(a,i+1,n,key); //recursive case
}

//here we are storing all the occurrences in an output array and returning the size of that array

int store_all_occurreneces(int *a,int i,int n,int key,int *out,int j){

    if(i == n){        //base case -> return size of the output array
        return j;
    }

    if(a[i] == key){  //if the ith position is equal to key then print the position -> store the position in output array

        out[j] = i;
        return store_all_occurreneces(a,i+1,n,key,out,j+1); //increment 'j' to accomodate current occurenece

    }

    return store_all_occurreneces(a,i+1,n,key,out,j);  //if a[i] != key -> 'j' remains unchanged and 'i' alone is incremented
}

int main(){

    int arr[] = {1,2,3,7,4,5,6,7,10};
    int key = 7;
    int n = sizeof(arr)/sizeof(int);
    
    cout << "All indices in which 7 occurs: " << endl;
    all_occurrences(arr,0,n,key);

    int output[100];
    int count = store_all_occurreneces(arr,0,n,key,output,0);

    cout << endl << "No. of indices in which 7 occurs: " << count << endl;
    
    cout << "All indices in which 7 occurs: " << endl;
    for(int k=0;k < count;++k){
        cout << output[k] << " ";
    }

return 0;
}