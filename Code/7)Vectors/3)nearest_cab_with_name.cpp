#include<iostream>
#include<algorithm>
using namespace std;

//PROBLEM: You are standing at origin and looking to book a cab. You found N no. of cabs and you need to choose the nearest one(with name).
//PROBLEM GOAL: to learn how to use vectors+strings+custom_class(template class)+sorting 

class Car{                                   //custom class Car

public:                                    //access modifier
    
    //data members
    string car_name;                      
    int x;
    int y;

    Car(){}                                 //empty constructor

    Car(string name,int x,int y){           //constructor which accepts name and coordinates
        car_name = name;
        this->x=x;
        this->y=y;
    }

    int dist(){                           //member method (function inside a class)
        return ((x*x)+(y*y));            //return the distance of the cab from origin(FORMULA:whole root of(square(x)+square(y)))
    }
};

bool compare(Car A,Car B){                  //comparator function

    int dist1 = A.dist();
    int dist2 = B.dist();

    if(dist1 == dist2){                    //if distance of 2 cabs are same then sort them lexicographically using name
        return A.car_name < B.car_name;
    }

return dist1 < dist2;                      
}

int main(){
    
    cout << "Enter number of cabs available: ";
    int n;
    cin >> n;                                          //no. of cabs

    vector<Car> v;                                    //vector of custom class -> Car

    for(int i=0;i < n;++i){

        int x,y;
        string name;

        cout << "Enter name and coordinates of the cab: ";
        cin >> name >> x >> y;                         //inputting name and coordinates

        Car temp(name,x,y);                           //initializing, that is, temp is instance of a class => temp is an object
        v.push_back(temp);
    }

    sort(v.begin(),v.end(),compare);

    for(auto c : v){
        cout << "CAR: " << c.car_name << " | DISTANCE: " << c.dist() << " | LOCATION: " << c.x << "," << c.y << endl;
    }

return 0;
}