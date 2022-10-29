#include<iostream>
using namespace std;

/*
NOTE: we will use this sort when the range of elements is small

TIME COMPLEXITY: O(N + range of elements) aprox. equals to O(N)
*/

void counting_sort(int *a,int n){

    int largest=-1;
    for(int i=0;i < n;++i){
        largest = max(largest,a[i]);  //finding the largest element in the array
    }

    //create a frequency array
    int *freq_arr = new int[largest+1]{0};

    for(int i=0;i<n;++i){
        freq_arr[a[i]]++;    //incrementing the frequency of each element
    }

    //put elements back into the array 'a' by reading freq_arr
    int j=0;
    for(int i=0;i <= largest;i++){

        while(freq_arr[i] > 0){
            /*
            ->suppose the frequency  of number 1 is 2. then we will first insert a[0] = 1;
            ->then we will decrement the frequency of 1 in the freq_arr
            ->and again we will insert the other 1 after incrementing the 'j' pointer i.e a[1]=1
            */
            a[j] = i;
            freq_arr[i]--;        
            j++;
        }

    }
}

int main(){

    int a[7] = {4,3,4,7,6,3,1};
    int n = sizeof(a)/sizeof(int);

    counting_sort(a,n);
    
    cout << "Sorted array: " << endl;
    
    for(int i=0;i < n;++i){
        cout << a[i] << " ";
    } 

return 0;
}