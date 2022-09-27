#include<iostream>
#include<algorithm>
using namespace std;

//PROBLEM: You are standing at origin and looking to book a cab. You found N no. of cabs and you need to choose the nearest one.
//PROBLEM GOAL: to learn how to use vectors+pairs+sorting

bool compare(pair<int,int> p1,pair<int,int> p2){                        //comparator function

    int dist1 = (p1.first * p1.first) + (p1.second * p1.second);        //distance from origin formula: whole root of(square(x)+square(y))
    int dist2 = (p2.first * p2.first) + (p2.second * p2.second);

    if(dist1 == dist2){                                                 //if the distance is equal, sort according to the x-coordinates
        return p1.first < p2.first;
    }

return dist1 < dist2;
}

int main(){
    
    cout << "Enter number of cabs available: ";
    int n;
    cin >> n;                              //no. of cabs

    vector<pair<int,int>> v;              //vector os pairs, and each pair will contain the coordinates x,y

    for(int i=0;i < n;++i){
        cout << "Enter coordinates of the cab: ";
        int x,y;
        cin >> x >> y;                     //inputting coordinates
        v.push_back(make_pair(x,y));       //inserting the values
    }

    sort(v.begin(),v.end(),compare);      //sorting using comparator

    cout << "Sorted order: " << endl;
    for(auto d : v){
        cout << d.first << "," << d.second << endl;  //printing all the cab locations in ascending order(in terms of distance)
    }

    cout << "The nearest cab is located at the coordinates: " << v[0].first << "," << v[0].second << endl;

return 0;
}