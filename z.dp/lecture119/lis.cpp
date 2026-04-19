#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int solve(vector<int>& nums, int s, int p, vector<vector<int>>& dp) {
    int n = nums.size();
    if(s == n) return 0;

    if(dp[s][p + 1] != -1) 
        return dp[s][p + 1];

    // exclude 
    int nottake = solve(nums, s + 1, p, dp);

    // include
    int take = 0;
    if(p == -1 || nums[s] > nums[p]) {
        take = 1 + solve(nums, s + 1, s, dp);
    }

    return dp[s][p + 1] = max(nottake, take);
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solve(nums, 0, -1, dp);
}


int tabulation(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for(int index = n - 1; index >= 0; index--) {
        for(int prev = index - 1; prev >= -1; prev--) {

            int notTake = dp[index + 1][prev + 1];

            int take = 0;
            if(prev == -1 || nums[index] > nums[prev]) {
                take = 1 + dp[index + 1][index + 1];
            }

            dp[index][prev + 1] = max(take, notTake);
        }
    }
    return dp[0][0];
}


int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << lengthOfLIS(nums) << endl;  // Output: 4
    cout <<tabulation(nums) << endl;  // Output: 4
    return 0;
}