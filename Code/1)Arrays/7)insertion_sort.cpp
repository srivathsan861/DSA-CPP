#include<iostream>        
using namespace std;   

int insertion_sort(int a[],int n){

    for(int i=1;i <= n-1;++i){      //for n elements to sort we need n-1 iterations, conside i is the start of unsorted array

        int e = a[i];               // storing the current element in e
        int j = i-1;                //initializing j = no. lesser than i, assume j is the start of sorted array

        while(j >=0 && a[j] > e){   // j should not be -ve and if a[j] > current element 

            a[j+1] = a[j];          //store the jth value in the position of j+1
            j = j - 1;              //decrementing j

        }
        a[j+1] = e;                //if e > a[j] store e in the j+1 position
    }
}

int main(){
    
    int a[5]={0};                 //declaration and initialization
    
    cout << "Enter the values:" << endl;

    for(int i = 0; i < 5; ++i){
        cin >> a[i];                 //input
    }
    
   cout << "Sorted order: ";

    insertion_sort(a,5);
    for(int i = 0; i < 5; ++i){
        cout << a[i] << " ";                 //output
    }

return 0;
}