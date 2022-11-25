#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>

using namespace std;

int has(vector<pair<char,int>> list, char vertex)
{
    for (auto &i : list)
    {
        if (i.first == vertex)
        {
            return i.second;
        }
    }
    return false;
}

int checkValidCycle(vector<char> array,map<char,vector<pair<char,int>>> graph){
    // iterate through all keys
    int totalDistance=0;
    for(auto i=array.begin();i<array.end()-1;i++){
        // iterate through each adjacent vertex of the key
        if(has(graph[*i],*(i+1))>0){
            totalDistance += has(graph[*i],*(i+1));
            continue;
        }
        return false;
    
    }
    return totalDistance;
}

int main()
{
    int e,n,distance;
    cin >> e>>n;
    char fVertex, adjVertex;
    // INITIALIZE ADJACENCY LIST
    map<char, vector<pair<char,int>>> adjVerList;
    for (auto i = 0; i < e; i++)
    {
        cin >> fVertex >> adjVertex>>distance;
        // check if vertex already in the list 
        if (!has(adjVerList[fVertex], adjVertex))
        {
            pair<char,int> item;
            item.first=adjVertex;
            item.second=distance;
            adjVerList[fVertex].push_back(item);
        }
    }
    for(int i=0;i<n;i++){
        vector<char> path;
        char ver;
        while(ver!='.'){
            cin>>ver;
            if(ver!=' '){
                path.push_back(ver);
            }
        }
        path.pop_back();
        ver='\0';
        int result = checkValidCycle(path,adjVerList);
        path.clear();
        if(result>0){
            cout<<result<<'\n';
        }
        else{
            cout<<"FALSE"<<'\n';
        }
        
    }
}
