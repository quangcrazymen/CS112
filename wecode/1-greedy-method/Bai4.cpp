#include <iostream>
#include <vector>
#include <istream>
#include <ostream>
#include <limits>
using namespace std;

class MulMachineSche{
    vector<vector<int>> jobs;
    vector<int> sol;
    vector<int>totalTime;
public:
    MulMachineSche(int n,int m){
        this->jobs = vector<vector<int>>(m,vector<int>(n,0));
        this->totalTime = vector<int>(m,0);
    }
    // Using matrix to store data
    friend istream& operator>>(istream &is,MulMachineSche &a){
        for(int i=0;i<a.jobs.size();i++){
            for(int j=0;j<a.jobs[0].size();j++){
                is>>a.jobs[i][j];
            }
        }
        return is;
    }
    friend ostream& operator<<(ostream &os,MulMachineSche &a){
        for(int i=0;i<a.jobs.size();i++){
            for(int j=0;j<a.jobs[0].size();j++){
                os<<a.jobs[i][j]<<' ';
            }
            cout<<'\n';
        }
        return os;
    }

    void scheduling(){
        for(int i=0;i<this->jobs[0].size();i++){
            int max=numeric_limits<int>::max();
            int argmax=0;
            for(int j=0;j<this->jobs.size();j++){
                if(totalTime[j]+jobs[j][i]<max && jobs[j][i]!=-1){
                    max=totalTime[j]+jobs[j][i];
                    argmax = j;
                }
            }
            totalTime[argmax]+=max;
            sol.push_back(argmax);
        }
        for(int i:this->sol){
            cout<<i<<" ";
        }
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    MulMachineSche a(n,m);
    cin>>a;
    a.scheduling();
}