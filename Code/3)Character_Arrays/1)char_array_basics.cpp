#include<iostream>
using namespace std;

int main(){

    int b[]={1,2,3};
    cout << b << " ";      //address of 0th element  will be printed

    char a[]={'a','b','c'};
    cout << a << " ";     //all elements will be printed

    cout << endl;

    char s1[10];
    cout << "Enter characters: " << endl;
    cin >> s1;                               //we don't need a loop to cin/cout char_arrays
    cout << "Output: " << endl;
    cout << s1;

    cout << endl;

    char s2[] = {'s','r','i'};
    cout << sizeof(s2) << " " << s2 << endl;   //3 - because it doesn't has a default null character at the end,you may get garbage

    char s3[] = {"sri"};
    cout << sizeof(s3) << " " << s3  << endl;  //4 - because it has a default null character at the end

return 0;
}