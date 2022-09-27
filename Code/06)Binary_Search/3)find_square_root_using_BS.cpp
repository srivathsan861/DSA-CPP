#include<iostream>
using namespace std;

float square_root(int n,int p){  // n -> number , p ->precision
     
    int start = 0;
    int end = n;        //this is because square root can range from 0 to the no. itself
    float ans = -1;      

    while(start<=end){

        int mid = (start+end) >> 1;

        if(mid*mid == n){       //it's a perfect square
            return mid;
        }

        if(mid*mid < n){        //mid is a potential ans,we are finding an ans which is lesser to n and closest to n
            ans = mid;         //storing the mmid to ans
            start = mid+1;    //trying to find square value closer to n
        }
        else{
            end = mid-1;     //if mid*mid > n, we are trying to bring the square of mid lesser than n
        }
    }
    
    float inc = 0.1;      

    for(int i=1;i <= p;++i){     //this loop runs till we hit the required no. of precisions

        while(ans*ans <= n){   //while ans square is lesser/equal to n we are adding in 0.1
            ans = ans + inc;  //at max it can run 10 times,that is,0 to 9
        }
        ans = ans-inc;       //subtracting the overshot value
        inc = inc/10;       //we should start incrementing for the 2nd precision,that is, 0.1/10 = 0.01
    }
    
  return ans;
}

int main(){

    int n,p;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Enter a precision: ";
    cin >> p;
    cout << "Square root of " << n << " is: " << square_root(n,p) << endl;

return 0;
}