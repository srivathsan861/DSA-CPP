#include<iostream>
#include<algorithm>
using namespace std;

//NOTE: dry run for better understanding

void print_factors(int n){

    vector <pair<int,int>> factors; //store factors and its counts

    int count;

    for(int i=2;i*i <= n;++i){      //2 to rootof(n) -> time complexity: O(rootof(n))

        if(n%i == 0){
            count = 0;              //reinitializing count
            while(n % i == 0){
                count++;            //incrementing count
                n = n/i;            
            }
        factors.push_back(make_pair(i,count));  
        }

        if(n != 1){                                 //this is the catch: suppose we hit a prime no. as a factror then that factor itself 
                                                    //won't get added in because we are running the loop till rootof(n) only
            factors.push_back(make_pair(n,1));
        }
    }

    for(auto p:factors){
        cout << "FACTOR: "<< p.first << " COUNT: " << p.second << endl;
    }

return;
}

int main(){

     int n;
     cin >> n;
     print_factors(n);

return 0;
}