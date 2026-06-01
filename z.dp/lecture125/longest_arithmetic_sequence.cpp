//-----------------------------------------------
// 125. Longest Arithmetic Subsequence
// https://leetcode.com/problems/longest-arithmetic-subsequence/
// Medium
//-----------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


// -----------------------------------------------
// Approach 1: Recursion
// Time Complexity: O(N^3)
// Space Complexity: O(N)
// -----------------------------------------------
class Solution {
public:
    int solve(int index , int diff,vector<int>& nums){
        if(index<=0) return 0;
        int ans = 0;
        for(int j = index-1;j>=0;j--){
           if(nums[index]-nums[j] == diff){
             ans = max(ans,1+ solve(j,diff,nums));
           }
        }
        return ans;
    }

    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                ans = max(ans,2+solve(i,nums[j]-nums[i],nums));
            }
        }
        return ans;
    }
};

// -----------------------------------------------
// Approach 2: Memoization
// Time Complexity: O(N^3)
// Space Complexity: O(N^2)
// -----------------------------------------------
class Memoization {
public:
    int solve(int index , int diff,vector<int>& nums,vector<unordered_map<int,int>>& dp){
        if(index<=0) return 0;

        if(dp[index].count(diff)) return dp[index][diff];

        int ans = 0;
        for(int j = index-1;j>=0;j--){
           if(nums[index]-nums[j] == diff){
             ans = max(ans,1+ solve(j,diff,nums,dp));
           }
        }
        return dp[index][diff] = ans;
    }

    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;

        vector<unordered_map<int,int>> dp(n);
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                ans = max(ans,2+solve(i,nums[j]-nums[i],nums,dp));
            }
        }
        return ans;
    }
};

// -----------------------------------------------
// Approach 3: Tabulation
// Time Complexity: O(N^2)
// Space Complexity: O(N^2)
// -----------------------------------------------
class Tabulation {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        int ans = 2;
        vector<unordered_map<int,int>> dp(n);
        for(int i = 1 ;i<n;i++){
            for(int j = 0;j<i;j++){
                int cnt = 1;
                int diff = nums[i]-nums[j];
                if(dp[j].count(diff))
                    cnt = dp[j][diff];
                
                dp[i][diff] = 1 + cnt;
                ans = max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};


int main(){
    vector<int> nums = {3,6,9,12};
    Solution sol;
    Memoization solMemoization;
    cout << "Tabulation Solution: " << sol.longestArithSeqLength(nums) << endl;
    cout << "Memoization Solution: " << solMemoization.longestArithSeqLength(nums) << endl;
    return 0;
}