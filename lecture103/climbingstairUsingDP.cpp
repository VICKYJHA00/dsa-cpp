#include<iostream>
#include<vector>
using namespace std;

// // noraml without DP
// int normla(int n){
//     if(n<=1) return 1;
//     return climbstirs(n-1) + climbstairs(n-2);
// }

// using memorization top-down approach
int memorization(vector<int> &cost, vector<int> &dp, int n){
    if(n == 0) return cost[0];
    if(n == 1) return cost[1];

    if(dp[n] != -1) return dp[n];

    dp[n] = cost[n] + min(memorization(cost,dp,n-1),memorization(cost,dp,n-2));
    return dp[n];
}

int climbstair(vector<int> &cost){
    int n = cost.size();
    vector<int> dp(n,-1);
    int ans = min(
        memorization(cost,dp,n-1),
        memorization(cost,dp,n-2)
    );
    return ans;
}

// using tabulation bottom-up approach
int solve2(vector<int> &cost, int n){
    vector<int> dp(n);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for(int i = 2;i<n;i++){
        dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
    }
    
    return min(dp[n-1],dp[n-2]);
}
int climbstair2(vector<int> &cost){
    int n = cost.size();
    return solve2(cost,n);
}

// using space optimization 
int solve3(vector<int>&cost, int n){
    int prev2 = cost[0];
    int prev1 = cost[1];
    
    for(int i = 2;i<n;i++){
        int curr = cost[i] + min(prev1,prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    return min(prev1,prev2);
}

int climbstair3(vector<int> &cost){
    int n = cost.size();
    return solve3(cost,n);
}


int main(){
 vector<int> cost = {10,15,20};
//   cout<<climbstair(cost);
    // cout<<climbstair2(cost);
    cout<<climbstair3(cost);
  return 0;
}