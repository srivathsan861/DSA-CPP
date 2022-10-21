#include<iostream>
using namespace std;

/*
QUESTION: Find all the possible subsets of characters corresponding to the given number.

NOTE:
 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
 a b c d e f g h i j   k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z

EXAMPLE: s = 1234
         *(1234) -> abcd
         *(12)(3)(4) -> lcd  
         *(1)(23)(4) -> awd

         *(12)(34) -> we can't take this because 34 is not a valid number

TIP: try to draw the recursive tree
*/

void generate_strings(char *in,char *out,int i,int j){

    if(in[i] == '\0'){ //base case
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    //recursive case - we have 2 options

    //option 1 - take one digit at a time

    int digit = in[i] - '0'; //converting the ith char digit to int because we are taking input as char

    char ch = digit + 'a' - 1; //if digit=1 -> 1+a-1=a, if digit=2 -> 2+a-1 = a+1 = b ....

    out[j] = ch;   //inserting the character in output array

    generate_strings(in,out,i+1,j+1); //incrementing input and output pointer

    //option 2 - take 2 digit at a time

    if(in[i+1] != '\0'){ //i.e if we want to take 2 digits, the second digit shouldn't be null
         
         int second_digit = in[i+1] - '0'; //converting char to int

         int no = digit * 10 + second_digit; //if first digit is 1 and second digit is 2, we should conside it as 12 so 1*10+2=12

         if(no <= 26){ //check: no. is valid or not

            ch = no + 'a' - 1;

            out[j] = ch; 
            
            generate_strings(in,out,i+2,j+1); //incrementing input pointer+2 because we are considering double digits
         }
    }

return;
}

int main(){

    cout << "Enter digits:" << endl;
    char in[100]; //digits
    cin >> in;

    char out[100];
    
    cout << "All possible subsets:" << endl;
    generate_strings(in,out,0,0);

return 0;
}