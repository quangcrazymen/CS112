// https://www.geeksforgeeks.org/print-all-combinations-of-balanced-parentheses/
#include <bits/stdc++.h>
using namespace std;

void generateParenthesis(int n,int open, int close, string s,vector<string>&answer);

int main(){
    int n;
    cin>>n;
    vector<string>answer;
    generateParenthesis(n,0,0,"",answer);
    for(auto &i:answer){
        cout<<i<<'\n';
    }
}

void generateParenthesis(int n,int open, int close, string s,vector<string>&answer){
    if(open == n && close == n){
        answer.push_back(s);
        return;
    }
    if(open<n){
        generateParenthesis(n,open+1,close,s+"(",answer);
    }
    if(close<open){
        generateParenthesis(n,open,close+1,s+")",answer);
    }
}