#include<iostream>
#include<climits>        // to use INT_MAX,INT_MIN
using namespace std;

int main(){

    int a[5]={0};                 //declaration and initialization
    
    cout << "Enter the values:" << endl;

    for(int i = 0; i < 5; ++i){
        cin >> a[i];                 //input
    }

    int smallest = INT_MAX;
    int largest = INT_MIN;

    for(int i=0;i < 5;++i){
        if(a[i] < smallest){   
            smallest = a[i];
        }
        if(largest < a[i]){
            largest = a[i];
        }
        /*(OR) we can use inbuit functions
        largest = max(largest,a[i])
        smallest = min(smallest,a[i])
        */
    }
    
    cout << "Largest: " << largest << " Smallest: " << smallest << endl;

return 0;
}