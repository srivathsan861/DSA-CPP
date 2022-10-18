#include<iostream>
using namespace std;

/*
QUESTION: Given a string containing N characters, find out all subsets/subsequences of that string.
          (a subset can also have non-continuous characters)

I/P: "abc" , O/P: ["","a","b","c","ab","ac","bc","abc"]

VISUALIZATION:
                                  s = abc
    either you can include 'a'               either you don't include 'a' 
    and include 'bc'                         and include 'bc'
    a bc                                     bc
       ↓            subsets of 'bc'           ↓
     a+""                                     ""   ->gets printed 8th
     a+"b"                                    "b"  ->gets printed 7th
     a+"c"                                    "c"  ->gets printed 6th
     a+"bc"                                   "bc" ->gets printed 5th
       ↓
      "a"   ->gets printed 4th
      "ab"  ->gets printed 3rd
      "ac"  ->gets printed 2nd
      "abc" ->gets printed 1st

TIP: try to draw the recursive tree 
*/

void generate_subsequences(char *in,char *out,int i,int j){

    //base case
    if(in[i] == '\0'){        //if 'i' reaches end of input array
        out[j] = '\0';        //insert 'null' at the output array
        cout << out << endl;  //print the output
        return;
    }

    //recursive case - we have 2 options

    //option 1: include the current character
    out[j] = in[i];
    generate_subsequences(in,out,i+1,j+1); //incrementing input array pointer and output array pointer

    //option 2: exclude the current character
    //note: we can do out[j] = '\0' but, we won't because those values will be replaced by other recursive calls
    generate_subsequences(in,out,i+1,j); //not incrementing output array pointer

}

int main(){

    char input[] = "abc";
    char output[100];
    
    generate_subsequences(input,output,0,0);

return 0;
}