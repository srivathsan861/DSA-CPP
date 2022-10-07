#include<iostream>
#include<cstring>
#define ll long
using namespace std;

/*
QUESTION: find no. of sub arrays such that sum of elements of subarray is divisible by no. of elements of the array(N).
          the array can contain negative values

EXAMPLE: 1,3,2,6,4 -> N=5
    O/P:   (3,2) =>  3 + 2 = 5 -> 5 % 5 = 0, hence true
           (6,4) =>  6 + 4 = 10 -> 10 % 5 = 0, hence true
           (3,2,6,4) =>  3 + 2 + 6 + 4 = 15 -> 15 % 5 = 0, hence true
           so the no. of subarrays which satisfies the condition is 3

NOTE: here we cannot generate all subarrays because we have multiple input test cases and
      value of N is large => N <= 10 POWER 5 => O(N*N) => TIME  LIMIT EXCEEDED

PROPERTY TO REMEMBER: (a-b)%m = ((a%m) - (b%m) + m)%m -> this extra +m is used to deal with negative values

PRINCIPLE TO REMEMBER: PIGEONHOLE (read about it)

APPROACH:
 ->find the cumulative sum and do (b-a)%n=0 to find whether that sum of sub array is divisible by N
 ->(b-a)%n=0 , this implies , b%N = a%N => a=b (so we will consider a new frequency array and consider the buckets which has frequency is atleast 2)
 ->and we will find nCr where n is the frequency and r is 2.

EXAMPLE:
 frequency array: 0 0 0 1 0 1 4 3
 ans = 4C2 +2C2 ->because there are 4 0s and 2 1s

NOTE: in code we will directly create the frequency array without creating a cummulative sum array
*/

ll arr[1000005];
ll freq_arr[1000005];

int main(){
  
  cout << "Enter no. of test cases: " << endl;
  int t;                                      
  cin >> t;

  while(t--){

    cout << "Enter the size of the array: ";
    int n;                                      
    cin >> n;

    memset(freq_arr,0,sizeof(freq_arr)); //(pointer to array,what value to initialize with,size)  //000000....00000

    freq_arr[0] = 1;   //there will be one empty substring for sure so the frequency of empty substring is 1
    
    int sum = 0;
    
    cout << "Enter the elements of the array: " << endl;
    for(int i=0;i < n;++i){

        cin >> arr[i];           //inputting the array elements
        sum += arr[i];           //adding all the values of the array and storing it in sum
        sum %= n;                //taking % n 
        sum = (sum + n)%n;       //+n to deal with negative values in array 
        freq_arr[sum]++;         //incrementing the frequency of a particular sum in the frequency array

    }

    ll ans = 0;

    for(int i=0;i < n;++i){

        int m = freq_arr[i];
        ans += (m) * (m-1)/2;   // finding nCr -> n * n-1/2  and adding it to ans

    }

   cout << "Number of sum of subarrays which are divisivle by " << n << ": " << ans << endl;

  }

return 0;
}