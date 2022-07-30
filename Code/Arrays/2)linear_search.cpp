#include<iostream>
using namespace std;

int linear_search(int a[],int n,int key){ //array, size of array, value to be found
    int i{};
    for( i=0;i <= n;++i){
        if(a[i] == key){         //if the element = key , then we are returning the index and breaking the loop
            return i;
            break;
        }
    }
    if(i == n){                  // if i reaches n => element is not found after the traversal so return -1
        return -1;
    }   
    /*(OR)
     for( i=0;i < n;++i){
        if(a[i] == key){
            return i;
            break;
        }
        if(i == n-1){
            return -1;
        }   
    }
    */
    return i;
}

int main(){
    
    int a[5]={0};                 //declaration and initialization
    
    cout << "Enter the values:" << endl;

    for(int i = 0; i < 5; ++i){
        cin >> a[i];                 //input
    }

    cout << "Present at Index: " << linear_search(a,5,10);

    return 0;

}