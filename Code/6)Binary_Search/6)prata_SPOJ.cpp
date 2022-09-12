#include<iostream>
using namespace std;

/*
 ->president want to serve paratas after function and all are asked to take paratas -> p(p <= 1000)
 ->the stall has 'L' cooks -> L(L <= 50), each cook rank -> R(1 <=R <=8)
 ->a cook wil rank 'R' will cook in this fashion : 1R 2R 3R ,that is for 1st parata he takes 1R time , 2nd parata -> 2R time
 ->EXAMPLE: cook with rank:1 for making 3 paratas -> 1(1) + 2(1) + 3(1) = 6 mins
 ->we need to find the min time to get the parata
*/

bool ip(int rank_arr[],int parata,int cook,int time_given){
    int c = 1;
    int parata_made = 0;
    int cp=0;

   int tt;
   int count = 0;
   int val = 1;

   for(int i=0;i < cook;++i){
     tt = rank_arr[i];
     count++;
     val++;
     tt += (val*rank_arr[i]);
   }
   cp += count;

   if(cp >= parata){
    return true;
   }
 return false;
}

int find_min_time(int arr[],int parata,int cooks){
    int start = 0;
    int end = 0;
    // for(int i=0;i < cooks;++i){
    //     end += arr[i];
    // }
    end = ((parata) * (parata+1))/2;
    int ans = 0;

    while(start <= end){
        int mid = (start+end)/2;
        bool is_possible = ip(arr,parata,cooks,mid);
        if(ip){
           ans = mid;
           end = mid - 1;
        }
        else{
           end = mid+1;
        }
    }
 return ans;
}

int main(){

    int t;      //no. of test cases
    cin >> t;

    for(int i=0;i < t;++i){

        int parata ,cooks;
        cin >> parata >> cooks;

        int arr[1000];

        for(int j=0;j < cooks;++j){
            cin >> arr[cooks];           //input no. of pages 
        }

        cout << find_min_time(arr,parata,cooks);
    }

    
return 0;
}