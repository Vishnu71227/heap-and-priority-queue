#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Heap{
    vector<int> vec;  //cbt
    public:
    
    void push(int val){
        //step1; 
        vec.push_back(val);

        //step2: 
        int x = vec.size()-1; //x is child index
        int parentIndex = (x-1)/2;  

        while(parentIndex>=0 && vec[x]>vec[parentIndex]){ //O(logn)
            swap(vec[x],vec[parentIndex]);
            x=parentIndex;
            parentIndex = (x-1)/2;
        }
    }

    void heapify(int parentIdx){
        int leftvalue = 2*parentIdx+1;
        int rightvalue = 2*parentIdx+2;

        int maxIdx =parentIdx;
        if(leftvalue<vec.size() && vec[maxIdx]<vec[leftvalue]){
            maxIdx = leftvalue;
        }

        if(rightvalue<vec.size() && vec[maxIdx]<vec[rightvalue]){
            maxIdx = rightvalue;
        }

        swap(vec[parentIdx],vec[maxIdx]);
        if(maxIdx!=parentIdx){
            heapify(maxIdx);
        }
    }

    void pop(){
        //step1 : 
        swap(vec[0],vec[vec.size()-1]);

        //step2
        vec.pop_back();

        //step3
        heapify(0);
    }

    int top(){ //(1)
        return vec[0]; // highest priority elemnt is on top
    }

    bool empty(){
        return vec.size()==0;
    }
};

int main(){
    Heap heap;
    heap.push(50);
    heap.push(10);
    heap.push(100);

    cout<<"top = "<<heap.top()<<endl;
    return 0;
}