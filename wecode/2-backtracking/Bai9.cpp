// https://www.youtube.com/watch?v=XhzHXj7wrwo
// Skyline problem
#include<iostream>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;
// priority queues
vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> h;
		
        // Convert each building into two segments.
        for (auto b : buildings) {
            h.push_back({b[0], -b[2]});
            h.push_back({b[1], b[2]});
        }
        
        // Sort the segments.
        sort(h.begin(), h.end());
        int prev = 0, cur = 0;
        
        multiset<int> m;
        vector<vector<int>> res;
        
        m.insert(0);
        for (auto i:h) {
            
            // If i.second is less than zero, then it means it is left boundary.
            if (i.second < 0) {
                m.insert(-i.second);
            } else { // else it is right boundary.
                m.erase(m.find(i.second));
            } 
            
            cur = *m.rbegin();
            
            // If current maximum height is not equal to maximum previuous height, it is a key point.
            if (cur != prev) {
                res.push_back({i.first, cur});
                prev = cur;
            }
        }
        return res;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> buildings(n,(vector<int>(3,0))); 
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>buildings[i][j];
        }
    }
    // vector<vector<int>> input{{2, 9, 10},{3, 7, 15},{5, 12, 12},{15, 20, 10},{19, 24, 8}};
    vector<vector<int>> output= getSkyline(buildings);
    for(auto i:output){
        for(auto j:i){
            cout<<j<<' ';
        }
        cout<<'\n';
    }
    return 0;
}