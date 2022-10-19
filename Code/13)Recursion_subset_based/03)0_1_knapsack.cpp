#include<iostream>
using namespace std;

/*
QUESTION: You are given N no. of items and you have all the wights and prices of items in two different arrays.
          You have a bag with a capacity 'C'. Fill the bag with items such that the price of items inside the bag is
          maximum. Also make sure don't overfull the bag!

EXAMPLE:
        ITEMS: I1 I2 I3 I4
      WEIGHTS:  1 2  3  5
       PRICES: 40 20 35 100
     CAPACITY: 7

     ->weight of I1 + I2 + I3 = 6 <= 7, true
       =>price = 40 + 20 + 35 = 95

     ->weight of I1 + I4 = 6 <= 7, true
       =>price = 40 + 100 = 140 <- max-profit

*HOW TO PROCEED?
Find subset of items such that weight of items in that subset <= C and profit is maximum.

APPROACH:
 ->for each item we have 2 cases, either to select it or not select it
 ->CASE 1: suppose we select last item -> include -> accordingly write the recursive call
 ->CASE 2: suppose we do not select last item -> exclude -> accordingly write the recursive call
 ->CASE 1, is only possible when C >= (weight of last item)
 ->return MAX(CASE 1,CASE 2)

BASE CASE:
 ->if N == 0 then return 0 -> no items left means 0 profit
 ->if C == 0 then return 0 -> if the bag capacity is 0 means we can't add more items
*/

int profit(int n,int c,int *wt,int *price){

    if(n == 0 || c == 0){ //base case
        return 0;
    }

    int ans=0;
    int inc,exc;
    inc=exc=0;

    //recursive case -> 2 options: include or exclude

    if(wt[n-1] <= c){    //check: is capacity available
        inc = price[n-1] + profit(n-1,c-wt[n-1],wt,price);
        //we do 'n-1' to check the next last item and weight of the item is reduced from the total available capacity
    }

    exc = profit(n-1,c,wt,price);
    //we do 'n-1' to check the next last item and here weight is not reduced since we are not including that item in the bag

    ans = max(inc,exc);

return ans;
}

int main(){

    int weights[] = {1,2,3,5};
    int prices[] = {40,20,30,100};
    int n=4;
    int c=7;

    cout << "Maximum profit: " << profit(n,c,weights,prices) << endl;

return 0;
}