/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

//###INSERT CODE HERE -
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
        }
    }
    void myProcess(int n)
    {
        int command;
        string x,y;
        for (auto i = 0; i < n; i++)
        {
            cin>>command;
            if (command == 1)
            {
                cin>>x>>y;
                if(adjMatrix[strToInt[x]][strToInt[y]]){
                    cout<<"TRUE"<<endl;
                }
                else{
                    cout<<"FALSE"<<endl;
                }
            }
            if(command == 2){
                bool hvAdjVertex=false;
                int index=0;
                cin>>x;
                for(auto j=this->adjMatrix[strToInt[x]].begin();j!=this->adjMatrix[strToInt[x]].end();j++){
                    if(*j==1){
                        hvAdjVertex=1;
                        cout<<intToStr[index]<<" ";
                    }
                    index++;
                }
                if(!hvAdjVertex){
                    cout<<"NONE"<<endl;
                }
                cout<<endl;
            }
            
        }
    }
};

int main()
{
    Graph G;
    int v, e, n;
    cin >> v >> e >> n;
    G.nhap(v, e);
    G.myProcess(n);
    return 0;
}
