#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>


using namespace std;

vector<char> split(string path){
    vector<char> array;
    for(auto i=0;i<path.size();i++){
        if(path[i]==' '){
            continue;
        }
        array.push_back(path[i]);
    }
    // pop "." out of array 
    array.pop_back();

    return array;
}

int checkValidCycle(string path,map<char,vector<pair<char,int>>> graph){
    vector<char> array = split(path);
    // iterate through all keys
    for(auto i:array){

    }
    return 1;
}

int main()
{
    int e,n,distance;
    cin >> e>> n;
    char fVertex, adjVertex;
    string path;
    // INITIALIZE ADJACENCY LIST
    map<char, vector<pair<char,int>>> adjVerList;
    for (auto i = 0; i < e; i++)
    {
        cin >> fVertex >> adjVertex>>distance;
        // check if vertex already in the list 
        pair<char,int> item;
        item=pair<char,int>(adjVertex,distance);
        adjVerList[fVertex].push_back(item);
    }
    path = "L K H F L .";
    checkValidCycle(path,adjVerList);
    // for(int i=0;i<n;i++){
    //     cin.ignore();
    //     getline(cin,path);
    //     int result = checkValidCycle(path,adjVerList);
    //     if(result>0){
    //         cout<<result<<'\n';
    //     }
    //     else{
    //         cout<<"FALSE"<<'\n';
    //     }
        
    // }
}