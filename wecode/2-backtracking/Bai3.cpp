#include <iostream>
#include <vector>
using namespace std;

// Palindrome partitioning

bool isPalindrome(string a,int l,int r){
    while(l<r){
        if(a[l]!=a[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}

string input;
vector<vector<string>> sol;
vector<string> part;

//https://www.techiedelight.com/convert-char-to-string-cpp/

void dfs(int i){
    if(i>=input.length()){
        sol.push_back(part);
        return;
    }
    for(int j=i;j<input.length();j++){
        if(isPalindrome(input,i,j)){
            part.push_back(input.substr(j,j-i+1));
            dfs(j+1);
            part.pop_back();
        }
    }
}

int main(){
    cin>>input;
    dfs(0);
    for (auto i:sol)
    {
        for (auto j:i)
            cout << j << " ";
        cout << "\n";
    }
}