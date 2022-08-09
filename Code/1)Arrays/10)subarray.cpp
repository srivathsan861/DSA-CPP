#include<iostream>        
using namespace std;     

int main(){
    
    int a[5]={0};                 //declaration and initialization
    
    cout << "Enter the values:" << endl;

    for(int i = 0; i < 5; ++i){
        cin >> a[i];                 //input
    }

    cout << "All possible sub arrays: " << endl;
    
   for(int i=0;i < 5;++i){            //i start from the start of the array

    for(int j=i;j < 5;++j){          //j start >= i , but not less than i

       for(int k=i;k <= j;++k){     //k traverses from i till j
        cout << a[k] << " ";       //printing all the subarray
       }

       cout << endl;
    }
   }
    
return 0;
}