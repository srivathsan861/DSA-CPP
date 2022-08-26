#include<iostream>
#include<algorithm>
using namespace std;

/*
CONTENT:
1)FIND FUNCTION
2)BINARY SEARCH FUNCTION
3)UPPER AND LOWER BOUND FUNCTION
4)MONEY CHANGE PROBLEM
5)ROTATE FUNCTION
6)NEXT PERMUTATION FUNCTION
7)SOME HANDY FUNCTIONS
8)PAIR CONTAINER
*/

bool compare(int a,int b){
    return a <= b;          //used in money change problem
}

int main(){
    //*****FIND FUNCTION*****
    int arr[] = {1,9,10,10,11,19,12};
    int n = sizeof(arr)/sizeof(int); //size of array

    auto it = find(arr,arr+n,10); //auto -> int* ,it returns the address of the respective element occuring for the first time

    int index = it - arr; //elements address - base address gives the index value of the element
    
    if(index == n){  //if index value reaches last index -> element not found
        cout << "Element not found!" << endl;
    }else{
        cout << "Element is found at index: " << index << endl;
    }

    cout  << "=============================================================" << endl;

    //*****BINARY_SEARCH FUNCTION*****
    bool present = binary_search(arr,arr+n,10); //returns boolean value

    if(present){
        cout << "Element is present!" << endl;
    }else{
        cout << "Element is absent!" << endl;
    }

    cout  << "=============================================================" << endl;

    //*****UPPER_BOUND AND LOWER_BOUND FUNCTION*****
    auto it2 = lower_bound(arr,arr+n,10);
    cout << "Lower bound of value 10 is: " << (it2 - arr) << endl; //returns address of the element occuring for the first time

    auto it3 = upper_bound(arr,arr+n,10);
    cout << "Upper bound of value 10 is: " << (it3 - arr) << endl; //returns address of the element occuring for the first time + 1

    cout << "Frequency of element with value 10 is: " << it3 - it2 << endl; //upper_bound - lower_bound = frequency of element(only if sorted)

    cout  << "=============================================================" << endl;

    //*****MONEY CHANGE PROBLEM*****
    
    /* 
    AIM :We want to find a number from the array which is lesser than money
    ->if we find lower_bound of 168, we will get 200 from the array, but we need 100
    ->if we -1 from from the address, then we will get 100, but what if we want 100 itself?(corner case)
    ->default lower_bound condition >= , this we are changing using a compare function to <=
    ->now if money = 168 -> we will get 100 AND if money = 100 -> we will get 100 
    ->we should keep on subtracting the coins unit we reach to 0
    ->Example: money = (input)168 , minimum coin change = (output)100,50,10,5,2,1
    */

    int coins[] = {1,2,5,10,20,50,100,200,500,2000}; //should be sorted

    int s = sizeof(coins)/sizeof(int);

    int money = 168;

    cout << "Minimum money change for 168 rs: " << endl;

    while(money > 0){
        int lb = lower_bound(coins,coins+s,money,compare) - coins - 1;
        int m = coins[lb];
        cout << m << ",";  
        money = money - m;
    }

    cout  << endl << "=============================================================" << endl;
     
    //*****ROTATE FUNCTION*****
    int arr2[] = {1,2,3,4,5};
    int n2 = sizeof(arr2)/sizeof(int);

    cout << "Input array: " << endl;
    for(int i=0;i < n2;++i){
       cout << arr2[i] << " ";   
    }

    rotate(arr2,arr2+2,arr2+n2);  //starts rotating from 2nd index

    cout << endl <<"Output array after rotation at index 2: " << endl;
    for(int i=0;i < n2;++i){
        cout << arr2[i] << " ";
    }

    cout << endl << "=============================================================" << endl;
    
    //*****NEXT_PERMUTATION FUNCTION*****
    vector<int> vec{1,2,3};                //vector-> variable sized array

    cout << "Input vector: " << endl;
    for(int i = 0;i < vec.size();++i){
        cout << vec[i] << " ";            //123
    }

    next_permutation(vec.begin(),vec.end()); //begin and end is first and last position of the vector

    cout << endl << "Output vector after performing next_permutation once: " << endl;
     for(int i = 0;i < vec.size();++i){
        cout << vec[i] << " ";            //132
    }

    next_permutation(vec.begin(),vec.end());

    cout << endl << "Output vector after performing next_permutation twice: " << endl;
     for(int i = 0;i < vec.size();++i){
        cout << vec[i] << " ";            //213
    }

    cout << endl << "=============================================================" << endl;
    
    //*****SOME HANDY FUNCTIONS FUNCTION*****
    vector<int> vec2 = {10,20,30,40,50};

    cout << "Input vector: " << endl;
    for(int i = 0;i < vec2.size();++i){
        cout << vec2[i] << " ";
    }

    int max_val =  *max_element(vec2.begin(),vec2.end()); //min and max won't work here but will work with arrays
    int min_val = *min_element(vec2.begin(),vec2.end());

    cout << endl << "Maximum value: " << max_val << endl;
    cout << "Minimum value: " << min_val << endl;

    swap(vec2[0],vec2[1]);                            //swapping first two elements of the vector

    cout << "After swapping first 2 indices: " << endl;
    for(int i = 0;i < vec2.size();++i){
        cout << vec2[i] << " ";
    }
    
    reverse(vec2.begin(),vec2.begin()+3);           //reversing first 3 elements of the vector

    cout << endl << "Reversing first 3 element of the vector: " << endl;          
    for(int i = 0;i < vec2.size();++i){
        cout << vec2[i] << " ";
    }
    
    cout << endl << "=============================================================" << endl;
    
    //*****PAIR CONTAINER*****
    pair<int,char> p1;     //can contain 2 values of same or different data types
    p1.first = 10;
    p1.second = 'S';
    cout << "Value of p1: " << p1.first << "," << p1.second << endl; 

    pair<int,char> p2(p1); //copying pair 1 to pair 2
    cout << "Value of p2: " << p2.first << "," << p2.second << endl; 

    pair<int,string> p3 = make_pair(100,"abc"); //another way to assign values to the pair(useful when we are taking pair values as inputs)
    cout << "Value of p3: " << p3.first << "," << p3.second << endl; 

    pair<pair<int,int>,string> p4; //pair of pairs,the first element of the pair is also a pair and the second element is a string
    p4.first.first = 10;
    p4.first.second = 20;
    p4.second = "xyz";
    cout << "Value of p4: " << p4.first.first << "," << p4.first.second << "," << p4.second << endl; 

    //NOTE: similarly we can create pair of vectors,arrays etc.

return 0;
}