#include<iostream>
using namespace std;

int main(){
    
    cout << "AND(&) OPERATOR: " << endl;
    cout << "1 & 1: " << (1 & 1) << endl;   //1
    cout << "1 & 0: " << (1 & 0) << endl;   //0
    cout << "0 & 1: " << (0 & 1) << endl;   //0
    cout << "0 & 0: " << (0 & 0) << endl;   //0
     
    cout << "OR(|) OPERATOR: " << endl;
    cout << "1 | 1: " << (1 | 1) << endl;   //1
    cout << "1 | 0: " << (1 | 0) << endl;   //1
    cout << "0 | 1: " << (0 | 1) << endl;   //1
    cout << "0 | 0: " << (0 | 0) << endl;   //0

    cout << "XOR(^) OPERATOR: " << endl;    //same bits 0, diff. bits 1
    cout << "1 ^ 1: " << (1 ^ 1) << endl;   //0
    cout << "1 ^ 0: " << (1 ^ 0) << endl;   //1
    cout << "0 ^ 1: " << (0 ^ 1) << endl;   //1
    cout << "0 ^ 0: " << (0 ^ 0) << endl;   //0
   
    cout << "NOT(~) OPERATOR: " << endl;
    cout << "~1: " << (~1) << endl;      //-2, because not of 1 is 0 (2 power -2 = 0)
    cout << "~0: " << (~0) << endl;      //-1, beacuse not of 0 is 1 (2 power -1 = 1)
    
    //means we are shifting all bits by one position towards left (a << b) = a * 2 power b
    cout << "LEFT SHIFT -> 5 << 1: " << (5 << 1) << endl;  //5 -> 000101,afterLeftShift 001010 -> 010 = 10
    
    //means we are shifting all bits by one position towards right (a >> b) = a/(2 power b)
    cout << "RIGHT SHIFT -> 5 >> 1: " << (5 >> 1) << endl; //5 -> 000101,afteRightShift 010 -> 010 = 2

return 0;
}