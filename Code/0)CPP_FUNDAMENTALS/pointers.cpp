#include<iostream>
using namespace std;

void increment_1(int a){
    a = a + 1;
    cout << "Inside function: " << a << endl;
}

void increment_2(int *a){
    *a = *a + 1;           //dereferencing and adding since it is an address
    cout << "Inside function: " << *a << endl;
}

int main(){

    //===============================================================================================

    int x = 10;

    cout << "Printing address of x: " << &x << endl;  // & -> fetches the address of variable

    int *y;  //pointer variable is used to store the address of a variable
    y = &x;  

    cout << "Printing y: " << y << endl; //address 

    //same
    cout << "Printing y after dereferencing it: " << *y << endl;  // * -> dereferencing
    cout << "Printing &x after dereferencing it: " << *(&x) << endl;

    cout << "*(y) + 1 : " << *(y) + 1 << endl; //10+1=11

    cout << "y+1: " << y+1 << endl; //next address
    cout << "*(y+1): " << *(y+1) << endl; //garbage value in next address

    //same
    cout << "*(&y): " << *(&y) << endl;
    cout << " &(*y): " << &(*y) << endl;


    int **yy = &y;   //double pointer --> stores address of address
    //same
    cout << "&y: " << &y << endl;
    cout << "**yy: " << yy << endl;

    //===========================================================================================
    //*****PASS BY VALUE********

    int a1 = 10;
    increment_1(a1);        // a copy of a1 is made and incremented
    cout << "Inside main: " << a1 << endl;

    //===========================================================================================
    //*****PASS BY REFERENCE********

    int a2 = 10;
    increment_2(&a2);      // no copy is made but the address of a2 is passed
    cout << "Inside main: " << a2 << endl;

return 0;
}