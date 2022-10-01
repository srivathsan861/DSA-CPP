#include<iostream>
using namespace std;

/*
EXAMPLE: a = 20,b = 12 -> GDC/HCF = 4 , LCM = 60   

BRUTE FORCE: check from 1 to min(a,b) and find the largest no. which divides both 20 and 12

EUCLID'S ALGORITHM: (try to dry run)
 ->GCD(a,b) = GCD(b,a%b)
 ->GCD(a,0) = a;
*/

int gcd(int a,int b){
    return (b == 0) ? a : gcd(b,a%b);   //recursive approach, here (b == 0) is the base case
}

int main(){
    
    cout << "Enter two numbers: " << endl;
    int a,b;
    cin >> a >> b;

    cout << "Greatest common divisor of " << a << " and " << b << ": " << gcd(a,b) << endl;

    int lcm = (a*b)/gcd(a,b); // lcm * gcd = a * b => lcm = (a*b)/gcd;

    cout << "Least common multiple(LCM) of " << a << " and " << b << ": " << lcm << endl;

return 0;
}