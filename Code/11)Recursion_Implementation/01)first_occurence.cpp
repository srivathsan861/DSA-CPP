#include<iostream>
using namespace std;

/*
QUESTION: find the first occurenece of key using recursion

TIP: try dry running and coding yourself once

VISUALIZATION:
 ->try dividing the array into 2 part -> first element is one array and consider the rest (N-1) elements in another array
                                  □□□□□□ -> size of array is N
                                    ↓
                                     (N-1)
                                 □   □□□□□
                                     i=0
 ->if the key is found in the first part of the array then return 0 because it is the first element
 ->if it is not found in the first part of the array keep on starting from the next base address and decrease the N
 ->finally return the index + 1 because we didn't include the first element.
 ->if N reaches 0 return -1 -> element not found
 ->EXAMPLE: find first occurence of 7
                            1 2 7 3 7        N=5
                              2 7 3 7        N=4
                                7 3 7        N=3
                    BOTTOM-UP
7 3 7     returns -> a[0] = 7 ->  return 0 
2 7 3 7   returns -> i+1 -> 0+1 = 1
1 2 7 3 7 returns -> i+1 -> 1+1 = 2   (index 2 is the first occurence of 7)

KEY POINTS:
 ->if suppose 7 is not present in f(N-1) then it will return -1 and our function also will return -1
 ->if suppose 7 is present then return 0 and on each previouse recursive calls will return i+1
*/

int first_occurenece(int *a,int n,int key){

    if(n == 0){             //base case
        return -1;
    }

    if(a[0] == key){        //if key is find on the oth position of the f[N-1] array -> return 0
        return 0;
    }

    int i = first_occurenece(a+1,n-1,key); //recursive case

    return i + 1;          //return index + 1 if any function call doesn't return -1
}

/*
-> another way of writing recursive code to find 'first occurence of key' this code is similar to linear search code.
-> the aim of this is to learn how we do linear search recursively and how we write loops in terms os recursive code 
->here we won't change the base address of the array but just increment ith position and check

VISUALIZATION: i=0  ->        i=1     ->    i=2, here a[2] == key
               (1 2 7 3 7) (1 2 7 3 7) (1 2 7 3 7) 
                return 2 <- return 2  <- return 2 <-
*/

int first_occurence_linear_search(int *a,int start,int end,int key){
      
      if(start == end){   //base case
        return -1;
      }

      if(a[start] == key){     //if condition in linear search
        return start;
      }

      return first_occurence_linear_search(a,start+1,end,key);
                                     //         ↓
                                     //      updation part
                                     //      if we are using loop
} 

int main(){

    int arr[] = {1,2,7,3,7};
    int n = sizeof(arr)/sizeof(int);
    int key = 7;

    cout << "First occurence of 7 is on index: " << first_occurenece(arr,n,key) << endl;
    cout << "First occurence of 7 is on index: " << first_occurence_linear_search(arr,0,n,key) << endl;

return 0;
}