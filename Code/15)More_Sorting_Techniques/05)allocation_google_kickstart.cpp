#include<iostream>
#include<algorithm>
using namespace std;

/*
QUESTION: There are N houses for sales. The ith house costs A dollars to buy. You have budget of B dollars
          to spend. What is the max no. of houses you can buy?

NOTE: Google kickstart level-1 problem

CONSTRAINTS:
 -> 1 <= test cases(t) <= 100
 -> 1 <= B <= 10^5
 -> 1 <= A <= 1000

INTUITION:
 to buy max no. of houses we should buy cheap houses first => we should first sort the array
*/

int main(){

    int t;  
    int n; 
    int b;
    int a[100000];

    cout << "Enter no. of test cases: ";
    cin >> t;

    while(t--){
        
        cout << "Enter no. of houses for sale and total budget available: " << endl;
        cin >> n >> b;
        
        cout << "Enter the cost of each house: " << endl;
        for(int i=1;i <= n;++i){
            cin >> a[i];
        }

        sort(a+1,a+n+1); //O(N LOG N)
        //we can use COUNTING SORT here as max cost of a house is just 1000 -> aprox.O(N)

        int ans=0;

        for(int i=1;i <=n;++i){

            if(b >= a[i]){   //check if you have budget to buy the house
                ans++;
                b -= a[i];   //reduce cost of house from the total budget
            }

        }

        cout << "Max no. of houses you can buy: " << ans << endl;
}

return 0;
}