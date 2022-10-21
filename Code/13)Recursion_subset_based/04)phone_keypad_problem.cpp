#include<iostream>
using namespace std;

/*
QUESTION: Print all the possible subsets of strings which can be formed when particular keys in keypad are clicked.

NOTE: 1 - 
      2 - abc
      3 - def
      4 - ghi
      5 - jkl
      6 - mno
      7 - pqrs
      8 - tuv
      9 - wxyz
      0 - 

EXAMPLE:
 ->PHONE-KEYPAD: 23  i.e user has pressed 2 and 3
                 2 -> abc , 3 -> def

            O/P: ad bd cd
                 ae be ce 
                 af bf cf

TIP: try to draw the recursive tree (it's similar to subset problem's recursive tree) 
*/

char keypad[][10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; //2D-char. array

void generate_names(char *in,char *out,int i,int j){

    if(in[i] == '\0'){    //base case
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    int digit = in[i] - '0'; //converting the ith char digit to int because we are taking input as char

    if(digit == 1 || digit == 0){  //corner-case i.e if we '0123' -> 0 and 1 will be skipped but subsets of 23 will be printed
        generate_names(in,out,i+1,j); //incrementing input pointer alone because there is no associated characters with 0 and 1
    }
    
    for(int k=0; keypad[digit][k] != '\0';k++){ //if digit = 2, then we are traversing 'abc' and inserting it in the output array
         
         out[j] = keypad[digit][k];  

         //fill the remaining part
         generate_names(in,out,i+1,j+1); //incrementing input and output pointer
    }

return;
}

int main(){
    
    cout << "Enter digits in keypad:" << endl;
    char in[100]; //digits
    cin >> in;

    char out[100];
    
    cout << "All possible subsets:" << endl;
    generate_names(in,out,0,0);

return 0;
}