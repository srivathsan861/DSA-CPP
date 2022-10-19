#include<iostream>
using namespace std;

/*
QUESTION: Generate balanced brackets using N pairs of round brackets

EXAMPLE: *N=2       *N=3   
          ()()       ()()()
          (())       (())()
                     ()(())
                     (()())
                     ((()))

APPROACH:
 ->we should fill a string of length 'N*2', we should fill in such a way that the brackets are balanced
 ->RANDOM-CASE: N=3, ( ( _ _ _ _
                         i
    *assume we have a case like this with 2 openning brackets at start and 'i' is at the current position
    *here we can put '(' or ')' bracket,HOW?
    *here we can put '(' because N=3 which implies there can be max of 3 continuous open brackets
    *here we can put ')' because to put a closing bracketwe should have atleast that no. of opening brackets
     i.e(count of closing bracket) < (count of opening bracket)

SUMMARIZING:
 ->at any index 'i', (no. of open brackets) < N
 ->at any index 'i', (no. of close bracket) < (np. of open brackets)

TIP: try to draw the recursive tree               
*/

void generate_brackets(char *out,int n,int idx,int open,int close){

    if(idx == 2*n){            //base case
        out[idx] = '\0';
        cout << out << endl;
        return;
    }

    //recursive case
    if(open < n){
        out[idx]='(';
        generate_brackets(out,n,idx+1,open+1,close); //incrementing index and no. of open brackets
    }
    if(close < open){
        out[idx]=')';
        generate_brackets(out,n,idx+1,open,close+1); //incrementing index and no. of close brackets
    }

return;
}

int main(){
    
    cout << "Enter a positive number: ";
    int n;
    cin >> n;

    char out[100];

    cout << "All possible balanced brackets: " << endl;
    generate_brackets(out,n,0,0,0);

return 0;
}