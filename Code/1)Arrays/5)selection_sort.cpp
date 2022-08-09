#include<iostream>        
using namespace std;      

void selection_sort(int a[],int n){

   for(int i=0;i < n-1;++i){          // this loops till < n-1 , because we don't need to sort the last element
                                     // i denotes end of the sorted array => 0 till i-1 is sorted
    int min_index = i;               //assumming min_index = i 

    for(int j=i;j <= n-1;++j){       //j denotes start of the unsorted array

        if(a[j] < a[min_index]){     // if a[j] < a[min_index], we are just interchanging the indices
            min_index = j;           //NOTE: we are not swapping the element here, we are swapping the indices
        }                            //since swaping is a costly operation , it is better to do it outside the inner loop

    }
    swap(a[i],a[min_index]);        //here we are swapping the ith element and the jth  (i.e the min_index) using inbuilt swap function

   }
}

int main(){
    
    int a[5]={0};                 //declaration and initialization
    
    cout << "Enter the values:" << endl;

    for(int i = 0; i < 5; ++i){
        cin >> a[i];                 //input
    }

    selection_sort(a,5);
    
    cout << "Sorted order: ";
    for(int i = 0;i < 5;++i){
        cout << a[i] << " ";
    }

return 0;
}