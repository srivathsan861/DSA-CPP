#include<iostream>
#include<string>
#include<cstring>
using namespace std;

/*
EXAMPLE: i/p:"1234" , o/p:1234

INTUITION:
 ->if you do (string "4" - string "0") -> we will get (int 4)

DRY-RUN: (on each recursive call do (n-1) where 'n' is the length of the string)
                    extracted
         "1 2 3 4" 
         "1 2 3"        4 => 123*10+4 = 1234 => returns 1234
         "1 2"          3 => 12*10+3 = 123 => returns 123
         "1"            2 => 1*10+2=12 => returns 12
         "0"            1 => 0*10+1  => return 1
                          multiply with 10
*/

int string_to_int(char *a,int n){

    if(n == 0){       //base case
        return 0;
    }

    int digit = a[n-1] - '0';  //last digit

    int small_ans = string_to_int(a,n-1);  //recursive case

    return (small_ans*10) + digit;
}

int main(){

    char s[] = "1234";
    int n = strlen(s);

    int ans = string_to_int(s,n);

    cout << "Adding 1 to the answer to check conversion to int: " << ans+1 << endl;

return 0;
}