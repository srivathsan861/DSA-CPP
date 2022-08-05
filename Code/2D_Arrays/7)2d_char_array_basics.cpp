#include<iostream>
using namespace std;

int main(){

    char a[][10] = {{'h','e','l','l','o','\0'},{'b','a','t','\0'}};  //declaration and initialization
    cout << a[0] << endl;
    cout << a[1] << endl;

    char b[][10] = {"ab","abc","abcd"};     //declaration and initialization
    cout << b[0] << endl;
    cout << b[1] << endl;
    cout << b[2] << endl;

    char c[10][10];                //declaration
    c[0][0] = 'a';                
    cout << c[0] << endl;

    char d[100][1000];           //declaration
    
    cout << "Enter row size: ";
    int n;
    cin >> n;
    cin.get();       //includes whitespace, this helps to take a input with white space in between them

    for(int i=0;i < n;++i){         //input
        cin.getline(d[i],1000);     //getline reads each line, and it is getting input in the ith position, 1000 represent the maximum size of string 
    }
    
    cout << "Output: " << endl;

    for(int i=0;i < n;++i){
        cout << d[i] << endl;      //output
    }

return 0;
}