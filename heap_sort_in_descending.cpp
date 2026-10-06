#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

void heapify(int parentidx, vector<int> &arr, int n){ //O(logn)
    int leftchildidx=2*parentidx+1;
    int rightchildidx=2*parentidx+2;

    int maxidx=parentidx;

    if(leftchildidx<n && arr[leftchildidx]<arr[maxidx]){
        maxidx=leftchildidx;
    }

    if(rightchildidx<n && arr[rightchildidx]<arr[maxidx]){
        maxidx=rightchildidx;
    }

    if(maxidx!=parentidx){
        swap(arr[maxidx],arr[parentidx]);
        heapify(maxidx,arr,n);
    }

}

void heapsort(vector<int> &arr){
    int n=arr.size();
    // step1: build maxheap
    for(int i=n/2-1;i>=0;i--){  //O(n*logn)
        heapify(i,arr,n);
    }

    //step2: talking elements to correct position
    for(int i=n-1;i>=0;i--){//O(n*logn)
        swap(arr[0],arr[i]);
        heapify(0,arr,i);   
    }
}


int main(){
    vector<int> arr={1,4,2,5,3};
    heapsort(arr);

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}