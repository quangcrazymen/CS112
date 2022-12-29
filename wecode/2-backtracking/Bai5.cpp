#include <iostream>
#include <vector>
#include <string>
#include<set>
using namespace std;

// Adjacent meaning i + 1
// word search
// https://www.youtube.com/watch?v=pfiQ_PS1g8E&list=PLot-Xpze53lf5C3HSjCnyFghlW0G1HHXo

void printBoard(vector<vector<string>> &board){
    for(auto i:board){
        for(auto j:i){
            cout<<j<<' ';
        }
        cout<<'\n';
    }
}

bool dfs(vector<vector<string>>&board,string &target,int r,int c,int i,
        int rows,int columns,set<pair<int,int>>&path){
    if(i==target.length()){
        return true;
    }
    pair<int,int> curChar(r,c);
    const bool is_visited = path.find(curChar)!=path.end();
    if(r<0 || c<0 ||r>=rows||c>=columns||
    string(1,target[i])!=board[r][c]||is_visited){
        return false;
    }
    path.insert(curChar);
    bool sol = dfs(board,target,r+1,c,i+1,rows,columns,path)||
                dfs(board,target,r-1,c,i+1,rows,columns,path)||
                dfs(board,target,r,c+1,i+1,rows,columns,path)||
                dfs(board,target,r,c-1,i+1,rows,columns,path);
    path.erase(curChar);
    return sol;
                
}

bool exist(vector<vector<string>> &board,string &target){
    int rows = board.size();
    int columns = board[0].size();
    set<pair<int,int>> path;
    for(int r=0;r<rows;r++){
        for(int c=0;c<columns;c++){
            if(dfs(board,target,r,c,0,rows,columns,path)){
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<string> rows;
    vector<vector<string>> board;
    string input,target;
    cin>>target;
    while (input != ".")
    {
        cin >> input;
        for (auto i:input)
        {
            rows.push_back(string(1,i));
        }
        board.push_back(rows);
        rows.clear();
    }
    // pop '.' out of the board
    board.pop_back();
    if(exist(board,target)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}