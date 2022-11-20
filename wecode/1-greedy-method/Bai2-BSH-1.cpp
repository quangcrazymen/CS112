#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <istream>
#include <ostream>
#include<algorithm>
using namespace std;

// sort the element on the basis of 2nd element in pair
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){
    return (a.second>b.second);
}
class BasicScheduling{
    vector<int> sol;
    vector<int> totalTime;
    vector<int> timeList;
    public:
    vector<pair<int,int>> jobs;
    BasicScheduling(int n,int m){
        this->sol = vector<int>(n,0);
        this->totalTime = vector<int>(m,0);
        this->timeList = vector<int>(n,0);
        this->jobs = vector<pair<int,int>>(n,pair<int,int>(0,0));
    }
    friend istream& operator>>(istream &is,BasicScheduling &a){
        for(int i=0;i<a.sol.size();i++){
            is>>a.timeList[i];
            a.jobs[i] = pair<int,int>(i,a.timeList[i]);
        }
        return is;
    }
    friend ostream& operator<<(ostream &os,BasicScheduling &a){
        for(int i=0;i<a.sol.size();i++){
            os<<a.timeList[i]<<" ";
        }
        return os;
    }

    void scheduling(){
        sort(jobs.begin(),jobs.end(),sortbysec);
        for(auto i=0;i<this->jobs.size();i++){
            // FIND ARG-MAX OF TOTAL
            int j = min_element(this->totalTime.begin(),this->totalTime.end())-this->totalTime.begin();
            this->totalTime[j]+=this->jobs[i].second;
            sol[jobs[i].first]=j;
        }
        for(auto &i:sol){
            cout<<i<<" ";
        }
    }
};

// https://www.geeksforgeeks.org/sort-vector-of-pairs-in-ascending-order-in-c/

int main(){
    int n,m;
    cin>>n>>m;
    BasicScheduling sche(n,m);
    cin>>sche;
    sche.scheduling();
}