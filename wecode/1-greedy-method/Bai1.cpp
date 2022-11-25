#include<iostream>
#include<stack>
#include<string>
using namespace std;

string deleteKdigits(string input,int k){
    int len = input.size();
    if(k>len){
        return "error";
    }
    else if(k==len){
        return "0";
    }
    else{
        stack<char> st;
        // iterate through input number
        for(char i:input){
            // sequencially delete bigger number
            // save small number to stack
            while(!st.empty()&&i<st.top()&&k>0){
                st.pop();
                k--;
            }
            if( !st.empty() || i!='0'){
                st.push(i);
            }
        }
        // remove largest value on top of the stack
        while (!st.empty() && k--)
		    st.pop();
	    if (st.empty())
		    return "0";

        while(!st.empty()){
            input[len-1]=st.top();
            st.pop();
            len--;
        }
    }
    return input.substr(len);
}

int main(){
    string input;
    int k;
    getline(cin,input);
    cin>>k;
    cout<<deleteKdigits(input,k);
}