#include<iostream>
#include<set>
#include<string>
using namespace std;

/*
QUESTION: Given a string S, find all permutations of string S.

EXAMPLE: "abc" -> abc,acb,bca,cab,bac,cba => for a string with length 3 there will be 3! permutations which is equal to 6

ROUGH VISUALIZATION:
                    "abc"
             _________↓_________
            ↓         ↓         ↓
         a bc       b ac       c ab    i.e we select 'a' first and recursively call (n-1)! i.e bc
           ↓          ↓          ↓         we select 'b'  and recursively call (n-1)! i.e ac (to do this we will swap 'a' with 'b')
           ↓          ↓          ↓         we select 'c'  and recursively call (n-1)! i.e ab (to do this we will swap 'a' with 'c')
         a cb       b ac       c ba    i.e we are repeating the same steps for the (n-1)! that is swapping (b,c) , (a,c) , (a,b)

TIP: try to draw the recursion tree
*/

void permute(char *in,int i){

    if(in[i] == '\0'){       //base case
        cout << in << " ";
        return;
    }

    for(int j=i;in[j] != '\0'; ++j){

        swap(in[i],in[j]);  //1st iteration 'a' will be swapped with itself, on 2nd 'a' will be swapped with 'b' and then 'a' with 'c'
        permute(in,i+1);    //incrementing 'i' i.e current index in substring
        swap(in[i],in[j]);  //bactracking step to restore original array
        /*
        if we don't restore the array then we won't get the desired output. Since array is pass by reference when the function returns a output
        that output change is reflected everywhere because we are not using 2 seperate arrays as input array and output array.
        Example: 1st -> 'a' should be swapped with itself
                 2nd -> 'a' should be swapped with 'b' but it may happen that during the previous call 'abc' is already replaceed with 'acb'
                         which implies 'a' will be swapped with 'c' instead of 'b'. So every time we backtrack restore the array back to 'abc'
        TIP: try to draw the recursive tree for solution without having the backtracking step, you will find the answer is not correct
        */
    }
}

/*
VARIATION: suppose we want to find unique permutations in lexo-graphical order
HINT: we can use sets
*/

void unique_permute(char a[],int i,set<string> &s){
    
    if(a[i] == '\0'){   //base case

        string t(a);    //is suppose the current output is 'acb' then store it in a string
        s.insert(t);    //insert the string in a set -> it will store only unique permutations
        return;
    }

    for(int j=i; a[j] != '\0'; ++j){  //recursive case

        swap(a[i],a[j]);
        unique_permute(a,i+1,s);
        swap(a[i],a[j]);

    }
}

int main(){

    char a[100] =  "abb";
    set<string> s;
    
    cout << "All possible permutations: " << endl;
    permute(a,0);

    cout << endl << "Unique permutations: " << endl;
    unique_permute(a,0,s);
    for(auto str : s){
        cout << str << " ";
    }

return 0;
}