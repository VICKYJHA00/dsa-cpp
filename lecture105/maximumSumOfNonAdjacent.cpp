#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// -- using recursion --
// int solve(vector<int> &nums, int n){
//     if(n < 0) return 0;
//     if(n == 0) return nums[0];
//     int incl = solve(nums,n-2) + nums[n];
//     int excl = solve(nums,n-1) + 0;

//     return max(incl,excl);
    
// }

// int maximumSumOfNonAdjacent(vector<int> &nums){
//     int n = nums.size();
//     return solve(nums,n-1);
// }


// -- using Memorization --
int solvemem(vector<int> &nums, int n , vector<int> &dp){
    if(n < 0 ) return 0;
    if(n == 0) return nums[0];
    if(dp[n ] != -1) retrun dp[n];
    int incl = solvemem(nums,n-2,dp) + nums[n];
    int excl = solvemem(nums,n-1,dp) + 0;
    do[n] = max(incl,excl);
    return dp[n];
}
int maximumSumOfNonAdjacent(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,-1);
    return solvemem(nums,n-1,dp);

}

//-- using tabulation --
int solvetab(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,0);
    dp[0] = nums[0];
    for(int i =1 ;i<n;i++){
        int incl = dp[i-2] + nums[i];
        int excl = dp[i-1] + 0;
        dp[i] = max(incl,excl);
    }

    return dp[n-1];
}

// using space optimazation
int solvetab(vector<int> &nums){
    int n = nums.size();
    int prev2 = 0;
    int prev1 = nums[0];
    
    for(int i =1 ;i<n;i++){
        int incl = dp[i-2] + nums[i];
        int excl = dp[i-1] + 0;
        int ans = max(incl,excl);
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

int main(){
    vector<int> nums = {2,1,4,9};
    cout<<maximumSumOfNonAdjacent(nums)<<endl;
    return 0;
}