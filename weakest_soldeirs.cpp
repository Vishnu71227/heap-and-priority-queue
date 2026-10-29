#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class row{
    public:
    int count;
    int index;

    row(int count, int index){
        this->count = count;
        this->index = index;
    }

    bool operator < (const row& obj) const {
        if(this->count==obj.count){
            return this->index>obj.index;
        }
        return this->count>obj.count;
    }
        
};

void weakestSoldeirs(vector<vector<int>> matrix,int k){
    vector<row> rows;

    for(int i=0;i<matrix.size();i++){
        int count = 0;
        for(int j=0;j<matrix[i].size() && matrix[i][j]==1;j++){
            count++;
    }
    rows.push_back({count,i});
    }

    priority_queue<row> pq(rows.begin(),rows.end());

    for(int i=0;i<k;i++){
        cout<<"rows: "<<pq.top().index<<endl;
        pq.pop();
    }
}

int main(){
    vector<vector<int>> matrix = {{1,0,0,0},
                                  {1,1,1,1},
                                  {1,0,0,0},
                                  {1,0,0,0}};

                                  weakestSoldeirs(matrix,2);
                                  return 0;
}