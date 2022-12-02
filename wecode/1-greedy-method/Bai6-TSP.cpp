#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <set>

using namespace std;

map<string, set<pair<string,int>>> adjVerList;
int checkValidCycle(string vertex,string prevVertex){
    for(auto &i:adjVerList[prevVertex]){
        if(i.first == vertex){
            return i.second;
        }
    }
    return -1;
}

int main()
{
    int e,distance,n;
    cin >> e>>n;
    string fVertex, adjVertex;
    // INITIALIZE ADJACENCY LIST
    for (auto i = 0; i < e; i++)
    {
        cin >> fVertex >> adjVertex>>distance;
        adjVerList[fVertex].insert(pair<string,int>(adjVertex,distance));
    }
    string vertex;
    string prevVertex;
    int totalDistance = 0;
    bool validCycle = 1;
    for(int i=0;i<n;i++){
        cin>>prevVertex;
        totalDistance = 0;
        validCycle = 1;
        // read user input until stringacter '.'
        while(1){
            cin>>vertex;
            if(vertex==".")
                break;
            int distance = checkValidCycle(vertex,prevVertex);
            if(distance>0){
                totalDistance+=distance;
            }
            else if(distance==-1){
                validCycle = 0;
                // ignore cin until '.'
                while(vertex!="."){
                    cin>>vertex;
                }
                break;
            }
            prevVertex=vertex;
        }
        if(validCycle){
            cout<<totalDistance<<'\n';
        }
        else
            cout<<"FALSE\n";
    }
}