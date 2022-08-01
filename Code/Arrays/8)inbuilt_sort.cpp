#include<iostream>           
#include<algorithm>           //to use inbuilt sort    
using namespace std;      

int main(){
    
    int a[5]={0};                 //declaration and initialization
    
    cout << "Enter the values:" << endl;

    for(int i = 0; i < 5; ++i){
        cin >> a[i];                 //input
    }

    sort(a,a+5);                 //inbuilt sort(start of array,end of array)
    
    cout << "Sorted order: ";
    for(int i=0;i < 5;++i){
       cout << a[i] << " ";       //output
    }

return 0;
}