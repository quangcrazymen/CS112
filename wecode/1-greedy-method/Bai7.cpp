#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <set>
#include <limits>
using namespace std;

void greedyTSP(map<string, set<pair<string,int>>> graph,string start){
    string vertex = start;
    string minVertex;
    set <string> visited;
    visited.insert(vertex);
    cout<<vertex<<' ';
    
    for(int i=0; i<graph.size()-1;i++){
        int min=numeric_limits<int>::max();
        for(auto j:graph[vertex]){
            // pre-check if vertex has been visited
            const bool is_visited = visited.find(j.first)!=visited.end();
            if(j.second<min && !is_visited){
                min=j.second;
                minVertex=j.first;
            }
            
        }
        visited.insert(minVertex);
        vertex = minVertex;
        cout<<minVertex<<' ';
    }
    cout<<start;
}

int main(){
    int e,distance;
    string s;
    cin >> e>>s;
    string fVertex, adjVertex;
    // INITIALIZE ADJACENCY LIST
    map<string, set<pair<string,int>>> adjVerList;
    for (auto i = 0; i < e; i++)
    {
        cin >> fVertex >> adjVertex>>distance;
        // check if vertex already in the list 
        adjVerList[fVertex].insert(pair<string,int>(adjVertex,distance));
    }
    greedyTSP(adjVerList,s);
}