#include <bits/stdc++.h>
using namespace std;
 
void insertInNonDecOrder(deque<char>& dq, char ch)
{
 
    // If container is empty , insert the current digit
    if (dq.empty())
        dq.push_back(ch);
 
    else {
        char temp = dq.back();
 
        // Keep removing digits larger than current digit
        // from the back side of deque
        while (temp > ch && !dq.empty()) {
            dq.pop_back();
            if (!dq.empty())
                temp = dq.back();
        }
 
        // Insert the current digit
        dq.push_back(ch);
    }
    return;
}
 
string buildLowestNumber(string str, int n)
{
    int len = str.length();
 
    // Deleting n digits means we need to print k digits
    int k = len - n;
 
    deque<char> dq;
    string res = "";
 
    // Leaving rightmost k-1 digits we need to choose
    // minimum digit from rest of the string and print it
    int i;
    for (i = 0; i <= len - k; i++)
 
        // Insert new digit from the back side in
        // appropriate position and/ keep removing
        // digits larger than current digit
        insertInNonDecOrder(dq, str[i]);
 
    // Now the minimum digit is at front of deque
    while (i < len) {
 
        // keep the minimum digit in output string
        res += dq.front();
 
        // remove minimum digit
        dq.pop_front();
 
        // Again insert new digit from the back
        // side in appropriate position and keep
        // removing digits larger than current digit
        insertInNonDecOrder(dq, str[i]);
        i++;
    }
 
    // Now only one element will be there in the deque
    res += dq.front();
    dq.pop_front();
    return res;
}
 
string lowestNumber(string str, int n)
{
    string res = buildLowestNumber(str, n);
     
    // Remove all the leading zeroes
    string ans = "";
    int flag = 0;
    for (int i = 0; i < res.length(); i++) {
        if (res[i] != '0' || flag == 1) {
            flag = 1;
            ans += res[i];
        }
    }
 
    if (ans.length() == 0)
        return "0";
    else
        return ans;
}
 
// Driver program to test above function
int main()
{
    string input;
    int k;
    getline(cin,input);
    cin>>k;
	if(k>input.length()){
		cout<<"error"<<endl;
	}
	else{
		cout <<lowestNumber(input, k);
	}
}