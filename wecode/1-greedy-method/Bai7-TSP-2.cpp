#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <cstring>

using namespace std;

int has(vector<pair<string,int>> list, string vertex)
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

vector<string> split(string path){
    vector<string> array;
    for(auto i:path){
        if(i==' '){
            continue;
        }
        array.push_back(to_string(i));
    }
    // pop "." out of array 
    array.pop_back();

    return array;
}

int checkValidCycle(string path,map<string,vector<pair<string,int>>> graph){
    vector<string> array = split(path);
    // iterate through all keys
    int totalDistance;
    for(auto i=array.begin();i<array.end()-1;i++){
        // iterate through each adjacent vertex of the key
        if(has(graph[*i],*(i))>0){
            totalDistance = has(graph[*i],*(i));
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
    string fVertex, adjVertex,path;
    // INITIALIZE ADJACENCY LIST
    map<string, vector<pair<string,int>>> adjVerList;
    for (auto i = 0; i < e; i++)
    {
        cin >> fVertex >> adjVertex>>distance;
        // check if vertex already in the list 
        if (!has(adjVerList[fVertex], adjVertex))
        {
            pair<string,int> item;
            item.first=adjVertex;
            item.second=distance;
            adjVerList[fVertex].push_back(item);
        }
    }

    for(int i=0;i<n;i++){
        cin.ignore();
        getline(cin,path);
        int result = checkValidCycle(path,adjVerList);
        if(result>0){
            cout<<result<<'\n';
        }
        else{
            cout<<"FALSE"<<'\n';
        }
        
    }
}
