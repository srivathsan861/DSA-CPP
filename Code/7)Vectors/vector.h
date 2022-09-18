
template<typename T> 
/*
Why templates?
suppose you created a custom class vector in which you can push integers, then you can only push integers in it.
you can't push other data types in it. so you should create another custom class for that specific data type which is not a good idea.
here comes the picture of templated class where 'T' is the type, you can fill T with any datatype like int, char,float etc.
*/

class Vector{

private:
    //private data members
    int cs;                    //current size
    int ms;                   //max size
    T *arr;

public:
  
    Vector(){                   //constructr
        cs = 0;                
        ms = 1;                //the max size of any vector which is declared is 1
        arr = new int[ms];    //dynamic array
    }

    void push_back(const T d){

        if(cs == ms){                    //vector is full

            T *oldArr = arr;            //store the current arr elements in oldArr
            arr = new T[2*ms];          //double the max size of the array
            ms = 2*ms;                  //update the max size

            for(int i=0;i < cs;i++){
            arr[i] = oldArr[i];         //copy the elements from oldArr back to arr
            }

            delete[] oldArr;
        }

        arr[cs] = d;                    //assign data to new array
        cs++;                          //incrementing current size
    }

    void pop_back(){
        cs--;                         //removing last item by decreasing the size of the array
    }

    T front()const{
        return arr[0];              //returns the first item
    }

    T back()const{
        return arr[cs-1];         //returns the last item
    }

    bool empty()const{
        return cs == 0;         //if current size is 0 then the vector is empty
    }

    int size()const{
        return cs;             //returns current size
    }

    int capacity()const{
        return ms;            //return maximum size
    }

    T* begin() const {
		return arr;           //returns the address of staring index
	}

	T* end() const {
		return arr + cs;      //returns the address of last index
	}

    T at(const int i){
        return arr[i];             //returns the ith value
    }

    T operator[](const int i){    //operator overloading
        return arr[i];            //returns the ith value
    }

    void clear(){
        cs = 0;                //removes all elements of the vector by making the current size to 0
    }
};