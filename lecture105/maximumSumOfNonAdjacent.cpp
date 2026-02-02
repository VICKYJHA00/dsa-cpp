#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(vector<int> &nums, int n){
    if(n < 0) return 0;
    if(n == 0) return nums[0];
    int incl = solve(nums,n-2) + nums[n];
    int excl = solve(nums,n-1) + 0;

    return max(incl,excl);
    
}

int maximumSumOfNonAdjacent(vector<int> &nums){
    int n = nums.size();
    return solve(nums,n-1);
}

int main(){
    vector<int> nums = {2,1,4,9};
    cout<<maximumSumOfNonAdjacent(nums)<<endl;
    return 0;
}