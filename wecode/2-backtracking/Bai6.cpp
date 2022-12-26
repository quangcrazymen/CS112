// https://coderscat.com/kth-largest-element-in-an-array/
// https://www.geeksforgeeks.org/kth-smallest-largest-element-in-unsorted-array/

#include <bits/stdc++.h>
using namespace std;

// void swap(vector<int>&a,int x,int y){
//     int t = a[y];
//     a[y] = a[x];
//     a[x] = t;
// }

// divide and conquer

class Solution {

private:
  void swap(vector<int>& a, int x, int y) {
    int t = a[y];
    a[y] = a[x];
    a[x] = t;
  }

  int random(int a, int b) {
    return (int) (rand() % (b - a + 1)) + a;
  }

  int partition(vector<int>& nums, int left, int right, int index) {
    int pivot = nums[index];
    swap(nums, index, right);
    int i = left - 1;
    for (int j=left; j<=right-1; j++)
      if (nums[j] <= pivot)
        swap(nums, ++i, j);
    swap(nums, right, i+1);
    return i+1;
  }

  int quick_select(vector<int>& nums, int left, int right, int k) {
    while (left <= right) {
      int pivot = partition(nums, left, right, random(left, right));
      if (pivot == k) return nums[k];
      else if (k > pivot) left = pivot + 1;
      else right = pivot - 1;
    }
    return -1;
  }

public:
  int findKthLargest(vector<int>& nums, int k) {
    return quick_select(nums, 0, nums.size() - 1, nums.size() - k);
  }
};


int main(){
    Solution a;
    vector<int> test{6,1,5,2,4,3};
    int n;
    int k;
    cin>>n>>k;
    vector<int> input(n,0);
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    cout<<a.findKthLargest(input,k);
}