#include<iostream>
using namespace std;

/*
EXAPMPLE: i/p: 2048 , o/p: two zero four eight

DRY-RUN: 
        TOP-DOWN
        N=2048  (perform n/10 on each recursive call)
            ↓     extracted (you can extract last digit of 'n' by performing n%10)
           204        8     ↑	 print "eight"
            ↓
            20        4     ↑	 print "four"
            ↓
            2         0     ↑	 print "zero"
            ↓
base case-> 0         2     ↑	 print "two"
                         BOTTOM-UP
*/

char words[][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

void print_spelling(int n){

    if(n == 0){        //base case
        return;
    }

    print_spelling(n/10);   //recursive case

    int digit = n % 10;    //we can fetch the last digit of 'n' by taking % 10

    cout << words[digit] << " ";  //we are printing after recursive call => bottom-up

return;
}

int main(){
    
    cout << "Enter a number: ";
    int n;
    cin >> n;

    cout << "Number to word: " << endl;
    print_spelling(n);

return 0;
}