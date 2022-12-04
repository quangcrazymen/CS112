// using backtracking
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    vector<vector<bool>> adjMatrix;
    // 2 maps to easily lookup key-value pair
    map<string, int> strToInt;
    map<int, string> intToStr;
    vector<int>sol;
    vector<int>initColor;
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
        this->sol=vector<int> (this->adjMatrix.size(),-1);

    }
    bool isValid(int v,int c){
        for(int i=0;i<this->adjMatrix.size();i++){
            if(this->adjMatrix[v][i] && c ==this->sol[i])
                return false;
        }
        return true;
    }
    // recursive util to solve m coloring problem
    bool graphColoringUtil(int m,int v){
        if(v==this->adjMatrix.size())
            return true;
        for(int c=0;c<m;c++){
            if(isValid(v,c)){
                this->sol[v]=c;
                if(graphColoringUtil(m,v+1)==true)
                    return true;
                this->sol[v]=-1;
            }

        }
        return false;
    }
    void graphColoring(){
        // number of possible color =99
        int m=99;
        this->graphColoringUtil(m,0);
        for(int i= 0;i<this->adjMatrix.size();i++){
            cout<<this->sol[i]<<" ";
        }
    }
};

int main(){
    Graph a;
    int v,e;cin>>v>>e;
    a.nhap(v,e);
    a.graphColoring();
}