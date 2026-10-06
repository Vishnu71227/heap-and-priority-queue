#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class student{
    public:
    string name;
    int marks;

    student(string name,int marks){
        this->name = name;
        this->marks = marks;    
    }

    bool operator < (const student &obj) const{
    return this->marks<obj.marks;
   }
};

int main(){
    priority_queue<student> pq;

    pq.push(student("A",100));
    pq.push(student("B",80));
    pq.push(student("C",90));

    while(!pq.empty()){
        cout<<pq.top().name<<" "<<pq.top().marks<<endl;
        pq.pop();
    }
    return 0;
}