// Burst a balloon
// https://thewayofnada.medium.com/how-to-solve-the-burst-balloons-problem-like-a-piece-of-cake-6121f365b1f
// https://www.youtube.com/watch?v=zfgZtcDQAxw

#include <iostream>
#include <vector>
using namespace std;

int index(vector<int> nums,int i){
    if(i>=0 and i<nums.size()){
        return nums[i];
    }
    return 1;
}

int burstBaloons(vector<int>balloons){
    int n= balloons.size();
    if(n==0){
        return 0;
    }
    if(n==1){
        return balloons[0];
    }
    if(n==2){
        return balloons[0]*balloons[1]+max(balloons[0],balloons[1])
    }
    for(int i=0;i<n;i++){

    }

}

int main(){
    int n,balloon;
    vector<int> balloons;
    cin>>n;
    vector<float> ratios(n,0);
    for(int i=0;i<n;i++){
        cin>>balloon;
        balloons.push_back(balloon);
    }

}

max_coins = max([index(nums, i-1)*index(nums, i)*index(nums,i+1)+self.maxCoins(nums[:i]+nums[i+1:]) for i in range(n)])