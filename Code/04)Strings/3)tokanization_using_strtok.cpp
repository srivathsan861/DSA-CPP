#include<iostream>
#include<cstring>
using namespace std;

int main(){

    char a[500];

    cout << "Enter a sentence: " << endl;
    cin.getline(a,500);

    cout << "Output: " << endl;

    char *ptr = strtok(a," ");           //strtok function return a new char_array address having the first word of the sentence

    cout << ptr << endl;                // here it prints first word of the sentence

    while(ptr != NULL){                
        ptr = strtok(NULL," ");        // here it will print the consequtive words seperately, space is used as delimeter here
        cout << ptr << endl;           
    }

    /* 
    --> char *strtok(char *s,char *delimeter)
    --> return a char pointer, return tokens on each subsequent call
    -->first call, function shoould be passed with string argument
    -->on subsequent calls we should pass the string argument as NULL
    -->this is because it internally maintains the state of string using a static array
    -->final value of ptr after all subsequence is NULL
    */

return 0;
}