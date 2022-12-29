// matrix chain multiplication
#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Get subvector from vector: https://stackoverflow.com/questions/421573/best-way-to-extract-a-subvector-from-a-vector
// Get the last element address in vector: https://stackoverflow.com/questions/3651847/prettier-syntax-for-pointer-to-last-element-stdvector
void evalu(vector<int> numbers,int k){
    vector<int> firstPart= vector<int>(&numbers[0],&numbers[k]);
    vector<int> secondPart= vector<int>(&numbers[k],&numbers.back()+1);
    if(k==firstPart.size()){
        cout<<firstPart[0]<<' ';
        // return firstPart[0];
        evalu(secondPart,k+1);
    }
    if(k==secondPart.size()){
        cout<<secondPart[0]<<' ';
        // return firstPart[0];
        evalu(firstPart,k+1);
    }
    // eval(firstPart,1);
    // eval(secondPart,1);

}

int main(){
    // string exp;
    // cin>>exp;
    // vector<int> numbers;
    // for(int i=0;i<exp.length();i+=2){
    //     numbers.push_back(stoi(string(1,exp[i]))); 
    // }
    vector<int>test{2,3,4,5,6,7};
    evalu(test,1);
}