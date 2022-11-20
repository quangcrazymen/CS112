#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

// UNDIRECTED GRAPH WITH NAME
class Graph
{
    vector<vector<bool>> adjMatrix;
    // 2 maps to easily lookup key-value pair
    map<string, int> strToInt;
    map<int, string> intToStr;

public:
    void nhap(int v, int e)
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
    }
    void getDegree(){
        for(auto &i:adjMatrix){
            int count=0;
            for(auto j:i){
                if(j==1){
                    count++;
                }
            }
            cout<<count<<" ";
        }
    }
};

int main(){
    Graph a;
    int v,e;cin>>v>>e;
    a.nhap(v,e);
    a.getDegree();
}