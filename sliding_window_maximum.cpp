#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;



void sliding_window_maximum(vector<int> arr,int k){
    priority_queue<pair<int, int>> pq;

    for(int i=0;i<k;i++){
        pq.push(make_pair(arr[i],i));
    }

    cout<<"output: "<<pq.top().first<<endl;

    for(int i=k;i<arr.size();i++){
        while(!pq.empty() && pq.top().second<=i-k){
            pq.pop();
        }
        pq.push(make_pair(arr[i],i));
        cout<<"output: "<<pq.top().first<<endl;
    }
}

int main(){
    vector<int> arr={1,3,-1,-3,5,3,6,7};
    int k=3;
    
    sliding_window_maximum(arr,k);
    
    return 0;
}