#include <iostream>
#include <vector>
#include <string>
using namespace std;

string s;
vector <string> solutions;

int findMin(int a,int b){
    return a<=b?a:b;
}

// Insert sequencially 4 dots to the string
void backtrack(int i,int dots,string curIP){
    if(dots == 4 & i == s.length()){
        solutions.push_back(curIP.substr(0,curIP.length()-1));
    }
    if(dots>4){
        return;
    }
    for(int j=i;j<findMin(i+3,s.length());j++){
        // use stoi to convert  str to int: https://www.geeksforgeeks.org/converting-strings-numbers-c-cpp/
        if(int(stoi(s.substr(i,j-i+1)))<256 & (i==j || s[i]!=0)){
            backtrack(j+1,dots+1,curIP+s.substr(i,j-i+1)+".");
        }
    }
}


// vector<string> restoreIpAddresses(string s){

// }

int main(){
    cin>>s;
    backtrack(0,0,"");
    for(auto &i:solutions){
        cout<<i<<'\n';
    }
}