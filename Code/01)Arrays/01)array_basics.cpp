#include<iostream>        // to use cout,cin
using namespace std;      // to avoid std:: before those functionalities std::cout, std::cin

int main(){
    
    int a[5]={0};                 //declaration and initialization
    
    cout << "Enter the values:" << endl;

    for(int i = 0; i < 5; ++i){
        cin >> a[i];                 //input
    }

    cout << "Out put:" << endl;
    
    for(int i = 0;i < 5;++i){
        cout << a[i] << " ";        //output
    }

    cout << endl;
    
    cout << "Size of array: ";
    cout << sizeof(a) << endl;

    cout << "No. of elements in the array: ";
    cout << sizeof(a)/sizeof(a[0]);

    return 0;

}