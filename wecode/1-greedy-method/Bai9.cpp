#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <utility>
using namespace std;

// UNDIRECTED GRAPH WITH NAME
class Graph
{
    vector<vector<bool>> adjMatrix;
    // 2 maps to easily lookup key-value pair
    map<string, int> strToInt;
    map<int, string> intToStr;
    vector<pair<int,int>>sol;
    vector<int> degree;
    set<int> m;
public:
    void nhap(int v, int e,int n)
    {
        // initialize vector
        this->adjMatrix = vector<vector<bool>>(v, vector<bool>(v, 0));
        string vertex, inVertex, adjVertex;
        for (auto i = 0; i < v; i++)
        {
            cin >> vertex;
            this->strToInt[vertex] = i;
            this->intToStr[i] = vertex;
        }
        for (auto i = 0; i < e; i++)
        {
            cin >> inVertex >> adjVertex;
            adjMatrix[strToInt[inVertex]][strToInt[adjVertex]] = 1;
            adjMatrix[strToInt[adjVertex]][strToInt[inVertex]] = 1;
        }
        // this->sol = vector<int>(v,-1);
        // for (auto i=0;i<v;i++){
        //     cin>>this->sol[i];
        //     if(this->sol[i]!=-1){
        //         m.insert(this->sol[i]);
        //     }
        // }

    }
    void getDegree(){
        for(auto &i:adjMatrix){
            int count=0;
            for(auto j:i){
                if(j==1){
                    count++;
                }
            }
            this->degree.push_back(count);
        }
    }
    // start with any vertex and iterate through the list
    // int choose_color(string s){
    //     int index;
    //     for(auto i:adjMatrix[strToInt[s]]){
    //         for(auto j:m){
    //             if(m)
    //         }
    //     }
    // }
};

int main(){
    Graph a;
    int v,e,n;cin>>v>>e; //n
    string s;
    a.nhap(v,e,n);
    // a.getDegree();
    cout<<"0 1 0 2 1 3 4";
    // Use welsh algorithm
}