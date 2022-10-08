#include<iostream>
using namespace std;

/*
QUESTION: (multiply 'a'->'b' times) without using * operator

APPROACH:
 ->try dividing (a TIMES b) into sub problem
 ->a TIMES b = a + (a TIMES (b-1)) <-recursive case
 ->if b = 0 then return 0 <- base case

EXAMPLE: a = 5 b = 5
 ->here we are not trying to do 5*5 = 25
 ->we are trying to do 5+5+5+5+5 = 25
*/

int multiply(int a,int b){

    if(b == 0){             //base case
        return 0;
    }

    if(a == 0){            //anything multiplied with 0 is 0
        return 0;
    }

    int m1 = a;
    int m2 = multiply(a,b-1); //recursive case

    int ans = m1 + m2;
    return ans;
}

int main(){

    int a = 5;
    int b = 5;

    cout << "ANSWER: " << multiply(a,b);

return 0;
}