#include<iostream>
using namespace std;

/*
 ->Farmer John has built a new long barn with N stalls and these stalls are located along straight line
 ->cows can be kept in these stalls, stalls >= cows (cows get aggressive when placed near)
 ->you need to assign the cows to stalls such that the minimum distance between any two cows is large as possible
 ->FIND the LARGEST MINIMUM DISTANCE
 */

int can_place_cows(int stalls[],int n,int cows,int min_seperation){ //mid value is passed in min seperation

    int last_cow = stalls[0];                       //assigning the first cow int the from thr stalls as the last cow
    int count = 1;                                  //and since we assigned the first cow , count is 1

    for(int i=1;i < n;++i){                        //starting from the second cow

        if(stalls[i] - last_cow >= min_seperation){ //if the subtraction of current stall and the last_cow stall is >= min seperation
            last_cow = stalls[i];                   //then placing the cow in that stall  (we are just changing the last cow position)
            count++;                                //incrementing the no. of cows placed till now
                                  
            if(count == cows){                     // if we place all the cows for that min seperation, return true
                return true;
            }
        }

    }
    return false;                                //if we did'nt place all the cows for the given min speration, return false
}

/*
EXAMPLE: DRY RUN

stalls are at : 1 2 3 8 9, mid is 3
last cow is at stall[0], that is, 1
constraint: stall[i] - last cow >= min seperation  (that is mid)

stall[1] - 1 >= 3
2 - 1 >= 3 , false

stall[2] - 1 >= 3
3 - 1 >= 3 , false

stall[3] - 1 >= 3
8 - 1 >= 3 , true  , then increment count, repeat it
if finally  count == cows , then it is a potential ans 
else decrease the value of min seperation
*/

int main(){

    int stalls[] = {1,2,3,4,8,9};
    int n = sizeof(stalls)/sizeof(int);
    int cows = 3;

    int start = 0;
    int end = stalls[n-1] - stalls[0]; //this is our search space because the max distance between 2 stalls can be last stall - first stall
    
    int ans = 0;

    while(start <= end){

        int mid = (start+end)/2;

        bool can_place = can_place_cows(stalls,n,cows,mid);

        if(can_place){
            ans = mid;          //we got an answer 
            start = mid+1;     //but searching for a greater ans
        }
        else{
            end = mid-1;      //we did'nt get an ans, so we are decreasing the minimum seperation and checking againg
        }

    }

    cout << "LARGEST MINIMUM DISTANCE: " << ans << endl;

return 0;
}