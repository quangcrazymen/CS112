#include <iostream>
#include <vector>
#include <string>
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

void dfs(){
    
}

void exist(){

}

int main()
{
    vector<string> rows;
    vector<vector<string>> board;
    string input;
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
    printBoard(board);
}