#include<iostream>        
using namespace std;  

bool compare(int a,int b){     //comparator function
    return a < b;              //descending order
}

void bubble_sort(int a[],int n,bool(&cmp)(int a,int b)){  //getting the comparator function as input parameter

    for(int i=1;i <= n-1;++i){            //for n elements to sort we need n-1 iterations

        for(int j=0;j <= n-i-1;++j){     //on each iteration we need to do pair wise comparisons from 0 to n-i-1, WHY -i?
     //it's because on each iteration i elements get sorted, so we don't need that sorted elements to get compared again(optimization)
            if(cmp(a[j],a[j+1])){          //using the comparator function to do the check
                swap(a[j],a[j+1]);
            }
        }
    }
}

int main(){
    
    int a[5]={0};                 //declaration and initialization
    
    cout << "Enter the values:" << endl;

    for(int i = 0; i < 5; ++i){
        cin >> a[i];                 //input
    }
    
   cout << "Sorted order(descending): ";

    bubble_sort(a,5,compare);
    for(int i = 0; i < 5; ++i){
        cout << a[i] << " ";                 //output
    }

return 0;
}