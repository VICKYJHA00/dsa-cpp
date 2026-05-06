#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;


int MOD = 1e9 + 7;
int solve(int n , int k , int target, vector<vector<int>>& dp){
    if(target<0) return 0;
    if(n == 0 && target == 0) return 1;
    if(n == 0 && target != 0) return 0;
    if(dp[n][target] != -1) return dp[n][target];

    long long ans = 0;
    for(int i = 1;i<=k;i++){
        ans += solve(n-1,k,target-i,dp);
    }

    return dp[n][target] = ans%MOD;
}

int numRollsToTarget(int n, int k, int target) {
    vector<vector<int>> dp(
        n + 1,
        vector<int>(target + 1, -1)
    );
    return solve(n,k,target,dp);
}

int tabulation(int n, int k , int target){
    vector<vector<int>> dp(n+1,vector<int>(target+1,0));
    dp[0][0] = 1;

    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=target;j++){
            long long ans = 0;
            for(int face =1;face<=k;face++){
                if(i-1>=0 && j-face>=0){
                    ans += dp[i-1][j-face];
                    dp[i][j] = ans%MOD;
                }
            }
        }
    }
    return dp[n][target];
}

int main(){
    int n = 2, k = 6, target = 7;
    cout<<numRollsToTarget(n,k,target)<<endl;
    cout<<tabulation(n,k,target)<<endl;
    return 0;
}
