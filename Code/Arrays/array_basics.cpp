#include<iostream>
using namespace std;

int main(){
    
    int a[5]={0};
    
    cout << "Enter the values:" << endl;

    for(int i = 0; i < 5; ++i){
        cin >> a[i];
    }

    cout << "Out put:" << endl;
    
    for(int i = 0;i < 5;++i){
        cout << a[i] << " ";
    }

    cout << endl;
    
    cout << "Size od array: ";
    cout << sizeof(a) << endl;

    cout << "No. of elements in the array: ";
    cout << sizeof(a)/sizeof(a[0]);

    return 0;

}