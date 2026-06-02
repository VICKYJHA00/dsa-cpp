#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int solve(vector<int>& nums, int difference){
    int n = nums.size();
    if(n<=1) return n;
    unordered_map<int,int> dp;
    int ans = 1;
    for(int i = 0;i<n;i++){
        int prev = nums[i] - difference;
        if(dp.count(prev)){
            dp[nums[i]] = dp[prev] + 1;
            ans = max(ans, dp[nums[i]]);
        } else {
            dp[nums[i]] = 1;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {1,2,3,4};
    int difference = 1;
    cout<<solve(nums,difference)<<endl;
    return 0;
}